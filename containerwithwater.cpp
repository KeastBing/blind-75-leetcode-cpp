// Blind 75 p6

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int maxArea(vector<int>& height) {

     int maxvolume = 0;
     int temp_vol = 0;
     int len = height.size() - 1 ;
     int i = 0, j = len;

     while(i < j){
          int min_height = min(height[i],height[j]);
          temp_vol = min_height * (j - i);

          if(height[i] > height[j]){
               j--;
          }
          else{
               i++;
          }
          maxvolume = max(maxvolume, temp_vol);
     }

     return maxvolume;
}

int main(){

     // tests
     vector<int> tests[2] = {{1,8,6,2,5,4,8,3,7}, {1,1}};

     for(auto &test : tests){
          cout<<maxArea(test)<<endl;
     }
     
     return 0;
}