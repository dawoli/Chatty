#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

char t[1000010];

bool cmp(char a , char b)
{
    return a > b;
}

int main()
{
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    string s;
    cin >> s;
    //cout << s << endl;
    int sz = 0;
    for (int i = 0; i < s.size(); i++)
    {
        //printf("%d %d[%c] %d\n" , int('0') , int(s[i]) , s[i] , int('9'));
        if (s[i] >= '0' && s[i] <= '9')
        {
            t[++sz] = s[i];
            //printf("t[%d]=%c\n" , sz , s[i]);
        }
    }
    //cout << endl;
    //cout << t + 1 << endl;
    sort(t + 1 , t + sz + 1 , cmp);
    //cout << t + 1 << endl;
    for (int i = 1; i <= sz; i++)
    {
        cout << t[i];
    }
    cout << '\n';
    return 0;
}
