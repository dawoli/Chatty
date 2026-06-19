#include <stdio.h>
#include <algorithm>
const int MAXN=1e4+10;// 数据有点水
struct S{
    int s,i;
}a[MAXN];
bool cmp(S a,S b){
    return a.s>b.s;
}
int n,m;
void solve(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n*m;++i){
        scanf("%d",&a[i].s);
        a[i].i=i;
    }
    std::sort(a,a+n*m,cmp);
    int ri=0;
    for (int i=0;i<n*m;++i){
        if (a[i].i==0) ri=i;
    }
    int c=ri/n,r=0;
    if (c&1){
        c+=1;
        r=n-ri%n;
    }else{
        c+=1;
        r=ri%n+1;
    }
    printf("%d %d\n",c,r);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}