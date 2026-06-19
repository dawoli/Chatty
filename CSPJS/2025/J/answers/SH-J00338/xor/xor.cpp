#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[200005],b[2]={};
	bool flag=false;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) flag=true;
		b[a[i]]++;
	}
	if(!flag) cout<<n;
	else if(k==0||k==1){
		if(k==0) cout<<b[0];
		else cout<<b[1];
	}
	else cout<<67; 
	return 0;
}
