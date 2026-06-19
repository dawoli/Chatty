#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXK = (1 << 20);
int n, k, rr, ans, tot, a[MAXN], sum[MAXN];
map <int, int> mp;
queue <int> q[MAXN];

struct segment{
	int l, r;
};

bool cmp(segment x, segment y){
	if (x.r == y.r)
		return x.l > y.l;
	return x.r < y.r;
}

vector <segment> seg;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	cin >> a[1];
	sum[1] = a[1];
	for (int i = 2; i <= n; ++i){
		cin >> a[i];
		sum[i] = a[i] ^ sum[i - 1];
	}
	for (int i = 1; i <= n; ++i){
		int cnt = (k ^ sum[i]);
		int temp;
		if (mp.find(cnt) == mp.end()){
			++tot;
			mp.insert({cnt, tot});
			temp = tot;
		}
		else
			temp = mp[cnt];
		while(!q[temp].empty()){
			int cur = q[temp].front();
			q[temp].pop();
			segment temp2;
			temp2.l = cur + 1;
			temp2.r = i;
			seg.push_back(temp2);				
		}
		if (sum[i] == k){
			segment temp2;
			temp2.l = 1;
			temp2.r = i;		
			seg.push_back(temp2);		
		}
		if (mp.find(sum[i]) == mp.end()){
			++tot;
			mp.insert({sum[i], tot});
			temp = tot;
		}
		else
			temp = mp[sum[i]];
		q[temp].push(i);
	}
	sort(seg.begin(), seg.end(), cmp);
	if (seg.size()){
		rr = seg[0].r;
		++ans;
	}
	for (size_t i = 1; i < seg.size(); ++i){
		if (seg[i].l > rr){
			++ans;
			rr = seg[i].r;
		}
	}
	cout << ans;
	return 0;
} 
