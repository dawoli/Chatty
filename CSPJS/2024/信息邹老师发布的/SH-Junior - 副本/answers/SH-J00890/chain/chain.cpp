#include<bits/stdc++.h>
using namespace std;
int a[110][110],b,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int n,m,k1;
	cin>>n>>k1>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j];
		}
	}	
	for(int i=1;i<=m;i++){
		cin>>b>>c;
		bool flag=1;
		if(b==1){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=a[j][0];k++){
					if(a[j][k]==1){
						for(int l=k+1;l<=a[j][0];l++){
							if(a[j][l]==c){cout<<1;break;
							}
						}
					}
				}
			}
		}
		else{
		for(int ii=1;ii<=n;ii++)
		for(int j=1;j<=a[ii][0];j++){
			if(a[ii][j]==c){
			flag=0;break;}
		}
		if(flag){
			cout<<0<<"\n";
			continue;
		}
		cout<<1;
		}
	}
	
	
	
	return 0;
}
