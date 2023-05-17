class Solution {
public:
//#Striver Sheet
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(i,0);
            ans.push_back(curr);
        }

        // for(int i=0;i<ans.size();i++)
        // {
        //     for(int j=0;j<ans[i].size();j++)
        //     {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        
        for(int i=0;i<n;i++)
        {
           
            
            for(int j=0;j<=i;j++)
            {
                 if(j==0 || j==i)
                 {
                     ans[i][j]=1;
                 } 
                 else
                 {
                     ans[i][j]=ans[i-1][j] + ans[i-1][j-1];
                 }
            }



          
        }

        return ans;
    }
};
