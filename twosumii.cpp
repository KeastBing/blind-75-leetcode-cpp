//167. Two Sum II - Input Array Is Sorted

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  
    int j = numbers.size() - 1;
    int i = 0;
    
    while(i < j){
        
        if(numbers[i] + numbers[j] > target){
            j--;
        }
        else if(numbers[i] + numbers[j] < target){
            i++;
        }
        else{
            return {i+1, j+1};
        }
    }

    return {};
}
 
int main(){
    //tests
    vector<vector<int>> tests = {{1,2,3,4} , {1,2,3,4,5,6}};
    int targ = 3;
    for(vector<int> test: tests){
        vector<int> res = twoSum(test, targ);
        targ++;
        for(int &i: res){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    
}