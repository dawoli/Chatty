#include<bits/stdc++.h>
using namespace std;
string s;
int c, T;

void check(int& ans, string& d, const char& i)
{
    if (d == "bool")
    {
        ans = max(ans, 1);
    }
    else if (d == "char")
    {
        ans = max(ans, 2);
    }
    else if (d == "int")
    {
        ans = max(ans, 3);
    }
    else if (d == "longlong")
    {
        ans = max(ans, 4);
    }
    else if (d == "float")
    {
        ans = max(ans, 5);
    }
    else if (d == "double")
    {
        ans = max(ans, 6);
    }
    d.clear();
    if (i == '+')
    {
        ans = max(ans, 3);
    }
    else if (i == '*')
    {
        ans = max(ans, 3);
    }
    else if (i == ',')
    {
        ans = 0;
    }
}

void solve()
{
    string d;
    int ans = 0;
    for (auto i : s)
    {
        if (i != '*' && i != '+' && i != ',')
        {
            d += i;
        }
        else
        {
            check(ans, d, i);
        }
    }
    check(ans, d, ' ');
    switch (ans)
    {
    case 1:
        cout << "bool\n";
        break;
    case 2:
        cout << "char\n";
        break;
    case 3:
        cout << "int\n";
        break;
    case 4:
        cout << "longlong\n";
        break;
    case 5:
        cout << "float\n";
        break;
    case 6:
        cout << "double\n";
        break;
    default:
        cout << "void\n";
        break;
    }
}

int main()
{
    cin >> c >> T;
    while (T--)
    {
        cin >> s;
        solve();
    }
    cout << endl;
    return 0;
}
