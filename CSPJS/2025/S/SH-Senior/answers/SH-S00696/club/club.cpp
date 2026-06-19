#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,b[200010],c[200010];
	cin>>t;
	for(long long i=0;i<t;i++){
		cin>>n;
		long long cnt=0,a[200010];
		for(long long j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a,a+n);
		for(long long k=n/2;k<n;k++){
			cnt=cnt+a[k];
		}
		cout<<cnt<<endl;
	}
	return 0;
}
