#include<iostream>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;



int main()
{
	fstream f1("il.txt");
	string line;
	bool dig = false;
	string il ;
	while (getline(f1, line))
	{


		for (int i = 0; i < line.length(); i++)
		{
			if (isdigit(line[i]))
			{

				il = il + line[i];
				dig = true;
			}
		}
		if (dig)
		{


			cout << "<IL, " << il << " >" << endl;
			il = "";
			dig = false;
		}

		
	}
	






	system("pause");
	return 0;
}