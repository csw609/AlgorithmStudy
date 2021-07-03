#include <iostream>
using namespace std;
int main()
{
	char word[101];
	int check = 0;
	cin >> word;
	for (int i = 0; word[i] != NULL; i++) {
		//cout << word[i] << endl;
		check++;

		if (word[i] == 'c')
		{
			if (word[i + 1] == '=' || word[i + 1] == '-')
			{
				check--;
			}
		}

		if (word[i] == 'd')
		{
			if (word[i+1] == 'z')
			{
				if (word[i+2] == '=')
				{
					check --;
				}
			}
			if (word[i+1] == '-')
			{
				check--;
			}
		}
		if (word[i] == 'l')
		{
			if (word[i + 1] == 'j')
			{
				check--;
			}
		}
		if (word[i] == 'n')
		{
			if (word[i + 1] == 'j')
			{
				check--;
			}
		}
		if (word[i] == 's' || word[i] == 'z')
		{
			if (word[i + 1] == '=')
			{
				check--;
			}
		}
	}
	
	cout << check << endl;
}
