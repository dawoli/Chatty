#include <bits/stdc++.h>
using namespace std;

string s[200010][3];
char aa[200010][3];
char bb[200010][3];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++)
    {
        cin >> s[i][1] >> s[i][2];
        if (s[i][1][0] == s[i][1][1])
        {
            aa[i][1] = s[i][1][0];
        }
        else
        {
            aa[i][1] = s[i][1][2];
        }
        for (int j = 1;j < s[i][1].size();j++)
        {
            if (s[i][1][j] != aa[i][1])
            {
                bb[i][1] = s[i][1][j];
            }
        }
        if (s[i][2][0] == s[i][2][1])
        {
            aa[i][2] = s[i][2][0];
        }
        else
        {
            aa[i][2] = s[i][2][2];
        }
        for (int j = 1;j < s[i][2].size();j++)
        {
            if (s[i][2][j] != aa[i][2])
            {
                bb[i][2] = s[i][2][j];
            }
        }
    }
    while (q--)
    {
        string t1,t2;
        cin >> t1 >> t2;
        char a,b;
        if (t1[0] == t1[1])
        {
            a = t1[0];
        }
        else
        {
            a = t1[2];
        }
        for (int i = 1;i < t1.size();i++)
        {
            if (t1[i] != a)
            {
                b = t1[i];
            }
        }
        char a2,b2;
        if (t2[0] == t2[1])
        {
            a2 = t2[0];
        }
        else
        {
            a2 = t2[2];
        }
        for (int i = 1;i < t2.size();i++)
        {
            if (t2[i] != a2)
            {
                b2 = t2[i];
            }
        }
        int cnt = 0;
        for (int i = 1;i <= n;i++)
        {
            if (aa[i][1] == a && bb[i][1] == b && aa[i][2] == a2 && bb[i][2] == b2)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
