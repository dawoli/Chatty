#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int mark=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    int goal;
    for(int i=1;i<=n*m;i++){
        if(a[i]==mark){
            goal=i;
            break;
        }
    }
    int c=(goal-1)/n+1;
    int flag=0;
    for(int i=1;i<=n;i++){
        if(goal>n*i&&goal<=n*(i+1)){
            if(n*(i+1)%2==0){
                flag=1;
            }
            else flag=0;
            break;
        }
    }
    int r;
    if(!flag){
        if(goal%m==0){
            r=m;
        }
        else{
            r=goal%m;
        }
    }
    else{
        if(goal%m==0){
            r=1;
        }
        else{
            r=goal%m;
        }

    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
