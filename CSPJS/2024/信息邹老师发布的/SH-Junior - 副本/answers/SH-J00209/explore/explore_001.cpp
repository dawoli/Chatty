#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,x0,y0,d0,ans;
ll fx[5]={0,1,0,-1},fy[5]={1,0,-1,0};
bool ansf=0,f[1005][1005];
char g[1005][1005];
void shuru(){
	cin>>n>>m>>k>>x0>>y0>>d0;
	for(ll j=1;j<=n;j++)
	    for(ll x=1;x<=m;x++)
	        cin>>g[j][x];
}
void dfs(ll x,ll y,ll d,ll step){
	if(step==k)
		return ;
	f[x][y]=1;
	ll xx=x+fx[d],yy=y+fy[d];
	if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&g[xx][yy]!='x'){
		//cout<<"!"<<xx<<' '<<yy<<' '<<step<<endl;
		if(f[xx][yy]==0)
		    ans++;
		dfs(xx,yy,d,step+1);
	}
	else
		dfs(x,y,(d+1)%4,step+1);
	f[x][y]=0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    cin>>t;
    for(ll i=0;i<t;i++){
    	shuru();
    	//cout<<t<<endl;
    	ans=1;
    	dfs(x0,y0,d0,0);
    	if(ansf==1)
		    cout<<endl;
		else
		    ansf=1;
		cout<<ans;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//2
//5 5 20
//1 1 0
//.....
//.xxx.
//.x.x.
//..xx.
//x....
//1 5 4
//1 1 2
//....x
