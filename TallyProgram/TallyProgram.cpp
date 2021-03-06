// TallyProgram.cpp
// Solution to r/DailyProgrammer challenge #361 by Tony Delgado

#include <iostream>		//For input/output processing
#include <string>		//For string usage
#include <array>		//Needed for array.size()
using namespace std;

void calcScore(string input);	//Takes a valid input string, calculates each player's score, organizes players from highest score to lowest & displays them in order
bool inputValid(string input);	//Determines if an input string is valid
array<char,10> validSet { 'a', 'b', 'c', 'd', 'e', 'A', 'B', 'C', 'D', 'E' };	//Used in conjunction with inputValid to determine an input string's validity
																				//That is to say, if the string contains characters not in this set, it is invalid

int main()
{
	//Variables
	string sampleOne = "abcde";					//	Example
	string sampleTwo = "dbbaCEDbdAacCEAadcB";	//	strings
	string input;								//	Captures user input
	bool running = true;						//	Becomes false once user inputs STOP, exits program loop

	cout << "5 Friends (let's call them a, b, c, d and e) are playing a game and need to keep track of the scores." << endl << "Each time someone scores a point, type the letter of their name in lowercase." << endl << "If someone loses a point, type the letter of their name in uppercase." << endl << "This program will give the resulting score from highest to lowest." << endl << endl;
	cout << "Example: " << sampleOne << endl << endl;
	calcScore(sampleOne);
	cout << "Example 2: " << sampleTwo << endl << endl;
	calcScore(sampleTwo);
	cout << "Now you try!  Input any sequence of upper & lower case characters between a and e, or type STOP to exit:" << endl << "> ";
	while (running == true)
	{
		cin >> input;
		if (input.compare("STOP") == 0)		//Stops the progam once user inputs STOP
		{
			running = false;
			cout << "Acknowledged.  Halting program." << endl;
			system("pause");				//"Press any key to continue. . ."
		}
		else
		{
			if (inputValid(input))
			{
				calcScore(input);
				cout << "Play again?  Input a valid character sequence or type STOP to quit:" << endl << "> ";
			}
			else
				cout << "Invalid input!  Please ensure your input sequence only contains either case of a, b, c, d, or e." << endl << "Alternatively, type STOP to quit:" << endl << "> ";

		}
	}
	return 0;
}

void calcScore(string input)
{
	array<int, 5> players { 0, 0, 0, 0, 0 };		//Needed to use bracket array format for players.size()
	char playerName[] { 'a', 'b', 'c', 'd', 'e' };
	int tempScore;									//Holders for 
	char tempPlayer;								//sorting swaps
	for (int x = 0; x < input.length(); x++)
	{
		switch(input[x])
		{
			case 'a': players[0]++; break;
			case 'A': players[0]--; break;
			case 'b': players[1]++; break;
			case 'B': players[1]--; break;
			case 'c': players[2]++; break;
			case 'C': players[2]--; break;
			case 'd': players[3]++; break;
			case 'D': players[3]--; break;
			case 'e': players[4]++; break;
			case 'E': players[4]--; break;
		}	//Raises or lowers the score of each player depending on each read input character
	}
	for (int x = 0; x+1 < players.size(); x++)	//X+1 < players.size() instead of x < players.size() to prevent going out-of-bounds due to checking character after x
	{
		if (players[x] < players[x + 1])		//If the current position's score is less than the next, swap the two and start checking again from the beginning
		{
			tempScore = players[x];
			tempPlayer = playerName[x];
			players[x] = players[x + 1];
			playerName[x] = playerName[x + 1];
			players[x + 1] = tempScore;
			playerName[x + 1] = tempPlayer;
			x = -1;		//Restarts sorting from top of list if a change has been made
		}
	}
	for (int x = 0; x < players.size(); x++)
		cout << playerName[x] << ": " << players[x] << endl; //Prints each player's name & score from highest to lowest
	cout << endl;
}

bool inputValid(string input)
{
	bool good;	//Checks to see if each character is valid
	for (int x = 0; x < input.length(); x++)
	{
		good = false; //Starts false; if it matches no characters in the valid set, exit the function with a false value
		for (int y = 0; y < validSet.size(); y++)
		{
			if (good == false)
				if (input[x] == validSet[y])
					good = true;
		}
		if (good == false)
			return false;
	}
	return true;
}