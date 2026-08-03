class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int , int >> adj[n+1];

        for(auto it: times){
            adj[it[0]].push_back({ it[1] , it[2] });

        }
        vector<int> mintimes(n+1  , 1e9 ) ;
        priority_queue< pair<int , int > , vector<pair<int , int>> , greater<pair<int, int >>> pq;

        pq.push( { 0 , k });
        mintimes[0]=0 ;
        mintimes[k]=0 ;

        while(!pq.empty()){
          auto it = pq.top();
          int node = it.second;
          int timetake = it.first;

          pq.pop();

          for( auto i : adj[node] ){
              int adjnode= i.first;
              int time = i.second;

              int newtime = timetake + time ; 

              if( newtime < mintimes[adjnode]){
                 mintimes[adjnode]= newtime ;
                 pq.push( { newtime , adjnode });
              }
            }
        }
         
      int minitime = INT_MIN;
      for( auto time : mintimes){
         if(time== 1e9 )return -1;
         else{
            minitime = max( minitime  , time );
          } 
        }

        return minitime ;

    }
};