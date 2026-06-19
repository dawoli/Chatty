#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	bool b=true;
	for(int i = 1;i<= n;i++){
		cin>>a[i];
		if(a[i]!=1)b=false;
	}
	if(n==3){
		int maxn=max(a[1],a[2]);
		maxn=max(maxn,a[3]);
		if(maxn*2<a[1]+a[2]+a[3]){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	else if(b){
		for(int i =3;i<=n;i++){
			int j=i;
			if(j>n/2)j=n-j;
			long long cnt=1;
			for(int k = n;k> n-j;k--){
				cnt*=k;
			}
			for(int k = 1;k<=j;k++){
				cnt/=k;
			}
			cnt=cnt%998244353;
			ans+=cnt;
			ans=ans%998244353;
		}
	}
	cout<<ans;
	return 0;
}

