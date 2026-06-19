#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e5+5;
int n,a[N],cnt[N];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int MAX=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],
		cnt[a[i]]++,
		MAX=max(MAX,a[i]);
	int r=0;
	for(int i=1;i<=MAX;i++)if(cnt[i]>r) r=cnt[i];
	cout<<r;
	return 0;
}
