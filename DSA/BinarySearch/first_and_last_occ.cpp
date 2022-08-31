#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int key)
{
    // Write your code here
    int ans = -1;
    int start = 0, end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    pair<int, int> p;
    while (start <= end)
    {
        //         cout<<"sol;"<<endl;
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    //     cout<<"ans 1 is "<<ans<<endl;
    p.first = ans;
    ans = -1;

    start = 0;
    end = arr.size() - 1;
    mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    p.second = ans;
    return p;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        
    }

    return 0;
}