#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
const int M=100009;
ll n,m,V,L,p[M],v[N],a[N],d[N];
vector<int> to[N];
bool t[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p+1,p+1+m);
		ll ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V&&d[i]<=p[m]){
					ans1++;
					for(int j=1;j<=m;j++)
					    if(p[j]>=d[i])
					    	to[j].push_back(i);
				}
				continue;
			}
			if(a[i]<0&&v[i]<=V)continue;
			if(d[i]>p[m])continue;
			double dis=(V*V-v[i]*v[i])/(2*a[i]);
			if(a[i]>0){
				double di=double(d[i])+dis;
				if(di>=p[m])continue;
				for(int j=1;j<=m;j++)
					if(p[j]>=di)
						to[j].push_back(i);
				ans1++;
			}
			if(a[i]<0){
				double di=double(d[i])+dis;
				bool key=0;
				for(int j=1;j<=m;j++)
					if(p[j]>=d[i]&&p[j]<di){
						to[j].push_back(i);
						if(!key)ans1++;
						key=1;
					}
			}
		}
		cout<<ans1<<" ";
		for(int i=1;i<=m;i++)
			if(ans2<to[i].size())ans2=to[i].size();
		cout<<ans2<<endl;
	}
	return 0;
}
