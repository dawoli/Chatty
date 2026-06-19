#include<bits/stdc++.h>
using namespace std;
int n,k,q,l,r,c;
int dst[100005];
vector<int> Al[100005];
int main(){
	cin.tie(nullptr);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T,x;
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			int js;
			for(int j=1;j<=l;j++){
				cin>>x;
				Al[i].push_back(x);
				if(x==1){
					js=j;
					
				}if(j-js>0&&j-js<k){
						dst[x]=1;
					} 
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(r==1){
				if(dst[c]==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				if(dst[c]<=r){
					cout<<1;
				}else{
					cout<<0;
				}
			}
			cout<<'\n';
		}
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
