//generate code for the following grammar
//<s> -> <a> <b> <c>
//<a> -> int main() { return 0; }
//<b> -> <d> <b> | <d>
//<d> -> <e> <f> <g>
//<e> -> int | float | double | char
//<f> -> <id> | <id> = <num>
//<g> -> ; | , <f> <g>
//<c> -> <h> <c> | <h>
//<h> -> <i> <j> <k>
//<i> -> <e> <f> <g>
//<j> -> <id> | <id> = <num>
//<k> -> ; | , <j> <k>
//<id> -> <letter> <id> | <letter>
//<num> -> <digit> <num> | <digit>
//<letter> -> a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z
//<digit> -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//<op> -> { | ( | <
//<sp> -> } | ) | ;
//<as> -> =
//<sc> -> ,
//<ao> -> +
//<kw> -> int | float | double | char | main | cout | if | else | while | for | break | switch | case
//<il> -> <digit> <il> | <digit>
//<lt> -> <
//<le> -> <=
//<as> -> =
//<st> -> "
//<op> -> {
//<sp> -> }
//<op> -> (
//<sp> -> )
//<sc> -> ;
//<kw> -> int | float | double | char | main | cout | if | else | while | for | break | switch | case
//<id> -> <letter> <id> | <letter>
//<il> -> <digit> <il> | <digit>
//<st> -> "
//<string> -> <st>
//generate code for the above grammar





#include <iostream>
#include<string>
#include<fstream>

using namespace std;
int check = 0;
fstream tokken("tokkens.txt");
bool is_letter(char ch);
bool is_digit(char ch);
bool is_delimeter(char ch);
void lexical(string str);









int main()
{
	string input;
	cout << "enter the string " << endl;
	/*getline(cin, input);*/
	input = " int hello=8; float x = 3.14; float y = 123e-2; string njs=\"jfaf\"; i++  ";

	cout << input << "\n";
	cout << "tokens are...." << endl;

	lexical(input);

	return 0;
}

bool is_letter(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	else
		return false;
}
bool is_digit(char ch)
{
	if ((ch >= '0' && ch <= '9'))
		return true;
	else
		return false;
}
bool is_delimeter(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n')
	{

		//if (ch == ' ')
		//{
		//	tokken << ' ';
		//}
		//else if (ch == '\n')
		//{
		//	tokken << '\n';
		//}
		//else
		//{
		//	tokken << '\t';
		//}


		return true;
	}
	else
		return false;
}


void lexical(string str)
{

	int state = 0;
	int i = 0;
	string lexeme = "";
	int flag = 1;
	int il = 1;
	char c = '\0';
	while (i != str.length())
	{

		c = str[i];
		//cout << "c=" << c << "\n";
		flag = 1;
		switch (state)
		{
		case 0:
			if (is_letter(c))
			{
				state = 1;
			}
			else if (is_digit(c))
			{

				state = 2;
			}
			else if (c == '=')
			{

				state = 3;

				/*cout << "tokken < " << " as , " << lexeme << " > " << endl;
				lexeme = "";
				flag = 0;*/
			}
			else if (c == '+')
			{
				state = 4;

			}
			else if (c == '-')
			{
				state = 9;

			}
			else if (c == ';')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " PN , " << lexeme << " > " << endl;
				tokken << "PN" << '\n';
				lexeme = "";
				flag = 0;
			}
			else if (c == '<')
			{
				state = 3;
			}
			else if (c == '>')
			{
				state = 3;
			}
			else if (c == '{')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " PN , " << lexeme << " > " << endl;
				tokken << "PN" << ' ';
				lexeme = "";
				flag = 0;
			}
			else if (c == '}')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " PN , " << lexeme << " > " << endl;
				tokken << "PN" << ' ';
				lexeme = "";
				flag = 0;
			}
			else if (c == '(')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " PN , " << lexeme << " > " << endl;
				tokken << "PN" << ' ';
				lexeme = "";
				flag = 0;
			}
			else if (c == ')')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " PN , " << lexeme << " > " << endl;
				tokken << "PN" << ' ';
				lexeme = "";
				flag = 0;
			}
			else if (c == '[')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " PN , " << lexeme << " > " << endl;
				tokken << "PN" << ' ';
				lexeme = "";
				flag = 0;
			}
			else if (c == ']')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " PN , " << lexeme << " > " << endl;
				tokken << "PN" << ' ';
				lexeme = "";
				flag = 0;
			}
			else if (c == ',')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " PN , " << lexeme << " > " << endl;
				tokken << "PN" << ' ';
				lexeme = "";
				flag = 0;
			}
			else if (c == '*')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";
				flag = 0;
			}
			else if (c == '/')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " Op , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";
				flag = 0;
				}
			else if (c == '&')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";
				flag = 0;
				}
			else if (c == '!')
			{
				state = 0;
				lexeme = c;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "PN"<<' ';
				lexeme = "";
				flag = 0;
				}
			else if (is_delimeter(c))
			{
				flag = 0;
			}
			else if (c == '"')
			{
				if (check == 0)
				{
					cout << "tokken < " << " string , ";

					check = 1;
				}
				state = 5;
			}
			else
			{
				cout << " invalid tokken " << endl;
				tokken << "IT";
				break;
			}

			break;

		case 1:
			if (!(is_letter(c) || is_digit(c)))
			{

				state = 0;
				if (lexeme == "int" || lexeme == "float" || lexeme == "double" || lexeme == "char" || lexeme == "main" || lexeme == "cout" ||
					lexeme == "if" || lexeme == "else" || lexeme == "while" || lexeme == "for" || lexeme == "break" || lexeme == "switch" || lexeme == "case")
				{
					cout << "tokken < " << " KW , " << lexeme << " > " << endl;
					tokken << lexeme << " ";
				}
				else
				{
					cout << "tokken < " << " ID , " << lexeme << " > " << endl;
					tokken << "ID" << " ";
				}
				lexeme = "";

				continue;
			}
			break;

		case 2:
			if (is_digit(c)) {
				flag = 1;
			}
			else if (c == '.' || c == 'e' || c == 'E') {
				state = 6; // Transition to the state for the fractional part of a float
				flag = 1;
			}
			else {
				state = 0;
				cout << "Token < IL , " << lexeme << " > " << endl;
				tokken << "Il" << ' ';
				lexeme = "";
				continue;
			}
			break;



		case 3:
			if (c == '=')
			{
				state = 0;
				lexeme = lexeme + c;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";

				//cout << c << " this \n";

			}
			else
			{
				state = 0;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";

				continue;
			}
			break;
		case 4:
			if (c == '+')
			{
				state = 0;
				lexeme = lexeme + c;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";

			}
			else
			{
				state = 0;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";
				continue;
			}
			break;

		case 5:
			if (c != '"')
			{
				lexeme = c;
				cout << lexeme;
				flag = 0;

			}
			else
			{
				state = 0;
				cout << ">" << endl;
				tokken << "SL" << ' ';
				flag = 0;
				lexeme = "";

			}
			break;

#

			// Add a new state for the fractional part of a float number with exponential notation
		case 6:
 			if (is_digit(c)) {
				flag = 1;	
			}
			else if (c == 'e' || c == 'E') {
				state = 7; // Transition to the state for the exponent part
				flag = 1;
			}
			else {
				state = 0;
				cout << "Token < FL , " << lexeme << " > " << endl;
				tokken << "FL" << ' ';
				lexeme = "";
				continue;
			}
			break;

			// Add a state for the exponent part of a floating-point number
		case 7:
			if (c == '+' || c == '-') {
				flag = 1;
			}
			else if (is_digit(c)) {
				state = 8; // Transition to the state for the exponent value
				flag = 1;
			}
			else {
				cout << "Invalid Tokken" << endl;
				tokken << "IT" << ' ';
				break;
			}
			break;

			// Add a state for the exponent value of a floating-point number
		case 8:
			if (is_digit(c)) {
				flag = 1;
			}
			else {
				state = 0;
				cout << "Token < FL , " << lexeme << " > " << endl;
				tokken << "FL" << ' ';
				lexeme = "";
				continue;
			}
			break;
		case 9:
			if (c == '-')
			{
				state = 0;
				lexeme = lexeme + c;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";

			}
			else
			{
				state = 0;
				cout << "tokken < " << " OP , " << lexeme << " > " << endl;
				tokken << "OP" << ' ';
				lexeme = "";
				continue;
			}
			break;

		}

			if (flag)
			{
				lexeme = lexeme + c;
			}
			i++;

			check = 0;
	}


}






