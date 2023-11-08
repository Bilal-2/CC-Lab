#include <iostream>
#include<sstream>
#include<string>
#include <stdlib.h>
using namespace std;
/*
E->TE'
E'->+TE'|-TE'|null
T-> FT'
T'->*FT'|/FT'|null
F-> id|num|(E)


Prediction Table:

    id      +       *      (       )       $

E   TE'                   TE'

E'          +TE'                   0        0        

T   FT'                    FT'

T'          0       *FT'           0        0

F   id                     (E)










*/
bool E();
bool Ed();
bool T();
bool Td();
bool F();
int countt = 0;
string expr;
string tokken;

int main() {
    cin >> expr;
    int l = expr.length();
    expr += " $";
    
    
    int i = 0;
    while (i<expr.length())
    {   
        if (expr[i] != ' ') {
            tokken += expr[i];
        }
        
        if (expr[i] == ' ')
        {
           /* if (tokken[0] == 'i')
            {
                E();
            }
            else if (tokken[0] == '+')
            {
                Ed();

            }
            else if (tokken[0] == '*')
            {
                Td();
            }
            else if (tokken[0] == '(')
            {
                E();
            }
            else if (tokken[0] == ')')
            {

            }
            else if (tokken[0] == '$')
            {

            }
            else {
                cout << "Invalid Sayntax" << "\n";
            }*/

            if (E())
                cout << "Parssed" << endl;
            else
                cout << "Rejected" << endl;

        }
        i++;
    }
    
   
   
}

bool E() {
    cout << "E->TE'" << endl;
    if (tokken == "id" || tokken == "(") {
        if (T() && Ed())
        {
            return true;
       }
    }
   
}

bool Ed() {


    if (tokken == "+")
    {
        cout << "E'->+TE'" << endl;
        if (T() && Ed()) {
            return true;
       }
    }
    else if (tokken == ")") {
        return true;
    }
    else if (tokken == "$") {
        return true;
    }
   /* if (expr[countt] == '+') {
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
    }*/
}

bool T() {
    cout << "T->FT'" << endl;
    if (tokken == "id" || tokken == "(") {
        if (F()) {
            return true;
       }
        else if (Td())
        {
            return true;
        }
       
    }
   
}

bool Td() {
    if (tokken == "*") {
        if (F() && Td()) {
            return true;
       }
    }

    else if (tokken == "+") {
        return true;
    }
    else if (tokken == ")") {
        return true;
    }
    else if (tokken == "$") {
        return true;
    }

   
}

bool F() {

    if (tokken == "id" ) {
        cout << "F->id" << endl;
        return true;
    }
    else if (tokken == "(") {
        cout << "F->(E)" << endl;
        if (E()) {
            return true;
        }
    }
    /*if (isalpha(expr[countt])) {
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
    }*/
}