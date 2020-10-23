//https://leetcode.com/problems/01-matrix/solution/
class Solution {
public:
    typedef pair<int,int> pii;
    vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    pii retSrc(vector<vector<int>>& matrix,int n,int m){
         pii src;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    src={i,j};
                    return src;
                }
                    
            }
    }
        return {-1,-1};
    }
    bool valid(int n,int m,int i,int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    void BFS(vector<vector<int>>& matrix,vector<vector<int>>& res,int n,int m){
      
        queue<pii> q;
        queue<int> rank;
       
        for(int i=0;i<n;++i){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    res[i][j]=0;
                     rank.push(0);
                     q.push({i,j});
                }
                    
            }
    }
        
        
       
        while(!q.empty()){
            pii cur=q.front();
            q.pop();
            int rank_=rank.front();
            rank.pop();
            for(int d=0;d<dir.size();++d){
                int i=dir[d].first+cur.first, j=dir[d].second+cur.second;
                int cur_rank;
                if(!valid(n,m,i,j)) continue;
                
                if(matrix[i][j]==1 && res[i][j]>rank_+1){
                    res[i][j]=rank_+1;
                    cur_rank=rank_+1;
                    q.push({i,j});
                rank.push(cur_rank);
                }
                
                
            }
        }
        
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m = n>0 ? matrix[0].size() : 0;
        vector<vector<int>> res(n,vector<int>(m,n*m));
        if(n==0||m==0)
            return res;
        
        BFS(matrix,res,n,m);
       
        return res;
        
    }
};
