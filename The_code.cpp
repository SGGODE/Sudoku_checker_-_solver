#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

//The_checker
//int n,m;
  bool check(vector<vector<char>>& board,int start,int end){
        map<int,int>mapfirst;
        map<int,int>mapsecond;
        map<int,int>mapthired;
        for(int i=start;i<end;i++){
           for(int j=0;j<3;j++){
                if(board[i][j]=='.')continue;
               if(mapfirst.find(board[i][j])!=mapfirst.end()){
                   //cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapfirst[board[i][j]]++;
           }
           for(int j=3;j<6;j++){
                if(board[i][j]=='.')continue;
               if(mapsecond.find(board[i][j])!=mapsecond.end()){
                  // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapsecond[board[i][j]]++;
           }
           for(int j=6;j<9;j++){
                if(board[i][j]=='.')continue;
               if(mapthired.find(board[i][j])!=mapthired.end()){
                  // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapthired[board[i][j]]++;
           }
        }
       return 1;
    }
bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            map<int,int>mp;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(mp.find(board[i][j])!=mp.end()){
                    //cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                    return 0;
                }
                mp[board[i][j]]++;
            }map<int,int>mpcol;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                if(mpcol.find(board[j][i])!=mpcol.end()){
                   // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                    return 0;
                }
                mpcol[board[j][i]]++;
            }
        }
        if(!check(board,0,3)){
            return 0;
        }
        if(!check(board,3,6)){
            return 0;
        }
        if(!check(board,6,9))return 0;
        return 1;
    }
//The_solver
bool valid(int i,int j,vector<vector<char>>& grid,char c){
        for(int k=0;k<9;k++){
            if(grid[i][k]==c)return 0;
            if(grid[k][j]==c)return 0;
            if(grid[3*(i/3)+k/3][3*(j/3)+k%3]==c)return 0;
        }
        return 1;
    }
bool solve(vector<vector<char>>& grid){
      for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
              if(grid[i][j]=='.'){
                  for(char k='1';k<='9';k++){
                      if(valid(i,j,grid,k)){
                          grid[i][j]=k;

                      if(solve(grid)==1)
                          return 1;
                      else
                          grid[i][j]='.';
                      }
                  }
                  return 0;
              }
          }
      }
        return 1;
    }
signed main (){
      //cin>>n>>m;
      vector<vector<char>>grid(9,vector<char>(9,'-1'));
      // enter 1 to 9 for valid input or "." for empty
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          cin>>grid[i][j];
        }
      }
      if(isValidSudoku(grid)){
        cout<<"It is a Valid Sudoku and its answer is:-"<<endl;
        solve(grid);
        for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
            cout<<grid[i][j]<<" ";
          }cout<<endl;
        }
      }else{
        cout<<"Please Enter A Valid Sudoku"<<endl;
      }
      return 0;
    }
