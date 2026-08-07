class cmp{
    public:
    bool operator()( string  a , string b ){\
        if(a.size()== b.size() ){
            return a > b ;
        }

         return a.size() > b.size() ;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
         priority_queue<string , vector<string> , cmp> minheap;

        for( auto num :nums){
            
            minheap.push(num);

            if(minheap.size()>k){
                minheap.pop();
            }
        }
        
        return minheap.top();
    }
};