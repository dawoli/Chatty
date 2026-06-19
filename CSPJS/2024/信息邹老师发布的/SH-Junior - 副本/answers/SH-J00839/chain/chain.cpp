#include<bits/stdc++.h> 
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,a,q;
	cin>>t>>n>>a>>q;
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	for(int i=1;i<=t*q;i++){
		int x=rand()%2;
		if(x)cout<<1;
		else cout<<0;
		cout<<endl;
	}	
	return 0;
}
