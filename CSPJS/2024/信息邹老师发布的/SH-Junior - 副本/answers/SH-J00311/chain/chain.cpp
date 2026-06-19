#include<bits/stdc++.h>
using namespace std;
bool flag;
int t,n,k,q,a[1005][2005],r,c,ans,s,e,l;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>l;
			for(int k=1;k<=l;k++)cin>>a[j][k];
		}
		for(int j=1;j<=q;j++){
			cin>>r>>c;
			ans=0;
			if(r==1){
				flag=false;
				for(int k=1;k<=n;k++){
					for(int o=1;o<=l;o++){
						if(a[k][o]==1){
							s=o;
						}
						if(a[k][o]==c){
							e=o;
						}
					}
					if(s-e>=2 && s-e<=k){
						flag=true;
						break;
					}
				}
			}
			if(flag==true)ans=1;
			else ans=0;
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
