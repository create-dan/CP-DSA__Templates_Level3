

class Solution
{
    public:
    
    void bubbleSort(int arr[], int n)
    {
       
        int cnt =1;
        while(cnt<n)
        {
            for(int i=0;i<n-cnt;i++)
            {
                if(arr[i]>arr[i+1])
                {
                    swap(&arr[i] , &arr[i+1]);
                }
                
                
            }
            cnt++;
        }
        
        return ;
    }
};
