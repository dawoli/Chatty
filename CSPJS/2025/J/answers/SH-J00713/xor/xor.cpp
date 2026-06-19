#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int a[500010];
bool vis[500010];

int ans;

struct seq{
	int l, r;
};
vector <seq> x;

inline seq newseq(int l, int r){
	seq tmp;tmp.l = l;tmp.r = r;
	return tmp;
}

bool cmp(seq l, seq r){
	return (l.r - l.l) < (r.r - r.l);
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)cin >> a[i];
	for(int i = 1; i <= n; i ++){
		int t = a[i];
		int cur = i;
		while(1){
			if(t == k){x.push_back(newseq(i, cur));break;}
			if(cur > n){break;}
			cur ++;
			t ^= a[cur];
		}
	}
	sort(x.begin(),x.end(), cmp);
	for(auto i : x){
		bool f = 0;
		for(int j = i.l; j <= i.r; j ++){
			if(vis[j] == 1){
				f = 1; break;
			}
		}
		if(!f){
			for(int j = i.l; j <= i.r; j ++){
				vis[j] = 1;
			}
			ans ++;
		}
	}
	/*for(auto i : x){
		cout << i.l << " " << i.r << endl;
	}*/
	cout << ans << endl;
	return 0;
}
