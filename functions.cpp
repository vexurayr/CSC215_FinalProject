// Additional source file for my function & class function definitions

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "functions.h"

using namespace std;

// Class member function definitions
Capital::Capital(int money) : // Constructor definition, parent class
	m_Money(money)
{}

inline int Capital::GetMoney() const
{
	return (m_Money);
}

Market::Market(int money, int income, int multiplier, int totalSpent) : // Child class of capital, inherits m_Money & GetMoney()
	Capital(money), // Calls base class constructor
	m_Income(income),
	m_Multiplier(multiplier),
	m_TotalSpent(totalSpent)
{}

inline int Market::GetIncome() const
{
	return (m_Income);
}

inline int Market::GetMultiplier() const
{
	return (m_Multiplier);
}

inline int Market::GetTotalSpent() const
{
	return (m_TotalSpent);
}

void Market::Transaction(int cost, int purchased, int multiplier)
{
	m_Money -= cost;
	m_Income += purchased;
	m_TotalSpent += cost;
	
	if (m_Money < 0)
	{
		cout << "You do not have the funds to purchase this.\n\n";
		m_Money += cost;
		m_Income -= purchased;
		m_TotalSpent -= cost;
	}
	else if (multiplier == 0)
	{
		cout << "You have purchased $" << purchased << " income for $" << cost << " dollars.\n\n";
	}
	else
	{
		cout << "You have purchased an increase to your multiplier for $" << cost << " dollars.\n\n";
		m_Multiplier += multiplier;
	}
}

// Regular function definitions
void coreGameplayLoop(const string& playerName, int& money, int& income, int& multiplier, int& totalSpent, int* const pDays)
{
	chrono::duration<int, milli> timespan(1200);
	int playerChoice;
	bool loop;
	Market playerBank(money, income, multiplier, totalSpent);

	cout << "What would you like to buy, " << playerName << "?\n";
	cout << "1 -> Add $1 to Income/ Cost = $2\n";
	cout << "2 -> Add $2 to Income/ Cost = $4\n";
	cout << "3 -> Add $5 to Income/ Cost = $15\n";
	cout << "4 -> Add $10 to Income/ Cost = $30\n";
	cout << "5 -> Add $50 to Income/ Cost = $150\n";
	cout << "6 -> Add $100 to Income/ Cost = $300\n";
	cout << "7 -> Add $500 to Income/ Cost = $1,500\n";
	cout << "8 -> Add $1,000 to Income/ Cost = $3,000\n";
	cout << "9 -> Increase multiplier/ Cost = $8,000\n";
	cout << "0 -> Wait\n\n";

	do
	{
		cout << "What will you do: ";
		cin >> playerChoice;
		cout << "\n";

		loop = true;
		switch (playerChoice)
		{
		case 1:
			playerBank.Transaction(2, 1, 0);
			break;
			// 1st # is cost/money spent, 2nd # is purchased/income increased, 3rd # is multiplier increase
		case 2:
			playerBank.Transaction(4, 2, 0);
			break;

		case 3:
			playerBank.Transaction(15, 5, 0);
			break;

		case 4:
			playerBank.Transaction(30, 10, 0);
			break;

		case 5:
			playerBank.Transaction(150, 50, 0);
			break;

		case 6:
			playerBank.Transaction(300, 100, 0);
			break;

		case 7:
			playerBank.Transaction(1500, 500, 0);
			break;

		case 8:
			playerBank.Transaction(3000, 1000, 0);
			break;

		case 9:
			playerBank.Transaction(8000, 0, 1);
			break;

		case 0: // The Wait choice
			cout << "You let your money build.\n\n";
			this_thread::sleep_for(timespan);
			*pDays = *pDays + 1; // Had *pDays++; before, but I have no clue why it wouldn't work
			loop = false;
			break;

		default:
			cout << "Just input 1-9. Don't make me repeat myself.\n\n";
			this_thread::sleep_for(timespan);
			cin.clear();
			cin.ignore(1);
		}

		if (loop)
		{
			cout << "Current Balance: $" << playerBank.GetMoney() << "\n";
			this_thread::sleep_for(timespan);

			cout << "Current Income: $" << playerBank.GetIncome() << "\n";
			this_thread::sleep_for(timespan);

			cout << "Multiplier: " << playerBank.GetMultiplier() << "\n\n";
			this_thread::sleep_for(timespan);
		}

	} while (loop);

	money = playerBank.GetMoney();
	income = playerBank.GetIncome();
	multiplier = playerBank.GetMultiplier();
	totalSpent = playerBank.GetTotalSpent();

	for (int i = 0; i < multiplier; i++) // If multiplier is 2, multiply income by 2, if it's 3, multiply income by 3...
	{
		money = money + income;
	}
}

bool quitOrPlayAgain()
{
	char playAgain;
	bool repeat;
	bool loop;
	chrono::duration<int, milli> timespan(1000);
	do
	{
		printf("Would you like to play again? y/n: ");
		cin >> playAgain;
		printf("\n");

		switch (playAgain)
		{
		case 'y':
		case 'Y':
			printf("Resetting the game...\n\n");
			repeat = true;
			loop = false;
			this_thread::sleep_for(timespan);
			break;

		case 'n':
		case 'N':
			printf("Goodbye! Thanks for playing.\n\n");
			repeat = false;
			loop = false;
			this_thread::sleep_for(timespan);
			break;

		default:
			printf("Please respond with y/n.\n\n");
			loop = true;
		}
	} while (loop);
	return repeat; // Function returns a value that is used in Main
}