#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],s[N],f[N],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=i-1;j>=0;j--){
			if(f[j]<f[i])
				break;
			if((s[i]^s[j])==k)
				f[i]=f[j]+1;
		}
	}
	cout<<f[n];
	return 0;
}
