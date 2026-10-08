#include <cmath>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

string moves[4][3];

int Random(int a, int b) {
    static random_device rand;
    static mt19937 generate_rand(rand());
    uniform_int_distribution<int> rand_range(a, b);
    return rand_range(generate_rand);
}

class Bender {
public:
    string name;
    string element;
    int hp;
    int max_hp;
    int attack;
    int defense;
    int speed;
    string moves[4][3];
    double type_multiplier = 1;
    int strongest_move = 0;
    vector<int> status_moves;
    string status = "";
    int status_turns;
    vector<int> heal_moves;
    bool can_heal;
    int wins = 0, losses = 0;

    Bender(string n, string e, int h, int a, int d, int s, string m[4][3]) {
        name = n;
        element = e;
        hp = h;
        max_hp = h;
        attack = a;
        defense = d;
        speed = s;
        for (int i=0; i<4; i++) {
            moves[i][0] = m[i][0];
            moves[i][1] = m[i][1];
            moves[i][2] = m[i][2];
        }
        for (int i=0; i<4; i++) {
            if (moves[strongest_move][2] == "Heal" && i != 3) strongest_move = i + 1;
            if (stoi(moves[i][1]) > stoi(moves[strongest_move][1]) && moves[i][2] != "Heal") strongest_move = i;
            if (moves[i][2] != "" && moves[i][2] != "Heal") status_moves.push_back(i);
            if (moves[i][2] == "Heal") heal_moves.push_back(i);
        }
        if (moves[strongest_move][2] == "Heal") {
            strongest_move = 0;
            for (int i=0; i<4; i++) {
                if (stoi(moves[i][1]) > stoi(moves[strongest_move][1])) strongest_move = i;
            }
        }
        if (heal_moves.empty())  can_heal = false;
        else can_heal = true;

    }

    bool is_fainted() {
        if (hp <= 0) return true;
        return false;
    }

    void display_stats() {
        cout << name << '(' << element << ") - ";
        cout << "HP: " << hp << '/' << max_hp << ", ";
        cout << "Attack: " << attack << ", ";
        cout << "Defense: " << defense << ", ";
        cout << "Speed: " << speed << "\n";
        cout << "Moves: ";
        for (int i = 0; i <= 3; i++) {
            cout << moves[i][0] << " (" << moves[i][1];
            if (moves[i][2] != "") cout << ", " << moves[i][2];
            if (i != 3) cout << "), ";
            else cout << ")";
        }
        cout << "\n\n";
    }
};

vector<Bender> benders;


class Duel {
public:
    double base_damage;
    int heal, final_damage, burnt_damage, critical_multiplier;
    int move, turns = 0, attacker, critical_hits = 0, effective_hits = 0;
    int status_effects = 0, resisted_hits = 0;
    string  winner, loser;
    string difficulty;

    double element_type_multiplier(const Bender &b1, const Bender &b2) {
        if (b1.element == "Fire") {
            if (b2.element == "Water") return 0.5;
            if (b2.element == "Air") return 2;
            return 1;
        }
        else if (b1.element == "Water") {
            if (b2.element == "Earth") return 0.5;
            if (b2.element == "Fire") return 2;
            return 1;
        }
        else if (b1.element == "Air") {
            if (b2.element == "Fire") return 0.5;
            if (b2.element == "Earth") return 2;
            return 1;
        }
        else if (b1.element == "Earth") {
            if (b2.element == "Air") return 0.5;
            if (b2.element == "Water") return 2;
            return 1;
        }
        return 1;
    }


    Duel(Bender &b1, Bender &b2, string tournament_difficulty) {
        difficulty = tournament_difficulty;
        b1.type_multiplier = element_type_multiplier(b1, b2);
        b2.type_multiplier = element_type_multiplier(b2, b1);

        cout << b1.name << " (" << b1.element << ", HP: " << b1.hp << '/' << b1.max_hp << ')';
        cout << " VS ";
        cout << b2.name << " (" << b2.element << ", HP: " << b2.hp << '/' << b2.max_hp << ')';
        cout << "\n\n";

        while (b1.is_fainted() == false && b2.is_fainted() == false) turn(b1, b2);
        if (b1.is_fainted()) {
            winner = b2.name;
            b2.wins++;
            loser = b1.name;
            b1.losses++;
        }
        else {
            winner = b1.name;
            b1.wins++;
            loser = b2.name;
            b2.losses++;
        }

        this_thread::sleep_for(chrono::seconds(1));
        cout << loser << " fainted!\n";
        cout << winner << " wins the Duel!\n\n";
        cout << "Duel Summary:\n";
        cout << "- Winner: " << winner << endl;
        cout << "- Turns: " << turns << endl;
        cout << "- Status effects used: " << status_effects << endl;
        cout << "- Difficulty: " << difficulty << endl;
        cout << "- Critical Hits: " << critical_hits << endl;
        cout << "- Super Effective Hits: " << effective_hits << endl;
        cout << "- Resisted Hits: " << resisted_hits << endl;
    }

    void Attack_Bender(Bender &b1, Bender &b2) {
        int flag = 0, heal_error = 0;

        int move_power = stoi(b1.moves[move][1]);
        if (b1.moves[move][2] == "Heal") {
            heal = move_power;
            b1.hp += heal;
            if (b1.hp > b1.max_hp) {
                heal_error = b1.hp - b1.max_hp;
                b1.hp = b1.max_hp;
            }
            cout << b1.name << " recovered " << move_power - heal_error << " HP\n";
            cout << b1.name << " HP: " << b1.hp << '/' << b1.max_hp << "\n\n";
        }
        else {
            if (b1.type_multiplier == 2) effective_hits++;

            int critical_rand = Random(1, 10);
            if (critical_rand == 1) {
                critical_multiplier = 2;
                critical_hits++;
                cout << "Critical Hit!\n";
            }
            else critical_multiplier = 1;

            base_damage = (static_cast<double>(b1.attack * move_power)) / static_cast<double>(b2.defense);
            final_damage = round(base_damage * b1.type_multiplier * critical_multiplier);
            if (final_damage == 0 && move_power > 0) final_damage = 1;
            b2.hp -= final_damage;
            if (b2.hp < 0) b2.hp = 0;
            cout << b2.name << " took " << final_damage << " damage!\n";

            for (int i=0; i<b1.status_moves.size(); i++) {
                if (move == b1.status_moves[i]) flag = 1;
            }
            if (flag == 1) {
                if (b1.moves[move][2] == "Burn") {
                    b2.status = "Burnt";
                    b2.status_turns = 4;
                    status_effects++;
                    cout << b2.name << " got Burnt! (" << b2.status_turns << " turns remaining)\n";
                }
                else if (b1.moves[move][2] == "Freeze") {
                    b2.status = "Frozen";
                    b2.status_turns = 3;
                    status_effects++;
                    cout << b2.name << " got Frozen! (" << b2.status_turns << " turns remaining)\n";
                }
                else if (b1.moves[move][2] == "Bury") {
                    b2.status = "Buried";
                    b2.status_turns = Random(2, 4);
                    status_effects++;
                    cout << b2.name << " got Buried! (" << b2.status_turns << " turns remaining)\n";
                }
                else if (b1.moves[move][2] == "Fly") {
                    b1.status = "Flew";
                    b1.status_turns = 1;
                    status_effects++;
                    cout << b1.name << " flew away! (" << b1.status_turns << " turns remaining)\n";
                }
            }
        }

        Burning(b1, b2);
    }

    void Burning(Bender &b1, Bender &b2) {
        if (b2.status == "Burnt" && b2.status_turns > 0 && b2.hp > 0) {
            b2.status_turns--;
            burnt_damage = b2.max_hp/10;
            b2.hp -= burnt_damage;
            if (b2.hp < 0) b2.hp = 0;
            cout << b2.name << " is burning.\n";
            cout << b2.name << " took " << burnt_damage << " damage!\n";
        }
    }

    void turn(Bender &b1, Bender &b2) {
        turns++;
        this_thread::sleep_for(chrono::seconds(1));

        if (b1.speed == b2.speed) {
            attacker = Random(1, 2);
        }
        else if (b1.speed > b2.speed) {
            if (turns % 2 == 1) attacker = 1;
            else attacker = 2;
        }
        else {
            if (turns % 2 == 1) attacker = 2;
            else attacker = 1;
        }

        cout << "Turn " << turns << ": ";

        if (attacker == 1) turn_status(b1, b2);
        else turn_status(b2, b1);
    }

    void turn_status(Bender &b1, Bender &b2) {
        move = choose_move(b1, b2);
        if (b2.status == "Burnt" && b2.status_turns == 0) {
            cout << b2.name << " stopped burning.\n";
            b2.status = "";
        }
        if (b1.status == "Buried" && b1.status_turns > 0) {
            cout << b1.name << " is buried and cannot move!\n";
            cout << "Turns remaining - " << b1.status_turns << "\n\n";
            b1.status_turns--;
            resisted_hits++;
        }
        else if (b1.status == "Buried" && b1.status_turns == 0) {
            cout << b1.name << " broke free from being buried!\n";
            b1.status = "";
            turn_display(b1, b2);
        }
        else if (b1.status == "Frozen" && b1.status_turns > 0) {
            b1.status_turns--;
            if (Random(1,2) == 1) {
                cout << b1.name << " is frozen and cannot move!\n";
                cout << "Turns remaining - " << b1.status_turns << "\n\n";
                resisted_hits++;
            }
            else turn_display(b1, b2);
        }
        else if (b1.status == "Frozen" && b1.status_turns == 0) {
            cout << b1.name << " broke free from being frozen!\n";
            b1.status = "";
            turn_display(b1, b2);
        }
        else if (b2.status == "Flew" && b2.status_turns == 1) {
            cout << b1.name << " strikes back!\n";
            cout << b2.name << " is flying high!\n";
            cout << b1.name << " missed!\n\n";
            if (b1.moves[move][2] != "Heal") resisted_hits++;
            if (b2.status == "Burnt") Burning(b1, b2);
            b2.status_turns--;
        }
        else if (b2.status == "Flew" && b2.status_turns == 0) {
            b2.status = "";
        }
        else turn_display(b1, b2);
    }

    void turn_display(Bender &b1, Bender &b2) {
        cout << b1.name;
        if (turns % 2 == 1) cout << " goes first! (Speed: " << b1.speed << " vs " << b2.speed << ")\n";
        else cout << " strikes back!\n";
        cout << b1.name << " used " << b1.moves[move][0] << "!\n";
        if (b1.moves[move][2] == "Heal") {
            cout << b1.name << " is healing itself!\n";
        }
        else if (b1.type_multiplier == 2) {
            cout << "Super Effective! (" << b1.element << " is strong against " << b2.element << ")\n";
        }
        else if (b1.type_multiplier == 0.5) {
            cout << "Not very effective ... (" << b1.element << " is weak against " << b2.element << ")\n";
        }
        Attack_Bender(b1, b2);
        if (b1.moves[move][2] != "Heal") cout << b2.name << " HP: " << b2.hp << '/' << b2.max_hp << "\n\n";
    }

    int choose_move(Bender &b1, Bender &b2) {
        if (difficulty == "easy"){
            return Random(0, 3);
        }
        else if (difficulty == "medium"){
            if (b1.hp < b1.max_hp/3) {
                if (b1.can_heal) {
                    if (b1.heal_moves.size() == 1) return b1.heal_moves[0];
                    else return b1.heal_moves[Random(0, b1.heal_moves.size()-1)];
                }
            }
            if (b2.hp <= b2.max_hp/4) return b1.strongest_move;
            return Random(0, 3);
        }
        else {
            if (b1.hp < b1.max_hp/3) {
                if (b1.can_heal) {
                    if (b1.heal_moves.size() == 1) return b1.heal_moves[0];
                    else return b1.heal_moves[Random(0, b1.heal_moves.size()-1)];
                }
            }
            if (b2.hp >= b2.max_hp*8/10 && b2.status == "") {
                if (b1.status_moves.empty() == false) return b1.status_moves[Random(0, b1.status_moves.size()-1)];
            }
            return b1.strongest_move;
        }
    }
};


class Tournament {
public:
    string name;
    vector<Bender> benders_list;
    vector<int> benders_numbers_list;
    vector<Bender> winners_list;
    vector<Duel> duels;
    int battles = 0, turns = 0, critical_hits = 0, status_effects = 0, effective_hits = 0, resisted_hits = 0;
    int participants;
    string current_match, match;
    vector<string> matches;
    vector<vector<Bender>> match_participants;
    string winner, first_runner_up, second_runner_up1, second_runner_up2;
    string difficulty;

    Tournament(string n, string d) {
        name = n;
        difficulty = d;
        for (int i=0; i<benders.size(); i++) {
            benders_list.push_back(benders[i]);
            benders_numbers_list.push_back(i);
        }
        do {
            match_fixtures();
            for (int i=0; i<matches.size(); i++) {
                cout << "\n ----  " <<matches[i] << "  ----" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                match_participants[i][0].status = "";
                match_participants[i][1].status = "";
                duels.push_back(Duel(match_participants[i][0], match_participants[i][1], difficulty));


                if (duels[duels.size()-1].winner == match_participants[i][0].name) winners_list.push_back(match_participants[i][0]);
                else winners_list.push_back(match_participants[i][1]);
                battles++;
            }

            benders_list.clear();
            benders_numbers_list.clear();
            for (int i=0; i<winners_list.size(); i++) {
                benders_list.push_back(winners_list[i]);
                benders_numbers_list.push_back(i);
            }
            winners_list.clear();

        }while (current_match != "Final");

        for (int i=0; i<duels.size(); i++) {
            turns += duels[i].turns;
            critical_hits += duels[i].critical_hits;
            status_effects += duels[i].status_effects;
            effective_hits += duels[i].effective_hits;
            resisted_hits += duels[i].resisted_hits;
        }

        winner = duels[duels.size()-1].winner;
        first_runner_up = duels[duels.size()-1].loser;

        this_thread::sleep_for(chrono::seconds(2));
        cout << "\n" << winner << " wins the " << name;
        cout << "\n\n===  Tournament Statistics  ===\n";
        cout << "Champion: " << winner << endl;
        cout << "Total Battles: " << battles << endl;
        cout << "Total Turns: " << turns << endl;
        cout << "Critical Hits: " << critical_hits << endl;
        cout << "Resisted Hits: " << resisted_hits << endl;
        cout << "Status Effects: " << status_effects << endl;
        cout << "Super Effective Hits: " << effective_hits << endl;
        cout << "\nFinal Standings:\n";
        cout << "1st: " << winner << endl;
        cout << "2nd: " << first_runner_up << endl;
        if (benders.size() > 2) {
            second_runner_up1 = duels[duels.size()-2].loser;
            second_runner_up2 = duels[duels.size()-3].loser;
            cout << "3rd: " << second_runner_up1 << " and " << second_runner_up2 << endl;
        }
    }

    void match_fixtures() {
        winners_list.clear();
        matches.clear();
        match_participants.clear();
        participants = benders_list.size();
        if (participants == 2) {
            current_match = "Final";
            matches.push_back("Final");
            match_participants.push_back({benders_list[0], benders_list[1]});
        }
        else if (participants == 4) {
            for (int i=1; i<=2; i++) {
                matches.push_back("Semifinal - "+to_string(i));
                assign_participants();
            }
        }
        else if (participants == 8) {
            for (int i=1; i<=4; i++) {
                matches.push_back("Quarterfinal - "+to_string(i));
                assign_participants();
            }
        }
        else {
            for (int i=1+battles; i<=benders_list.size()/2+battles; i++) {
                match = "Match - " + to_string(i);
                matches.push_back(match);
                assign_participants();
            }
        }
        cout << "\nCurrent Match Fixtures:\n";
        for (int i=0; i<matches.size(); i++) {
            cout << matches[i] << ": ";
            cout << match_participants[i][0].name << " vs ";
            cout << match_participants[i][1].name << endl;
        }
    }

    void assign_participants() {
        int index, participant1, participant2;
        index = Random(0, benders_numbers_list.size()-1);
        participant1 = benders_numbers_list[index];
        benders_numbers_list.erase(benders_numbers_list.begin() + index);
        index = Random(0, benders_numbers_list.size()-1);
        participant2 = benders_numbers_list[index];
        benders_numbers_list.erase(benders_numbers_list.begin() + index);
        match_participants.push_back({benders_list[participant1], benders_list[participant2]});
    }
};



void input(string &n, string &e, int &h, int &a, int &d, int &s) {
    int flag;
    cout << "Name:";
    cin >> ws;
    getline(cin, n);
    cout << "Element (Water, Fire, Earth or Air):";
    cin >> e;
    cout << "HP (integer in 1-200):";
    cin >> h;
    while (h < 1 || h > 200) {
        cout << "Enter the value in the given range:";
        cin >> h;
    }
    cout << "Attack (integer in 1-100):";
    cin >> a;
    while (a < 1 || a > 100) {
        cout << "Enter the value in the given range:";
        cin >> a;
    }
    cout << "Defense (integer in 1-100):";
    cin >> d;
    while (d < 1 || d > 100) {
        cout << "Enter the value in the given range:";
        cin >> d;
    }
    cout << "Speed (integer in 1-100):";
    cin >> s;
    while (s < 1 || s > 100) {
        cout << "Enter the value in the given range:";
        cin >> s;
    }

    for (int i=0; i<4; i++) {
        moves[i][2] = "";
    }
    int m;
    cout << "Moves:\n";
    for (int i=0; i<4; i++) {
        flag = 0;
        cout << "\nMove - " << i+1 << endl;
        cout << "Name:";
        cin >> ws;
        getline(cin, moves[i][0]);
        cout << "Power Level:";
        cin >> m;
        moves[i][1] = to_string(m);
        cout << "To enter a status effect(Burn, Freeze, Fly, Bury or Heal) to the move enter 1, else enter any other number.";
        cin >> flag;
        if (flag == 1) {
            cout << "Status Effect:";
            cin >> moves[i][2];
        }
    }
    cout << endl;
}

bool exponent_of_two(int num) {
    if (num < 2) return false;
    while (num >= 2 && num % 2 == 0) {
        num = num / 2;
    }
    if (num > 2) return false;
    return true;
}

void bender_input(int start, int num) {
    string name, element;
    int hp, attack, defense, speed;
    for (int i=start; i<num+start; i++) {
        cout << "\nBender-" << i << ":\n";
        input(name, element, hp, attack, defense, speed);
        benders.push_back(Bender(name, element, hp, attack, defense, speed, moves));
    }
}

int main() {

    int choice, bender_number;

    string moves1[4][3] = {{"Fire Punch", "30", ""}, {"Fire Wheel", "45", "Burn"}, {"Rage", "45", "Heal"}, {"Flame Blast", "60", ""}};
    string moves2[4][3] = {{"Tsunami", "75", ""}, {"Ice Dance", "15", "Freeze"}, {"Still Water", "55", "Heal"}, {"Whirlpool", "40", ""}};
    string moves3[4][3] = {{"Gust", "30", ""}, {"Breeze", "50", "Heal"}, {"High Wind", "40", "Fly"}, {"Tornado", "58", ""}};
    string moves4[4][3] = {{"Rockslide", "35", ""}, {"Quicksand Trap", "0", "Bury"}, {"Stone Fist", "25", ""}, {"Seismic Waves", "50", ""}};
    benders.push_back(Bender("Agni", "Fire", 100, 58, 38, 68, moves1));
    benders.push_back(Bender("Jal", "Water", 92, 50, 55, 60, moves2));
    benders.push_back(Bender("Vayu", "Air", 95, 60, 32, 95, moves3));
    benders.push_back(Bender("Prithvi", "Earth", 150, 48, 62, 50, moves4));

    cout << "Default Benders:\n\n";
    for (int i=0; i<4; i++) {
        cout << "Bender-" << i+1 << ":\n";
        benders[i].display_stats();
    }


    cout << "To use only the manually entered benders press 1.\n";
    cout << "To add benders manually to the the default benders press 2.\n";
    cout << "To use only the default benders press any other number.\n";
    cout << "Choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1: {
            benders.clear();
            cout << "Enter the number of benders(only exponent of 2, ex: 2, 4, 8, 16, ...) to enter:";
            cin >> bender_number;
            while (!exponent_of_two(bender_number)) {
                cout << "Invalid number! Enter again\n";
                cin >> bender_number;
            }
            cout << "\nEnter the Bender Stats: " << endl;
            bender_input(1, bender_number);
            break;
        }
        case 2: {
            cout << "Enter the number of benders(only (exponent of 2)-4, ex: 4, 12, 28 ...) to enter:";
            cin >> bender_number;
            while (bender_number > 0 && !exponent_of_two(bender_number+4)) {
                cout << "Invalid number! Enter again\n";
                cin >> bender_number;
            }
            cout << "\nEnter the Bender Stats: " << endl;
            bender_input(5, bender_number);
            break;
        }
    }

    cout << "\nFinal Benders:\n\n";
    for (int i=0; i<benders.size(); i++) {
        cout << "Bender-" << i+1 << ":\n";
        benders[i].display_stats();
    }

    string name, difficulty_input;
    cout << "Enter the Tournament Name:";
    cin >> ws;
    getline(cin, name);
    cout << "Enter the difficulty level:";
    cin >> difficulty_input;
    for (char &c : difficulty_input) {
        c = tolower(static_cast<unsigned char>(c));
    }
    Tournament tournament(name, difficulty_input);
}