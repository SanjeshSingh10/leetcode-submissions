class Solution {
public:
    int countGoodRotations(vector<int>& arr) {
        int n = arr.size();
        int half = n/2 ;

        long long first = 0 ;
        long long total = 0;

        for( int i= 0 ; i< n ; i++){
            total = total + arr[i];

            if( i < half) first += arr[i];
            
        }

        int ans = 0 ;

        for( int j = 0 ; j < n ; j++){
            if( 2* first >  total ) ans++;
            first = first - arr[j] + arr[(j+half)%n];
        }
  return ans;
        
    }
};