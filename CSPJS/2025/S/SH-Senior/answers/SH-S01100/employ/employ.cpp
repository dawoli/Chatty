#include <bits/stdc++.h>
using namespace std;
int main() {
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n,m,d=1;
	cin>>n>>m;
	for(int i=n;i>0;i--){
		d=d*i;
	}
	string s;
	int c[n];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	}
	if(m==n){
		cout<<0;
	}
	if(m==1){
		cout<<n;
	}
	else{
		cout<<c;
	}
	
	return 0;
}
