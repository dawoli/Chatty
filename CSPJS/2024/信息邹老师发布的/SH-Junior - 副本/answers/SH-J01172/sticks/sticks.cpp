#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sticknum[10]={6,2,5,5,4,5,6,3,7,6},smallnum[8]={-1,-1,1,7,4,2,6,8},hs[7]={-1,-1,1,2,2,2,6};
ll T,n,x[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
		}
		else if(n%7==0){
			for(ll i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1){
			cout<<1<<0;
			for(ll i=1;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}

