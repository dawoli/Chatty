#include<bits/stdc++.h>
using namespace std;
const int N=10019,INF=1e9;
int n,m,kp,pri_ad[19][N],y[N][N];
long long ans=1e9,dis[N][N];
bool exist[N];
struct CITY{
	int next,value;
};
vector<CITY> v[N];
long long solve(){
	int dis[N],u=1;
	long long ans_p=0;
	for(int i=2;i<=n;i++)
		dis[i]=INF,exist[i]=0;
	exist[1]=1;
	dis[1]=0;
	for(int p=1;p<n;p++){
		int min_dis=INF,min_n=1;
		for(int i=0;i<v[u].size();i++)
			dis[v[u][i].next]=min(dis[v[u][i].next],v[u][i].value);
		for(int i=1;i<=n;i++)
			if(exist[i]==0&&dis[i]<min_dis) min_dis=dis[i],min_n=i;
		ans_p+=min_dis;
		u=min_n;
		dis[u]=0;
		exist[u]=1;
	}
	return ans_p;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>kp;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			y[i][j]=INF;
	for(int i=1;i<=m;i++){
		int a,b,val;
		cin>>a>>b>>val;
		v[a].push_back({b,val});
		v[b].push_back({a,val});
	}
	for(int i=1;i<=kp;i++){
		cin>>pri_ad[i][0];
		for(int j=1;j<=n;j++)
			cin>>pri_ad[i][j];
	}
	ans=min(ans,solve());
	for(int o=1;o<=kp;o++){
		vector<CITY> vn[N];
		for(int i=1;i<=n;i++)
			for(int j=0;j<v[i].size();j++)
				vn[i].push_back(v[i][j]);
		n++;
		for(int i=1;i<n;i++)
			vn[n].push_back({i,pri_ad[o][i]});
		for(int i=1;i<n;i++)
			vn[i].push_back({n,pri_ad[o][i]});
		int dis[N],u=1;
		long long ans_p=0;
		for(int i=2;i<=n;i++)
			dis[i]=INF,exist[i]=0;
		exist[1]=1;
		dis[1]=0;
		for(int p=1;p<n;p++){
			int min_dis=INF,min_n=1;
			for(int i=0;i<vn[u].size();i++)
				dis[vn[u][i].next]=min(dis[vn[u][i].next],vn[u][i].value);
			for(int i=1;i<=n;i++)
				if(exist[i]==0&&dis[i]<min_dis) min_dis=dis[i],min_n=i;
			ans_p+=min_dis;
			u=min_n;
			dis[u]=0;
			exist[u]=1;
		}
		ans_p+=pri_ad[o][0];
		ans=min(ans,ans_p);
	}
	cout<<ans<<endl;
	return 0;
}


