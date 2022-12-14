#include <iostream>
#include <string>
#include <ctime>
using namespace std;
//時間類
class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    //設置時間
    void set(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    //時間走一秒,時分秒的變化情况
    void next()
    {
        if (second < 59)
            second++;
        else if (minute < 59)
        {
            second = 0;
            minute++;
        }
        else if (hour < 23)
        {
            minute = 0;
            hour++;
        }
        else
            hour = 0;
    }
    //得到時間
    int get()
    {
        return hour * 10000 + minute * 100 + second;
    }
};
//時鐘類
class Clock
{
private:
    Time now;
    Time ring_time;

public:
    //對表，設定初始時間
    void adjust_now(int h, int m, int s)
    {
        now.set(h, m, s);
        cout << "现在的时间是：" << h << "时" << m << "分" << s << "秒" << endl;
    }
    //設定鬧鈴時間
    void adjust_ring(int h, int m, int s)
    {
        ring_time.set(h, m, s);
        cout << "闹铃时间是：" << h << "时" << m << "分" << s << "秒" << endl;
    }
    //時間過一秒
    void tick()
    {
        long int old = time(0);
        while (time(0) == old)
            ;
        now.next();
    }
    //顯示當前時間
    void showtime()
    {
        cout << now.get() << endl;
    }
    //時鐘開始走時,等到了鬧鈴時間，開始響
    void run()
    {
        do
        {
            tick();
            showtime();
            if (now.get() >= ring_time.get())
            {
                cout << '\a';
                break;
            }
        } while (1);
    }
};

int main()
{

    Clock c;
    int h, m, s, hr, mi, se;
    cin >> h >> m >> s >> hr >> mi >> se; //使用者要先自行輸入起始時間(h、m、s)和鬧鈴時間(hr、mi、se)
    c.adjust_now(h, m, s);                //起始時間
    c.adjust_ring(hr, mi, se);            //鬧鈴時間

    c.run();
    srand(time(NULL));
    cout << "1.Get up、2.Keep sleeping:";
    int a;
    cin >> a; //a 為使用者輸入的數字
    if (a == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "趕快起床,再賴床你試試看!" << '\a' << endl;
        }

        char lucky[7][100] = {"Pupu💩", "Diamond💎", "Lipstick💄", "Necklace📿", "A bag of money💰", "Love letters💌", "Flying money💸"};
        /* 指定亂數範圍 */
        int min = 0;
        int max = 6;
        /* 產生 [min , max] 的整數亂數 */
        int x = rand() % (max - min + 1) + min;

        if (x == 0)
        {
            cout << "Your lucky item today is : " << lucky[0] << endl;
            cout << "Please be careful not to step on the shit while walking today!" << endl;
        }
        else if (x == 4)
        {
            cout << "Your lucky item today is : " << lucky[4] << endl;
            cout << "Hurry up and buy lotto!" << endl;
        }
        else if (x == 5)
        {
            cout << "Your lucky item today is : " << lucky[5] << endl;
            cout << "Your destiny is coming!" << endl;
        }
        else if (x == 6)
        {
            cout << "Your lucky item today is : " << lucky[6] << endl;
            cout << "Be optimistic about your money, don't let it lose!" << endl;
        }
        else
        {
            cout << "Your lucky item today is : " << lucky[x] << endl;
        }
    }
}
