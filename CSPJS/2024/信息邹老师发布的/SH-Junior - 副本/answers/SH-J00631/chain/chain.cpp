#include<bits/stdc++.h>
using namespace std;
long long t,a[1005][2005];
map<long long,int> m;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			long long c,cnt=0,f=0;
			cin>>c;
			for(int j=1;j<=c;j++){
				cin>>a[i][j];
				if(f==1){
					cnt++;
					if(cnt>=k){
						f=0;
						continue;
					}
					m[a[i][j]]=1;
				}
				if(a[i][j]==1){
					f=1;
					continue;
				}
			}
		}
		for(int i=1;i<=q;i++){
			long long r,c;
			cin>>r>>c;
			if(m[c]) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}
