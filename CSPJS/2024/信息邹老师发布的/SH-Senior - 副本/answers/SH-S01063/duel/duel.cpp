#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,ans;
multiset<int> killer;
int a[maxn];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	ans = n;
	for(int i = 1;i <= n;i ++){
		scanf("%d",&a[i]);
		killer.insert(a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++){
		set<int>::iterator it;
		it = killer.upper_bound(a[i]);
		if(it != killer.end()){
			killer.erase(it);
			ans --;
		}
	}
	printf("%d",ans);
	return 0;
} 
