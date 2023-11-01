#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool is_Letter(char ch);
bool is_Digit(char ch);
bool is_Delimeter(char ch);
void Lexical();

int main()
{
    //string input;
    //cout<<"Enter the string "<<endl;
    //getline(cin,input);
   // cout<<"Tokens are...."<<endl;
    //cout<<input<<endl;
    Lexical();
    return 0;
}

bool is_Letter(char ch)
{
   if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
    return true;
   else
    return false;
}
bool is_Digit(char ch)
{
   if((ch>='0' && ch<='9') )
    return true;
   else
    return false;
}
bool is_Delimeter(char ch)
{
   if(ch==' ' || ch=='\t' || ch=='\n' )
    return true;
   else
    return false;
}



void Lexical()
{
  	ifstream str("quiz1.txt"); // Replace 'source.cpp' with your source file's name
	if (!str.is_open()) {
		cout << "Failed to open source file." << endl;
	}
  int state=0;
  //int i=0;
  string lexeme="";
  int flag=1;
  char c='\0';

  while (str.get(c))
  {
      flag=1;
      switch(state)
      {
        case 0:
            if(is_Letter(c))
            {
                state=1;
            }
            else if(is_Digit(c))
            {
                state=2;
            }
            else if (c == '"')
            {
                state = 4;
            }
            else if(c=='=')
            {
                state=0;
                lexeme=c;
                cout<<"Tokken < "<<" AS , "<<lexeme<<" > " <<endl;
                lexeme="";
                flag=0;
            }
            else if(c=='+')
            {
                state = 5;
            }
            else if(c==';')
            {
                state=0;
                lexeme=c;
                cout<<"Tokken < "<<" SC , "<<lexeme<<" > " <<endl;
                lexeme="";
                flag=0;
            }
            else if(c=='<')
            {
                state=3;
            }
            else if(c=='{')
            {
                state=0;
                lexeme=c;
                cout<<"Tokken < "<<" OP , "<<lexeme<<" > " <<endl;
                lexeme="";
                flag=0;
            }
            else if(c=='}')
            {
                state=0;
                lexeme=c;
                cout<<"Tokken < "<<" EP , "<<lexeme<<" > " <<endl;
                lexeme="";
                flag=0;
            }
            else if(is_Delimeter(c))
            {
               flag=0;
            }
            else
            {
                cout<<" Invalid Tokken "<<endl;
                break;
            }

        break;

        case 1:
            if(!(is_Letter(c) || is_Digit(c)))
            {

                state=0;
                if(lexeme=="int" || lexeme=="main" || lexeme=="cout" || lexeme=="string")
                {
                    cout<<"Tokken < "<<" KW , "<<lexeme<<" > " <<endl;
                }
                else
                {
                    cout<<"Tokken < "<<" ID , "<<lexeme<<" > " <<endl;
                }
                lexeme="";

                continue;
            }
        break;

        case 2:
            if(!is_Digit(c))
            {
                state=0;
                cout<<"Tokken < "<<" IL , "<<lexeme<<" > " <<endl;
                lexeme="";
                continue;
            }
        break;

        case 3:
            if(c=='=')
            {
                state=0;
                cout<<"Tokken < "<<" LE , "<<lexeme<<" > " <<endl;
                lexeme="";

            }
            else
            {
                state=0;
                cout<<"Tokken < "<<" LT , "<<lexeme<<" > " <<endl;
                lexeme="";
                continue;
            }
        break;

        case 4:
            if (c == '"')
            {
                state = 0;
                cout << "Tokken < " << " SL , " << lexeme << c << " > " << endl;
                lexeme = "";
                flag = 0;
            }
        break;

        case 5:
        {
            if (c == '+')
            {
                state = 0;
                lexeme = lexeme + c;
                cout << "Tokken < " << " IO , " << lexeme << " > " << endl;
                lexeme = "";
                flag = 0;
                //continue;

            }
            else {

                state = 0;
                cout << "Tokken < " << " AO , " << lexeme << " > " << endl;
                lexeme = "";
                flag = 0;
            }
        }
        break;

      }

     if(flag) // if keyword continues
        lexeme=lexeme+c;

   //i++; // new char
  }

  str.close();
}



















