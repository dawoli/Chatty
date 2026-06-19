#include<bits/stdc++.h>
#define N 100009
using namespace std;
int n;
multiset<int>ms;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int r,i=1;i<=n;++i)cin>>r,ms.insert(r);
	for(multiset<int>::iterator it=ms.begin();it!=ms.end();++it)
		if(*it!=*ms.begin())ms.erase(ms.begin());
	cout<<ms.size();
	return 0;
}
