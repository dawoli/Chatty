#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,sum=0;
int dx[6],dy[6],vis[1002][1002];
string a[1002];
void dfs(int x,int y,int d,int lv){
    if(vis[x][y]==0){
        vis[x][y]=1;
        sum++;
    }
    if(lv==k){
        return;
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<=m&&xx>=1&&yy<=n&&yy>=1&&a[xx][yy]=='.'){
            dfs(xx,yy,i,lv+1);
        }else{
            k++;
        }
    }
}
void check(int m,int x,int y,int d){
    y--; m--;
    int ans=1,cnt=0;
    string s; cin>>s;
    if(d==3||d==1) cnt++;
    if(d==0){
        for(int i=x+1;i<=m;i++){
            if(s[i]=='.'){
                ans++;
                cnt++;
            }
            else{
                cnt+=2;
                break;
            }
            if(cnt>=k){
            cout<<ans<<endl;
            return;
            }
        }
        cnt+=ans-1;
        if(cnt>=k){
            cout<<ans<<endl;
            return;
        }
        for(int i=x-1;i>=1;i--){
            if(s[i]=='.'){
                ans++;
                cnt++;
            }
            else{
                cnt+=2;
                break;
            }
            if(cnt>=k){
            cout<<ans<<endl;
            return;
            }
        }
        cout<<ans<<endl;
        return;
    }
    ////////////////////////////////////////////////////////////////////fengexian
    if(d==2){
        for(int i=x-1;i>=1;i--){
            if(s[i]=='.'){
                ans++;
                cnt++;
            }
            else{
                cnt+=2;
                break;
            }
            if(cnt>=k){
            cout<<ans<<endl;
            return;
            }
        }
        cnt+=ans-1;
        if(cnt>=k){
            cout<<ans<<endl;
            return;
        }
        for(int i=x+1;i<=m;i++){
            if(s[i]=='.'){
                ans++;
                cnt++;
            }
            else{
                cnt+=2;
                break;
            }
            if(cnt>=k){
            cout<<ans<<endl;
            return;
            }
        }
        cout<<ans<<endl;
        return;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        sum=0;
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        if(n==1){
            if(m<=2){
                string s; cin>>s;
                if(m==1){
                    cout<<1<<endl;
                    continue;
                }
                if(s[0]=='x'||s[1]=='x'){
                    if(k>=4-d){
                        cout<<1<<endl;
                        continue;
                    }
                    if(d==0&&y==1){
                        cout<<1<<endl;
                        continue;
                    }
                    if(d==2&&y==2){
                        cout<<1<<endl;
                        continue;
                    }
                }
                if(y==1){
                    if(d==0||k>=4-d){
                        cout<<2<<endl;
                        continue;
                    }
                    else{
                        cout<<1<<endl;
                        continue;
                    }
                }
                else{
                    if(d==2||(d==3&&k>=3)||(d==0&&k>=2)||(d==1&&k>=1)){
                        cout<<2<<endl;
                        continue;
                    }
                    cout<<1<<endl;
                    continue;
                }
            }
            check(m,x,y,d);
            continue;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(d==0){
            dx[0]=1;
            dx[1]=0;
            dx[2]=-1;
            dx[3]=0;
            dy[0]=0;
            dy[1]=1;
            dy[2]=0;
            dy[3]=-1;
            dfs(x,y,d,0);
        }
        else if(d==1){
            dx[0]=0;
            dx[1]=-1;
            dx[2]=0;
            dx[3]=1;
            dy[0]=1;
            dy[1]=0;
            dy[2]=-1;
            dy[3]=0;
            dfs(x,y,d,0);
        }
        else if(d==2){
            dx[0]=-1;
            dx[1]=0;
            dx[2]=1;
            dx[3]=0;
            dy[0]=0;
            dy[1]=-1;
            dy[2]=0;
            dy[3]=1;
            dfs(x,y,d,0);
        }
        else{
            dx[0]=0;
            dx[1]=1;
            dx[2]=0;
            dx[3]=-1;
            dy[0]=-1;
            dy[1]=0;
            dy[2]=1;
            dy[3]=0;
            dfs(x,y,d,0);
        }
        cout<<sum<<endl;
    }
    return 0;
}
