#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,v[10]={6,2,5,5,4,5,6,3,7,6};
ll db[1000]={0,0,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888,18888888,20088888,20888888,28888888,68888888,88888888,108888888,188888888,200888888,208888888,288888888,688888888,888888888};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		else if(n<=50)cout<<db[n]<<"\n";
		else if(n%7==0){
			for(ll i=1;i<=n/7;i++)cout<<"8";
			cout<<"\n";
		}
		else if(n%7==1){
			cout<<"10";
			for(ll i=2;i<=n/7;i++)cout<<"8";
			cout<<"\n";
		}
		else if(n%7==2){
			cout<<"1";
			for(ll i=1;i<=n/7;i++)cout<<"8";
			cout<<"\n";
		}
		else if(n%7==3){
			cout<<"200";
			for(ll i=3;i<=n/7;i++)cout<<"8";
			cout<<"\n";
		}
		else if(n%7==4){
			cout<<"20";
			for(ll i=2;i<=n/7;i++)cout<<"8";
			cout<<"\n";
		}
		else if(n%7==5){
			cout<<"2";
			for(ll i=1;i<=n/7;i++)cout<<"8";
			cout<<"\n";
		}
		else if(n%7==6){
			cout<<"6";
			for(ll i=1;i<=n/7;i++)cout<<"8";
			cout<<"\n";
		}
	}
	return 0;
} 
