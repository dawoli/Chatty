#include <bits/stdc++.h>

using namespace std;
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);

int t;
int n;
int l[10];
int main()
{
    l[0]=6;
    l[1]=2;
    l[2]=5;
    l[4]=4;
    l[6]=6;
    l[7]=3;
    l[8]=7;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int m=n/7;
        int k=0;
        for(int j=0;j<m;j++){
            k*=10;
            k+=8;
        }
        cout<<k;
    }
    return 0;
}
