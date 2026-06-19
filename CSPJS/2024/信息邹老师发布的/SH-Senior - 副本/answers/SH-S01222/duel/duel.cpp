#include<bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n,a[maxn],ans;
multiset<int> xx,yy; 
inline int read(){
	int x = 0,f = 1; char c = getchar();
	while('0' > c || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	} return x * f;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n = read();
	for(int i = 1 ; i <= n ; i ++) a[i] = read();
	sort(a + 1,a + n + 1);
	for(int i = 1 ; i <= n ; i ++) {
		if(a[i] == a[1])xx.insert(a[i]);
		if(a[i] != a[1])yy.insert(a[i]);	
	}
	for(int i = 1 ; i <= n ; i ++){
		multiset<int>::iterator it = yy.upper_bound(a[i]);
		if(it == yy.end()) continue;
		int num = *it;
		xx.insert(num); 
		yy.erase(it);
		multiset<int>::iterator it2 = xx.lower_bound(a[i]);
		xx.erase(it2);
		ans += 1;
	}
	printf("%d\n",n - ans);
	return 0;
}
