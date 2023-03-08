#include<bits/stdc++.h> 
using namespace std; 



class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        
        bool prime[n+1];
        memset(prime , true ,sizeof(prime));
        
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==true)
            {
                for(int j=i*i ;j<=n;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        
        vector<int> v;
        for(int i=2;i<=n;i++)
        {
            if(prime[i])
            {
                v.push_back(i);
            }
        }
        
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
