#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int rows=0, columns=0, generations;
int initial_population=0, peak_population=0, current_population=0;
int neighbours=0, neighbour_row, neighbour_column;
int i, j, g, dr, dc;
int f1=0, f2=0, f3=0;
string line;
vector<string> grid;

void classify(int steps) {
    char grid_1[rows][columns], grid_2[rows][columns];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            grid_1[i][j] = grid[i][j];
            grid_2[i][j] = grid[i][j];
        }
    }

    for (g = 0; g < steps; g++) {
        f1=0, f2=0, f3=0;
        current_population = 0;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                neighbours = 0;

                for (dr = -1; dr <= 1; dr++) {
                    for (dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0) continue;
                        neighbour_row = (i + dr + rows) % rows;
                        neighbour_column = (j + dc + columns) % columns;
                        if (grid_1[neighbour_row][neighbour_column] == '#') neighbours++;
                    }
                }

                if (grid_1[i][j] == '#') {
                    if (neighbours < 2 || neighbours > 3) grid_2[i][j] = '.';
                }
                else if (neighbours == 3) grid_2[i][j] = '#';
            }
        }

        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                if (grid_2[i][j] != '.') {
                    f1=1;
                }
                if (grid_2[i][j] != grid_1[i][j]) {
                    f2=1;
                }
                if (grid_2[i][j] != grid[i][j]) {
                    f3=1;
                }
            }
        }

        for (i=0; i<rows; i++) {
            for (j=0; j<columns; j++) {
                grid_1[i][j] = grid_2[i][j];
                if (grid_2[i][j] == '#') {
                    current_population++;
                }
            }
        }

        if (f1 == 0) {
            if (f2 != 0) g++;
            cout << "Classification : Extinct" << endl;
            cout << "Extinction Step : " << g << endl;
            cout << "Final Population : 0" << endl;
            return;
        }
        if (f2 == 0) {
            cout << "Classification : Still Life" << endl;
            cout << "Stable at Step : " << g << endl;
            cout << "Period : 1" << endl;
            cout << "Final Population : " << current_population << endl;
            return;
        }
        if (f3 == 0) {
            g++;
            cout << "Classification : Oscillator" << endl;
            cout << "Period : " << g << endl;
            cout << "First Repeat Step : " << g << endl;
            cout << "Population : " << current_population << endl;
            return;
        }
    }
    cout << "Classification : Active" << endl;
    cout << "Reason : No repeat or extinction detected within K = " << steps << " steps" << endl;
    cout << "Final Population : " << current_population << endl;
}
void com() {
    int n=0;
    int r_min=rows-1, r_max=0, r_total=0;
    int c_min=columns-1, c_max=0, c_total=0;
    double r_com=0, c_com=0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (grid[i][j] == '#') {
                n++;
                r_total += i;
                c_total += j;
                if (r_min > i) r_min = i;
                if (r_max < i) r_max = i;
                if (c_min > j) c_min = j;
                if (c_max < j) c_max = j;
            }
        }
    }
    r_com = double(r_total) / double(n) ;
    c_com = double(c_total) / double(n) ;
    r_com = round(r_com*100.0) / 100.0;
    c_com = round(c_com*100.0) / 100.0;
    cout << "Live Cells : " << n << endl;
    if (n == 0) {
        cout << "Bounding Box : 0 x 0" << endl;
        cout << "Center of Mass : N/A" << endl;
    }
    else {
        cout << "Bounding Box : " << r_max - r_min +1 << " x " << c_max - c_min +1 << endl;
        cout << "Center of Mass : (" << r_com << ", " << c_com << ")" << endl;
    }
}

int main() {
    cout << "Enter the number of rows in the grid : " << endl;
    cin >> rows;
    if (rows < 1) {
        cout << "Not enough rows in the grid!" << endl;
    }
    else if (rows > 100) {
        cout << "Too much rows to handle!" << endl;
    }
    else {
        cout << "Enter the number of columns in the grid : " << endl;
        cin >> columns;
        if (columns < 1) {
            cout << "Not enough columns in the grid!" << endl;
        }
        else if (columns > 100) {
            cout << "Too much columns to handle!" << endl;
        }
        else {
            cout << "Enter the number of generations to simulate : " << endl;
            cin >> generations;
            if (generations < 0) {
                cout << "Enter a valid number of generations!" << endl;
            }
            else if (generations > 1000) {
                cout << "Too much generations to handle!" << endl;
            }
            else {
                char grid_1[rows][columns], grid_2[rows][columns];
                cout << "Enter the grid pattern (# for Alive and . for Dead): " << endl;

                for (i = 0; i < rows; i++) {
                    cin >> line;
                    grid.push_back(line);
                    for (j = 0; j < columns; j++) {
                        grid_1[i][j] = grid[i][j];
                        grid_2[i][j] = grid[i][j];
                        if (grid[i][j] != '#' && grid[i][j] != '.') {
                            cout << "Enter either . or # !" << endl;
                            cout << "Exiting because of invalid input!" << endl;
                            exit(0);
                        }
                        if (grid[i][j] == '#') {
                            initial_population++;
                        }
                    }
                }

                peak_population = initial_population;
                for (g=0; g<generations; g++){
                    current_population = 0;
                    for (i = 0; i < rows; i++) {
                        for (j = 0; j < columns; j++) {
                            neighbours = 0;

                            for (dr = -1; dr <= 1; dr++) {
                                for (dc = -1; dc <= 1; dc++) {
                                    if (dr == 0 && dc == 0) continue;
                                    neighbour_row = (i + dr + rows) % rows;
                                    neighbour_column = (j + dc + columns) % columns;
                                    if (grid_1[neighbour_row][neighbour_column] == '#') neighbours++;
                                }
                            }


                            if (grid_1[i][j] == '#') {
                                if (neighbours < 2 || neighbours > 3) grid_2[i][j] = '.';
                            }
                            else if (neighbours == 3) grid_2[i][j] = '#';
                        }
                    }

                    for (i=0; i<rows; i++) {
                        for (j=0; j<columns; j++) {
                            grid_1[i][j] = grid_2[i][j];
                            if (grid_1[i][j] == '#') {
                                current_population++;
                            }
                        }
                    }
                    if (current_population > peak_population) peak_population = current_population;
                }
                if (generations == 0) current_population = initial_population;

                cout << "\nInitial Population : " << initial_population << endl;
                cout << "Final Population : " << current_population << endl;
                cout << "Peak Population : " << peak_population << endl;
                cout << "Final Grid : " << endl;
                for (i=0; i<rows; i++) {
                    for (j=0; j<columns; j++) {
                        cout << grid_2[i][j];
                    }
                    cout << endl;
                }

                cout << "\nEnter the given number to perform the following functions : " << endl;
                cout << "1) Classify the pattern automatically." << endl;
                cout << "2) Classify the pattern manually." << endl;
                cout << "3) Find center of mass of the pattern." << endl;
                cout << "Anything else to exit the program." << endl;

                int choice=0, n=10;
                cin >> choice;
                switch (choice) {
                    case 1: {
                        classify(n);
                        break;
                    }
                    case 2: {
                        cout << "Enter the step count : " << endl;
                        cin >> n;
                        classify(n);
                        break;
                    }
                    case 3: {
                        com();
                        break;
                    }
                    default: {
                        cout << "Invalid Choice!";
                        break;
                    }
                }
            }
        }
    }
}