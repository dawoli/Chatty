#include<bits/stdc++.h>
using namespace std;
int t,n,m;string a[6][9];
signed main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++)cin>>a[i][j];
		}cin>>n>>m;
		int d=m,cnt=0;
		for(int i=1;i<=n;i++){
			if(d==6){
				d++;
				continue;
			}if(d==7){
				d=1;
				continue;
			}for(int j=1;j<=8;j++){
				if(a[d][j]=="math")cnt++;
			}d++;
		}cout<<cnt<<'\n';
	} 
}
