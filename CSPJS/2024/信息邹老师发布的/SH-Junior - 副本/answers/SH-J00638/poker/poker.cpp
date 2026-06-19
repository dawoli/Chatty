#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s[55];
map<string,bool> m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i],m[s[i]]=1;
	for(int i=1;i<=n;i++){
		if(m[s[i]]) ans++,m[s[i]]=0;
	}
	printf("%d\n",52-ans);
	return 0;
}
