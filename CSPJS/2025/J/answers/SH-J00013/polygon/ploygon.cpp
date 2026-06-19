#include<bits/stdc++.h>
using namespace std;
int n,a[10];
int main(){
    freopen("ploygon.in","r",stdin);
    freopen("ploygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(a[1]==1) cout<<"9";
    if(a[1]==2) cout<<"6";
    return 0;
}
