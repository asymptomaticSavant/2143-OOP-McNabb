//------------------------------------------------------------------------------------------------------------
//
//Katherine McNabb
//
//Course: OOP
//
//Purpose: War.
//
//------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <time.h>

#include "fighterSub.cpp"
#include "fighter.hpp"
#include "dice.cpp"
#include "LList.cpp"

using namespace std;

string wageWar(LList, LList, int);

int main()
{
	string fileName = "";       //temp. for various file name inputs
	string currentFighter = ""; //temp. for holding file inputs
	LList one; //attacker queue
	LList zero; //defender queue
	int counter = 0; //temp. tracker for incrementation

	srand(time(NULL)); //seed rand

	//open input file
	ifstream infile;
	infile.open("input.dat");

	//input file of choice
	//cout << "Input file: ";
	//cin >> fileName;
	//infile.open(fileName);

	if (!infile) //file could not be opened
	{
		cerr << "Error: file could not be opened.\n";
		system("pause");
		exit(10);
	}

	//open output file
	ofstream outfile;
	outfile.open("output.dat");

	//outfile of choice
	//cout << "Output File: ";
	//cin >> fileName;
	//outfile.open(fileName);

	if (!outfile) //file could not be opened
	{
		cerr << "Error: file could not be opened.\n";
		system("pause");
		exit(10);
	}

	//prints header to file
	outfile << "Katherine McNabb\n";
	outfile << "Program 3 - Greedy Algorithm\n\n";

	//prints header
	cout << "\n\nKatherine McNabb\n";
	cout << "Program 3 - Greedy Algorithm\n\n";

	//Read in the file
	while (!infile.eof())
	{

		//read in num from file; start time
		infile >> currentFighter;
		switch (currentFighter[0])
		{
		case 'f':
			one.enqueue(BaseFighter());
			break;
		case 'a':
			one.enqueue(archer());
			break;
		case 'e':
			one.enqueue(elf());
			break;
		case 'd':
			one.enqueue(dragonborn());
			break;
		case 'w':
			if (currentFighter[1] == 'i') {
				one.enqueue(wizard());
			}
			else {
				one.enqueue(paladin());
			}
			break;
		base:
			cout << "?????";
			break;
		}
		counter++;

	}
	for (int i = 0; i < (counter / 10); i++)
	{
		currentFighter = ((rand() % 10) == 0) ? "wi" : ((rand() % 10) == 1) ? "wa" : ((rand() % 10) == 2) ? "f" : ((rand() % 10) == 3) ? "d" : ((rand() % 4) == 0) ? "e" : "a";
		switch (currentFighter[0])
		{
		case 'f':
			one.enqueue(BaseFighter());
			break;
		case 'a':
			one.enqueue(archer());
			break;
		case 'e':
			one.enqueue(elf());
			break;
		case 'd':
			one.enqueue(dragonborn());
			break;
		case 'w':
			if (currentFighter[1] == 'i') {
				one.enqueue(wizard());
			}
			else {
				one.enqueue(paladin());
			}
			break;
		base:
			cout << "?????";
			break;
		}
	}

	//close files
	infile.close();
	outfile.close();

	//gross reuse of var haha
	//commented out because broken whoops
	//fileName = wageWar(one, zero, counter);

	cout << "\nThe " << fileName << " wins.";
	outfile << "\nThe " << fileName << " wins.";

	return 0;
}

//just meant to be pseudocode, really
//underlying LList struct is terribly suited; dont mind it
//it was stop gap anyway
string wageWar(LList one, LList zero, int counter) {
	string victor = "defenders";

	for (int i = 0; i < counter;) {
		int currHealth = zero->data.hp();
		int currHealth2 = one->data.hp();

		while (currHealth != 0 || currHealth2 != 0) {
			currHealth - one->data.use(); //fight
			currHealth2 - zero->data.use();
			
			for (int ii = 0; ii < (counter / 3); ii++) {
				one.next()->data.regen + one->data.hp; //regen
													   //pretend next actually moves the thing, ugh
			}
		}
	}
	return victor;
}