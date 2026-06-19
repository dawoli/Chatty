/*#include <bits/stdc++.h>
using namespace std;
int t;
int a[11] = {0,0,1,7,4,2,6,8,0,0,0};
int main()
{
    cin>>t;
    while (t--)
    {
        stack <int> s;
        int ans;
        int minn = 1e7;
        int p = 0;
        cin>>ans;
        if (ans<=1)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            bool flag = false;
            int j = 7;
            while (j>=2)
            {
                int num = ans;
                p=0;
                for (int i=j;i>=2;i--)
                {
                    if (i == 6)
                    {
                        while (num-6 >= 2)
                        {
                            s.push(0);
                            num-=6;
                        }
                    }
                    while (num-i>=0)
                    {
                        s.push(a[i]);
                        num-=i;
                    }
                }
                if (num == 0)
                {
                    flag = true;
                    while (!s.empty())
                    {
                        p = p*10+s.top();
                        s.pop();
                    }
                    minn = min(p,minn);
                }
                else
                {
                    while (!s.empty())
                    {
                        s.pop();
                    }
                }
                j--;
            }
            if (flag == false)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                cout<<minn<<endl;
            }
        }
    }
}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if (n<=1)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            string ans = "";
            if (n%6 == 0)
            {
                int h = n/6;
                if (h == 1)
                {
                    cout<<6<<endl;
                }
                else
                {
                    h-=2;
                    cout<<2;
                    for (int i=1;i<=h;i++)
                    {
                        cout<<0;
                    }
                    cout<<8<<endl;
                }
            }
            else
            {
                int h = n/6;
                if (h>=1)
                {
                    if (1+h*6 == n)
                    {
                        h--;
                        cout<<1;
                        for (int i=1;i<=h;i++)
                        {
                            cout<<0;
                        }
                        cout<<2<<endl;
                    }
                    else if (2+h*6 == n)
                    {
                        cout<<1;
                        for (int i=1;i<=h;i++)
                        {
                            cout<<0;
                        }
                        cout<<endl;
                    }
                    else if (3+h*6 == n)
                    {
                        h--;
                        cout<<2;
                        for (int i=1;i<=h;i++)
                        {
                            cout<<0;
                        }
                        cout<<4<<endl;
                    }
                    else if (4+h*6 == n)
                    {
                        cout<<1;
                        for (int i=1;i<=h;i++)
                        {
                            cout<<0;
                        }
                        cout<<1<<endl;
                    }
                    else if (5+h*6 == n)
                    {
                        cout<<2;
                        for (int i=1;i<=h;i++)
                        {
                            cout<<0;
                        }
                        cout<<endl;
                    }
                }
                else
                {
                    if (n == 2)
                    {
                        cout<<1<<endl;
                    }
                    else if (n == 3)
                    {
                        cout<<7<<endl;
                    }
                    else if (n == 4)
                    {
                        cout<<4<<endl;
                    }
                    else if (n == 5)
                    {
                        cout<<2<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
