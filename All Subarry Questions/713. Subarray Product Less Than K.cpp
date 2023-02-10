https://leetcode.com/problems/subarray-product-less-than-k/description/


class Solution {
public:

    //sliding window approach
    


    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int n = nums.size();
        if(k==0) return 0;
        int i=0,j=0;
        int pro=1;
         int ans=0;
        while(j<n)
        {
            //10
            pro*=nums[j];
            // cout<<pro<<" ";
          

            while(pro>=k and i<=j)
            {
                pro=pro/nums[i];
                i++;
               
            }
               ans+=(j-i+1);
            //    cout<<ans<<" ";
            j++;

        }
        // cout<<endl;

        return ans;
        
    }
};
