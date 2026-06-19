#include<bits/stdc++.h>
using namespace std;
int s[1005][2005]={},l[2005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		while(q--){
			long long r,c;
			cin>>r>>c;
			bool flag=1;
			for(long long i=1;i<=n&&flag==1;i++){
				for(long long j=1;j<=l[i];j++){
					if(s[i][j]==c&&j!=1){
						cout<<1<<endl;
						flag=0;
						break;
					}
				}
			}
			if(flag==1) cout<<0<<endl;
		}
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

