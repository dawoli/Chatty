#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int>q;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
            int num=s[i]-'0';
            q.push(num);
        }
    }
    while (!q.empty())
    {
        int num=q.top();
        q.pop();
        char c=num+'0';
        putchar(c);
    }
    putchar('\n');
    return 0;
}