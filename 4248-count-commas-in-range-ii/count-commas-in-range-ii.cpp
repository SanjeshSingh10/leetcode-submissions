class Solution {
public:
    long long countCommas(long long n) {
        
       long long ans = 0 ;

       long long start = 1000 ;
       long long cnt = 1 ;

       while( start <= n  ){
            long long end = min( n , start*1000 -1 );
            long long nos = end - start +1 ;

            ans += (nos*cnt) ;
            start *= 1000;

            cnt +=1;
        }

       return ans; 
    }
};