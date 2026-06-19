#include<bits/stdc++.h>
using namespace std; int a[100010];
int main(){
    freopen("duel.in","r",stdin); freopen("duel.out","w",stdout);
    int n,s=1; scanf("%d",&n); a[n+1]=1e9;
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) if(a[i]>a[s]) ++s;
    printf("%d\n",n+1-s); return 0;
}