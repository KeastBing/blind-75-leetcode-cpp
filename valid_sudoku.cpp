//36 Valid sudoku


#include<stdio.h>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<int>> row;
    unordered_map<int, unordered_set<int>> col;
    unordered_map<int, unordered_set<int>> sqr;

    int n = 9; 

    for(int i = 0; i < n; i++){
        //top triangle 
        
        for(int j = i; j < n; j++){

            int num = board[i][j];

            if(num == '.'){
                continue;
            }

            if(row[i].count(num)){
                cout<<"row moment -"<<num<<"- "<<i;
                return false;
            }
            row[i].insert(num);

            if(col[j].count(num)){
                cout<<"col moment "<<num<<" "<<j;
                return false;
            }
            col[j].insert(num);

            int sqr_inx = (i/3)*3 + (j/3);

            if(sqr[sqr_inx].count(num)){
                cout<<"square moment "<<num<<" "<<j<<" "<<i;
                return false;
            }
            sqr[sqr_inx].insert(num);
        }

        //bot triangle

        for(int j = i+1; j < n; j++){

            int num = board[j][i];

            if(num == '.'){
                continue;
            }

            if(col[i].count(num)){
                cout<<"col moment part 2 "<<num<<" "<<j<<" "<<i;
                return false;
            }
            col[i].insert(num);

            if(row[j].count(num)){
                cout<<"row moment part 2 "<<num<<" "<<j<<" "<<i;
                return false;
            }
            row[j].insert(num);

            int sqr_inx = (j/3)*3 + (i/3);

            if(sqr[sqr_inx].count(num)){
                cout<<"sqr moment part 2 "<<num<<" "<<j<<" "<<i;
                return false;
            }

            sqr[sqr_inx].insert(num);
        }
    }
        
    return true;
    
}


int main(){
    //tests
    vector<vector<vector<char>>> tests = {{{'1','2','.','.','3','.','.','.','.'},
                                 {'4','.','.','5','.','.','.','.','.'},
                                 {'.','9','1','.','.','.','.','.','3'},
                                 {'5','.','.','.','6','.','.','.','4'},
                                 {'.','.','.','8','.','3','.','.','5'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','.','.','.','.','.','2','.','.'},
                                 {'.','.','.','4','1','9','.','.','8'},
                                 {'.','.','.','.','8','.','.','7','9'}}, 
                                 
                                {{'8','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}}} ;

    for(vector<vector<char>> &test: tests){

        cout<<isValidSudoku(test);
        cout<<endl;
    }
}


//PS i did do the method that only checks row wise, however i wanted to try the method of checking upper triangle and lower triangle thinking itd be faster
// it was infact NOT faster :( but i'll keep this one in the repo either way since it runs as fast as the other 