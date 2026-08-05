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
    int removeStones(vector<vector<int>>& stones) {
      int maxrow = 0 ;
      int maxcol=0;
      for( auto it : stones){
        maxrow = max( maxrow , it[0]);
        maxcol = max( maxcol , it[1]);
      }
      DisjointSet ds(maxrow+ maxcol+2);
      unordered_map<int , int> stoneNode;

      for(auto it:stones){
        int u = it[0];
        int v = it[1] + maxrow + 1;

        ds.unionBySize( u , v);
        stoneNode[u]= 1 ;
        stoneNode[v]= 1 ;

      }

      int cnt =0 ;
      for( auto it:stoneNode){
        if(ds.findUPar(it.first)== it.first)
          cnt++;
      }

     return stones.size() -cnt;
    }
};