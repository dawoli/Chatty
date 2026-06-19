#include<bits/stdc++.h>
using namespace std;
long long cnt[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n,m = -1e9;
	cin>>n;
	for(long long i = 0;i < n;i++){
		long long a;
		cin>>a;
		m = max(m,a);
		cnt[a]++;
	}
	sort(cnt,cnt + m);
	cout<<cnt[m - 1];
	return 0;
}
