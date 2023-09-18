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
	string comment;
	while (getline(f1, line))
	{
		/*cout << line << endl;*/
		

		for (int i = 1; i < line.length(); i++)
		{
			if (line[i ] == '<' )
			{
				
				mc = true;
			}
		}
		if (mc) {
			comment = comment + line;
			for (int i = 1; i < line.length(); i++)
			{
				if (line[i] != '<' && line[i] != '>')
				{
					//comment = comment + line[i];
				}
				if (line[i ] == '>' )
				{
					mc = false;
					cout <<"<ML, " << comment << " >" << endl;
					


				}
			}
		}
	}
	if (mc) {
		cout << "<ML, " << comment << " >" << endl;
		cout << " the whole lines are Multi Commented without ending tag" << endl;
	}






	system("pause");
	return 0;
}