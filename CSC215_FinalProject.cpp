// Putting together everything we've learned this semester into a game about growing your money to a million dollars

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "functions.h" // Inserts the contents of the file here

using namespace std;

int main()
{
	chrono::duration<int, milli> timespan(1200);

	bool repeat;
	int fewestDays = 0; // Need this outside the main game loop so that it is not reset on play again
	string playerName; // Used to store the player's name and greet them by it

	cout << "What's your name, stranger: ";
	cin >> playerName; // Program accepts user input
	cout << endl;

	cout << "Howdy, " << playerName << ".\n";
	this_thread::sleep_for(timespan);
	this_thread::sleep_for(timespan);
	cout << "This game is all about earning money by spending money.\n"; // Describes the program to the player and prints text to display
	this_thread::sleep_for(timespan);
	this_thread::sleep_for(timespan);
	cout << "Buying income will earn you more money, which you can use to boost your income further.\n";
	this_thread::sleep_for(timespan);
	this_thread::sleep_for(timespan);
	cout << "You can buy up multiple things in one day.\n";
	this_thread::sleep_for(timespan);
	this_thread::sleep_for(timespan);
	cout << "Wait until the next day and your income will be added to your cash.\n";
	this_thread::sleep_for(timespan);
	this_thread::sleep_for(timespan);
	cout << "How many days will it take you to reach one million dollars?\n\n";
	this_thread::sleep_for(timespan);
	this_thread::sleep_for(timespan);

	do // Main game loop starts here
	{
		int days = 1; // Simple data type variables
		int money = 1; // I really wanted to start in cents, why must floats have these decimal problems
		int income = 1;
		int multiplier = 1;
		int totalSpent = 0;

		do // Program uses many do while loops and one for loop
		{
			cout << "Day: " << days << "\n";
			this_thread::sleep_for(timespan);

			cout << "Current Balance: $" << money << "\n";
			this_thread::sleep_for(timespan);

			cout << "Current Income: $" << income << "\n";
			this_thread::sleep_for(timespan);

			cout << "Multiplier: " << multiplier << "\n\n";
			this_thread::sleep_for(timespan);

			coreGameplayLoop(playerName, money, income, multiplier, totalSpent, &days); // Function takes 6 parameters

		} while (money < 1000000);

		cout << "Congratulations, " << playerName << "! You've gone from broke to being a millionare.\n\n";
		this_thread::sleep_for(timespan);
		this_thread::sleep_for(timespan);
		cout << "Final Balance: $" << money << "\n";
		this_thread::sleep_for(timespan);
		this_thread::sleep_for(timespan);
		cout << "Final Income: $" << income << "\n";
		this_thread::sleep_for(timespan);
		this_thread::sleep_for(timespan);
		cout << "Final Multiplier: " << multiplier << "\n";
		this_thread::sleep_for(timespan);
		this_thread::sleep_for(timespan);
		cout << "Total Spent: $" << totalSpent << "\n";
		this_thread::sleep_for(timespan);
		this_thread::sleep_for(timespan);
		cout << "Days Passed: " << days << "\n\n";
		this_thread::sleep_for(timespan);
		this_thread::sleep_for(timespan);

		repeat = quitOrPlayAgain();

		if (repeat)
		{
			if (fewestDays == 0) // First time through always puts the day you ended on as your fastest run
			{
				fewestDays = days;
			}
			else if (fewestDays > days) // Subsequent runs only update fewest days if your run was faster
			{
				fewestDays = days;
			}
			cout << "Fastest you've reached one million: " << fewestDays << " days\n\n";
			this_thread::sleep_for(timespan);
			this_thread::sleep_for(timespan);
		}

	} while (repeat);

	return 0;
}