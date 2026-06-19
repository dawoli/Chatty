#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
const int mod = 998244353;
int n,ans;
int a[N];
//void build(int l,int r){
//	if(l == r){
//		sum[l][r] = a[l];
//	}
//	int mid = l+r>>1;
//	build(l,mid);
//	build(mid+1,r);
//	sum[l][r] = sum[l][mid]+sum[mid+1][r];
//}
void f(int t,int sm,int last){
	if(!t){
		if(sm>last*2){
			ans++;
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		int sumary = sm + a[i];
		f(t-1,sumary,i);
	}
}
int sum(int a){
	return (a+1)*a/2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	build(1,n);
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			int side=i-2;
			for(int j=1;j<=n-i+1;j++){
				ans+=sum(n-j-side);
				ans %= mod;
			}
		}
		cout<<ans;
	}else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=3;i<=n;i++){
			f(i,0,0);
		}
		cout<<ans;
	}
	return 0;
}
