//blind 75 p4

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int missing = 0;
    int maxlen = nums.size();
    int missin_sum = 0;

    int sum =(maxlen * (maxlen+1))/2;

    for(int &num: nums){
        missin_sum += num;
    }

    missing = sum - missin_sum;
    return missing;
}

int main(){
    //test cases
    vector<int> test [4] = {{0,1},{3,0,1},{9,6,4,2,3,5,7,0,1}, };

    for(auto &i: test){
         cout<<missingNumber(i)<<endl;
    } 
}