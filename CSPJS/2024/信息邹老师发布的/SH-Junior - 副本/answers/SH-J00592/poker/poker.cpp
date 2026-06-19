#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
map<string,bool>m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s;
		if(!m[s])ans++,m[s]=1;
	}
	printf("%d\n",52-ans);
	return 0;
}
