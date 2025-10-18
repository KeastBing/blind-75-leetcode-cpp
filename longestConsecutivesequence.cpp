//blind 75 p3

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> tracking;
    int maxlen = 0;
    for(int &i : nums){
        if(tracking[i] == 0){
            tracking[i] = tracking[i+1] + tracking[i-1] + 1;
            tracking[i - tracking[i - 1]] = tracking[i];
            tracking[i + tracking[i + 1]] = tracking[i]; 
            maxlen = max(maxlen, tracking[i]);
        }
    }

    return maxlen;

}


int main(){
    vector<int> testcase1 = {0,3,7,2,5,8,4,6,0,1};
    cout<<longestConsecutive(testcase1)<<endl; // 9

    vector<int> testcase2 = {100,4,200,1,3,2};
    cout<<longestConsecutive(testcase2)<<endl; // 4

    vector<int> testcase3 = {1,2,0,1};
    cout<<longestConsecutive(testcase3)<<endl; // 3

}
