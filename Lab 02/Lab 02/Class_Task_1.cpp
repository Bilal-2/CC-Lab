//
//#include<iostream>
//#include <fstream>
//#include <string>
//#include <ctype.h>
//using namespace std;
//
//
//int main()
//{	
//	
//	fstream f1 ("readfile.txt");
//	string s;
//	bool flag=false;
//	while (f1.eof() == 0)
//	{
//		flag = true;
//		f1 >> s;
//		
//		
//			
//
//
//			for (int i = 1; i < s.length(); i++)
//			{
//				
//
//				if (isdigit(s[i]) || isalpha(s[i]) || s[i]=='_')
//				{
//					
//				}
//				else {
//					flag = false;
//				}
//
//
//			}
//			
//			if (flag) {
//
//			
//
//				if (isalpha(s[0]) || s[0] == '_')
//				{
//					cout << s << endl;
//				}
//			}
//
//	}
//	system("pause");
//	return 0;
//}