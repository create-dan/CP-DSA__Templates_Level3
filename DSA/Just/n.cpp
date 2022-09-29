

// cout << endl;
// can be said equivalent to cout << ‘\n’ << flush;

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
// #define endl "\n"

int32_t main()
{

    auto start = high_resolution_clock::now();

    for (int i = 0; i < 1e6; i++)
    {
        cout << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    return 0;
}
