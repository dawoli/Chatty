#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,coun=0;
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=m*n;i++){
		int j;
		cin>>j;
		if(j>s) coun++;
	}
	int p=coun/n+1;
	cout<<p<<" ";
	if(p%2==0){
		cout<<n-coun%n;
	}
	else cout<<coun%n+1;
	return 0;
}
