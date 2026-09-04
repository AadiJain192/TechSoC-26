//Compile the code and run the executable file formed.

#include <iostream>
#include <string>
#include <bits/this_thread_sleep.h>

using namespace std;

int rows, columns, generations;
int population=0;
int neighbours=0, neighbour_row, neighbour_column;
int i, j, g, dr, dc;
int delay=0;
string line;

void clearscreen() {
    system("cls");
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
                char grid[rows][columns], grid_1[rows][columns], grid_2[rows][columns];
                cout << "Enter the grid pattern (# for Alive and . for Dead): " << endl;

                for (i = 0; i < rows; i++) {
                    cin >> line;
                    for (j = 0; j < columns; j++) {
                        grid[i][j] = line.at(j);
                        grid_1[i][j] = grid[i][j];
                        grid_2[i][j] = grid[i][j];
                        if (grid[i][j] != '#' && grid[i][j] != '.') {
                            cout << "Enter either . or # !" << endl;
                            cout << "Exiting because of invalid input!" << endl;
                            exit(0);
                        }
                        if (grid[i][j] == '#') {
                            population++;
                        }
                    }
                }

                cout << "Enter the delay in seconds : " << endl;
                cin >> delay;

                clearscreen();
                cout << "Generation : " << 0 << "   Population : " << population << endl;
                for (i=0; i<rows; i++) {
                    for (j=0; j<columns; j++) {
                        cout << grid_2[i][j];
                    }
                    cout << endl;
                }

                for (g = 0; g < generations; g++){

                    this_thread::sleep_for(chrono::seconds(delay));
                    clearscreen();
                    
                    population = 0;
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
                            if (grid_2[i][j] == '#') {
                                population++;
                            }
                        }
                    }

                    cout << "Generation : " << g+1 << "   Population : " << population << endl;
                    for (i=0; i<rows; i++) {
                        for (j=0; j<columns; j++) {
                            cout << grid_2[i][j];
                        }
                        cout << endl;
                    }
                }
                cout << "Simulation Complete!";
                this_thread::sleep_for(chrono::seconds(10));
            }
        }
    }
}
