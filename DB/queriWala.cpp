// An array is given (indexing starts with 1) of size S and N number of queries is given by user N(i)= (M P R); 1<=i<=N. Print the Rth minimum element from the array after updating Mth index.
// Example: – Array: [2, 4, 6, 1, 7], S=5

// Queries: N=3

// 2 5 3

// 5 3 2

// 4 8 4

// Output: – 5 2 6

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {2, 4, 6, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int queries;
    cin >> queries;

    while (queries--)
    {
        int N, X, K;
        cin >> N >> X >> K;

        vector<int> subarray(arr + X, arr + X + N);
        sort(subarray.begin(), subarray.end());

        cout << subarray[K - 1] << " ";
    }

    return 0;
}
