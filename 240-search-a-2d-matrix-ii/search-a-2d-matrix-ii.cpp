class Solution {
public:
   
    bool searchMatrix(vector<vector<int>>& mat, int target) {
       int n = mat.size();
       int m = mat[0].size();
        
        int x= 0 ; int y = m-1 ;

        while( x< n && y >=0){
            int cur = mat[x ][y];

            if( mat[x][y] > target) y--;
            else if ( mat[x][y] < target ) x++;
            else return true;

        }
       
       return false;
    }
};