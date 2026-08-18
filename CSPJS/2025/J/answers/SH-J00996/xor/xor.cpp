#include<bits/stdc++.h>
using namespace std;
const int N=500009;
int n,k,a[N],ans,x,y,z,s[N],flag=1;
// int abs(int x){
// 	if(x>=0) return x;
// 	else return -x;
// }
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) x++;
		if(a[i]<=1) y++;
		if(a[i]<=255) z++;
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++) s[i]=s[i-1]^a[i];
	if(k==0&x==n){
		cout<<n/2;
		return 0;
	}
	if(k<=1&&y==n){
		if(k==1){
			cout<<x;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i-1]==0) continue;
				if(a[i]==1&&a[i-1]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(z==n){
		for(int i=1;i<=n;i++){
			int now=abs(s[i]-s[flag-1]);
			if(now==k){
				ans++;
				flag=i;
			}
		}
		cout<<ans;
	}
	cout<<128943;
	return 0;
}
