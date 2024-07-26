#include <iostream>
using namespace std;

struct stGameStats
{
	short RoundNum = 0, Win = 0, Loss = 0, Draw = 0;
};

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

int ReadRoundNumber()
{
	int Number = 0;
	cout << "Please enter round number:\n";
	cin >> Number;

	return Number;
}

short ReadChoice()
{
	short Choice = 0;
	cout << "Your choice: [1]: Rock, [2]: Paper, [3]: Scissors:  ";
	cin >> Choice;

	return Choice;
}

short ReadComputerChoice()
{
	short ComputerChoice;
	ComputerChoice = RandomNumber(1, 3);

	return ComputerChoice;
}

string ReturnChoice(int Choice)
{
	switch (Choice)
	{
	case 1: return "Rock";
	case 2: return "Paper";
	case 3: return "Scissors";
	}
}

stGameStats PrintWinner(int Choice, int ComputerChoice)
{
	stGameStats Stats;
	Stats.RoundNum += 1;

	if (Choice == ComputerChoice)
	{
		Stats.Draw += 1;
		system("color 6F");
		cout << "[No Winner]\n";
	}
	else
	{
		switch (Choice)
		{
		case 1: if (ComputerChoice < 3)
		{
			Stats.Loss += 1;
			system("color 4F");
			cout << "[ Computer ]\n";
		}
			  else
		{
			Stats.Win += 1;
			system("color 2F");
			cout << "[ Player ]\n";
		}
			  break;
		case 2: if (ComputerChoice < 2)
		{
			Stats.Win += 1;
			system("color 2F");
			cout << "[ Player ]\n";
		}
			  else
		{
			Stats.Loss += 1;
			system("color 4F");
			cout << "[ Computer ]\n";
		}
			  break;
		case 3: if (ComputerChoice < 2)
		{
			Stats.Loss += 1;
			system("color 4F");
			cout << "[ Computer ]\n";
		}
			  else
		{
			Stats.Win += 1;
			system("color 2F");
			cout << "[ Player ]\n";
		}
			  break;
		}
	}

	return Stats;

}

stGameStats PrintRoundResults(int Counter, stGameStats Stats)
{
	cout << "\n";
	short Choice = ReadChoice();
	cout << "\n";
	short ComputerChoice = ReadComputerChoice();
	cout << "-------------------Round [" << Counter << "]-------------------\n\n";
	cout << "Player choice: " << ReturnChoice(Choice) << "\n";
	cout << "Computer choice: " << ReturnChoice(ComputerChoice) << "\n";
	cout << "Round Winner: ";
	Stats = PrintWinner(Choice, ComputerChoice);
	cout << "\n-------------------------------------------------\n";

	return Stats;
}

stGameStats BeginRound(int RoundNumber)
{
	int Counter = 0;
	stGameStats Stats, AllStats;

	do
	{
		Counter++;
		cout << "\nRound " << Counter << " begins: \n";
		Stats = PrintRoundResults(Counter, Stats);
		AllStats.Win += Stats.Win;
		AllStats.Draw += Stats.Draw;
		AllStats.Loss += Stats.Loss;
		AllStats.RoundNum = Counter;

	} while (Counter < RoundNumber);

	return AllStats;
}

void PrintGameOver()
{
	cout << "\n\t\t----------------------------------------------------------\n";
	cout << "\t\t                     *** Game Over ***                         \n";
	cout << "\t\t----------------------------------------------------------\n\n";
}

string PrintGameWinner(stGameStats Stats)
{
	if (Stats.Loss == Stats.Win)
		return "[ Draw ]";
	else if (Stats.Win > Stats.Loss)
		return "[ Player ]";
	else
		return "[ Computer ]";
}

void PrintGameResults(stGameStats AllStats)
{
	PrintGameOver();

	cout << "\t\t----------------------[Game Results]----------------------\n";
	cout << "\t\tGame Rounds : " << AllStats.RoundNum << "\n";
	cout << "\t\tPlayer wins : " << AllStats.Win << "\n";
	cout << "\t\tComputer wins : " << AllStats.Loss << "\n";
	cout << "\t\tDraw Times : " << AllStats.Draw << "\n";
	cout << "\t\tGame Winner : " << PrintGameWinner(AllStats) << "\n";
	cout << "\t\t----------------------------------------------------------\n\n\n";
}

bool AskForReplay()
{
	bool Ask;
	cout << "\t\tDo you want to play again?: [Yes] : 1, [No] : 0  ";
	cin >> Ask;

	return Ask;
}

void ResetWindow()
{
	system("color 0F");
	system("cls");
}

void RestartGame()
{
	while (AskForReplay())
	{
		ResetWindow();
		PrintGameResults(BeginRound(ReadRoundNumber()));
	}
}

void StartGame()
{
	PrintGameResults(BeginRound(ReadRoundNumber()));
	RestartGame();
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}