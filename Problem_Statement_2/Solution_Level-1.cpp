#include <cmath>
#include <iostream>
#include <string>
#include <random>

using namespace std;

int i, j;


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

        void attackbender(Bender& b, int move);
        bool is_fainted();
        void display_stats();
};


void Bender::display_stats() {
    cout << name << '(' << element << ") - ";
    cout << "HP: " << hp << '/' << max_hp << ", ";
    cout << "Attack: " << attack << ", ";
    cout << "Defense: " << defense << ", ";
    cout << "Speed: " << speed << endl;
    cout << "Moves: ";
    cout << moves[0][0] << " (" << moves[0][1] << "), ";
    cout << moves[1][0] << " (" << moves[1][1] << "), ";
    cout << moves[2][0] << " (" << moves[2][1] << "), ";
    cout << moves[3][0] << " (" << moves[3][1] << ")\n" << endl;
}

void Bender::attackbender(Bender& b, int move) {
    int move_power = stoi(moves[move][1]);
    int damage = round((static_cast<double>(attack * move_power)) / static_cast<double>(b.defense));
    b.hp -= damage;
    if (b.hp < 0) b.hp = 0;
    cout << b.name << " took " << damage << " damage!\n" << endl;
}

bool Bender::is_fainted() {
    if (hp == 0) return true;
    else return false;
}


string moves[4][2];
void input(string &n, string &e, int &h, int &a, int &d, int &s) {
    cout << "Name:";
    cin >> n;
    cout << "Element (Water, Fire, Earth or Air):";
    cin >> e;
    cout << "HP (integer in 1-200):";
    cin >> h;
    cout << "Attack (integer in 1-100):";
    cin >> a;
    cout << "Defense (integer in 1-100):";
    cin >> d;
    cout << "Speed (integer in 1-100):";
    cin >> s;
    cout << "Moves:\n";
     for (i=0; i<4; i++) {
         cout << "\nMove - " << i+1 << endl;
         cout << "Name:";
         cin >> ws;
         getline(cin, moves[i][0]);
         cout << "Power Level:";
         cin >> moves[i][1];
     }
}

int main() {
    string name, element;
    int hp, attack, defense, speed;
    int move, attack_probability, probability, attacker=0;

    random_device rand;
    mt19937 generate_rand(rand());
    uniform_int_distribution<int> move_range(0, 3);
    uniform_int_distribution<int> probability_range(1, 100);

    cout << "Enter the Bender Stats: " << endl;

    cout << "\nBender-1:\n";
    input(name, element, hp, attack, defense, speed);
    Bender bender1(name, element, hp, attack, defense, speed, moves);

    cout << "\nBender-2:\n";
    input(name, element, hp, attack, defense, speed);
    Bender bender2(name, element, hp, attack, defense, speed, moves);

    move = move_range(generate_rand);
    cout << endl;
    bender1.display_stats();
    bender2.display_stats();

    probability = probability_range(generate_rand);
    if (bender1.speed > bender2.speed) {
        attack_probability = 50 + bender1.speed - bender2.speed;
        if (probability <= attack_probability) attacker = 1;
        else attacker = 2;
    }
    else{
        attack_probability = 50 + bender2.speed - bender1.speed;
        if (probability <= attack_probability) attacker = 2;
        else attacker = 1;
    }


    if (attacker == 1){
        cout << bender1.name << " used " << bender1.moves[move][0] << '!' << endl;
        bender1.attackbender(bender2, move);
        bender2.display_stats();
        cout << bender2.name << " fainted: " << boolalpha << bender2.is_fainted();
    }
    else {
        cout << bender2.name << " used " << bender2.moves[move][0] << '!' << endl;
        bender2.attackbender(bender1, move);
        bender1.display_stats();
        cout << bender1.name << " fainted: " << boolalpha << bender1.is_fainted();
    }

}