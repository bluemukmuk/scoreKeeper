/* To run, g++ scoreKeeper.cpp -o score
 * ./score
 *
 *
 */
#include <iostream>
#include <istream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
int main() {
    //Define all the Teams to be the rows and Cabins are the columns
    string Team[5][5];
    string Cabin[5][5];
    int CabinPoints[5];
    int number = 0;

    for (int r=1; r<5; r++){
        CabinPoints[r] = 0;
    }

    //SETUP Reading in the file
    ifstream myfile("teamlist.txt");
    char x;
    if (myfile.is_open()) {
        string line;
        while (!myfile.eof()){
            string name;
            string team_cabin;

            getline(myfile,line);
            if (line.empty()) {
                continue;
            }

            stringstream ss(line);

            ss >> team_cabin >> number;
            //Print Team Names
            cout << team_cabin << number << " has ";
            if (team_cabin == "Team") {
                for(int k=0; k<4;k++) {
                    ss >> name;
                    Team[number][k] = name;
                }
                for (int j=0; j<4; j++) {
                    cout << Team[number][j] << " ";
                }
                cout << endl;
            } else {
                for(int k=0; k<4;k++) {
                    ss >> name;
                    Cabin[number][k] = name;
                }
                for (int j=0; j<4; j++) {
                    cout << Cabin[number][j] << " ";
                }
                cout << endl;
            }
        }

    }
    // DONE SETUP READING IN FILE


    //POINT SYSTEM
    //ENTER NEW SCORE
    int team = 0;
    int rank = 0;
    int multiplier = 1;
    string personWhoGetsPoints;
    int addScore = 0;


    cout << "Type in multiplier: ";
    cin >> multiplier;

    for (int r=0; r<4; r++){

        cout << "Please type in the following separated by spaces: | team | rank | " << endl;
        cout << "                                                  | 1-4  | 1-4  | " << endl;
        while () {
            cin >> team >> rank;
        }
        // Do some checks for possible input

        addScore = (5-rank)*multiplier;

        cout << "Multiplier was " << multiplier << endl;
        cout << "Team was " << team << endl;
        cout << "Rank was " << rank << endl;
        cout << "AddScore is " << addScore << endl;


        for (int i=1; i<5; i++) {
            personWhoGetsPoints = Team[team][i];
            for (int j=1; j<5; j++) {
                for (int k=1; k<5; k++) {
                    if (Cabin[j][k] == personWhoGetsPoints) {
                        CabinPoints[j] += addScore;
                        continue;
                    }
                }
            }
        }
    }


    for (int r=1; r<5; r++){
        cout << "Cabin " << r << " has " << CabinPoints[r] << endl;
    }


    // ADD NEW SCORE





    // MAKE A PURCHASE






    // PRINT CURRENT SCORES PER CABIN

    return 0;
}
