#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int N=1e5+10;
int t,n,ans;
struct node{
	int v[3];
	int mx,mxpos;
	int md,mdpos;
	int mn,mnpos;
}a[N];
bool mem[460][460][460];
int cache[460][460][460];
int solve(int dep,int x,int y){
	if(x>n/2||y>n/2||dep-x-y>n/2) return -INF;
	if(dep==n) return 0;
	if(mem[dep][x][y]) return cache[dep][x][y];
	mem[dep][x][y]=true;
	return cache[dep][x][y]=max(solve(dep+1,x+1,y)+a[dep+1].v[0],max(solve(dep+1,x,y+1)+a[dep+1].v[1],solve(dep+1,x,y)+a[dep+1].v[2]));
}
queue<int> b[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0; 
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].v[0]>>a[i].v[1]>>a[i].v[2];
			a[i].mx=max(a[i].v[0],max(a[i].v[1],a[i].v[2]));
			a[i].mn=min(a[i].v[0],min(a[i].v[1],a[i].v[2]));
			a[i].md=a[i].v[0]+a[i].v[1]+a[i].v[2]-a[i].mx-a[i].mn;
			for(int j=0;j<3;j++)
				if(a[i].v[j]==a[i].mx) a[i].mxpos=j;
			for(int j=0;j<3;j++)
				if(a[i].v[j]==a[i].mn&&j!=a[i].mxpos) a[i].mnpos=j;
			a[i].mdpos=3-a[i].mxpos-a[i].mnpos;
		}
		if(n<=450){
			memset(mem,false,sizeof(mem)); 
			cout<<solve(0,0,0)<<endl;
			continue;
		}
		bool spA=true;
		for(int i=1;i<=n;i++){
			if(a[i].v[1]!=0||a[i].v[2]!=0){
				spA=false;
				break;
			}
		}
		if(spA){
			sort(a+1,a+1+n,[](node p,node q){ return p.v[0]>q.v[0]; });
			for(int i=1;i<=n/2;i++) ans+=a[i].v[0];
			cout<<ans<<endl;
			continue;
		}
		bool spB=true;
		for(int i=1;i<=n;i++){
			if(a[i].v[3]!=0){
				spB=false;
				break;
			}
		}
		if(spB){
			sort(a+1,a+1+n,[](node p,node q){ return p.v[0]-p.v[1]>q.v[0]-q.v[1]; });
			for(int i=1;i<=n/2;i++) ans+=a[i].v[0];
			for(int i=n/2+1;i<=n;i++) ans+=a[i].v[1];
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+1+n,[](node p,node q){ return p.mx>q.mx; });
		for(int i=1;i<=n;i++){
			int pos=a[i].mxpos;
			if(b[pos].size()!=n/2) b[pos].push(i),ans+=a[i].mx;
			else{
				int u=b[pos].front();
				if(a[u].v[pos]+a[i].md>a[u].v[a[u].mdpos]+a[i].mx){
					b[a[i].mdpos].push(i);
					ans+=a[i].md;
				}else{
					b[pos].pop();
					b[pos].push(i);
					ans-=a[u].v[pos];
					ans+=a[i].mx;
					if(pos==0){
						if(a[u].v[1]>a[u].v[2]) b[1].push(u),ans+=a[u].v[1];
						else 					b[2].push(u),ans+=a[u].v[2];
					}else if(pos==1){
						if(a[u].v[0]>a[u].v[2]) b[0].push(u),ans+=a[u].v[0];
						else 					b[2].push(u),ans+=a[u].v[2];
					}else{
						if(a[u].v[1]>a[u].v[0]) b[1].push(u),ans+=a[u].v[1];
						else 					b[0].push(u),ans+=a[u].v[0];
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			a[i].v[0]=a[i].v[1]=a[i].v[2]=0;
			a[i].mx=a[i].md=a[i].mn=0;
			a[i].mxpos=a[i].mdpos=a[i].mnpos=0;
		}
		for(int i=0;i<3;i++)
			while(!b[i].empty()) b[i].pop();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
