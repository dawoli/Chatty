#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
};
bool cmp(node x,node y){
    return x.a>y.a;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r;
    cin>>c>>r;
    int n=c*r;
    vector<node> a(n);
    vector<node> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i].a;
        if(i==0) a[i].b=1;
        else a[i].b=0;
    }

    int z=0;
    for(int i=1;i<=r;i++){
        if(i%2!=0){
            for(int j=1;j<=c;j++){
                b[z].a=i;
                b[z].b=j;
                z++;
            }
        }else{
            for(int j=c;j>=1;j--){
                b[z].a=i;
                b[z].b=j;
                z++;
            }
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        if(a[i].b==1){
            cout<<b[i].a<<" "<<b[i].b;
            return 0;
        }
    }
    return 0;
}
