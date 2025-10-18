//11. Container With Most Water

#include<stdio.h>
#include<iostream>
#include<vector>


using namespace std;

int maxArea(vector<int>& heights) {

    int n = heights.size() - 1;
    int i = 0;
    int max_vol = 0;

    while(i < n){
        
        if(heights[i] <= heights[n]){
            
            max_vol = max(max_vol, (heights[i] * (n-i)));
            i++;
        }
        else if(heights[i] > heights[n]){

            max_vol = max(max_vol, (heights[n] * (n-i)));
            n--;
        }
        
    }

    return max_vol;
}

int main(){
    
    //tests
    vector<vector<int>> tests = {{1,7,2,5,4,7,3,6}, {2,2,2}};

    for(vector<int> &test: tests){
        cout<<maxArea(test);
        cout<<endl;
    }
    
}