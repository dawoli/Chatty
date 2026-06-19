#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct Stu{
    int score,id,aa,bb;
}a[105];
bool cmp(Stu a,Stu b){
    return a.score>b.score;
}
bool cmp2(Stu a,Stu b){
    return a.id<b.id;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                cnt++;
                a[cnt].aa=j;
                a[cnt].bb=i;
            }
        }
        else {
            for(int i=n;i>=1;i--){
                cnt++;
                a[cnt].aa=j;
                a[cnt].bb=i;
            }
        }
    }
    sort(a+1,a+n*m+1,cmp2);
    cout<<a[1].aa<<" "<<a[1].bb;
    return 0;
}
