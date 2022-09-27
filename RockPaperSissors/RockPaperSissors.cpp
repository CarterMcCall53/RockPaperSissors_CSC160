/* Rock Paper Sissors
*  Carter McCall
*  8 September 2022
*  Purpose:
*		Create the rock paper sissors game
*  Modified 12 September 2022:
*		Add score keeping abilities
*  Modified 22 September 2022:
*		Add file read and write capabilities
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string repeat, input, fileName, userName, choices[] = { "Rock", "Paper", "Sissors" };
	char repChar, charChoice;
	int compChoice, userChoice,
		wins = 0, losses = 0, ties = 0;
	srand(time(0));
	cout << "What is your name? ";
	getline(cin, userName);
	fileName = userName + ".txt";
	ifstream infile;
	ofstream outfile;
	infile.open(fileName);
	if (infile) infile >> wins >> losses >> ties;
	do
	{
		compChoice = rand() % 3;
		cout << "\nYou have " << wins << " wins, " << losses << " losses, and "
			<< ties << " ties!" << endl;
		cout << "\nWhat would you like to play? (R|P|S): ";
		cin >> input;
		charChoice = tolower(input[0]);
		if (charChoice == 'r') userChoice = 0;
		else if (charChoice == 'p') userChoice = 1;
		else if (charChoice == 's') userChoice = 2;
		else
		{
			cout << "PLEASE CHOOSE A VALID PLAY";
			continue;
		}
		if (userChoice == compChoice)
		{
			cout << "You have tied the computer!" << endl;
			ties++;
		}
		else if (userChoice == 0 && compChoice == 2)
		{
			cout << "You Win!" << endl;
			wins++;
		}
		else if (userChoice == 1 && compChoice == 0)
		{
			cout << "You Win!" << endl;
			wins++;
		}
		else if (userChoice == 2 && compChoice == 1)
		{
			cout << "You Win!" << endl;
			wins++;
		}
		else
		{
			cout << "Computer Wins!" << endl;
			losses++;
		}
		cout << "You chose " << choices[userChoice] << " and the computer chose "
			<< choices[compChoice] << endl;
		do {
			cout << "Do you want to play again? (Y|N): ";
			cin >> input;
			repChar = tolower(input[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
	cout << "\nYou ended with " << wins << " wins, " << losses << " losses, and "
		<< ties << " ties!\n";
	infile.close();
	outfile.open(fileName);
	if (outfile) {
		outfile << wins << " " << losses << " " << ties;
	}
	outfile.close();
}