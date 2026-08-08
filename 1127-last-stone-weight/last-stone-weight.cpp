class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;
        for(auto it: stones){
            pq.push(it);
        }


        while( pq.size()>1){
            int heavyStone = pq.top();
            pq.pop();
            
            int lightStone = pq.top();
            pq.pop();
            int newstone = heavyStone - lightStone;

            pq.push( newstone);

        }

        return pq.top();
    }
};