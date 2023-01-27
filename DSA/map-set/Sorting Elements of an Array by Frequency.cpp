//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    
    static bool  cmp(pair<int,int> p1, pair<int,int> p2)
    {
        if(p1.second==p2.second) return p1.first<p2.first;
        return p1.second > p2.second;
    }
    
    
    vector<int> sortByFreq(int arr[],int n)
    {
       map<int,int> mp1,mp2;
       for(int i=0;i<n;i++) mp1[arr[i]]++;
     
    //   for(auto i : mp1)
    //   {
    //       cout<<i.first<<" "<<i.second<<endl;
    //   }
    //   cout<<"after sort"<<endl;
      
    //   sort(mp1.begin(),mp1.end(),cmp);
      
    //     for(auto i : mp1)
    //   {
    //       cout<<i.first<<" "<<i.second<<endl;
    //   }
    
       int sz = mp1.size();
       pair<int,int> p[sz];
       int i=0;
       for(auto it=mp1.begin();it!=mp1.end();it++)
       p[i++]=make_pair(it->first,it->second);
       
       sort(p,p+sz,cmp);
       vector<int> ans;
       for(auto i : p)
       {
           while(i.second--)
           {
               ans.push_back(i.first);
           }
       }
       
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends
