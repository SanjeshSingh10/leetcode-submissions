class Solution {
public:
    bool dfs( int ind , int row , int col , vector<vector<char>>& mat ,  string& word){
          
        if( ind == word.size()){
            return true;
        }  
        if( row < 0  || row >= mat.size() || col<0 || col >= mat[0].size() ||   mat[row][col] != word[ind]  ) return false ;

        
         
        char  temp = mat[row][col];
        mat[row][col] = '#' ;
        bool found =  dfs( ind +1 , row , col-1 , mat , word ) ||
                     dfs( ind +1 , row , col+1 , mat , word )||
                     dfs( ind +1 , row-1, col , mat , word )||
                     dfs( ind +1 , row+1 , col, mat , word );
         
        mat[row][col] = temp;

        return found; 

    }

    bool exist(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();

       

        for(int i =0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if( mat[i][j] == word[0] ){
                    if( dfs( 0 , i , j , mat , word ) ){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};