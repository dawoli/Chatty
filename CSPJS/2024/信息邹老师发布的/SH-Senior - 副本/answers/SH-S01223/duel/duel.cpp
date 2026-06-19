#include <bits/stdc++.h>
using namespace std;
int a[200000];
int cnt[200000];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]] ++;
	}
	int c = 0;
	for(int i=1;i<=100000;i++)
		c = max(c, cnt[i]);
	cout << c <<endl;
	return 0;
}
