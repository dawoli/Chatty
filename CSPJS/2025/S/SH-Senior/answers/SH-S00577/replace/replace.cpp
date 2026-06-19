#include<bits/stdc++.h>
using namespace std;
int n,q;
string xy[200009][2],qu[200009][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>xy[i][0]>>xy[i][1];
	for(int i=1;i<=n;i++) cin>>qu[i][0]>>qu[i][1];
	for(int i=1;i<=q;i++){
		if(qu[i][0].size()!=qu[i][1].size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0,dft1=0,dft2=0,dft3=0,dft4=0;
		for(int j=0;j<qu[i][0].size();j++)
			if(qu[i][0][j]!=qu[i][1][j]) dft1=j;
		for(int j=qu[i][0].size()-1;i>=0;i--)
			if(qu[i][0][j]!=qu[i][1][j]) dft2=j;
		for(int j=1;j<=n;j++){
			for(int k=0;k<xy[j][0].size();k++){
				if(xy[j][0][k]!=xy[j][1][k]) dft3=k;
			}
			for(int k=xy[j][0].size()-1;k>=0;k--){
				if(xy[j][0][k]!=xy[j][1][k]) dft4=k;
			}
			if(substr(qu[i][0]+dft1,dft2-dft1+1)==substr(xy[j][0]+dft3,dft4-dft3+1)
			&&substr(qu[i][1]+dft1,dft2-dft1+1)==substr(xy[j][1]+dft3,dft4-dft3+1)){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
