#include<bits/stdc++.h>
using namespace std;
int n,r[105000];
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&r[i]);
    sort(r+1,r+1+n);
    int l=0;
    for (int i=1;i<=n;i++) {
        if (r[i]>r[l+1]) l++;
    }
    printf("%d\n",n-l);
    return 0;
}
