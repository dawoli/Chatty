#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans;
char c[1010][1010];
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=0;
        for(int p=1;p<=n;p++){
            for(int q=1;q<=m;q++){
                cin>>c[p][q];
            }
        }
        c[x][y]='!';
        for(int t=1;t<=k;t++){
            int tx=x+fx[d];
            int ty=y+fy[d];
            if(1<=tx<=n&&1<=ty<=m&&(c[tx][ty]=='.'||c[tx][ty]=='!')){
            		x=tx;y=ty;
            		c[x][y]='!';
            }
            else{
                d=(d+1)%4;
            }
	}
	for(int p=1;p<=n;p++){
            for(int q=1;q<=m;q++){
                if(c[p][q]=='!'){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
