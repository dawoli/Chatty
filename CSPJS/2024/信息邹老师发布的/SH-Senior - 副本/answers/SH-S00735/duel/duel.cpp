#include<bits/stdc++.h>
using namespace std;
int n,r[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++)
        scanf("%d",&r[i]);
    sort(r+1,r+n+1);
    for(i=1,j=2;j<=n;j++)
        if(r[i]<r[j])i++;
    printf("%d\n",n-i+1);
    return 0;
}