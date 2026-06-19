#include<bits/stdc++.h>
using namespace std;
int n,m,s,l,d[114514],v[114514],a[114514],p[114514],x,mn=INT_MAX;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
	x=0;
	cin>>n>>m>>l>>s;
	for(int i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
		mn=min(mn,a[i]); 
	}
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]>=0){
			if(sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]))>s && d[i]<=p[m])x++;
		}
		if(a[i]<0){
			int l=1,r=m;
			while(l<r){
				int mid=l+r>>1;
				if(p[mid]<d[i]) l=mid+1;
				else r=mid;
			}
			if(d[i]<=p[l] && sqrt(v[i]*v[i]+2*a[i]*(p[l]-d[i]))>=s)x++;
		}
	}
	cout<<x<<" "<<m-1<<'\n';
	
	}
	return 0;
} 
