#include <iostream>
using namespace std;
int main(){
	int n;
    cout<<"Enter board dimantion :\t";   cin>>n;
    int board[9][9]={0}; // 0 = empty , 1 = x , 2 = o
    int row_num[20],col_num[20],increase_row[20],increase_col[20];
    int verify=0;
    // Add rows 
    for(int r=0;r<n;r++)
        row_num[verify]=r ,col_num[verify]=0 ,    increase_row[verify]=0 , increase_col[verify++]=1;
        //row_num     =[0,1,2,3,4,5,6,7,8]   col_num      =[0,0,0,0,0,0,0,0,0] (if n==9)
        //increase_row=[0,0,0,0,0,0,0,0,0]   increase_col =[1,1,1,1,1,1,1,1,1]
    //Add columns
    for(int c=0;c<n;c++)
        row_num[verify]=0 ,col_num[verify]=c ,    increase_row[verify]=1 , increase_col[verify++]=0;
        //row_num       =[0,1,2,3,4,5,6,7,8,0,0,0,0,0,0,0,0,0]  col_num     =[0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8] 
		//increase_row  =[0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1]  increase_col=[1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0]
    //Add left diagonal 
    row_num[verify]=0 ,col_num[verify]=0 ,increase_row[verify]=1 ,increase_col[verify++]=1;
        //row_num       =[0,1,2,3,4,5,6,7,8,0,0,0,0,0,0,0,0,0,0]  col_num     =[0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,0] 
		//increase_row  =[0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1]  increase_col=[1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1]
    //Add right diagonal
    row_num[verify]=0 ,col_num[verify]=n-1 ,increase_row[verify]=1 ,increase_col[verify++]=-1;
        //row_num       =[0,1,2,3,4,5,6,7,8,0,0,0,0,0,0,0,0,0,0,0]  col_num     =[0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,0,8] 
		//increase_row  =[0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1]  increase_col=[1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,-1]
    bool turn=0; // 0 for x turn , 1 for o turn 
    int turns=0;
    while(true){
        if(turn == n*n){
            cout<<"Tie !";
            break;
        }
        char sympol = 'x';
        if(turn){
            sympol='o';
        }
        cout<<"Player "<<sympol<<" turn . Enter empty location :"<<endl;
        int r,c;
        cin>>r>>c;
        r-=1,c-=1;
        if(r<0 || r>=n || c<0 || c>=n || board[r][c]!=0){
            cout<<"Invalid input . Try again"<<endl;
            continue;
        }
        board[r][c]=turn+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                    cout<<'x'<<" ";
                else if(board[i][j]==2)
                    cout<<'o'<<" ";
                else
                    cout<<'.'<<" ";
                if(j+1==n)
                    cout<<endl;
            }
        }
        //check win
        for(int check=0;check<verify;check++){
            int r = row_num[check] , c = col_num[check] , ic_r = increase_row[check] , ic_c = increase_col[check];
            int cnt = 0 , first = board[r][c];
            if(first==0)
                continue;
            for(int steps=0;steps<n; steps++ , r+=ic_r , c+=ic_c)
                cnt += (first == board[r][c]);
            if(cnt == n){
                cout<<"Player "<<sympol<<" won !!"<<endl;
                return 0;
            } 
        }
        turn=!turn;
        ++turns;
    }
	return 0;
}