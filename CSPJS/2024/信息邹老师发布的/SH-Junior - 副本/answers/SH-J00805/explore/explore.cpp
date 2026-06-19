#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e3+9;
char mp[N][N];
bool vis[N][N];
int n,m,k;
struct node{
	int x;
	int y;
	int dir;
};
bool ck(node a){
	int x=a.x,y=a.y;
	if(x<1) return false;
	if(y<1) return false;
	if(x>n) return false;
	if(y>m) return false;
	if(mp[x][y]=='x') return false;
	return true; 
}
void cl(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mp[i][j]=' ';
			vis[i][j]=0;
		}
	}
	n=0; m=0; k=0; 
}
node nxt(node a){
	node ans;
	ans.dir=a.dir;
	switch(a.dir){
		case 0:{
			ans.x=a.x;
			ans.y=a.y+1;
			break;
		}
		case 1:{
			ans.x=a.x+1;
			ans.y=a.y;
			break;
		}
		case 2:{
			ans.x=a.x;
			ans.y=a.y-1;
			break;
		}
		case 3:{
			ans.x=a.x-1;
			ans.y=a.y;
			break;
		}
		default:{
			ans.x=a.x;
			ans.y=a.y;
			break;
		}
	}
	return ans;
}
void cal(){
	cl();
	cin>>n>>m>>k;
	int ans=1; node st,now;
	cin>>st.x>>st.y>>st.dir;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>mp[i][j];
	now=st;
	vis[st.x][st.y]=true;
	for(int i=0;i<k;i++){
		node cop=now;
		cop=nxt(cop);
		if(ck(cop)) now=cop;
		else now.dir=(now.dir+1)%4;
		if(!vis[now.x][now.y]) ans++;
		vis[now.x][now.y]=1;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t; cin>>t;
	while(t--) cal();
	return 0;
}
//SH-J00805
