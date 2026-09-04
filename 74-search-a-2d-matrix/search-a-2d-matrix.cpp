class Solution {
public:
    bool rowBS( vector<vector<int>>& mat , int mid , int low ,int high , int target ){
        
        while( low <=  high){
            int rowMid = low + (high -low)/2 ;
            if( mat[mid][rowMid] == target  ) return true ;
            else if( mat[mid][rowMid] > target  ) high = rowMid -1 ;
            else{ 
                low= rowMid+1 ;
            }
        }
      return false ;
    };

    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0; int high = n-1 ;

        while( low <= high ){

            int mid = low + (high -low)/2 ;

            if( mat[mid][m-1] == t ){
                return true ;
            }
            else if(  t < mat[mid][ m-1 ]   ){
                if( t >= mat[mid][0]  ){
                    return rowBS( mat , mid , 0 , m-1 , t );
                }
                else{
                    high = mid -1;
                }
            } 
            else{
                low = mid +1 ;
            };
        }

        return false;
    }
};