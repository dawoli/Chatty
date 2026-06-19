#include<iostream>
using namespace std;
int s[10010][10010],r[10010],c[10010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int h=1;h<=t;h++){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			int a=1;
			if(r[i]==1){
				for(int x=1;i<=n;x++){
					bool co=false;
					for(int y=1;y<=k;y++){
						if(s[x][y]==c[i]){
							cout<<1<<endl;
							co=true;break;
						}
					}
					if(co) break;
				}
			}
		}
		
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
