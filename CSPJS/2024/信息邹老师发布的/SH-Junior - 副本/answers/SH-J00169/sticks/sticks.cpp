#include <iostream>
using namespace std;
int T, n, turn=1;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    for (int i=1; i<=T; i++)
    {
        turn =1;
        cin >> n;
        if (n<=1) cout << -1;
        else
        {
            int digit = (n-n%7)/7, remain=n%7, sticksLeft=n;
            while (sticksLeft>0)
            {
                remain = sticksLeft%7;
                if (sticksLeft<=7)
                {
                    if (sticksLeft==2)
                    {
                        cout << 1;
                        sticksLeft -= 2;
                    }
                    else if (sticksLeft==3)
                    {
                        cout << 7;
                        sticksLeft-=3;
                    }
                    else if (sticksLeft==4)
                    {
                        cout << 4;
                        sticksLeft-=4;
                    }
                    else if (sticksLeft==5)
                    {
                        cout << 2;
                        sticksLeft -=5;
                    }
                    else if (sticksLeft==6 && turn == 1)
                    {
                        cout << 6;
                        sticksLeft-=6;
                    }
                    else if (sticksLeft==6 && turn !=1)
                    {
                        cout << 0;
                        sticksLeft-=6;
                    }
                    else if (sticksLeft == 7)
                    {
                        cout << 8;
                        sticksLeft -= 7;
                    }
                }
                else
                {
                if (turn == 1)
                {
                    if (remain == 0)
                    {
                        cout << 8;
                        sticksLeft -=7;
                    }
                    else if (remain == 1 || remain ==2)
                    {
                        cout << 1;
                        sticksLeft -= 2;
                    }
                    else if (remain ==3 || remain==4 || remain==5)
                    {
                        cout << 2;
                        sticksLeft-=5;
                    }
                    else if (remain == 6)
                    {
                        cout << 6;
                        sticksLeft -=6;
                    }
                    turn++;
                }
                else
                {
                    if (remain == 0)
                    {
                        cout << 8;
                        sticksLeft -= 7;
                    }
                    else
                    {
                        cout << 0;
                        sticksLeft -= 6;
                    }
                }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
