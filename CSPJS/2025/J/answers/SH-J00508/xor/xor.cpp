#include<bits/stdc++.h>
using namespace std;

struct node{
	int a, b;
};
int n, m, a[500007], l[500007], r, ans;
vector<node> v;

bool cmp(node x, node y){
	if(x.b == y.b) return x.a > y.a;
	else return x.b < y.b;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i = -~i){
		cin >> a[i];
		l[i] = l[~-i] ^ a[i];
	}
	for(int i = 1; i <= n; i = -~i)	for(int j = i; j <= n; j = -~j) if((l[j] ^ l[~-i]) == m) v.push_back({i, j});
	sort(v.begin(), v.end(), cmp);
	for(auto i : v){
		if(i.a > r){
			ans = -~ans;
			r = i.b;
		}
	}
	cout << ans;
	return 0;
}
