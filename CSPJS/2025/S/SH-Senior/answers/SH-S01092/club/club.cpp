#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a[500005][5],b[500005];
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 3; j++){
                scanf("%d",&a[i][j]);
                if(j == 1) b[i] = a[i][j];
            }
        }
        sort(b+1,b+n+1,cmp);
        int ans = 0;
        for(int i = 1; i <= n/2; i++){
            ans += b[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
