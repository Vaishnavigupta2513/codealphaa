#include<iostream>
#include<vector>
using namespace std;
void printBoard(const vector<vector<int> >& board){
    for(int row=0;row<9;row++){
     for(int col=0;col<9;col++){
        cout<<board[row][col]<<" ";
     }
        cout<<endl;
     
     }
}
bool isValid(const vector<vector<int> >& board,int row,int col,int num){
    for(int i=0;i<9;i++){
        if(board[row][i]==num){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(board[i][col]==num){
            return false;
        }
    }
int startRow =row - row % 3;
int startCol =col - col % 3;
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(board[startRow+i][startCol+j]==num){
            return false;
        }
    }
}
return true;
}
bool solveSudoku(vector<vector<int> >& board){
    int row,col;
    bool emptyCell=false;
    for( row=0;row<9;row++){
    for( col=0;col<9;col++){
        if(board[row][col]==0){
            emptyCell=true;
            break;
        }
    }
    if(emptyCell){
        break;
    }
}
    if(!emptyCell){
        return true;
    }
for(int num=1;num<=9;num++){
    if(isValid(board,row,col,num)){
        board[row][col]=num;
        if(solveSudoku(board)){
            return true;
        }
        board[row][col]=0;
    }
}
return false;
}
void inputBoard(vector<vector<int> >& board){
    cout<<"Enter the Sudoku puzzle :\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
}
int main(){
    vector<vector<int> > board(9,vector<int>(9,0));
    inputBoard(board);
    if(solveSudoku(board)){
        cout<<"Solved Sudoku:\n";
        printBoard(board);
    }else{
        cout<<"No Solution exist for given sudoku.\n";
    }
    return 0;
}