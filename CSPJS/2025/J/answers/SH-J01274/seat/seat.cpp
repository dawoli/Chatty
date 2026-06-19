#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m;
	int a[10010];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int ai;
		cin>>ai;
		a[i]=ai;
	}
	int k=a[0],kw;
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==k){
			kw=n*m-i-1;
		}
	}
	int x=kw/n+1;
	if(x%2!=0){
		if((kw+1)%n==0){
			cout<<x<<" "<<n;
		}
		else{
			cout<<x<<" "<<(kw+1)%3;
		}
	}
	else{
		if((kw+1)%n==0){
			cout<<x<<" "<<1;
		}
		else{
			cout<<x<<" "<<n-(kw+1)%3+1;
		}
	}
	return 0;
}

