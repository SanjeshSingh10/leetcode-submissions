class Twitter {
public:
    // here we store the userid-> following 
    unordered_map< int , unordered_set<int>> following ;
     
    // here we store the userid->{ timestamp , tweetid}
    unordered_map< int , vector<pair<int , int>>  >  tweets ;
  
    int time = 0 ;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
      time++ ;

      tweets[userId].push_back( { time , tweetId }); 
        
    }
    
    
    
    void follow(int followerId, int followeeId) {

        following[followerId].insert(followeeId); 
        
    }
    
    void unfollow(int followerId, int followeeId) {

        following[followerId].erase( followeeId );
        
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans ;

        priority_queue< tuple< int , int , int , int > > pq ;
        
        // first take the user itself 
        if(!tweets[userId].empty()){
          
          int index = tweets[userId].size() -1;

          auto [ t , tweet ] = tweets[userId][index];

          pq.push({ t , tweet , userId , index});

        }
        // now the followers that user follows 
        for(auto follower: following[userId]  ){

            if(!tweets[follower].empty()){
                int index = tweets[follower].size() -1 ;

                auto [ t, tweet ] = tweets[follower][index];

                pq.push( { t, tweet , follower , index});
                
            }

           

        }

        // now priority queue has all tweets of user now we want just the 10 recently tweeted
        while(!pq.empty() && ans.size()< 10){
           auto [ t, tweet , user , index] = pq.top();

           pq.pop();

           ans.push_back( tweet);

           index--;
           // tweet never gets empty so we check index is there or not 
           if(index>=0){
             
             auto [ time , tweetid]= tweets[user][index];

             pq.push( { time , tweetid, user , index});

           }

        }
        return ans ;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */