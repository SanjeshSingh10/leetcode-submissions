class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       
       vector<pair<int , int>> adj[n];
       for( auto it: edges){
         adj[it[0]].push_back({ it[1] , it[2] });
         adj[it[1]].push_back({ it[0] , it[2] });
       }
        
       vector<int> cities(n);

       for( int i = 0 ; i< n ; i++){
            int cnt =0 ;
            priority_queue< pair<int , int > , vector< pair< int , int >> , greater<pair<int, int >>  > pq;
            vector<int> dist(n,1e9 );
            pq.push( { 0 , i});
            dist[i]=0;

            while(!pq.empty()){
                auto it = pq.top();
                int node = it.second;
                int distance= it.first;

                pq.pop();

                if( distance > dist[node])continue;

                for(auto neighbour : adj[node]){
                   int adjnode = neighbour.first ;
                   int edW = neighbour.second ;

                   int newDistance = edW + dist[node];

                   if( newDistance < dist[adjnode]){
                      pq.push({ newDistance , adjnode});
                      dist[adjnode]= newDistance;
                   }
                    
                }
            
            }
           for( auto j: dist){
                if( j <= distanceThreshold ){
                            cnt++;
                }
           }
           cities[i]=cnt ;
        } 

        int mincity = INT_MAX; 
        int city;
        for(int i =0 ; i<n ;i++){
            if( cities[i]<= mincity){
                mincity = cities[i];
                city = i;
            }
        }

        return city ;
    }
};