#include<bits/stdc++.h>
using namespace std;
int n,ans,l,a[200009];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1);
    l=1;
    ans=n;
    for(int i=1;i<=n;i++){
        while(l<=n&&a[l]<=a[i])l++;
        if(l<=n){
            ans--;
            l++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
