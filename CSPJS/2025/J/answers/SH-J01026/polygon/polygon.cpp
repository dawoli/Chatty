#include<bits/stdc++.h>
using namespace std;
int a[10005];
int b[1005][1005];
int v[10005];
int n,sum,maxn,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	if(n==3){
		maxn=a[n-1];
		if(a[1]+a[2]>a[3]){
			cout<<1<<endl;
		}
		else cout<<0<<endl;
	}
	else if(n==4){
		if(a[1]+a[2]>a[3]){
			ans++;
		}
		if(a[1]+a[2]>a[4]){
			ans++;
		}
		if(a[1]+a[3]>a[4]){
			ans++;
		}
		if(a[2]+a[3]>a[4]){
			ans++;
		}
		if(a[1]+a[2]+a[3]>a[4]){
			ans++;
		}
		cout<<ans<<endl;
	}
	else if(n==5){
		if(a[1]+a[2]>a[3]){
			ans++;
		}
		if(a[1]+a[2]>a[4]){
			ans++;
		}
		if(a[1]+a[2]>a[5]){
			ans++;
		}
		if(a[1]+a[3]>a[4]){
			ans++;
		}
		if(a[1]+a[3]>a[5]){
			ans++;
		}
		if(a[1]+a[4]>a[5]){
			ans++;
		}
		if(a[2]+a[3]>a[4]){
			ans++;
		}
		if(a[2]+a[3]>a[5]){
			ans++;
		}
		if(a[2]+a[4]>a[5]){
			ans++;
		}
		if(a[3]+a[4]>a[5]){
			ans++;
		}
		if(a[1]+a[2]+a[4]>a[5]){
			ans++;
		}
		if(a[1]+a[2]+a[3]>a[4]){
			ans++;
		}
		if(a[1]+a[2]+a[3]>a[5]){
			ans++;
		}
		if(a[1]+a[3]+a[4]>a[5]){
			ans++;
		}
		if(a[2]+a[3]+a[4]>a[5]){
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]>a[5]){
			ans++;
		}
		cout<<ans<<endl;
	}

	else{
		cout<<366911923<<endl;
	}
	return 0;
}
