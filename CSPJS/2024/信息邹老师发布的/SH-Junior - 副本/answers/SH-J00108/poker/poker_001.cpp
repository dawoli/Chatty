#include <bits/stdc++.h>
using namespace std;
int n;
set<string> s;string card;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;for (int i=1;i<=n;++i) cin>>card,s.insert(card);
	printf("%d\n",52-(int)s.size());
	fclose(stdin);fclose(stdout);
	return 0;
}
