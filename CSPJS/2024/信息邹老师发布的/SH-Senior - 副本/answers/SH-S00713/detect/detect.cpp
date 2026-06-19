#include<bits/stdc++.h>
using namespace std;
const int N=100001;

long long L, V;
int T, n, m, d[N], v[N], a[N], p[N], cnt, vis[N], ans;
vector<int>g[N];
int bond(int qq){
	int l=1, r=m, res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(p[mid]>=qq){
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return res;
}
int bond2(int qq){
	int l=1, r=m, res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(p[mid]>qq){
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return res;
}
void add(int st, int i){
	if(st==-1)return;
	cnt++;
	for(int j=st;j<=m;j++){
		g[j].push_back(i);
	}
	return;
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin>>T;
	while(T--){
		cnt=0, ans=0;
		memset(g, 0, sizeof g);
		memset(vis, 0, sizeof vis);
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)cin>>p[i];
		for(int i=1;i<=m;i++)g[i].push_back(1);
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]<=V)continue;
				int st=bond(d[i]);add(st, i);
			}
			if(a[i]>0){
				if(v[i]>V){
					int st=bond(d[i]);add(st, i);
				}
				else{
					long long ar=(V*V-v[i]*v[i])/(2*a[i]);
					if(ar*2*a[i]==V*V-v[i]*v[i]){
						int st=bond2(d[i]+ar);add(st, i);
					}
					else{
						int st=bond(d[i]+ar);add(st, i);
					}
				}
			}
			if(a[i]<0){
				if(v[i]<=V)continue;
				long long ar=(V*V-v[i]*v[i])/(2*a[i]);
				if(ar*2*a[i]==V*V-v[i]*v[i]){
					int st=bond(d[i]+ar), st2=bond(d[i]);
					if(st2==-1)continue;
					if(p[st2]>=d[i]+ar)continue;
					cnt++;
					if(st==-1){
						for(int j=st2;j<=m;j++)g[j].push_back(i);
					}
					else 
						for(int j=st2;j<st;j++)g[j].push_back(i);
						
				}
				else{
					int st=bond(d[i]+ar), st2=bond(d[i]);
					if(st2==-1)continue;
					if(p[st2]>d[i]+ar)continue;
					cnt++;
					if(st==-1)for(int j=st2;j<=m;j++)g[j].push_back(i);
					else if(p[st]==d[i]+ar)for(int j=st2;j<=st;j++)g[j].push_back(i);
					else for(int j=st2;j<st;j++)g[j].push_back(i);
				}
			}	
		}
		cout<<cnt<<" ";
		for(int i=1;i<=m;i++){
			int sz=g[i].size();
			g[i][0]=sz-1;
			for(int j=1;j<g[i].size();j++){
				vis[g[i][j]]=1;
			}
		}
		while(cnt!=0){
			vector<int>now;
			int mx=-1;
			for(int i=1;i<=m;i++){
				if(g[i][0]>mx){
					mx=g[i][0];now=g[i];
				}
			}
			ans++;
			for(int i=1;i<now.size();i++){
				if(vis[now[i]]){
					cnt--;vis[now[i]]=0;
				}
			}
			for(int i=1;i<=m;i++){
				for(int j=1;j<g[i].size();j++){
					if(!vis[g[i][j]]&&g[i][j]!=0){
						g[i][j]=0;g[i][0]--;
					}
				}
			}
		}
		cout<<m-ans<<endl;
	}
	return 0;
}
