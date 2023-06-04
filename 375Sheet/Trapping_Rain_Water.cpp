

//Revised

#include<bits/stdc++.h>

using namespace std;



class Solution{

    // Function to find the trapped water between the blocks.
    public:
    //#SD
    //left and right prefix and suffix array banao 
    //https://www.youtube.com/watch?v=m18Hntz4go8&ab_channel=takeUforward
    
    long long trappingWater(int arr[], int n){
        // code here
        
        long long int left[n],right[n];
         int curr=arr[0];
        left[0]=curr;
        for( int i=1;i<n;i++)
        {
            curr=max(curr,arr[i]);
            left[i]=curr;
        }
        
        curr=arr[n-1];
        right[n-1]=curr;
        for( int i=n-2;i>=0;i--)
        {
            curr=max(curr,arr[i]);
            right[i]=curr;
        }
        
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(left[i],right[i]);
            ans-=arr[i];
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
