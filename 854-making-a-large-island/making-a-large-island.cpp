class DisjointSet{
    public:
    vector<int> parent , size ;

    DisjointSet(int n ){
      parent.resize(n);
      size.resize(n,1);

        for(int i =0 ; i<n ; i++)parent[i]=i;

    }
    int findUPar(int node){
        if(parent[node] != node )
             parent[node] = findUPar(parent[node]);

        return parent[node] ;
    }
    
    void unionBySize(int u ,int  v){
        int ulp_u= findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v)return ;
        
        if(size[ulp_u] <size[ulp_v] ){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }  
    }
};
class Solution {
public:
    bool isvalid( int r , int c , int n ){
        if( r >=0 && r<n && c >=0 && c <n   )return true ;

        return false;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int  n = grid.size();

        DisjointSet ds(n*n);
       // step 1 connect components
        for(int i =0 ; i < n ; i++){
            for( int j =0 ; j< n ; j++){
                if(grid[i][j] == 0  )continue;
               
                int drow[] = { -1, 0,1,0 };
                int dcol[] = { 0,-1,0,1 };

                for(int ind = 0 ; ind<4 ; ind++){
                    int nr = i + drow[ind];
                    int nc = j + dcol[ind];

                    if(isvalid(nr , nc , n) && grid[nr][nc]==1 ){
                        int nodeNo = i * n + j;
                        int adjnodeNo = nr*n +nc;
                        ds.unionBySize( nodeNo , adjnodeNo );
                    }
                }

            }
        }
        int mx =0 ;
        for(int i =0 ; i < n ; i++){
            for( int j =0 ; j< n ; j++){
                if(grid[i][j] == 1  )continue;
               
                int drow[] = { -1, 0,1,0 };
                int dcol[] = { 0,-1,0,1 };
                set<int> components;
                for(int ind = 0 ; ind<4 ; ind++){
                    int nr = i + drow[ind];
                    int nc = j + dcol[ind];

                    if(isvalid(nr , nc , n) && grid[nr][nc]==1 ){
                      components.insert(ds.findUPar( nr*n +nc)) ;  
                    }
                }
                int sizetotal=0;
                for(auto it : components){
                  sizetotal += ds.size[it];
                }
                mx= max(mx , sizetotal+1);// +1 is considered for the 0th cell 

            }
        } 

        for( int cellno = 0 ; cellno <n*n ; cellno++){
            mx = max(mx , ds.size[ds.findUPar(cellno)]);
        }
     return mx ;
    }
};