class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair< int , pair<int , int >> > maxH ;

        for( auto it : arr ){
            int x = it[0] ;
            int y = it[1];
            int distance = x*x + y*y ;

            maxH.push({ distance , { x , y }});
            
            if( maxH.size()> k ){
                maxH.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxH.empty()){
            auto it = maxH.top();
            maxH.pop();
            int x = it.second.first;
            int y = it.second.second;

            ans.push_back( { x, y});

        }

        return ans;
    }
};