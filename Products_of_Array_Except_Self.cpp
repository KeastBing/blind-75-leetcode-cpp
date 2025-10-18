//238 product of array except self

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();
    vector<int> output(n);
    output[0] = 1;

    for(int i = 1; i < n; i++){

        output[i] = output[i-1] * nums[i -1];
    }
   
    int temp = 1;

    for(int i = n-2; i >= 0; i--){
        temp *= nums[i+1];
        output[i] = output[i] * temp;
    }
    return output;
}

int main(){
    //tests
    vector<vector<int>> tests = {{-1,0,1,2,3},{1,2,3,4},{0,1,2,-1}};

    for(vector<int> &test: tests){
        vector<int> res = productExceptSelf(test);

        for(int &i: res){
            cout<<i<<" ";
        }

        cout<<endl;
    }
    
}