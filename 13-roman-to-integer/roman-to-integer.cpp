class Solution {
public:
    void mark(  unordered_map< char , int > &mpp ){
        mpp['I'] = 1 ;
        mpp['V'] = 5 ;
        mpp['X'] = 10 ;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500 ;
        mpp['M'] = 1000 ;

    };
    int romanToInt(string s) {
        unordered_map< char , int > mpp;
        
        mark( mpp );
        int result = 0;
        int n = s.size();
        for( int i = 0 ; i < n ; i++ ){
            if( i +1 < n && mpp[s[i]] < mpp[s[i+1]]  ){
                result -= mpp[s[i]];
            }
            else{
               result+= mpp[s[i]];
            }             
        }
    


      return result ;  
    }
};