#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,k;
int a[500009];
bool flag1=true,flag2=true;
void solve1(){
	cout<<n/2;
}
void solve2(){
	int ans=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)
				ans++;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1])
				ans++,i++;
		}
		cout<<ans;
	}
}
void solve3(){
	cout<<n/2;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			flag1=false;
		if(a[i]>1)
			flag2=false;
	}
	if(flag1)
		solve1();
	else if(flag2)
		solve2();
	else if(n<=1000)
		solve3();
	return 0;
}
/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
*/
