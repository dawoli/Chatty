#include<bits/stdc++.h>
using namespace std;
const int KS=1e5+10;
struct N {
	int x,y,z;
};
N a[KS];
bool cmp(N x,N y) {
	if(x.x!=y.x) {
		return x.x>y.x;
	}
	if(x.y!=y.y) {
		return x.y<y.y;
	}
	return x.z<y.z;
}
bool cmp1(N x,N y) {
	if(x.y!=y.y) {
		return x.y>y.y;
	}
	if(x.x!=y.x) {
		return x.x<y.x;
	}
	return x.z<y.z;
}
bool cmp2(N x,N y) {
	if(x.z!=y.z) {
		return x.z>y.z;
	}
	if(x.x!=y.x) {
		return x.x<y.x;
	}
	return x.y<y.y;
}
void work() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	long long ans=0;
	sort(a+1,a+1+n,cmp);
	long long sum=0;
	for(int i=1; i<=n/2; i++) {
		sum+=a[i].x;
	}
	for(int i=n/2+1; i<=n; i++) {
		sum+=max(a[i].z,a[i].y);
	}

	sort(a+1,a+1+n,cmp1);
	long long sum1=0;
	for(int i=1; i<=n/2; i++) {
		sum1+=a[i].y;
	}
	for(int i=n/2+1; i<=n; i++) {
		sum1+=max(a[i].x,a[i].z);
	}

	sort(a+1,a+1+n,cmp2);
	long long sum2=0;
	for(int i=1; i<=n/2; i++) {
		sum2+=a[i].z;
	}
	for(int i=n/2+1; i<=n; i++) {
		sum2+=max(a[i].x,a[i].y);
	}
	cout<<max(sum,max(sum2,sum1))<<"\n";
	return;
}
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1; i<=T; i++) {
		work();
	}
	return 0;
}
