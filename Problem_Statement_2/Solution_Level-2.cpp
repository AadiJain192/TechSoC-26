#include <cmath>
#include <iostream>
#include <string>
#include <random>

using namespace std;

int i, j;

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
        string moves[4][2];
        double type_multiplier = 1;


        Bender(string n, string e, int h, int a, int d, int s, string m[4][2]) {
            name = n;
            element = e;
            hp = h;
            max_hp = h;
            attack = a;
            defense = d;
            speed = s;
            for (i=0; i<4; i++) {
                moves[i][0] = m[i][0];
                moves[i][1] = m[i][1];
            }
        }

        bool is_fainted();
        void display_stats();
};



class Duel {
    public:
        double base_damage;
        int final_damage, critical_multiplier;
        int move, turns = 0, attacker, critical_hits = 0, effective_hits = 0;
        string  winner, loser;

        double element_type_multiplier(Bender b1, Bender b2) {
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
            else {
                if (b2.element == "Air") return 0.5;
                if (b2.element == "Water") return 2;
                return 1;
            }
        }


        Duel(Bender &b1, Bender &b2) {
            b1.type_multiplier = element_type_multiplier(b1, b2);
            b2.type_multiplier = element_type_multiplier(b2, b1);
            cout << "----  DUEL BEGINS!  ----\n";
            cout << b1.name << " (" << b1.element << ", HP: " << b1.hp << '/' << b1.max_hp << ')';
            cout << " VS ";
            cout << b2.name << " (" << b2.element << ", HP: " << b2.hp << '/' << b2.max_hp << ')';
            cout << "\n\n";
            while (b1.is_fainted() == false && b2.is_fainted() == false) turn(b1, b2);
            if (b1.is_fainted()) {
                winner = b2.name;
                loser = b1.name;
            }
            else {
                winner = b1.name;
                loser = b2.name;
            }
            cout << loser << " fainted!\n";
            cout << winner << " wins the Duel!\n\n";
            cout << "Duel Summary:\n";
            cout << "- Winner: " << winner << endl;
            cout << "- Turns: " << turns << endl;
            cout << "- Critical Hits: " << critical_hits << endl;
            cout << "- Super Effective Hits: " << effective_hits << endl;
        }

        void Attack_Bender(Bender &b1, Bender &b2) {

            int critical_rand = Random(1, 10);
            if (critical_rand == 1) {
                critical_multiplier = 2;
                critical_hits++;
                cout << "Critical Hit!\n";
            }
            else critical_multiplier = 1;

            if (b1.type_multiplier == 2) effective_hits++;

            int move_power = stoi(b1.moves[move][1]);
            base_damage = (static_cast<double>(b1.attack * move_power)) / static_cast<double>(b2.defense);
            final_damage = round(base_damage * b1.type_multiplier * critical_multiplier);
            b2.hp -= final_damage;
            if (b2.hp < 0) b2.hp = 0;
            cout << b2.name << " took " << final_damage << " damage!\n";
        }

        void turn(Bender &b1, Bender &b2) {
            turns++;

            move = Random(0, 3);

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
            if (attacker == 1) turn_display(b1, b2);
            else turn_display(b2, b1);
        }

        void turn_display(Bender &b1, Bender &b2) {
            cout << b1.name;
            if (turns % 2 == 1) cout << " goes first! (Speed: " << b1.speed << " vs " << b2.speed << ")\n";
            else cout << " strikes back!\n";
            cout << b1.name << " used " << b1.moves[move][0] << "!\n";
            if (b1.type_multiplier == 2) {
                cout << "Super Effective! (" << b1.element << " is strong against " << b2.element << ")\n";
            }
            else if (b1.type_multiplier == 0.5){
                cout << "Not very effective ... (" << b1.element << " is weak against " << b2.element << ")\n";
            }
            Attack_Bender(b1, b2);
            cout << b2.name << " HP: " << b2.hp << '/' << b2.max_hp << "\n\n";
        }
};



void Bender::display_stats() {
    cout << name << '(' << element << ") - ";
    cout << "HP: " << hp << '/' << max_hp << ", ";
    cout << "Attack: " << attack << ", ";
    cout << "Defense: " << defense << ", ";
    cout << "Speed: " << speed << "\n\n";
    cout << "Moves: ";
    cout << moves[0][0] << " (" << moves[0][1] << "), ";
    cout << moves[1][0] << " (" << moves[1][1] << "), ";
    cout << moves[2][0] << " (" << moves[2][1] << "), ";
    cout << moves[3][0] << " (" << moves[3][1] << ")\n" << endl;
}


bool Bender::is_fainted() {
    if (hp == 0) return true;
    return false;
}


string moves[4][2];
void input(string &n, string &e, int &h, int &a, int &d, int &s) {
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

    int m;
    cout << "Moves:\n";
    for (int i=0; i<4; i++) {
        cout << "\nMove - " << i+1 << endl;
        cout << "Name:";
        cin >> ws;
        getline(cin, moves[i][0]);
        cout << "Power Level:";
        cin >> m;
        moves[i][1] = to_string(m);
    }
}

int main() {
    string name, element;
    int hp, attack, defense, speed;
    int choice;

    cout << "Enter 1 to enter Benders manually and any other number for default Benders: ";
    cin >> choice;
    cout << endl;


    if (choice == 1) {
        cout << "Enter the Bender Stats: " << endl;

        cout << "\nBender-1:\n";
        input(name, element, hp, attack, defense, speed);
        Bender bender1(name, element, hp, attack, defense, speed, moves);

        cout << "\nBender-2:\n";
        input(name, element, hp, attack, defense, speed);
        Bender bender2(name, element, hp, attack, defense, speed, moves);

        cout << endl;
        cout << "Bender-1:\n";
        bender1.display_stats();
        cout << "Bender-2:\n";
        bender2.display_stats();
        Duel(bender1, bender2);
    }
    else {
        string moves1[4][2] = {{"Ember Slash", "40"}, {"Quick Jab", "30"}, {"Focus", "0"}, {"Flame Surge", "70"}};
        string moves2[4][2] = {{"Water Whip", "35"}, {"Tide Push", "25"}, {"Mist Veil", "0"}, {"Tidal Wave", "60"}};
        Bender bender1("Kael", "Fire", 100, 58, 38, 88, moves1);
        Bender bender2("Mira", "Water", 92, 50, 45, 60, moves2);

        cout << "Bender-1:\n";
        bender1.display_stats();
        cout << "Bender-2:\n";
        bender2.display_stats();
        Duel(bender1, bender2);
    }
}