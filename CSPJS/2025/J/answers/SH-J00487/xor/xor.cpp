#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,xu[255],ans;
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>xu[i];
		if(xu[i]+xu[n]==n){
			ans++;
		}
	}
	cout<<ans;
} 
 
