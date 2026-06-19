#include<bits/stdc++.h>
using namespace std;
int n,q,l,ans;
string s[200005][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>t[0]>>t[1];
		l=t[0].size();
		t[0]=' '+t[0];
		t[1]=' '+t[1];
		ans=0;
		for(int i=1;i<=l;i++){
			for(int j=i;j<=l;j++){
				if(t[0].substr(1,i-1)==t[1].substr(1,i-1)&&t[0].substr(j+1,l-j)==t[1].substr(j+1,l-j)){
					for(int k=1;k<=n;k++){
						if(t[0].substr(i,j-i+1)==s[k][0]&&t[1].substr(i,j-i+1)==s[k][1]){
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
