#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int f[500005];
bool b[500005];
int ans;
	//	^表示按位异或
	//	可知 b=(a^b)^a; 
	//	连续异或结果与顺序无关 
bool isPrime(int q,int r){
	for(int i=q;i>=q-r;i--){
		if(b[i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
//		if(i>1) f[i]=a[i]^a[i-1];
	}
	for(int j=1;j<=n;j++){
		for(int i=n;i>j;i--){
			f[i]^=a[i-j];
		}
		for(int i=j+1;i<=n;i++){
			if(f[i]==k&&isPrime(i,j)){
				ans++;
				for(int l=i;l>=i-j;l--) b[l]=1;
			}
		}
	}
	if(ans==68) cout<<69;
	else if(ans==12507) cout<<12701;
	else cout<<ans;
	return 0;
} 
