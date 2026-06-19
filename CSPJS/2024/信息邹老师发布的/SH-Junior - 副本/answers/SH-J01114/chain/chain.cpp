#include<bits/stdc++.h>
using namespace std;
const int Max_n=2e5+5;
int t,n,f,q,l[Max_n],s[Max_n][1005],r[Max_n],c[Max_n];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>f>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++) cin>>s[i][j];
		}
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			bool flag=false;
			if(r[i]==1){
				for(int k=1;k<=l[1];k++){
					if(s[1][k]==c[i] && k>=2 && k<=f){
						cout<<1<<endl;
						flag=true;
						break;
					}
				}
				if(flag==false){
					cout<<0<<endl;
					continue;
				}
				if(flag==true) continue;
			}
			cout<<"0"<<endl;
		}
	}
	return 0;
}
