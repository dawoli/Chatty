#include<bits/stdc++.h>
using namespace std;
int n,x[100005];
multiset<int> s;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		if(s.size()&&x[i]!=(*s.begin())) s.erase(s.begin());
		s.insert(x[i]);
	}
	cout<<s.size()<<endl;
	return 0;
}
