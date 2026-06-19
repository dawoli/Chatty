#include<bits/stdc++.h>
using namespace std;
int n;
map<pair<char,char>,int>mp;
int ans = 52;
char enl;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);scanf("%c",&enl);
	for(int i = 1;i <= n;i++){
		char fl,pt;
		scanf("%c%c%c",&fl,&pt,&enl);
		if(!mp[make_pair(fl,pt)]){
			ans--;
			mp[make_pair(fl,pt)] = true;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
