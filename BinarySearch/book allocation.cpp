class Solution {
public:



   bool isValid(vector<int> &nums ,int k , int mid)
   {
       int part=1;
       int sum =0;
       for(int i=0;i<nums.size();i++)
       {
            sum+=nums[i];
            if(sum>mid) {
                part++;
                sum=nums[i];
            }

            if(part>k) return false;
       }

       return true;
   }

    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());

        int s=0,e=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==mx){
                s=mx;
            }

            e+=nums[i];
        }

        int ans =0;


        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(isValid(nums,k,mid)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }


        return ans;
    }
};
