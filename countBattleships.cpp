//https://leetcode.com/problems/battleships-in-a-board/submissions/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int n=board.size(),m=n>0?board[0].size():0;
        if(m==0 || n==0) return 0;
        int res=0;
        bool cont=false;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;++col){
                if(!cont && board[row][col]=='X'){
                    if(row<n-1){
                        if(board[row+1][col]=='X')continue;
                    } 
                    if(row>0) {
                       if(board[row-1][col]=='X') continue;
                    }
                    
                    cont=true;
                    res++;
                    
                }
                if(cont &&  (board[row][col]=='.' || col==m-1)){
                    cont=false;
                }
            }
        }
        cont=false;
        for(int col=0;col<m;++col){
            for(int row=0;row<n;row++){
                if(!cont && board[row][col]=='X'){
                    if(row<n-1 && board[row+1][col]=='X'){
                        cont=true;
                         res++;
                    }
                }
                if(cont && ( board[row][col]=='.' || row==n-1)){
                    cont=false;
                }
            }
        }
        return res;
    }
};
