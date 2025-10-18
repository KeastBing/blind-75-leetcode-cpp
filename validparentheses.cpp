//blind 75 p2

#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include <stack>

using namespace std;

bool isValid(string s) 
{
    unordered_map<char,int> brack_map = {{'(',')'}, {'{','}'},{'[',']'} };
    stack<char> st;
    int s_len = s.length();

    for(int i = 0 ; i < s_len; i++){
        if(brack_map.find(s[i]) != brack_map.end()){
            st.push(s[i]);
        }
        else if(!st.empty() && brack_map[st.top()] == s[i]){
            st.pop();
        }
        else{
            return false;
        }
    }
    return st.empty() ; 
}

int main(){
    //test cases
    cout<<isValid("[(])"); //false
    cout<<isValid(")"); //false
    cout<<isValid("[]()"); //true
    cout<<isValid("{[()]}"); //true
}
