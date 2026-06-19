#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],p[500010],q[500010],r,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[i]=a[i]^p[i-1];
	}
	for(int i=1;i<=n;++i){
		q[i]=p[i]^k;
		for(int j=i-1;j>=0;--j){
			if(q[i]==p[j]&&r<j+1){
				r=i;
				++ans;
			}
		}
	}
	cout<<ans;
	return 0;
}
