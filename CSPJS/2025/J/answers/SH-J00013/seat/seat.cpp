#include<bits/stdc++.h>
using namespace std;
int n,m,xn,d;
int a[100],b[100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    xn=a[1];
    sort(a+1,a+n+1);
    int js=0;
    for(int i=n*m;i>=1;i--){
        js++;
        b[js]=a[i];
    }
    for(int i=1;i<=n*m;i++) if(a[i]==xn) d=i;
    printf("%d %d",m*n%m+1,m*n%m+2);
    return 0;
}
