//blind 75 p1

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{   
    unordered_map<int ,int> pairs;
    for(int i = 0 ; i < nums.size(); i++)
    {
        if(pairs.find(target - nums[i]) != pairs.end())
        {
            return{(pairs[target - nums[i]]), i};
        }
        pairs[nums[i]] = i;
    }

    return {};
}

int main(){

    //test
    vector<int> cases = {2,5,5,11};
    vector<int> ans = twoSum(cases ,10);

    for(int &i : ans)
    {
        cout<<i;
    }
}
