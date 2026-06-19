#include"bits/stdc++.h"
using namespace std;
#define int long long
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>r(n,0),b(n,0);
		vector<int>a(n,0);
		for(int i=0;i<n;i++)cin>>a[i];
		int rmax=0,bmax=0;
		for(int i=1;i<n;i++){
			for(int j=0;j<i-1;j++){
				rmax=max(rmax,r[j]+(a[j]==a[i])*a[i]);
				r[j]+=(a[i]==a[i-1])*a[i];
			}
			for(int j=0;j<i-1;j++){
				bmax=max(bmax,b[j]+(a[j]==a[i])*a[i]);
				b[j]+=(a[i]==a[i-1])*b[i];
			}
			r[i]+=(a[i]==a[i-1])*a[i];
			b[i]+=(a[i]==a[i-1])*a[i];
			r[i-1]=bmax;
			b[i-1]=rmax;
			//for(int i=0;i<n;i++)cout<<r[i];
			//for(int i=0;i<n;i++)cout<<b[i];
			//cout<<endl;
		}
		for(int i=0;i<n;i++){
			rmax=max(rmax,r[i]);
		}
		for(int i=0;i<n;i++){
			bmax=max(bmax,b[i]);
		}
		cout<<max(rmax,bmax)<<endl;
	}
}
