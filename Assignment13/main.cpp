/* Assignment 13 programmed by Ethan Laur
 * This program will read a list of horses (no max for entries)
 * from a file and pick 4 to race. the program will then wait 3
 * seconds, while counting down in 1 second intervals and start the race
 * the race will display on the screen until one horse crosses the finish
 * line, at which the line will remove itself from the screen.
 * EXTRA CREDIT FEATURES:
 * 1.) Finish line
 * 2.) Beautiful display of horse finishes */
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
using namespace std;
/*definition of horse structure*/
struct Horse
{
	string name;
	int quarter[4];
	unsigned int odds, position;
};
void moveHorses(Horse[]); //horse move function
void rdm(Horse horse[], int size)  // randomizes the horses to be in the correct order
{
    Horse temp;
    int randm[2];
    for (int i=0; i<100; i++)
    {
        randm[1] = rand() % size;
        randm[0] = rand() % size;
        temp = horse[randm[0]];
        horse[randm[0]] = horse[randm[1]];
        horse[randm[1]] = temp;
    }
}
int main(int argc,char**argv)
{
	srand(time(NULL));
	char fname[30] = "/Users/phyrrus9/horses"; //name of input file
	cout << "What is the name of the input file? ";
	cin >> fname;
	Horse horses[20];
	int i = 0;
	ifstream file(fname);
    //	cout << fname << endl;
    if (!file){
        cout << "ERROR: FILE COULD NOT BE READ" << endl;exit(-1);} //close if bad file
	while (!file.eof())
	{
		file >> horses[i].name;//read in the 
		file >> horses[i].quarter[0]>> horses[i].quarter[1] >> horses[i].quarter[2] >> horses[i].quarter[3];// = atoi(file->fget().c_str());
		int odd = (horses[i].quarter[0] + horses[i].quarter[1] + horses[i].quarter[2] + horses[i].quarter[3]) - 7;
		horses[i].odds = odd; //set the odds
		horses[i].position = 0;
		i++;
	}
	file.close();
	rdm(horses,i); //mix up the horses
	cout << endl << setw(2) << "NO" << setw(15) << "Horse" << setw(7) << "Odds" << setw(3) << "q1" << setw(3) << "q2" << setw(3) << "q3" << setw(3) << "q4" << endl;
	for (int a=0; a < 4; a++)
        cout << setw(2) << a+1 << setw(15) << horses[a].name << setw(7) << horses[a].odds << "-to-1" << setw(3) << horses[a].quarter[0] << setw(3) << horses[a].quarter[1] << setw(3) << horses[a].quarter[2] << setw(3) << horses[a].quarter[3] << endl;
    cout << "Please enter a character and press enter to start the race ";
    cin >> ws;
    bool done = false;
    int currQuarter = 0;
    int leader =0;
    do                      // main loop to move horses.
    {
        leader = 0;
        moveHorses(horses);
        for (int i=0;i<4; i++)
        {
            int move =1;
            int num = 1 + rand() % 10;
            if (horses[i].quarter[currQuarter] >= num)
                move++;
            horses[i].position += move;
            if (horses[i].position > leader)
                leader = horses[i].position;
            currQuarter = leader / 10;
            if (leader >= 40)
            {
                done = true;
                break;
            }
        }
        //moveHorses(horses);      // displays the horses in their updated positions.
        sleep(1);
    } while (!done);
    moveHorses(horses);
    for (int k=0; k<4; k++)
    {
        if (horses[k].position >= 40)            //shows the winning horse.
        {
            cout << "The Winner is horse #" << k+1 << " (" << horses[k].name << ")" << endl;
            return EXIT_SUCCESS;
        }
    }
}
void moveHorses(Horse horse[]) // prints the current position of the horses through the race
{
    system("clear");
    cout << "NO Horse              Odds  q1 q2 q3 q4 |         |         |         |          | " << 
    endl;
    for(int i=0; i<4; i++)
    {
        cout    << setw(2)  << right << i+1 << " "
        << setw(12) << left << horse[i].name  << " "
        << setw(6)  << right<< horse[i].odds       << "-to-1" << " "
        << setw(2)  << right<< horse[i].quarter[0] << " "
        << setw(2)  << right<< horse[i].quarter[1] << " "
        << setw(2)  << right<< horse[i].quarter[2] << " "
        << setw(2)  << right<< horse[i].quarter[3] << " " << ":";
        for (int k=0; k<41; k++)
        {
            if (k == horse[i].position)
                cout << i+1;
            else
                cout << " ";
            if (k == 39)
            {
                bool cross = false;
                for (int count = 0; count < 4; count++)
                    if (horse[count].position > 39)
                        cross = true;
                if (!cross)
                    cout << "|";
            }
        }
        cout << endl;
    }
}
