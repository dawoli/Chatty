#include<bits/stdc++.h>

using namespace std;

bool cmp(long a,long b)
{
    return(a>b);
}

int main()
{
    FILE *fp=freopen("number.in","r",stdin);
    unsigned int i;
    string s;
    vector<long> v;
    cin>>s;
    fclose(fp);
    for(i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            v.push_back(s[i]-48);
    sort(v.begin(),v.end(),cmp);
    fp=freopen("number.out","w",stdout);
    for(i=0;i<v.size();i++)
        cout<<v[i];
    fclose(fp);
    return(0);
}
