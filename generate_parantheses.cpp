//22. Generate Parentheses

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void backtracking(int open, int close, int n, string &temp, vector<string> &res  ){

    if(open == n && close == n){
        res.push_back(temp);
        return ;
    }
    if(open < n){
        temp += "(";
        ++open;
        backtracking(open, close, n, temp, res);
        temp.pop_back();
        --open;
    }
    if(close < open){
        temp += ")";
        ++close;
        backtracking(open, close, n, temp, res);
        temp.pop_back();
        --open;
    }
}

vector<string> generateParenthesis(int n) {

    if(n <= 0){
        return {};
    }
    vector<string> res;
    int open = 0, close  = 0;
    string temp;

    backtracking(open, close, n, temp, res);

    return res;
}

int main(){
    //tests
    vector<int> tests = {1,2,3,4,5};

    for(int test : tests){
        vector<string> ans = generateParenthesis(test);

        for(string an: ans){
            cout<<an<<" ";
        }
        cout<<endl;
    }

    return 0;
}