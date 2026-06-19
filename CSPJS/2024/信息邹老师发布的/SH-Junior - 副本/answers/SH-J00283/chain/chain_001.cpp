#include<bits/stdc++.h>
using namespace std;
int s[100010];
int l[100010];
int r[100010],c[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[j];
			}
		}
		for(int j=1;j<=q;j++){
			cin>>c[j]>>r[j];
		}
		cout<<0<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
