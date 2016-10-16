#include<iostream>
#include<string>
#include<vector>

using namespace std;

string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	int numCases;
	cin >> numCases;

	for (int i = 0; i < numCases; i++)
	{

		string kword = "";
		cin >> kword;

		string code = "";
		getline(cin, code);
		getline(cin, code);

		//remove duplicate letters
		for (string::iterator start = kword.begin(); start != kword.end(); start++)
		{
			for (string::iterator nstart = kword.begin(); nstart != kword.end(); nstart++)
			{
				if (*start == *nstart && nstart != start)
				{
					kword.erase(nstart);
					break;
				}
			}
		}

		string cipherLetters = "";

		vector< vector< char> > grid;

		vector<char> temp(kword.begin(), kword.end());

		grid.push_back(temp);
		int rowCount = 0;
		string push = "";
		for (int i = 0; i < 26; i++)
		{
			bool cont = false;
			for (auto a : kword)
			{
				if (a == letters[i])
					cont = true;
			}
			if (!cont)
			{
				if (push.size() == kword.size())
				{
					vector<char> toPush(push.begin(), push.end());
					push = letters[i];
					grid.push_back(toPush);
				}
				else {
					push.push_back(letters[i]);
				}
			}

		}

		if (push.length() > 0)
		{
			vector<char> toPush(push.begin(), push.end());
			while (toPush.size() < kword.length())
				toPush.push_back('!');
			grid.push_back(toPush);


		}

		vector<int> order;

		for (auto a : kword)
		{
			for (int i = 0; i < 26; i++)
			{
				if (a == letters[i])
				{
					order.push_back(i);
					break;
				}
			}
		}

		for (auto a : kword)
		{
			int currentMin = 27; int loc = -1;
			for (unsigned int i = 0; i < order.size(); i++)
			{
				if (order[i] < currentMin) {
					loc = i; currentMin = order[i];
				}
			}

			order[loc] = 28;

			for (unsigned int j = 0; j < grid.size(); j++)
			{
				if (grid[j][loc] != '!')
					cipherLetters.push_back(grid[j][loc]);
			}
		}

		string decode = "";
		for (auto a : code)
		{
			if (a != ' ')
			{
				for (int i = 0; i < 26; i++)
				{
					if (cipherLetters[i] == a)
					{
						decode.push_back(letters[i]);
						break;
					}
				}
			}
			else {
				decode.push_back(' ');
			}
		}

		cout << decode << endl;

	}
	

	return 0;
}