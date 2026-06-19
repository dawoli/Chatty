#include <bits/stdc++.h>

using namespace std;

const int N=100005;
int t;
int n,nn;
struct st
{
    int a;
    int b;
    int c;
    int cl;
}ys[N];
int dfs(int x,int d1,int d2,int d3)
{
    if(x==n){
        int sum=0;
        for(int i=0;i<n;i++){
            if(ys[i].cl==1){
                sum+=ys[i].a;
            }
            if(ys[i].cl==2){
                sum+=ys[i].b;
            }
            if(ys[i].cl==3){
                sum+=ys[i].c;
            }
        }
        return sum;
    }
    int ret=0;
    if(d1<nn){
        ys[x].cl=1;
        int f=dfs(x+1,d1+1,d2,d3);
        ret=max(ret,f);
    }
    if(d2<nn){
        ys[x].cl=2;
        int f=dfs(x+1,d1,d2+1,d3);
        ret=max(ret,f);
    }
    if(d3<nn){
        ys[x].cl=3;
        int f=dfs(x+1,d1,d2,d3+1);
        ret=max(ret,f);
    }
    return ret;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        nn=n/2;
        for(int j=0;j<n;j++){
            cin>>ys[j].a>>ys[j].b>>ys[j].c;
            ys[i].cl=0;
        }
        int sc=dfs(0,0,0,0);
        cout<<sc<<endl;
    }
    return 0;
}
