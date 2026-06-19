#include<bits/stdc++.h>
using namespace std;
set<string> p;
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		p.insert(s);
	}
	printf("%d",52-p.size());
	return 0;
}
