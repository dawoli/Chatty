#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)  cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,cmd);
	int ans;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			ans=i;
			break;
		}
	}
	if(ans%n==0){
		int b=ans/n;
		if(b%2!=0)cout<<b<<" "<<m;
		else cout<<b<<" "<<1;
	}
	else {
		int b=ans/n+1;
		if(b%2!=0)cout<<b<<" "<<ans%n;
		else cout<<b<<" "<<m-ans%n+1;
	}
}

