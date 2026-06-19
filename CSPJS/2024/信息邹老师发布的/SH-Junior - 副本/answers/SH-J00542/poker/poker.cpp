#include<bits/stdc++.h>
using namespace std;
int n;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string ss;
		cin>>ss;
		s.insert(ss);
	}
	printf("%d",52-(int)s.size());
	return 0;
}
