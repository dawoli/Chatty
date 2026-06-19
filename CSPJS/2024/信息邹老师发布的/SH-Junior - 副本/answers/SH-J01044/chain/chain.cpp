#include <iostream>
#include <cstdio>
#include <vector>
using namesapce std;

int T,n,k,q;
vector <int> v[1005];
int r[100005];
int c[100005];


int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin>>T;
	for (int t=1;t<=T;t++){
		cin>>n>>k>>q;
		for (int i=1;i<=n;i++){
			int l1;cin>>l1;
			for (int j=1;j<=l1;j++){
				int x;cin>>x;
				v[i].push_back(x);
			}
		} 
		
		for (int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			bool flag=false;
			for (int i=1;i<=n;i++){
				for (int j=0;j<v[i].size();j++){
					if (v[i][j]==c[i]){
						flag=true;
					}
				}
			}
			if (flag==true)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
