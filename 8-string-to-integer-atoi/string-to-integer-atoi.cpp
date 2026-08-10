class Solution {
public:

    long long convert(int i , string &s , int sign , long long ans  ){
        if( i >=s.size() || !isdigit(s[i])){
            return sign*ans;
        }

        int digit = s[i]-'0';

        if(ans > (INT_MAX - digit)/10  ){
            if(sign == -1)
              return INT_MIN;
            else{
                return INT_MAX ;
            }
        }

        ans = ans*10 + digit ;

        return convert( i+1 , s , sign , ans  );

    }

    int myAtoi(string s) {
        int i = 0 ;
        long long n = s.size();

        while( i<n && s[i]==' '){
            i++;
        }
        int sign =1;
        if( i < n && (s[i] == '+' || s[i]== '-' ) ){
            if(s[i]=='-')sign = -1 ;
            i++;
        };

      

        return convert(i , s , sign , 0);
        
    }
};