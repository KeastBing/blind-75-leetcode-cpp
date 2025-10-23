// 739. Daily Temperatures

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    
    if(temperatures.size() <= 0){
        return {};
    }
    stack<int> stk;
    vector<int> res(temperatures.size(), 0);

    for(int i = 0 ; i < temperatures.size(); i++){

        while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
            int j = stk.top();
            stk.pop();
            res[j] = i - j;
        }

        stk.push(i);
    }

    return res;
}

int main(){
    //test
    vector<int> test  = {73,74,75,71,69,72,76,73};

    vector<int> ans = dailyTemperatures(test);
    
    for(int ind : ans){
        cout<<ind<<" ";
    }

    return 0;
}