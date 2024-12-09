#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Deposit.h"

using namespace std;

vector<Deposit> read_data(string file_name)
{
	vector<Deposit> result;
	string line;
	ifstream inFile(file_name);
	if (inFile)
	{
		while (getline(inFile, line))
		{
			Deposit currentDeposit;
			string currentLine;
			stringstream ss(line);
			int counter = 0;
			while (getline(ss, currentLine, ';'))
			{
				if (counter == 0) { currentDeposit.name = currentLine; }
				else if (counter == 1) { currentDeposit.summ = stoi(currentLine); }
				else if (counter == 2) { currentDeposit.currency = currentLine; }
				else if (counter == 3)
				{
					stringstream fl(currentLine);
					double p;
					fl >> p;
					currentDeposit.percent = p;
				}
				counter++;
			}
			result.push_back(currentDeposit);
		}
		return result;
	}
	else
	{
		return result;
	}
}