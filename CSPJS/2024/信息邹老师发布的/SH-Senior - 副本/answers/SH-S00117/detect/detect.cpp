#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,m,l,vmx,a[maxn],d[maxn],v[maxn],p[maxn],sum,ans;
bool vis[maxn];
inline void solve1(){
	for(register int i=1;i<=n;i++){
		if(v[i]>vmx){
			sum++;
		}
	}
	cout<<sum<<" ";
	if(sum==0){
		cout<<m<<"\n";
	}
	else{
		cout<<m-1<<"\n";
	}
	return ;
}
inline void solve2(){
	for(register int i=1;i<=n;i++){
		if(v[i]<=vmx&&a[i]<=0){
			vis[i]=1;
			continue;
		}
		if(v[i]>vmx){
			int x=lower_bound(p+1,p+m+1,d[i])-p;
			if(d[i]==p[x]){
				sum++;
			}
			else if(p[x]<d[i]){
				vis[i]=1;
				continue;
			}
			else{
				if(a[i]>=0){
					sum++;
				}
				else{
					double vt=(double)sqrt(v[i]*v[i]+2*a[i]*(p[x]-d[i]));
					if(vt<=vmx){
						vis[i]=1;
						continue;
					}
					else{
						sum++;
					}
				}
			}
		}
		else{//a[i]>0,v[i]<=vmx
			int x=lower_bound(p+1,p+m+1,d[i])-p;
			if(d[i]>p[x]){
				vis[i]=1;
				continue;
			}
			else if(d[i]<=p[x]){
				double vt=(double)sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]));
				if(vt<=vmx){
					vis[i]=1;
					continue;
				}
				else{
					sum++;
				}
			}
		}
	}
	cout<<sum<<" ";
	cout<<m-sum<<"\n";
	return ;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag=0;
		cin>>n>>m>>l>>vmx;
		sum=0,ans=0;
		for(register int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]<0){
				flag=1;
			}
		}
		for(register int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(!flag){
			solve1();
		}
		else if(flag){
			solve2();
		}
	}
	return 0;
}
