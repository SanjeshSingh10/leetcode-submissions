class Solution {
public:
    bool find( vector<vector<int>>& mat, int target , int mid ){
        int low = 0  ; int high = mat[0].size() -1 ; 
        while( low <=  high){
            int rowMid = low + (high -low)/2 ;
            if( mat[mid][rowMid] == target  ) return true ;
            else if( mat[mid][rowMid] > target  ) high = rowMid -1 ;
            else{ 
                low= rowMid+1 ;
            }
        }
      return false ;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
       

        for( int i =0 ; i< n ; i++){
            if( mat[i][0] <= target && target <= mat[i][m-1] ){
                bool ans = find(  mat , target , i  );
                if( ans ) return ans ;
            }
        }

       return false;
    }
};