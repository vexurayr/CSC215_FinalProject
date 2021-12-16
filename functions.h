#pragma once
// Header file for my function & class prototypes

// Threw in a pointer here because I don't know what else to use them for besides a less efficient reference
void coreGameplayLoop(const std::string& playerName, int& money, int& income, int& multiplier, int& totalSpent, int* const pDays); // References and pointer passed in here
bool quitOrPlayAgain();

// Class definition
class Capital // Parent class
{
public:
	Capital(int money = 1); // Constructor prototype
	int GetMoney() const; // Member function prototype

protected: // I need protected rather than private so that my child class can access it
	int m_Money; // Data member
};

class Market : public Capital // Child class of Capital, builds on the data member money by adding ways to spend it
{
public:
	Market(int money = 1, int income = 1, int multiplier = 1, int totalSpent = 0);
	int GetIncome() const;
	int GetMultiplier() const;
	int GetTotalSpent() const;
	void Transaction(int cost = 0, int purchased = 0, int multiplier = 0);

private:
	int m_Income;
	int m_Multiplier;
	int m_TotalSpent;
};