#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7,M=1e6+7;
int T,n,a[N],f[N];
int check(int x,int loc){
	for(int i=loc-1;i>=1;--i)
	    if(a[i]==x) return i;
	return false;
}
bool cov(int b,int e){
	for(int i=b+1;i<e;++i)
		for(int j=i+2;j<e;++j)
			if(a[i]==a[j]) return true;
	return false;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=2;i<=n;++i){
			int t=check(a[i],i);
			if(!t) f[i]=f[i-1];
			else{
				if(cov(t,i)) f[i]=max(f[i-1],f[t]+a[i]);
				else f[i]=f[i-1]+a[i];
			}
    	}
    	cout<<f[n]<<endl;
	}
	return 0;
}
