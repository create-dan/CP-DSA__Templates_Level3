//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
   
   
    //sort according to the maximum profit
    //deadline pai javo and id dal do (last deadline)
    //check from deadline if there is allready job id present , do deadline-- and check again
    //
   
   
    static bool cmp(Job a , Job b){
        return a.profit > b.profit;
    }
   
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx = max(mx,arr[i].dead);
        }
        
        
        int slot[mx+1];
        memset(slot,-1,sizeof(slot));
      
        
        int cnt=0, sum=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1){
                    slot[j]=i;
                    cnt++;
                    sum+=arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(sum);
        
        
        return ans ;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
