class Solution {
public:
    int countCommas(int n) {
        int totalnos = 0 ;
        if( n == 1000 ) return 1;
        if( n > 1000) totalnos = n-1000 ;
        else{ 
            return 0;
        }
        
      return totalnos + 1 ;
    }
};