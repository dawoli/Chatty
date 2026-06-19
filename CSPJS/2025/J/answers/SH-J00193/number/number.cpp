#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen(number.in,"r",stdin);
    freopen(number.out,"w",stdout);
    string s;
    string num;
    int x;
    cin>>s;
    int len = s.size();
    for(int i = 0;i<len;i++)
    {
        if(isdigit(s[i]))
        {
            num+=s[i];

        }
    }
    int len2 = num.size();
    char c;
    for(long long i = 0 ;i<len2;i++)
    {
        for(long long j = 0;j<i;j++)
        {
            if(num[i]>num[j])
            {
                c=num[i];
                num[i]=num[j];
                num[j]=c;
            }
        }
    }
    cout<<num;
    return 0;
}
