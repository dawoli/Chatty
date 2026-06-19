#include <bits/stdc++.h>
using namespace std;
int n,k,cnt=0,mid;
int a[1001];
void f(int l,int r) {
	if(l==r){
		return;
	}
	int ca=0;
	for(int i=r;i>=l;i--){
		ca^=a[i];
		if(ca==k){
			cnt++;
			f(i-1,r);
			return;
		}
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==k) {
			cnt++;
			mid=i;
		}
	}
	f(1,mid-1);
	f(mid+1,n);
	cout<<cnt;
	return 0;
}
