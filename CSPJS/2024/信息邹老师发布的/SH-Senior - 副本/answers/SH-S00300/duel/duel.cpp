#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,a[N];
multiset <int> s;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(s.empty()){
			s.insert(-a[i]);
			continue;
		}
		multiset <int>::iterator it=s.upper_bound(-a[i]);
		if(it!=s.end()) s.erase(it);
		s.insert(-a[i]);
	}
	cout<<s.size()<<'\n';
	return 0;
} 
