#include<bits/stdc++.h>

using namespace std;

long s[128]={};

bool cmp(long a,long b)
{
    return(a>b);
}

int main()
{
    FILE *fp=freopen("seat.in","r",stdin);
    long n,m,sr,i;
    cin>>n>>m;
    long nm=n*m;
    for(i=0;i<nm;i++)
        cin>>s[i];
    fclose(fp);
    sr=s[0];
    sort(s,s+nm,cmp);
    for(i=0;i<nm;i++)
        if(s[i]==sr)
            break;
    fp=freopen("seat.out","w",stdout);
    cout<<((i/n)+1)<<' ';
    if((i/n)%2)
        cout<<(n-(i%n));
    else
        cout<<((i%n)+1);
    fclose(fp);
    return(0);
}
