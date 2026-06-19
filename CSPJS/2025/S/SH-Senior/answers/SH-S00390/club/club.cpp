#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+5;
int n,ans=0;
int a[N][5],vis[N];
vector<int> c[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=3;i++)	c[i].clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int maxn=-1,maxidx;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(maxn<a[i][j]){
					maxn=a[i][j];
					maxidx=j;
				}
			}
			c[maxidx].push_back(i);
			ans+=maxn;
		}
		int idx=0,sec=0,fir=0;
		for(int i=1;i<=3;i++){
			if(c[i].size()>(n>>1)){
				idx=i;
			}
			else{
				if(fir)	sec=i;
				else	fir=i;
			}
		}
		if(!idx){
			cout<<ans<<"\n";
			continue;
		}
		int need=c[idx].size()-(n>>1);
		priority_queue<pii,vector<pii>,greater<pii> > q[5];
		for(int i=0;i<c[idx].size();i++){
			q[fir].push({a[c[idx][i]][idx]-a[c[idx][i]][fir],c[idx][i]});
			q[sec].push({a[c[idx][i]][idx]-a[c[idx][i]][sec],c[idx][i]});
		}
		int qwe=0,asd=0;
		while(need--){
			if((q[fir].top().first<=q[sec].top().first&&(c[fir].size()+qwe)<(n>>1))||(c[sec].size()+asd==(n>>1))){
				if(vis[q[fir].top().second]){
					need++;
					q[fir].pop();
					continue;
				}
				vis[q[fir].top().second]=1;
				ans-=q[fir].top().first;
				q[fir].pop();
				qwe++;
			}
			else{
				if(vis[q[sec].top().second]){
					need++;
					q[sec].pop();
					continue;
				}
				vis[q[sec].top().second]=1;
				ans-=q[sec].top().first;
				q[sec].pop();
				asd++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
