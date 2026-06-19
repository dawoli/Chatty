#include<bits/stdc++.h>
using namespace std;
int l[1005],s[1005][2005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,t,q;
		cin>>n>>t>>q;
		for(int j=0;j<n;j++){
			cin>>l[j];
			for(int k=0;k<l[j];k++){
				cin>>s[j][k];
			}
		}
		int r,c;
		for(int j=0;j<q;j++){
			cin>>r>>c;
			bool flag=false;
			for(int k=0;k<n;k++){
				int l1=-0x3f3f3f3f;
				for(int a=0;a<l[k];a++){
					if(s[k][a]==1){
						l1=a;
					}
					if(s[k][a]==c){
						if(a-l1<t){
							flag=true;
							break;
						}
					}
				}
				if(flag){
					break;
				}
			}
			if(flag){
				cout<<1<<endl;
			}	
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
