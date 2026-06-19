#include<bits/stdc++.h>
using namespace std;
int n,m,l,v,x,y,z,cnt,ans,k[3005][3005],maxn=-1;
bool vis[100005];
struct node{
	int d,v,a,minn,maxx;
}s[100005];
int p[100005];
bool cmp(node xx,node yy){
	return xx.d<yy.d;
}
void dfs(int st){
	if(st==m+1){
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(int j=1;j<=m;j++){
				if(k[i][j]){
					flag=true;
				}
			}
			if(!flag){
				return;
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			bool flag=true;
			for(int j=1;j<=n;j++){
				if(k[i][j]){
					flag=false;
				}
			}
			if(flag){
				ans++;
			}
		}
		maxn=max(ans,maxn);
	}
	dfs(st+1);
	int ssk[3005];
	for(int i=1;i<=n;i++){
		if(k[i][st]!=0) ssk[i]=1;
		k[i][st]=0;
	}
	dfs(st+1);
	for(int i=1;i<=n;i++){
		k[i][st]=ssk[i];
	}
}
int main(){
//	freopen("detect.in","r",stdin);
//	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> l >> v;
		x=y=z=cnt=ans=0;
		for(int i=1;i<=n;i++){
			cin >> s[i].d >> s[i].v >> s[i].a;
			vis[i]=false;
			if(s[i].a>0) x++;
			if(s[i].a==0) y++;
			if(s[i].a<0) z++;
		}
		for(int i=1;i<=m;i++){
			cin >> p[i];
		}
		sort(p+1,p+m+1);
		if(x==n){
			for(int i=1;i<=n;i++){
				if(s[i].d>p[m]) continue;
				if((s[i].v*s[i].v+2*s[i].a*(p[m]-s[i].d))>v*v){
					cnt++;
				}
			}
			if(cnt==0) m++;
			cout << cnt << " " << m-1 << endl;
			continue;
		}
		if(y==n){
			for(int i=1;i<=n;i++){
				if(s[i].d>p[m]) continue;
				if(s[i].v>v){
					cnt++;
				}
			}
			if(cnt==0) m++;
			cout << cnt << " " << m-1 << endl;
			continue;
		}
		if(z==n){
			for(int i=1;i<=n;i++){
				bool flag=false;
				for(int j=m;j>=1;j--){
					if(p[j]<s[i].d){
						break;
					}
					if((s[i].v*s[i].v+2*s[i].a*(p[j]-s[i].d))>v*v){
						flag=true;
					}
				}
				if(flag){
					cnt++;
					vis[i]=true;
				} 
			}
			cout << cnt << " ";
			int nnow=1;
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(p[nnow]>=s[i].d&&(s[i].v*s[i].v+2*s[i].a*(p[nnow]-s[i].d))>v*v){
					continue;
				}
				for(int j=nnow;j<=m;j++){
					if((s[i].v*s[i].v+2*s[i].a*(p[j]-s[i].d))<=v*v){
						nnow=j-1;
						ans++;
						break;
					}
				}
			}
			cout << m-ans << endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if((s[i].v*s[i].v+2*s[i].a*(p[j]-s[i].d))>v*v){
					k[i][j]=1;
					vis[i]=1;
				}
			}
			if(vis[i]==1){
				cnt++;
			}
		}
		dfs(1);
		cout << cnt << " " << maxn << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
