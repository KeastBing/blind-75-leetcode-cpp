//155 min stack

#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

class MinStack {
private:
    stack<long> stk;
    long minele;
public:
    MinStack() {
         
    }
    
    void push(long val) {
        if(stk.empty()){
            minele = val;
        }
        if(val < minele){
            long temp = val;
            val = 2*val - minele;
            minele = temp;
            stk.push(val);
        }
        else{
            stk.push(val);
        }
        
    }
    
    void pop() {
        if(stk.top() < minele){
            minele = 2*minele - stk.top();
        }
        stk.pop();
    }
    
    int top() {
        if(stk.top() < minele){
            return minele;
        }
        return stk.top();
    }
    
    int getMin() {
        return minele;
    }
};

int main(){
    //test
    MinStack a;
    a.push(10);
    cout<<a.getMin()<<endl;
    a.push(9);
    cout<<a.getMin()<<endl;
    a.push(2);
    cout<<a.getMin()<<endl;
    cout<<a.top()<<endl;
    a.pop();
    cout<<a.getMin()<<endl;
    cout<<a.top()<<endl;
}