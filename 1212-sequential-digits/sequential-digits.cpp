class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans ;

        for( int i = 1 ; i <= 9 ; i++){
            int p = i ;
            for( int j = i+1 ; j<=9 ; j++){
               p = p*10 + j ;

               if( p >= low && p <= high){
                ans.push_back( p );
               }
            }
        }
        sort(ans.begin() , ans.end());
        
        return ans ;
    }
};