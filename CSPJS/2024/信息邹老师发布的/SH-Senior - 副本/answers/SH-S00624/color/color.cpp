#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[200010];
int b[200010];
int s(int x){
	int ans=0;
	for(int i=1;i<=n;++i){
		b[i]=x%2;
		x/=2;
	}
	for(int i=1;i<=n;++i)
		for(int j=i-1;j>=1;--j)
			if(b[i]==b[j]){
				if(a[i]==a[j])
					ans+=a[i];
				break;
			}
	return ans;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int w=1;w<=t;++w){
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		int maxn=0;
		for(int i=0;i<=pow(2,n);++i)
			maxn=max(maxn,s(i)); 
		cout<<maxn<<endl;
	}
	return 0;
}
