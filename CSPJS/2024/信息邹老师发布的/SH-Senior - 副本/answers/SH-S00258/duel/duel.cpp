#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N],cnt[N];
bool cd1(){for(int i=1;i<=n;++i)if(a[i]>2)return 0;return 1;}
set<int>s;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i],s.insert(a[i]);
	sort(a+1,a+1+n);
	if(cd1()){int cnt=0;for(int i=1;i<=n;++i)if(a[i]==2)++cnt;cout<<max(cnt,n-cnt)<<'\n';return 0;}
	cout<<s.size()<<'\n';
	return 0;
}
