#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,l[1005],s[1005][1005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
	  cin>>n>>k>>q;
	  if(n>1000){
	  	for(int i=1;i<=q;i++) cout<<"0"<<endl;
	  	continue;
	  }
	  for(int i=1;i<=n;i++){
	  	cin>>l[i];
	  	for(int j=1;j<=l[i];j++) cin>>s[i][j];
	  }
	  while(q--){
	  	cin>>r>>c;
	  	bool val=false;
	  	for(int i=1;i<=n;i++){
	  	  for(int j=1;j<=l[i];j++){
	  	  	if(s[i][j]==1){
	  	  	  for(int dis=j+1;dis<=j+k&&dis<=l[i];dis++){
	  	  	  	if(s[i][dis]==c){
	  	  	  	  val=true;
	  	  	  	  break;
				}
			  }
			}
			if(val){
			  break;
			}
		  }
		  if(val){
		  	break;
		  }
		}
		if(val) cout<<"1"<<endl;
		else cout<<"0"<<endl;
	  }
	}
	return 0;
}
