#include<bits/stdc++.h>
using namespace std;
int n,k,nw,u[1048576],mr,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	u[0]=1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		nw^=x;
		if(u[nw^k]>mr){
			mr=i;
			ans++;
		}
		u[nw]=i+1;
	}
	cout<<ans;
	return 0;
}
