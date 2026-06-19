#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],Z,O,E;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) Z++;
		else if(a[i]==1) O++;
		else E=max(E,a[i]);
	}
	if(Z==0 && O && E==0){
		if(k==1) cout<<n;
		else cout<<0;
	}
	else if(Z || O && E==0){
		if(k!=1 && k!=0) cout<<0;
		else if(k==0) cout<<Z;
		else cout<<O; 
	}
	else if(k==0) cout<<Z;
	else if(k==1) cout<<O;
	else cout<<n/2;
	return 0;
}
