#include<bits/stdc++.h>
using namespace std;
int a[200000],b[200000],r[200000],c[200000];
int s[2000][2000];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		cin>>n>>k>>q;
		int flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=a[i];j++){
				cin>>s[i][j];
				if(flag&&j-flag+1<=k){
					b[s[i][j]]=1;
				}
				if(s[i][j]==1){
					flag=j;
				}
			}
			flag=0;
		}	
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			if(b[c[i]]){
				cout<<1<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}
