class Solution {
public:
   
   //regular express matching jaisa
   //? -> any single character 
   //* -> any sequence of characters
   //https://www.youtube.com/watch?v=OgovJ9CB0hI&ab_channel=CodeHelp-byBabbar


   
   

   bool helper(string &s , string &p , int i , int j , vector<vector<int>> &dp)
   {
       if(i<0 and j<0){
           return true;
           
       }


       if(i>=0 and j<0) return false;

       if(i<0 and j>=0)
       {
           for(int k=0;k<=j;k++)
           {
               if(p[k]!='*') return false;
           }
           return true;
       }


       if(dp[i][j]!=-1) return dp[i][j];


       if(s[i]==p[j] || p[j]=='?'){
           return dp[i][j] = helper(s,p,i-1,j-1,dp);
       }
       else if(p[j]=='*')
       {
           return dp[i][j] =( helper(s,p,i-1,j,dp) || helper(s,p,i,j-1,dp));
       }
       else {
           return false;
       }
   }

    bool isMatch(string s, string p) {
        
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return helper(s,p,n-1,m-1,dp);
    }
};
