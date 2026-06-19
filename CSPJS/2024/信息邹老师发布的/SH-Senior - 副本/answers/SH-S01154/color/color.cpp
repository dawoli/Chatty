#include<bits/stdc++.h>
using namespace std;
long long t, n, f[100006];
long long g[100006], h[100006], a[100006], v[1000003];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t; 
	for(int tt=1; tt<=t; tt++){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i];
			g[i]=v[a[i]];
			v[a[i]]=i;
		}
		int tmp=a[n], tmp2=1;
		h[n]=1;
		for(int i=n-1; i>=1; i--){
			if(tmp==a[i]){
				h[i]=1;
				tmp2++;
			}
			else{
				h[i]=tmp2;
				tmp2=1;
			}
			tmp=a[i];
		}
		for(int i=1; i<=n; i++){
			if(g[i]==0){
				f[i]=f[i-1];
				continue;
			}
			f[i]=max(f[g[i]+h[g[i]]]+a[i], f[i-1]);
			f[i]=max(f[i], f[g[i]]+a[i]);
		}
		cout<<f[n]<<"\n";
		for(int i=1; i<=n; i++){
			cout<<f[i]<<" "<<g[i]<<" "<<h[i]<<" "<<endl;
			v[a[i]]=0;
			a[i]=0;
			f[i]=0;
			g[i]=0;
			h[i]=0;
		}
	}
	return 0;
}
