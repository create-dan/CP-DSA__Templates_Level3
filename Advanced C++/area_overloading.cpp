#include <bits/stdc++.h>
using namespace std;

// function overloading
// area function
// cicle and rectangle
// cicle(int) and rectangle(int , int )

//function overloading - compile time overloading
//which version of function wants to bind 
//early binding


float area(int r)
{
    return (3.14 * r * r);
}

int area(int l, int b)
{
    return l * b;
}

int32_t main()
{

    int r;
    cin >> r;

    cout << "Area of circle " << area(r) << endl;

    int l, b;
    cin >> l >> b;

    cout << "Area of rectangle " << area(l, b) << endl;

    return 0;
}
