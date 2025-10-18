//150. Evaluate Reverse Polish Notation

#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<unordered_set>

using namespace std;

int evalRPN(vector<string>& tokens) {

    if(tokens.size() == 0 ){
        return 0;
    }

    stack<int> stk;
    unordered_set<string> ops = {"+", "-", "*", "/"};
    int ans;

    for(string symbols: tokens){

        if(ops.find(symbols) != ops.end()){

            if(symbols == "+"){
                int a = stk.top();
                stk.pop();
                int b= stk.top();
                stk.pop();
                int ans = a + b;
                stk.push(ans);
            }
            else if(symbols == "-"){
                int a = stk.top();
                stk.pop();
                int b= stk.top();
                stk.pop();
                int ans = b - a;
                stk.push(ans);
            }
            else if(symbols == "*"){
                int a = stk.top();
                stk.pop();
                int b= stk.top();
                stk.pop();
                int ans = a * b;
                stk.push(ans);
            }
            else if(symbols == "/"){
                int a = stk.top();
                stk.pop();
                int b= stk.top();
                stk.pop();
                int ans = b/a;
                stk.push(ans);
            }
            continue;
        }

        int temp = stoi(symbols);
        stk.push(temp);
    }
    return stk.top();
}

int main(){
    //test
    vector<string> test = {"1","2","+","3","*","4","-"};

    int ans = evalRPN(test);
    cout<<ans;
}