// TallyProgram.cpp
// Solution to r/DailyProgrammer challenge #361 by Tony Delgado

#include <iostream>
#include <string>
#include <array>
using namespace std;

void calcScore(string input);

int main()
{
	//Variables
	string sampleOne = "abcde";

	cout << "5 Friends (let's call them a, b, c, d and e) are playing a game and need to keep track of the scores." << endl << "Each time someone scores a point, type the letter of their name in lowercase." << endl << "If someone loses a point, type the letter of their name in uppercase." << endl << "This program will give the resulting score from highest to lowest." << endl << endl;
	cout << "Example: " << sampleOne << endl << endl;
	calcScore(sampleOne);
	system("pause");
	return 0;
}

void calcScore(string input)
{
	//int players[] { 0, 0, 0, 0, 0 };
	array<int, 5> players { 0, 0, 0, 0, 0 };
	char playerName[] { 'a', 'b', 'c', 'd', 'e' };
	int arraySize = 5; //array.size() wouldn't work.  Need to use
	int temp;
	char tempChar;
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
		}
	}
	for(int x = 0; x < players.size(); )
	if (players[0] < players[1])
		temp = players[0];
		players[0] = players[1];
		players[1] = temp;
	//cout << players[0] << players[1] << players[2] << players[3] << players[4];
}