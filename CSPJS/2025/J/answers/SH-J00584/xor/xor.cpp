#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int ten_to_two(int x){
	int y=0,p=1;
	while(x>0){
		y+=x%2*p;
		x/=2;
		p*=10;
	}
	return y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}
		else a[i]=ten_to_two(a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=-1&&(a[i]-1==ten_to_two(k)||a[i]+1==ten_to_two(k))) ans++;
	}
	if(k==0) ans--;
	cout<<ans;
	return 0;
}
