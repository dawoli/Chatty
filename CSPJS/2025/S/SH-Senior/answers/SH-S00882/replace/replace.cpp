#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string sf[10005],sc[10005],tf,tc,stf;
bool flag=false;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sf[i]>>sc[i];
	}
	while(q--){
		ans=0;
		cin>>tf>>tc;
		for(int i=1;i<=n;i++){
			if(tf.size()<sf[i].size())continue;
			
			
			for(int k=0;k<=stf.size()-sf[i].size();k++){
				stf=tf;
				flag=true;
				for(int j=0;j<sf[i].size();j++){
					if(stf[j+k]!=sf[i][j]){
						flag=false;
					}
				}
				if(flag){
				
					for(int j=0;j<sf[i].size();j++){
						stf[j+k]=sc[i][j];
					}
					if(stf==tc){
						ans++;
						
					}
				
				}
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
