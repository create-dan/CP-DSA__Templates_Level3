
// https : // www.hackerearth.com/problem/algorithm/free-walk-0f675f40-0d59a400/

#include <iostream>
        using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int currA = 0, currC = 0;

        int mxA = 0, mxC = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                currA++;
                currC--;
            }
            else if (s[i] == 'C')
            {
                currC++;
                currA--;
            }
            else
            {
                currA++;
                currC++;
            }

            mxA = max(mxA, currA);
            mxC = max(mxC, currC);
        }

        cout << max(mxA, mxC) << endl;
    }
}