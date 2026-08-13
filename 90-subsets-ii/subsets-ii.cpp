class Solution {
public:
    void findsubsets( int ind , vector<int>& arr , vector<int>& ds , vector<vector<int>>& ans  ){
    
         ans.push_back( ds );
         
       
       
    
      for( int i = ind ; i < arr.size() ; i++ ){
        
            if( i > ind  && arr[i] == arr[i-1] )continue ;


            ds.push_back( arr[i]);

            findsubsets( i+1 , arr, ds ,ans );

            ds.pop_back();
       }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort( arr.begin() , arr.end() );

        vector<int> ds ;
        vector<vector<int>> ans ; 

        findsubsets( 0 , arr , ds , ans  );

        return ans ;
        
    }
};