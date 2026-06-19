#include<bits/stdc++.h>
using namespace std;
double d[100005];
double v[100005];
double a[100005];
int p[100005];
int n,m,L,V;
pair<int,int> special_car[100005];
void init(){
	memset(d,0,sizeof(d));
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
	memset(p,0,sizeof(p));
}
int find(double x){
	int l=1,r=m;
	while(l<r and l!=r-1){
		int mid=(l+r)>>1;
		if(p[mid]<x) l=mid;
		else if(p[mid]>x) r=mid;
		else return mid;
	}
	return l;
}
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first==y.first) return x.second<y.second;
	return x.first<y.first;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		//init();
		cin>>n>>m>>L>>V;
		int ans1=0;
		int cnt=0;
		int ans2=0;
		bool flag=false;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(d[i]<=p[m] and v[i]>V){
					ans1++;
					flag=true;
				}
			}
			else if(a[i]>0){
				int c=max(0.0,V-v[i]);
				double t=c*1.0/a[i]*1.0;
				if(0.0+d[i]+v[i]*t+a[i]*t*t/2.0<=p[m]){
					ans1++;
					flag=true;
				}
			}
			else{
				double s=(V*V-v[i]*v[i])/(2*a[i])*1.0;
				if(s<0) continue;
				if(d[i]+s<p[1]) continue;
				if(d[i]+s>=p[m]) ans1++;
				else{
					int k=find(d[i]+s);
					int l=find(d[i]);
					if(p[l]<d[i]) l++;
					if(p[k]>=d[i]) ans1++;
					cnt++;
					special_car[cnt]=make_pair(l,k);
				}
			}
		}
		cout<<ans1<<" ";
		if(cnt!=0){
			ans2++;
			sort(special_car+1,special_car+cnt+1,cmp);
			int l=special_car[1].first,r=special_car[1].second;
			for(int i=2;i<=cnt;i++){
				if(special_car[i].first<=r and special_car[i].second>=l){
					l=max(l,special_car[i].first);
					r=min(r,special_car[i].second);
				}
				else{
					ans2++;
					l=special_car[i].first;
					r=special_car[i].second;
				}
			}
			if(flag and m>r) ans2++;
		}
		else if(flag) ans2=1;
		cout<<m-ans2<<endl;
	}
}
