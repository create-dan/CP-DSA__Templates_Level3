// operator overlaoding
#include <bits/stdc++.h>
using namespace std;

class Marks
{
    int intMarks;
    int extMarks;

public:
    Marks()
    {
        intMarks = 0;
        extMarks = 0;
    }

    Marks(int a, int b)
    {
        intMarks = a;
        extMarks = b;
    }

    void display()
    {
        cout << intMarks << " " << extMarks << endl;
    }

    Marks operator+(Marks m)
    {
        Marks temp;
        temp.intMarks = intMarks + m.intMarks;
        temp.extMarks = extMarks + m.extMarks;
        return temp;
    }
};

int32_t main()
{

    Marks m1(10, 20);
    Marks m2(20, 30);

    Marks m3 = m1 + m2;
    m3.display();
    // output-- > 30 50

        return 0;
}