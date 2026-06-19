#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,m,dn,vn;
int d[N],v[N],a[N];
int l[N],r[N];
int p[N];
void w(int i){//第 i 辆车在[l[i],r[i]]范围内超速
	if(a[i]==0){
		if(v[i]>vn)
			l[i]=d[i],r[i]=dn;
		else
			l[i]=r[i]=-1;
		return ;
	}
	if(a[i]>0){
		int s=floor((vn*vn-v[i]*v[i])/((long double)2.0*a[i]));
		l[i]=max(min(s+d[i]+1,dn+1),d[i]);
		r[i]=dn;
	}
	else{
		int s=ceil((vn*vn-v[i]*v[i])/(2.0*a[i]));
		r[i]=min(max(s+d[i]-1,-1),dn);
		l[i]=d[i];
	}
}
pair<int,int> x[N];
int cnt=0;
void mem(){
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	memset(a,0,sizeof(a));
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(p,0,sizeof(p));
	memset(x,0,sizeof(x));
	cnt=0;
}
int main(){
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		mem();
		cin>>n>>m>>dn>>vn;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i],w(i);
		for(int i=1;i<=m;i++)
			cin>>p[i];
		int ans=0;
		for(int i=1;i<=n;i++){
//			cout<<l[i]<<' '<<r[i]<<endl;
			l[i]=lower_bound(p+1,p+m+1,l[i])-p;
			r[i]=upper_bound(p+1,p+m+1,r[i])-p;
			r[i]--;
			if(r[i]>=l[i]){
				ans++;
				x[++cnt].first=l[i],x[cnt].second=r[i];
			}
//			else{
//				cout<<d[i]<<' '<<v[i]<<' '<<a[i]<<endl;
//			}
//			cout<<l[i]<<' '<<r[i]<<endl;
		}
//		p[k] ( k属于[l[i],r[i]] )位置的测速仪可以测到第 i 辆车超速
		cout<<ans<<' ';
		sort(x+1,x+1+cnt);
		ans=0;
//		cout<<endl;
//		for(int i=1;i<=cnt;i++)
//			cout<<x[i].first<<' '<<x[i].second<<endl;
//		cout<<cnt<<endl;
		for(int i=1;i<=cnt;){
			int xl=x[i].first,xr=x[i].second;
			int j=i+1,mn=xr;
			while(x[j].first<=xr&&j<=cnt)
				mn=min(mn,x[j].second),j++;
//			cout<<i<<' '<<xl<<' '<<xr<<' ';
//			cout<<mn<<endl;
			ans++;
			while(x[i].first<=mn&&i<=cnt)i++;
		}
		cout<<m-ans<<'\n';
	}
	cout<<endl;
	return 0;
}
/*
9 10 62098 741
1143 996 -3
1514 952 -8
280 883 -5
44155 834 -216
1813 879 -5
1100 882 -69
4216 909 -3
11307 810 -2
2306 873 -18
1062 1304 1722 2663 5502 12378 16995 22981 27236 44366

*/
