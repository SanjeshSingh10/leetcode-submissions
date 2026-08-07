
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort( nums.begin(), nums.end() , []( const string& a , const string& b){
            int m = a.size() ; int n = b.size();

            return m !=n ? m > n : a > b;
        });

        return nums[ k -1];
    }
};