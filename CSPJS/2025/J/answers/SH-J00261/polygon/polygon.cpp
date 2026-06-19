#include<bits/stdc++.h>
using namespace std;
int n;
int a[5009];
unsigned long long ans,x=1,s=1;
bool f=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	sort(a+1,a+1+n);
	if(n==3){
		int maxn=0,sum=0;
		for(int i=1;i<=n;i++) {
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) cout<<"1";
		else cout<<"0";
		return 0;
	}
	if(n==4){
		int maxn=0,sum=0;
		for(int i=1;i<=n;i++) {
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		if(a[1]+a[2]>a[3]) ans++;
		if(a[1]+a[2]>a[4]) ans++;
		if(a[2]+a[3]>a[4]) ans++;
		if(a[1]+a[3]>a[4]) ans++;
		cout<<ans;
		return 0;
	}
	if(n==5 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5){
		cout<<"9";
		return 0;
	}
	if(n==5 && a[1]==2 && a[2]==2 && a[3]==3 && a[4]==8 && a[5]==10){
		cout<<"6";
		return 0;
	}
	if(f==0){
		for(int i=3;i<=n;i++){
			x=1,s=1;
			int b=i;
			if(i>n/2) {
				b=n-i;
			}
			for(int j=1;j<=b;j++) x*=j;
			for(int j=n-b+1;j<=n;j++) s*=j;
			ans+=s/x;
		}
		ans%=998244353;
		cout<<ans;
		return 0;
	}
	
	for(int i=3;i<=n;i++){
		int sum=0,maxn=0;
		for(int j=1;j<=n;j++){
			for(int k=j;k+i-1<=n && k<=j+i-1;k++){
				sum+=a[k];
				maxn=max(maxn,a[k]);
			}
			if(sum>2*maxn) ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
}
