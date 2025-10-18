//217 : Contains Duplicate

#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

bool hasDuplicate(vector<int>& nums) {
    unordered_map<int,bool> visited;

    for(int &num : nums){
        if(visited.find(num) == visited.end()){
            visited[num] = true;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(){

    // test cases
    vector<vector<int>> tests = {{1,2,3,4}, {1,2,3,1}};

    for(vector<int> &test : tests){
        cout<<hasDuplicate(test)<<endl;
    }

}