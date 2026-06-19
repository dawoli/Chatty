#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N]; 
int b[N];
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	int mvp=0;
	int x=0;
	int y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		} 
		if(a[i]==0) mvp++;
	}
	if(cnt==n){
		if(n==0) cout<<"0";
		else if(n==1) cout<<"0";
		else if(n==2) cout<<"1";
		else if(n%2==0) cout<<n/2;
		else cout<<(n-1)/2;
	}
	return 0;
}
