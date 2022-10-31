/* Rock Paper Sissors
*  Carter McCall
*  8 September 2022
*  Purpose:
*		Create the rock paper sissors game
*  Modified 12 September 2022:
*		Add score keeping abilities
*  Modified 22 September 2022:
*		Add file read and write capabilities
*  Modified 27 September 2022:
*		Add 2 player capabilities
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	int mode;
	do {
		cout << "1 Player or 2 Player mode? ";
		cin >> mode;
		if (mode == 1)
		{
			string repeat, input, fileName, userName, choices[] = { "Rock", "Paper", "Sissors" };
			char repChar, charChoice;
			int compChoice, userChoice,
				wins = 0, losses = 0, ties = 0;
			srand(time(0));
			cout << "What is your name? ";
			cin >> userName;
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
			break;
		}
		else if (mode == 2)
		{
			string repeat, input, fileName1, fileName2, userName1,
				userName2, choices[] = { "Rock", "Paper", "Sissors" };
			char repChar, charOneChoice, charTwoChoice;
			int pOneChoice, pTwoChoice, pOneWins = 0, pTwoWins = 0, pOneLosses = 0, pTwoLosses = 0,
				pOneTies = 0, pTwoTies = 0;
			cout << "What is player one's name? ";
			cin >> userName1;
			fileName1 = userName1 + ".txt";
			cout << "What is player two's name? ";
			cin >> userName2;
			fileName2 = userName2 + ".txt";
			ifstream infile;
			ofstream outfile;
			infile.open(fileName1);
			if (infile) infile >> pOneWins, pOneLosses, pOneTies;
			infile.close();
			infile.open(fileName2);
			if (infile) infile >> pTwoWins >> pTwoLosses >> pTwoTies;
			infile.close();
			do
			{
				cout << userName1 << " has " << pOneWins << " wins, " << pOneLosses << " losses, and "
					<< pOneTies << " ties!" << endl;
				cout << userName2 << " has " << pTwoWins << " wins, " << pTwoLosses << " losses, and "
					<< pTwoTies << " ties!" << endl;
				cout << "\nWhat would " << userName1 << " like to play? (R|P|S): ";
				cin >> input;
				charOneChoice = tolower(input[0]);
				if (charOneChoice == 'r') pOneChoice = 0;
				else if (charOneChoice == 'p') pOneChoice = 1;
				else if (charOneChoice == 's') pOneChoice = 2;
				else
				{
					cout << "PLEASE CHOOSE A VALID PLAY";
					continue;
				}
				system("CLS");	
				cout << "What would " << userName2 << " like to play? (R|P|S): ";
				cin >> input;
				charTwoChoice = tolower(input[0]);
				if (charTwoChoice == 'r') pTwoChoice = 0;
				else if (charTwoChoice == 'p') pTwoChoice = 1;
				else if (charTwoChoice == 's') pTwoChoice = 2;
				else
				{
					cout << "PLEASE CHOOSE A VALID PLAY";
					continue;
				}
				if (pOneChoice == pTwoChoice)
				{
					cout << "You have tied!" << endl;
					pOneTies++;
					pTwoTies++;
				}
				else if (pOneChoice == 0 && pTwoChoice == 2)
				{
					cout << userName1 << " Wins!" << endl;
					pOneWins++;
					pTwoLosses++;
				}
				else if (pOneChoice == 1 && pTwoChoice == 0)
				{
					cout << userName1 << " Wins!" << endl;
					pOneWins++;
					pTwoLosses++;
				}
				else if (pOneChoice == 2 && pTwoChoice == 1)
				{
					cout << userName1 << " Wins!" << endl;
					pOneWins++;
					pTwoLosses++;
				}
				else
				{
					cout << userName2 << " Wins!" << endl;
					pOneLosses++;
					pTwoWins++;
				}
				cout << userName1 << " chose " << choices[pOneChoice] << " and " << userName2 << " chose "
					<< choices[pTwoChoice] << endl;
				do {
					cout << "Do you want to play again? (Y|N): ";
					cin >> input;
					repChar = tolower(input[0]);
				} while (repChar != 'y' && repChar != 'n');
			} while (repChar == 'y');
			cout << "\n" << userName1 << " ended with " << pOneWins << " wins, " << pOneLosses << " losses, and "
				<< pOneTies << " ties!\n";
			cout << "\n" << userName2 << " ended with " << pTwoWins << " wins, " << pTwoLosses << " losses, and "
				<< pTwoTies << " ties!\n";
			outfile.open(fileName1);
			if (outfile) outfile << pOneWins << " " << pOneLosses << " " << pOneTies;
			outfile.close();
			outfile.open(fileName2);
			if (outfile) outfile << pTwoWins << " " << pTwoLosses << " " << pTwoTies;
			outfile.close();
			break;
		}
		else cout << "Please choose a valid mode!\n";
	} while (mode != 1 || mode != 2);
}