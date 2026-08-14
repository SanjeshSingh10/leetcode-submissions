class Solution {
public:
    void  findcombinations( int ind , string& arr ,  vector<string>& mpp , string& s  , vector<string>& ans){

        if(ind == arr.size()){
            ans.push_back(s );
            return ;
        }
        int digit = arr[ind] - '0';

        string letters = mpp[digit];

        for( char ch : letters){
           s.push_back(ch);

           findcombinations( ind+ 1, arr , mpp , s , ans);

           s.pop_back();         
 
        }

    }
     
    vector<string> letterCombinations(string arr) {

        vector<string> mpp(10);
        string s = "";
        vector<string> ans ;
          
        
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";

        findcombinations( 0 , arr, mpp , s , ans );

        return ans ;
    }    
};