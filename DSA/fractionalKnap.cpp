#include <bits/stdc++.h>
using namespace std;

class Item
{

public:
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;

    return r1 > r2;
}

double
fractionalKnap(int w, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= w)
        {
            w -= arr[i].weight;
            ans += arr[i].profit;
        }
        else
        {
            ans += arr[i].profit * ((double)w / (double)arr[i].weight);
            break;
        }
    }

    return ans;
}

int main()
{
    cout << "Enter the Total Capacity " << endl;
    int w;
    cin >> w;

    // Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    Item arr[] = {{500, 30}};
    int N = sizeof(arr) / sizeof(arr[0]);

    double ans = fractionalKnap(w, arr, N);
    cout << "Maximum value " << ans << endl;
    return 0;
}