#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
const int N=2e5+10;
struct st
{
	int x,y,z,m;
} s[N];
ll t,n,ans,f[4],c[4];
vector<int> v[4];
void clear(){
	for(int i=1;i<=N-1;i++) s[i].x=s[i].y=s[i].z=s[i].m=0;
	ans=0;
	c[1]=c[2]=c[3]=0;
}
void dfs(int x,int l1,int l2,int l3){
	if(l1>n/2 || l2>n/2 || l3>n/2){
		return;
	}
	if(l1==n/2) if(c[1]<f[1]) return;
	if(l2==n/2) if(c[2]<f[2]) return;
	if(l2==n/2) if(c[3]<f[3]) return;
	if(x==n+1) {
		if(ans<c[1]+c[2]+c[3]) ans=c[1]+c[2]+c[3],f[1]=c[1],f[2]=c[2],f[3]=c[3];
	}	
	c[1]+=s[x].x;
	dfs(x+1,l1+1,l2,l3);
	c[1]-=s[x].x;
	c[2]+=s[x].y;
	dfs(x+1,l1,l2+1,l3);
	c[2]-=s[x].y;
	c[3]+=s[x].z;
	dfs(x+1,l1,l2,l3+1);
	c[3]-=s[x].z;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	sync();
	cin>>t;
	while(t--){
		clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].x>>s[i].y>>s[i].z;
		}
		dfs(1,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

