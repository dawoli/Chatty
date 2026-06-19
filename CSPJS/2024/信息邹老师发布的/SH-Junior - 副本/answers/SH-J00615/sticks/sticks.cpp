#include<iostream>
#include<fstream>
using namespace std;
int a[]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int b[]={888,108,188,200,208,288,688};
void solve(){
    int n;
    scanf("%d",&n);
    if(n<15)
        printf("%d",a[n]);
    else{
        printf("%d",b[n%7]);
        for(int i=0;i<(n-1)/7-2;i++)
            printf("8");
    }
    printf("\n");
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}