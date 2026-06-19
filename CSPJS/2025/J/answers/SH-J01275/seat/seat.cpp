#include<bits/stdc++.h>
using namespace std;
struct s{
    int id;
    int score;
};
s a[110];
bool cmp(s a,s b){
    return a.score>b.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        a[i].id=i;
        cin >> a[i].score;
    }
    sort(a+1,a+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for (int j=1;j<=n;j++){
                if (a[++cnt].id==1){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
        else{
            for (int j=n;j>=1;j--){
                if (a[++cnt].id==1){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
}
