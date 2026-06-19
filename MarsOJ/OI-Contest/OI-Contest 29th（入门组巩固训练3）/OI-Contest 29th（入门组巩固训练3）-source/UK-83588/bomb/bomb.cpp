#include<bits/stdc++.h>
using namespace std;
int n,t,m,vis[1005][1005],d[4][2]={0,1,0,-1,1,0,-1,0};
string s[1005];
struct node{
    int x,y,h;
};
queue<node> q;
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)cin>>s[i];
        if(n==1){
            int sum=0;
            for(int i=0;i<int(s[0].size());i++){
                if(s[0][i]=='$')sum++;
            }
            cout<<sum<<' '<<m-1<<endl;
            continue;
        }
    }
    return 0;
}
