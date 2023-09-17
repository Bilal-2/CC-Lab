#include<iostream>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;



int main()
{
	fstream f1("comments.txt");
	string line;
	bool mc = false;
	while (getline(f1, line))
	{
		cout << line << endl;
		for (int i = 1; i < line.length(); i++)
		{
			if (line[i-1] == '/' && line[i] == '/')
			{
				cout << "Single Commented" << endl;
			}
		}

		for (int i = 1; i < line.length(); i++)
		{
			if (line[i - 1] == '/' && line[i] == '*')
			{
				mc = true;
			}
		}
		if (mc) {
			for (int i = 1; i < line.length(); i++)
			{
				if (line[i - 1] == '*' && line[i] == '/')
				{
					mc = false;
					cout << "Multi Commented" << endl;


				}
			}
		}
	}






	system("pause");
	return 0;
}