#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q,ans=0;
string t[MAXN][3],s[MAXN][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int p=1;p<=q;p++)
		for(int k=1;k<=n;k++){
			int len=s[k][1].size();
			string s,x,y,z;
			for(int i=0;i<len;i++){
				for(int j=i;j<len;j++){
					y=s[k][1].substr(i,j);
					if(i=0){
						x=" ";
					}
					else{
						x=s[k][1].substr(0,i-1);
					}
					if(j=len-1){
						z=" ";
					}
					else{
						z=s[k][1].substr(j+1,len-1);
					}
					if(y==t[p][1]){
						if(x+t[p][2]+z==s[k][2]){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	return 0;
}
