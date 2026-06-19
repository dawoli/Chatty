//#include <bits/stdc++.h>
//using namespace std;
//int n,k,a[1005],ans[1005][1005],cnt=0;
//bool is[1005];
//int main() {
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
//	cin>>n>>k;
//	for(int i=1;i<=n;i++) cin>>a[i];
//	for(int i=1;i<=n;i++) {
//		for(int j=i;j<=n;j++) {
//			if(i==j) ans[i][j]=a[i];
//			else {
//				ans[i][j]=ans[i][j-1]^a[j];
//			}
//			if(ans[i][j]==k) {
//				bool f=true;
//				for(int ii=i;ii<=j;ii++) {
//					if(is[ii]) {
//						f=false;
//						break;
//					}
//				}
//				if(f) {
//					cnt++;
//					for(int ii=i;ii<=j;ii++) {
//						is[ii]=true;
//					}
//				}
//			}
//		}
//	}
//	cout<<cnt;
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
int n,k,a[1005],ans[1005][1005],cnt=0;
int is[1005][2],zz=0;//i和j的区间出现过了 
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool iss=false;
	cin>>a[1];
	for(int i=2;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=a[i-1]) iss=true;
	}
	if(!iss) {
		if(a[1]==k) {
			cout<<n;
		} else if(k==0) {
			cout<<n/2;
		}
		return 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			if(i==j) ans[i][j]=a[i];
			else ans[i][j]=ans[i][j-1]^a[j];
			if(ans[i][j]==k) {
				bool f=false;
				for(int z=1;z<=zz;z++) {
					int x=is[z][0],y=is[z][1];
					if(!(i>y||x>j)) {
						f=true;
						break;
					}
				}
				if(!f) {
					cnt++,zz++;
					is[zz][0]=i,is[zz][1]=j;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
