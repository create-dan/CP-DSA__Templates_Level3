#include <bits/stdc++.h>
using namespace std;

// time
// hour , min , second (4:30:35)
// setTime , showTime , normalize
// normalize - > 4:100:100 -->    5:41:40

class Time
{
private:
    int HR, MIN, SEC;

public:
    void setTime(int h, int m, int s)
    {

        HR = h;
        MIN = m;
        SEC = s;
    }

    void showTime()
    {

        cout << HR << ":" << MIN << ":" << SEC << endl;
    }

    void normalize()
    {
        MIN = MIN + SEC / 60;
        SEC = SEC % 60;
        HR = HR + MIN / 60;
        MIN = MIN % 60;
    }
};

int32_t
main()
{
    Time t1;
    t1.setTime(4, 100, 100);
    t1.showTime();
    t1.normalize();
    t1.showTime();

    return 0;
}
