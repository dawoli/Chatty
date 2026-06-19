#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int num[]={6,2,5,5,4,5,6,3,7,6};
bool check(int x){
	int sum=0;
	while(x>0){
		sum+=num[x%10];
		x/=10;
		if(sum>n)return 0;
	}
	if(sum==n)return 1;
	return 0;
}
void solve(){
	int mn=0;
	for(int i=1;i<n/7.0;i++){
		mn=mn*10+8;
	}
	int mx=mn*10+8;
	for(int i=mn;i<=mx;i++){
		if(check(i)){
			cout<<i<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
		} 
		else if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=n/7-1;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else{
			solve();
		}
	}
	return 0;
}

