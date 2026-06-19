#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,a[maxn],c[maxn],sum;
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(register int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		if(unique(a+1,a+n+1)-a-1==n){
			cout<<"0\n";
			continue;
		}
		cout<<sum*3/8<<"\n";
	}
	return 0;
}
