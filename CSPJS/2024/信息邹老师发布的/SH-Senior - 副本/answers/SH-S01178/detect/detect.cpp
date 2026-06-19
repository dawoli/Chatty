#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long T,n,m,L,V,d[N],a[N],p[N],x[N];
double v[N];
bool b[N]; 
set<long long> st[N]; 
double cal(double v1,long long a1,long long s1){
	if(a1==0)
		return v1;
	return sqrt(v1*v1+2*a1*s1*1.0);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int ii=1;ii<=T;ii++){
		cin>>n>>m>>L>>V;
		if(n>N or m>N)
			return 0;
		for(int i=1;i<=m;i++){
			st[i].clear();
		}
		for(int i=1;i<=n;i++){
			x[i]=0,b[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(d[i]>p[j])
					continue;
				long long s=p[j]-d[i];
				double vf=cal(v[i],a[i],s); 
				if(vf>(double){V*1.0}){
					st[j].insert(i);
					x[i]++; 
					b[i]=1;
				}
			}
		}
		long long ans1=0;
		for(int i=1;i<=n;i++){
			ans1+=b[i];
		}
		long long cnt=0; 
		for(int j=1;j<=m;j++){
			bool flag=0;  
			for(auto k:st[j]){
				if(x[k]==1)
					flag=1;
			}
			if(!flag){
				for(auto k:st[j]){
					x[k]--;
				}
				cnt++;
			}
		} 
		cout<<ans1<<" "<<cnt;
		if(ii!=T)
			cout<<endl;
	}
	return 0; 
}
