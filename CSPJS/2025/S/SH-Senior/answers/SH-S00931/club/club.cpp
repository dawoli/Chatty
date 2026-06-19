#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
}
#define N 111111
#define int long long
int t,n,a[N][4],id[N],d[N];
signed main(){
	open("club");
	cin>>t;
	while(t--){
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int m=max({a[i][1],a[i][2],a[i][3]});
			if(m==a[i][1]){++cnt1;id[i]=1;ans+=a[i][1];
			}else if(m==a[i][2]){++cnt2;id[i]=2;ans+=a[i][2];
			}else if(m==a[i][3]){++cnt3;id[i]=3;ans+=a[i][3];
			}else return -1;
		}
		if(cnt1>n/2){
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(id[i]==1)
					d[++cnt]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			sort(d+1,d+1+cnt);
			for(int i=1;i<=cnt-n/2;i++)
				ans-=d[i];
		}
		if(cnt2>n/2){
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(id[i]==2)
					d[++cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			sort(d+1,d+1+cnt);
			for(int i=1;i<=cnt-n/2;i++)
				ans-=d[i];
		}
		if(cnt3>n/2){
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(id[i]==3)
					d[++cnt]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
			sort(d+1,d+1+cnt);
			for(int i=1;i<=cnt-n/2;i++)
				ans-=d[i];
		}
		cout<<ans<<endl;
	}
}
