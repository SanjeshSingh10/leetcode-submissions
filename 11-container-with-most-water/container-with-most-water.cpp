class Solution {
public:
    int maxArea(vector<int>& height) {
       int n= height.size();
       int maxwater = INT_MIN;
       int  leftmax = 0 ; int  rightmax = n-1;

       int water ;

       while( leftmax < rightmax){
          water = min( height[rightmax] , height[leftmax] )*(rightmax-leftmax );
          maxwater = max( maxwater , water);

          if( height[leftmax] < height[rightmax] ) leftmax++ ;
          else if( height[rightmax]  < height[leftmax] ) rightmax-- ;
          else{ leftmax++ ; 
              rightmax--;
          }
       }

       return maxwater ; 
    }
};