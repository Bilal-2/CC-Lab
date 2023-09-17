//
//#include<iostream>
//#include <fstream>
//#include <string>
//#include <ctype.h>
//#include<sstream>
//using namespace std;
//
//
//int main()
//{
//	ifstream f2,f3,f4,f5,f6,f7,f8;
//	fstream f1("New Text Document.txt");
//	
//	
//	string line ,comp , word;
//	int line_no = 0;
//	bool flag = false;
//	while (getline(f1, line))
//	{
//		line_no++;
//		stringstream s1(line);
//		while (s1 >> word)
//		{
//			flag = false;
//			//cout << word << " in Line : " << line_no << endl;
//			f2.open("adjectives.txt");
//			while (f2 >> comp)
//			{
//				
//				if (comp.compare(word) == 0)
//				{
//					cout << "<" << comp << ", Adjective> " << endl;
//					flag = true;
//					break;
//				}
//
//			}
//			f2.close();
//
//			f3.open("adverbs.txt");
//			while (f3 >> comp)
//			{
//
//				if (comp.compare(word) == 0)
//				{
//					cout << "<" << comp << ", Adverb> " << endl;
//					flag = true;
//					break;
//				}
//
//			}
//
//			f3.close();
//			f4.open("articles.txt");
//			while (f4 >> comp)
//			{
//
//				if (comp.compare(word) == 0)
//				{
//					cout << "<" << comp << ", Article> " << endl;
//					flag = true;
//					break;
//				}
//
//			}
//
//			f4.close();
//			f5.open("nouns.txt");
//			while (f5 >> comp)
//			{
//
//				if (comp.compare(word) == 0)
//				{
//					cout << "<" << comp << ", Noun> " << endl;
//					flag = true;
//					break;
//				}
//
//			}
//
//			f5.close();
//			f6.open("preposition.txt");
//			while (f6 >> comp)
//			{
//
//				if (comp.compare(word) == 0)
//				{
//					cout << "<" << comp << ", Preposition> " << endl;
//					flag = true;
//					break;
//				}
//
//			}
//
//			f6.close();
//			f7.open("pronouns.txt");
//			while (f7 >> comp)
//			{
//
//				if (comp.compare(word) == 0)
//				{
//					cout << "<" << comp << ", Pronoun> " << endl;
//					flag = true;
//					break;
//				}
//
//			}
//
//			f7.close();
//			f8.open("verbs.txt");
//			while (f8 >> comp)
//			{
//
//				if (comp.compare(word) == 0)
//				{
//					cout << "<" << comp << ", Verb> " << endl;
//					flag = true;
//					break;
//				}
//
//			}
//
//			f8.close();
//
//
//
//
//
//
//			if (!flag)
//			{
//				cout << "<" << word << "> Error in Line " << line_no << endl;
//			}
//		}
//
//	}
//
//
//
//
//		//for (int i = 0; i < word.length(); i++)
//		//{
//		//	word[i]=tolower(word[i]);
//
//		//}
//		//cout << word<<endl;
//		///*cout << word<<endl;*/
//		//while (f2 >> comp)
//		//{
//		//	if (word == comp)
//		//	{
//		//		cout << comp << " This belongs to Adjectives" << endl;
//		//	}
//		//	
//		//}
//		//while (f3 >> comp)
//		//{
//		//	if (word == comp)
//		//	{
//		//		cout << comp << " This belongs to Adverbs" << endl;
//		//		//break:
//		//	}
//
//		//}
//		//while (f4 >> comp)
//		//{
//		//	if (word == comp)
//		//	{
//		//		cout << comp << " This belongs to Articals" << endl;
//		//		//break:
//		//	}
//
//		//}
//		//while (f5 >> comp)
//		//{
//		//	if (word == comp)
//		//	{
//		//		cout << comp << " This belongs to Nouns" << endl;
//		//		//break:
//		//	}
//
//		//}
//		//while (f6 >> comp)
//		//{
//		//	if (word == comp)
//		//	{
//		//		cout << comp << " This belongs to Preposistions" << endl;
//		//		//break:
//		//	}
//
//		//}
//		//while (f7 >> comp)
//		//{
//		//	if (word == comp)
//		//	{
//		//		cout << comp << " This belongs to Pronouns" << endl;
//		//		//break:
//		//	}
//
//		//}
//		//while (f8 >> comp)
//		//{
//		//	if (word == comp)
//		//	{
//		//		cout << comp << " This belongs to Verbs" << endl;
//		//		//break:
//		//	}
//
//		//}
//		
//	
//	system("pause");
//	return 0;
//}