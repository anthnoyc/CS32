//
//  main.cpp
//  eval
//
//  Created by Anthony Chen on 4/29/23.
//

#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

bool isValid(string infix);
bool evalPost(string str);

string remove_spaces(string s){
    string new_s = "";
    for(int i = 0; i < s.size(); i++){
        char c1 = s[i];
        if(c1 != ' '){
            new_s += c1;
        }
    }
    cerr << new_s << endl;
    return new_s;
}

int evaluate(string infix, string& postfix, bool& result){
    // detect if the infix is valid
    // put the postfix version in postfix,
    // put the result of the equation in result
    // if valid, return 0, not valid return 1
    string m_string = remove_spaces(infix);
    if(!isValid(m_string)){
        return 1;
    }
    char ch;
    postfix.clear();
    stack <char> op_stack;
    for(int i = 0; i < m_string.size(); i++){
        ch = m_string[i];
        switch(ch){
            case('T'):
            case('F'):
                postfix += ch;
                break;
            case('('):
                op_stack.push(ch);
                break;
            case(')'):
                while(op_stack.top() != '('){
                    postfix += op_stack.top();
                    op_stack.pop();
                }
                op_stack.pop();
                break;
            case('!'):
            case('&'):
            case('^'):
                while(!op_stack.empty() && op_stack.top() != '(' && ch >= op_stack.top()){
                    postfix += op_stack.top();
                    op_stack.pop();
                }
                op_stack.push(ch);
                break;
        }
    }
    while (!op_stack.empty()) {
        postfix += op_stack.top();
        op_stack.pop();
    }
    result = evalPost(postfix);
    return 0;
}



bool isValid(string str){
    stack <char> paren;
    for(int j = 0; j < str.size(); j++){
        char c = str[j];
        switch(c){
            case('('):
                paren.push(c);
                break;
            case(')'):
                if (paren.empty() || paren.top() != '(')
                    return false;
                paren.pop();
                break;
        }
    }
    if(!paren.empty()){
        return false;
    }
    if(str[0] == '&' || str[0] == ')' || str[0] == '^'){
        return false;
    }
    if(str.empty()){
        return false;
    }
    char c1;
    char c2;
    for(int i = 0; i < str.size(); i++){
        c1 = str[i];
        c2 = str[i + 1];
        if(c1 != 'T' && c1 != 'F' && c1 != '!' && c1 != '^' && c1 != '&' && c1 != '(' && c1 != ')'){
            return false;
        }
        if(c1 == 'T' || c1 == 'F'){
            if(c2 == 'F' || c2 == 'T' || c2 == '!' || c2 =='('){
                return false;
            }
        }
        if(c1 == '!' || c1 == '&' || c1 == '^' || c1 =='('){
            if(c2 == '&' || c2 == '^' || c2 == ')') {
                return false;
            }
        }
        if (c1 == ')'){
            if(c2 == '!' || c2 =='('){
                return false;
            }
        }
    }
    char c3 = str[str.size() - 1];
    if(c3 == '!' || c3 == '&' || c3 == '^' || c3 == '('){
        return false;
    }
    
    
    
    
    
    
    
    
    
    return true;
}


bool evalPost(string str) {
    stack <char> m_stack;
    char c1;
    char result;
    bool b1;
    bool b2;
    for(int i = 0; i < str.size(); i++){
        c1 = str[i];
        if(c1 == 'T' || c1 =='F'){
            m_stack.push(c1);
        } else if(c1 == '!'){
            if(m_stack.top() == 'T'){
                m_stack.pop();
                m_stack.push('F');
            }
            m_stack.pop();
            m_stack.push('T');
        } else {
            char op2 = m_stack.top();
            m_stack.pop();
            char op1 = m_stack.top();
            m_stack.pop();
            if(op1 == 'T'){
                b1 = true;
            } else if (op1 == 'F'){
                b1 = false;
            }
            if(op2 == 'T'){
                b2 = true;
            } else if (op2 == 'F'){
                b2 = false;
            }
            
            if(c1 == '&'){
                if((b1 && b2) == true){
                    result = 'T';
                } else {
                    result = 'F';
                }
            } else if(c1 == '^'){
                if((b1 ^ b2)){
                    result = 'T';
                } else {
                    result = 'F';
                }
            }
            m_stack.push(result);
        }
    }
    if(m_stack.top() == 'T')
        return true;
    return false;
}



        int main()
        {
        string pf;
        bool answer;
        assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
        assert(evaluate("T^", pf, answer) == 1);
        assert(evaluate("F F", pf, answer) == 1);
        assert(evaluate("TF", pf, answer) == 1);
        assert(evaluate("()", pf, answer) == 1);
        assert(evaluate("()T", pf, answer) == 1);
        assert(evaluate("T(F^T)", pf, answer) == 1);
        assert(evaluate("T(&T)", pf, answer) == 1);
        assert(evaluate("(T&(F^F)", pf, answer) == 1);
        assert(evaluate("T|F", pf, answer) == 1);
        assert(evaluate("", pf, answer) == 1);
        assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0
                               &&  pf == "FF!TF&&^"  &&  !answer);
        assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
        assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
        cout << "Passed all tests" << endl;
        }

