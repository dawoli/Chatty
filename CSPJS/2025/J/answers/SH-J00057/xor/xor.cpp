#include<bits/stdc++.h>
using namespace std;
int a[100013];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
		}
		if(a[1]+a[2]==k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
