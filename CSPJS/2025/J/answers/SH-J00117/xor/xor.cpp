#include<bits/stdc++.h>
using namespace std;
int o,l[500005],ans;
//This program only aims to get partial marks for special properties A and B.
int main(){
	freopen("xor.in","r",stdin)
	freopen("xor.out","w",stdout)
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]==1)
			o++;
	}
	if(k==1)
		cout<<o;
	else {
		for(int i=1;i<=n;){
			if(l[i]==0){
				ans++;
				i+=1;
			} else if(l[i]==1&&l[i+1]==1){
				ans++;
				i+=2;
			} else {
				i+=1;
			}
		}
		cout<<ans;
	}
	return 0;
}
