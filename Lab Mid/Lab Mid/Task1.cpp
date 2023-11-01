#include <iostream>
#include<string>
#include<fstream>

using namespace std;
int check = 0;
bool is_Letter(char ch);
bool is_Digit(char ch);
bool is_Delimeter(char ch);
void Lexical(string str);



/*
stmt-->if (bexp) stmt
		|if (bexp) stmt  else stmt
		|id

stmt-->if (bexp) stmt A|id
A---->else stmt|null

bexp-->  B O B| id
		 |int literal
B --> bexp
O-->	  <|>
		 

bexp-->  bexp > bexp
		 |bexp <bexp
		 | id
		 |intliteral

*/

/*
E->TE'
E'->+TE'|-TE'|null
T-> FT'
T'->*FT'|/FT'|null
F-> id|num|(E)
*/

void Stmt();
void A();
void bexp();
void B();
void O();
void id();
int countt = 0;
string expr;


int main()
{
	//string input;
	//cout << "Enter the string " << endl;
	///*getline(cin, input);*/
	//input=" if(a<5) \n {a}\nelse\n {c} ";
	//cout << input <<"\n";
	//cout << "Tokens are...." << endl;

	//Lexical(input);
	cout << "enter Expression \n";
	cin >> expr;
	int l = expr.length();
	expr += "$";
	E();
	if (l == countt)
		cout << "Accepted" << endl;
	else
		cout << "Rejected" << endl;
	return 0;
}

//bool is_Letter(char ch)
//{
//	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
//		return true;
//	else
//		return false;
//}
//bool is_Digit(char ch)
//{
//	if ((ch >= '0' && ch <= '9'))
//		return true;
//	else
//		return false;
//}
//bool is_Delimeter(char ch)
//{
//	if (ch == ' ' || ch == '\t' || ch == '\n')
//		return true;
//	else
//		return false;
//}
//
//
//void Lexical(string str)
//{
//
//	int state = 0;
//	int i = 0;
//	string lexeme = "";
//	int flag = 1;
//	char c = '\0';
//	while (i != str.length())
//	{
//
//		c = str[i];
//		flag = 1;
//		switch (state)
//		{
//		case 0:
//			if (is_Letter(c))
//			{
//				state = 1;
//			}
//			else if (is_Digit(c))
//			{
//				state = 2;
//			}
//			else if (c == '=')
//			{
//				state = 0;
//				lexeme = c;
//				cout << "Tokken < " << " AS , " << lexeme << " > " << endl;
//				lexeme = "";
//				flag = 0;
//			}
//			else if (c == '+')
//			{
//				state = 4;
//
//			}
//			else if (c == ';')
//			{
//				state = 0;
//				lexeme = c;
//				cout << "Tokken < " << " SC , " << lexeme << " > " << endl;
//				lexeme = "";
//				flag = 0;
//			}
//			else if (c == '<')
//			{
//				state = 3;
//			}
//			else if (c == '{')
//			{
//				state = 0;
//				lexeme = c;
//				cout << "Tokken < " << " OP , " << lexeme << " > " << endl;
//				lexeme = "";
//				flag = 0;
//			}
//			else if (c == '}')
//			{
//				state = 0;
//				lexeme = c;
//				cout << "Tokken < " << " SP , " << lexeme << " > " << endl;
//				lexeme = "";
//				flag = 0;
//			}
//			else if (c == '(')
//			{
//				state = 0;
//				lexeme = c;
//				cout << "Tokken < " << " OP , " << lexeme << " > " << endl;
//				lexeme = "";
//				flag = 0;
//			}
//			else if (c == ')')
//			{
//				state = 0;
//				lexeme = c;
//				cout << "Tokken < " << " SP , " << lexeme << " > " << endl;
//				lexeme = "";
//				flag = 0;
//			}
//			else if (is_Delimeter(c))
//			{
//				flag = 0;
//			}
//			else if (c == '"')
//			{
//				if (check == 0)
//				{
//					cout << "Tokken < " << " STring , ";
//
//					check = 1;
//				}
//				state = 5;
//			}
//			else
//			{
//				cout << " Invalid Tokken " << endl;
//				break;
//			}
//
//			break;
//
//		case 1:
//			if (!(is_Letter(c) || is_Digit(c)))
//			{
//
//				state = 0;
//				if (lexeme == "int" || lexeme == "main" || lexeme == "cout" || lexeme =="if" || lexeme == "else")
//				{
//					cout << "Tokken < " << " KW , " << lexeme << " > " << endl;
//				}
//				else
//				{
//					cout << "Tokken < " << " ID , " << lexeme << " > " << endl;
//				}
//				lexeme = "";
//
//				continue;
//			}
//			break;
//
//		case 2:
//			if (!is_Digit(c))
//			{
//				state = 0;
//				cout << "Tokken < " << " IL , " << lexeme << " > " << endl;
//				lexeme = "";
//				continue;
//			}
//			break;
//
//		case 3:
//			if (c == '=')
//			{
//				state = 0;
//				cout << "Tokken < " << " LE , " << lexeme << " > " << endl;
//				lexeme = "";
//
//			}
//			else
//			{
//				state = 0;
//				cout << "Tokken < " << " LT , " << lexeme << " > " << endl;
//				lexeme = "";
//				continue;
//			}
//			break;
//		case 4:
//			if (c == '+')
//			{
//				state = 0;
//				cout << "Tokken < " << " Ao , " << lexeme << " +> " << endl;
//				lexeme = "";
//
//			}
//			else
//			{
//				state = 0;
//				cout << "Tokken < " << " As , " << lexeme << " > " << endl;
//				lexeme = "";
//				continue;
//			}
//			break;
//
//		case 5:
//			if (c != '"')
//			{
//				lexeme = c;
//				cout << lexeme;
//				flag = 0;
//
//			}
//			else
//			{
//				state = 0;
//				cout << ">" << endl;
//				flag = 0;
//				lexeme = "";
//
//			}
//			break;
//
//#
//		}
//		if (flag)
//			lexeme = lexeme + c;
//		i++;
//
//		check = 0;
//	}
//
//
//}

void Stmt() {
	
	if (expr[countt] == 'i') {
		countt++;
		cout << "If(bexp) stmt A " << endl;
		bexp();
		Stmt();
		A();
	}

	else  {
		cout << "id" << endl;
		id();
	}

	
	
}

void A() {
	if (expr[countt] == 'e') {
		countt++;
		cout << "else stmt" << endl;
		Stmt();
	
	}

	else {
		
		cout << "A->null" << endl;
		
	}

	
}

void bexp() {
	cout << "bexp->B O B'" << endl;
	B();
	if (expr[countt] == '<' || expr[countt] == '>') {
		cout << "O-><|>" << endl;
		O();
		B();
	}
	else if (expr[countt] == 'i')
	{
		cout << "bexp->int" << endl;
	}
	else {
		cout << "B->id" << endl;
		id();
	}
}

void O() {
	if (expr[countt] == '<') {
		countt++;
		cout << "O-> <" << endl;
		
	}

	else  {
		countt++;
		cout << "O-> <" << endl;
		
	}

	
}

void id() {
	if (isalpha(expr[countt])) {
		countt++;
		cout << "F->id" << endl;
	}
	
	else if (expr[countt] == '(') {
		countt++;
		cout << "F->(E)" << endl;
		E();
		if (expr[countt] != ')') {
			cout << "Rejected" << endl;
			exit(0);
		}
		countt++;
	}
	else {
		cout << "Rejected" << endl;
		exit(0);
	}
}







#include <iostream>
#include<string>
#include<fstream>

using namespace std;
int check = 0;
bool is_Letter(char ch);
bool is_Digit(char ch);
bool is_Delimeter(char ch);
void Lexical(string str);

/*
E->TE'
E'->+TE'|-TE'|null
T-> FT'
T'->*FT'|/FT'|null
F-> id|num|(E)
*/
void statement();
void bexp();
void T();
void Td();
void F();
int countt = 0;
string expr = " ";
fstream file("f.txt");
string token;

int main()
{
	string input;
	cout << "Enter the string " << endl;
	getline(cin, input);
	cout << "expr are...." << endl;

   Lexical(input);

	cout << " \n " << expr;
	getline(file, token);
	int l = token.length();
	token += "$";
	statement();
	if (l == countt)
		cout << "Accepted" << endl;
	else
		cout << "Rejected" << endl;
	if (l == countt)
		cout << "Accepted" << endl;
	else
		cout << "Rejected" << endl;
	system("pause");

	return 0;
}

bool is_Letter(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	else
		return false;
}
bool is_Digit(char ch)
{
	if ((ch >= '0' && ch <= '9'))
		return true;
	else
		return false;
}
bool is_Delimeter(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n')
		return true;
	else
		return false;
}


void Lexical(string str)
{

	int state = 0;
	int i = 0;
	string lexeme = "";
	int flag = 1;
	char c = '\0';
	while (i != str.length()+1)
	{

		c = str[i];
		flag = 1;
		switch (state)
		{
		case 0:
			if (is_Letter(c))
			{
				state = 1;
			}
			else if (is_Digit(c))
			{
				state = 2;
			}
			else if (c == '=')
			{
				state = 0;
				lexeme = c;
				cout << "Tokken < " << " AS , " << lexeme << " > " << endl;
				lexeme = "";
				flag = 0;
			}
			
			else if (c == ';')
			{
				state = 0;
				lexeme = c;
				lexeme = "";
				flag = 0;
			}
			else if (c == '<')
			{
				state = 0;
				lexeme = c;
				expr.append(" ");
				expr.append(lexeme);
				file << " " << lexeme;
				lexeme = "";
				flag = 0;
			}
			else if (c == '>')
			{
				state = 0;
				lexeme = c;
				expr.append(" ");

				expr.append(lexeme);
				file << " " << lexeme;
				lexeme = "";
				flag = 0;
			}
			else if (c == '(')
			{
				state = 0;
				lexeme = c;
				expr.append(" ");
				expr.append(lexeme);
				file << " " << lexeme;
				lexeme = "";
				flag = 0;
			}
			else if (c == ')')
			{
				state = 0;
				lexeme = c;
				expr.append(" ");
				expr.append(lexeme);
				file << " " << lexeme;
				lexeme = "";
				flag = 0;
			}
			else if (c == '(')
			{
				state = 0;
				lexeme = c;
				lexeme = "";
				flag = 0;
			}
			else if (c == ')')
			{
				state = 0;
				lexeme = c;
				lexeme = "";
				flag = 0;
			}
			else if (is_Delimeter(c))
			{
				flag = 0;
			}
			else if (c == '"')
			{
				if (check == 0)
				{
					cout << "Tokken < " << " STring , ";

					check = 1;
				}
				state = 5;
			}
			else
			{

				break;
			}

			break;

		case 1:
			if (!(is_Letter(c) || is_Digit(c)))
			{

				state = 0;
				if (lexeme == "int" || lexeme == "main" || lexeme == "cout" || lexeme == "if" || lexeme == "else")
				{
					expr.append(" ");

					expr.append(lexeme);
					file << " " << lexeme;
				}
				else
				{
					expr.append(" ");

					expr.append(lexeme);
					file << " " << lexeme;
				}
				lexeme = "";

				continue;
			}
			break;

		case 2:
			if (!is_Digit(c))
			{
				state = 0;
				expr.append(" ");

				expr.append(lexeme);
				file <<" "<<lexeme;
				lexeme = "";
				continue;
			}
			break;

		

#
		}
		if (flag)
			lexeme = lexeme + c;
		i++;

		check = 0;
	}


}




void statement() {
	if (token[countt] == 'i')
	{
		countt++;
		if (token[countt] == 'f')
		{
			countt++;
			bexp();
		}
		
	}
	else
	{
		
	}
}

void bexp() {
	if (expr[countt] == '+') {
		countt++;
		cout << "E'->+TE'" << endl;
		T();
		Ed();
	}

	else if (expr[countt] == '-') {
		countt++;
		cout << "E'->-TE'" << endl;
		T();
		Ed();
	}

	else {
		cout << "E'->null" << endl;
	}
}

void T() {
	cout << "T->FT'" << endl;
	F();
	Td();
}

void Td() {
	if (expr[countt] == '*') {
		countt++;
		cout << "T'->*FT'" << endl;
		F();
		Td();
	}

	else if (expr[countt] == '/') {
		countt++;
		cout << "T'->/FT'" << endl;
		F();
		Td();
	}

	else {
		cout << "T'->null" << endl;
	}
}

void F() {
	if (isalpha(expr[countt])) {
		countt++;
		cout << "F->id" << endl;
	}
	else if (isdigit(expr[countt])) {
		countt++;
		cout << "F->digit" << endl;
	}
	else if (expr[countt] == '(') {
		countt++;
		cout << "F->(E)" << endl;
		E();
		if (expr[countt] != ')') {
			cout << "Rejected" << endl;
			exit(0);
		}
		countt++;
	}
	else {
		cout << "Rejected" << endl;
		exit(0);
	}
}