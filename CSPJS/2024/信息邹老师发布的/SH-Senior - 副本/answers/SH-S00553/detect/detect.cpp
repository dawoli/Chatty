#include <bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],vis[100005],tot[100005];
double l[100005],r[100005];
struct node{
	int res[3001];
	int num;
}pos[3001];
bool cmp(node a,node b){
	return a.num>b.num; 
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(tot,0,sizeof(tot));
		int n,m,L,V;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]==0){
				if(v[i]>V){
					l[i]=d[i],r[i]=L;
				}
			}else{
				double x=(V*V-v[i]*v[i])/(2*a[i]);
				if(v[i]<V&&d[i]+x<=L){
					l[i]=d[i]+x,r[i]=L;
				}else if(v[i]>V){
					if(d[i]+x<=L&&x>=0){
						l[i]=d[i],r[i]=d[i]+x;
					}else{
						l[i]=d[i],r[i]=L;
					}
				}
			}
	    }
	    int cnt=0,cnt2=0,sum=0;
		for(int i = 1,x;i <= m;i++){
			cin >> x;
			for(int j = 1;j <= n;j++){
				if(l[j]<=x&&x<=r[j]){
					vis[j]=1;
					pos[i].res[++tot[i]]=j;
				}
			}
		}
		sort(pos+1,pos+m+1,cmp);
		for(int i = 1;i <= n;i++){
			if(vis[i]==1) cnt++;
		}
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= m;i++){
			int flag=0;
			for(int j = 1;j <= tot[i];j++){
				if(vis[pos[i].res[j]]==0){
					flag=1;
					vis[pos[i].res[j]]=1;
				}
			}
			if(flag==0) --m;
		}
		cout << cnt << ' ' << m << '\n';
	}
	return 0;
} 
