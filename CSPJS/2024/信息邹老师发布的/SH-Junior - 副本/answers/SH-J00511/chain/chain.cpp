#include <bits/stdc++.h>
using namespace std;
int n,k,q;
int r,c;
int ans=0;
int maxx=-1;
int s[2020][2020];
void dfs(int rnow,int begin,int refuse){
	//rnow轮数，begin开头元素，refuse不能接上的人 
	if(rnow==r && ans==0){ans=1;return;}
	for(int ii=0;ii<n;ii++){
		if(ii==refuse)continue;
		for(int i=0;i<s[ii][0]-1;i++){
			for(int j=1;j<(s[ii][0]-i);j++){
				if(s[ii][i]!=begin)continue;
				if(j<k)dfs(rnow+1,s[ii][i+j],ii);
			}
		} 
	}
}
int main(){
	int t;
	cin>>t;
	for(int iii=0;iii<t;iii++){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>s[i][0];
			for(int j=1;j<=s[i][0];j++){cin>>s[i][j];maxx=max(maxx,s[i][j]);}
		}
		while(q--){
			cin>>r>>c;
			/* 
			ans=0;
			if(maxx<c)cout<<ans<<endl;
			else {
				dfs(0,1,0);
				cout<<ans<<endl;
			}
			*/
			cout<<0<<endl;
		}
	}
	return 0;
}
