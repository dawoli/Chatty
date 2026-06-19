#include<bits/stdc++.h>
using namespace std;
int t,n,q,k,l[200005],ll[20005][20005],c,r;
int v[1000001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>ll[l[i]][j];
				v[ll[l[i]][j]]=1;
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(v[c]!=1){
				cout<<0<<endl;
			}
			else{
				cout<<1<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
