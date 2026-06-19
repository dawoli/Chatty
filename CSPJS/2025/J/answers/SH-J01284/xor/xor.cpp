#include<bits/stdc++.h>
using namespace std;
int n,complete=1;
long long k,lst[500005]={0},ans=0,p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>lst[i];
	for(int i=1;i<=n;i++){
		p=lst[i];
		for(int j=i;j>=complete;j--){
			if(p==k){
				ans++;
				complete=i+1;
				i=complete-1;
				break;
			}
			p=p^lst[j-1];
		}
	}
	cout<<ans;
	return 0;
}

