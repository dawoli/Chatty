#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
char a[1010][1010];
ll ans=0;
bool vis[1010][1010];
ll n,m,c;
ll x,y,d;
ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void f(){
	ll now=0;
	while(now!=c){
		for(ll i=0;i<=3;i++){
			if(d==i){
				ll x2=x+dx[i],y2=y+dy[i];
				if(x2>n||y2>m||x2<1||y2<1){
					d=(d+1)%4;
				}else if(a[x2][y2]=='x'){
					d=(d+1)%4;
				}else{
					if(vis[x2][y2]==0){
						ans++;
						vis[x2][y2]=1;
					}
					x=x2,y=y2;
				}
				now++;
				break;
			}
		}	
	}
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){//Çå¿Õ£¡£¡£¡£¡ 
		ans=0;
		for(ll i=0;i<=1000;i++){
			for(ll j=0;j<=1000;j++){
				vis[i][j]=0;
			}
		}
		cin>>n>>m>>c;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		ans++;
		vis[x][y]=1;
		f();
	}
}
