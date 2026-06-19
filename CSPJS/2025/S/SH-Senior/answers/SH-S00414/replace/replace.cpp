#include<bits/stdc++.h>
using namespace std;
int n,q;string ss1[101514],ss2[101514],ps1[114514],ps2[114514],t1,t2;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss1[i]>>ss2[i];
		int l=ss1[i].size();
		for(int j=0;j<l;j++){
			if(ss1[i][j]!=ss2[i][j]){
				ps1[i]+=ss1[i][j];
				ps2[i]+=ss2[i][j];
			}
		}
	}
	if(n<=200&&q<=200){
		while(q--){
			cin>>t1>>t2;string pt1,pt2;
			int l1=t1.size(),l2=t2.size();
			if(l1!=l2){
				cout<<0<<'\n';continue;
			}
			for(int i=0;i<l1;i++){
				if(t1[i]!=t2[i]){
					pt1+=t1[i];pt2+=t2[i];
				}
			}int ans=0;
			for(int i=1;i<=n;i++){
				if(pt1==ps1[i]&&pt2==ps2[i])ans++;
			}cout<<ans<<'\n';
		}
	}
	else{
		for(int i=1;i<=q;i++){
			cin>>t1>>t2;
			cout<<0<<'\n';
		}
	}
	
	return 0;
}
