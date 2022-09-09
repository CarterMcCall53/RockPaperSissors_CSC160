/* Rock Paper Sissors
*  Carter McCall
*  8 September 2022
*  Purpose:
*		Create the rock paper sissors game
*/

#include <iostream>
using namespace std;

int main() {
	string repeat;
	string input;
	string choices[] = { "Rock", "Paper", "Sissors" };
	char repChar;
	char charChoice;
	int compChoice, userChoice;
	srand(int(time(0)));
	do
	{
		compChoice = rand() % 3;
		cout << "What would you like to play? (R|P|S): ";
		for (int i = 1; i > 0;) {
			cin >> input;
			charChoice = tolower(input[0]);
			if (charChoice == 'r') 
			{
				userChoice = 0;
				i -= 1;
			}
			else if (charChoice == 'p')
			{
				userChoice = 1;
				i -= 1;
			}
			else if (charChoice == 's')
			{
				userChoice = 2;
				i -= 1;
			}
			else cout << "PLEASE CHOOSE A VALID PLAY";
		}
		cout << "\n";
		if (userChoice == compChoice) cout << "You have tied the computer!" << endl;
		else if (userChoice == 0 && compChoice == 2) cout << "You Win!" << endl;
		else if (userChoice == 1 && compChoice == 0) cout << "You Win!" << endl;
		else if (userChoice == 2 && compChoice == 1) cout << "You Win!" << endl;
		else cout << "Computer Wins!" << endl;
		cout << "You chose " << choices[userChoice] << " and the computer chose "
			<< choices[compChoice] << endl;
		cout << "Do you want to play again? (Y|N): ";
		cin >> input;
		repChar = tolower(input[0]);
	} while (repChar == 'y');
}