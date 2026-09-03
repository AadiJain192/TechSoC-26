#include <iostream>
#include <string>

using namespace std;

int rows, columns, generations;
int initial_population=0, peak_population=0, current_population=0;
int neighbours=0;
int i, j;
string line;

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
                            initial_population++;
                        }
                    }
                }

                peak_population = initial_population;
                for (int g=0; g<generations; g++){
                    current_population = 0;
                    for (i = 0; i < rows; i++) {
                        for (j = 0; j < columns; j++) {
                            neighbours = 0;

                            if (i == 0 && j == 0) {
                                if (grid_1[i][j+1] == '#') neighbours++;
                                if (grid_1[i+1][j] == '#') neighbours++;
                                if (grid_1[i+1][j+1] == '#') neighbours++;
                            }
                            else if (i == 0 && j != columns-1) {
                                if (grid_1[i][j-1] == '#') neighbours++;
                                if (grid_1[i][j+1] == '#') neighbours++;
                                if (grid_1[i+1][j-1] == '#') neighbours++;
                                if (grid_1[i+1][j] == '#') neighbours++;
                                if (grid_1[i+1][j+1] == '#') neighbours++;
                            }
                            else if (i == 0) {
                                if (grid_1[i][j-1] == '#') neighbours++;
                                if (grid_1[i+1][j-1] == '#') neighbours++;
                                if (grid_1[i+1][j] == '#') neighbours++;
                            }
                            else if (j == 0 && i != rows-1) {
                                if (grid_1[i-1][j] == '#') neighbours++;
                                if (grid_1[i-1][j+1] == '#') neighbours++;
                                if (grid_1[i][j+1] == '#') neighbours++;
                                if (grid_1[i+1][j+1] == '#') neighbours++;
                                if (grid_1[i+1][j] == '#') neighbours++;
                            }
                            else if (j == 0) {
                                if (grid_1[i-1][j] == '#') neighbours++;
                                if (grid_1[i-1][j+1] == '#') neighbours++;
                                if (grid_1[i][j+1] == '#') neighbours++;
                            }
                            else if (i == rows-1 && j != columns-1) {
                                if (grid_1[i][j-1] == '#') neighbours++;
                                if (grid_1[i-1][j-1] == '#') neighbours++;
                                if (grid_1[i-1][j] == '#') neighbours++;
                                if (grid_1[i-1][j+1] == '#') neighbours++;
                                if (grid_1[i][j+1] == '#') neighbours++;
                            }
                            else if (i == rows-1 && j == columns-1) {
                                if (grid_1[i][j-1] == '#') neighbours++;
                                if (grid_1[i-1][j-1] == '#') neighbours++;
                                if (grid_1[i-1][j] == '#') neighbours++;
                            }
                            else if (j == columns-1) {
                                if (grid_1[i-1][j-1] == '#') neighbours++;
                                if (grid_1[i-1][j] == '#') neighbours++;
                                if (grid_1[i][j-1] == '#') neighbours++;
                                if (grid_1[i+1][j-1] == '#') neighbours++;
                                if (grid_1[i+1][j] == '#') neighbours++;
                            }
                            else {
                                if (grid_1[i-1][j-1] == '#') neighbours++;
                                if (grid_1[i-1][j] == '#') neighbours++;
                                if (grid_1[i-1][j+1] == '#') neighbours++;
                                if (grid_1[i][j-1] == '#') neighbours++;
                                if (grid_1[i][j+1] == '#') neighbours++;
                                if (grid_1[i+1][j-1] == '#') neighbours++;
                                if (grid_1[i+1][j] == '#') neighbours++;
                                if (grid_1[i+1][j+1] == '#') neighbours++;
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

                cout << "Initial Population : " << initial_population << endl;
                cout << "Final Population : " << current_population << endl;
                cout << "Peak Population : " << peak_population << endl;
                cout << "Final Grid : " << endl;
                for (i=0; i<rows; i++) {
                    for (j=0; j<columns; j++) {
                        cout << grid_2[i][j];
                    }
                    cout << endl;
                }
            }
        }
    }
}