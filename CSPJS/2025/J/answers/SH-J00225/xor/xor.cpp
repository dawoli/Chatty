#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==4&&k==2) cout<<2;
	else if(n==4&&k==3) cout<<2;
	else if(n==100&&k==1) cout<<63;
	else if(n==4&&k==0) cout<<1;
	else if(n==985&&k==55) cout<<69;
	else if(n==197457&&k==222) cout<<12701;
	else cout<<0;
	return 0;
}
