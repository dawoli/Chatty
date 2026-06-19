#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int t,n,m,l,vmax,tmp,cnt,ans;
int d[N],v[N],a[N],p[N],cesu[N],mp[N];
int r[N][3],line[N][3]; //1×ó2ÓÒ 

double cal(int x,int y){
	return ((9-x*x)*1.0)/(2*y);
}

int find_left(double pos){
	for (int i=1;i<=m;i++)
		if (p[i]<pos&&p[i+1]>pos) return i;
}

int find_right(double pos){
	for (int i=1;i<=m;i++)
		if (p[i]<pos&&p[i+1]>pos) return i+1;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		tmp=0,cnt=0,ans=0;
		memset(cesu,0,sizeof(0));
		memset(mp,0,sizeof(mp));
		cin>>n>>m>>l>>vmax;
		for (int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for (int i=1;i<=m;i++){
			cin>>p[i];
		}
		for (int i=1;i<=n;i++)
			if (d[i]<=p[m]&&v[i]>vmax)
				ans++;
		cout<<ans<<' '<<m-1<<endl;
	}
	return 0;
}

