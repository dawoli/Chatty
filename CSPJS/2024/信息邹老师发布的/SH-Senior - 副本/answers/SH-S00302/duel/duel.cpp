#include<bits/stdc++.h>
#define long long ll
using namespace std;

int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f * x;
}

const int maxn = 1e5 + 10;
int n, a[maxn], res1, res2, cnt[maxn], ans, pre[maxn];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
	}
		sort(a + 1, a + n + 1);
		int pos = 1;
		for(int i = 1; i < n; i++){
			if(a[i] == a[i + 1]) cnt[pos]++;
			else{
				cnt[pos]++;
				pos++;
			}
		}
		cnt[pos]++;
		/*
		for(int i = 1; i <= pos; i++){
			cout << cnt[i] << endl;
		}*/
		for(int i = 1; i < pos; i++){
			pre[i] += cnt[i];
			//cout << pre[i] << endl;
			pre[i + 1] += pre[i] - cnt[i + 1];
			if(pre[i + 1] < 0) pre[i + 1] = 0;
			pre[i + 1] += cnt[n + 1];
		}
		pre[pos] += cnt[pos]; 
		cout << pre[pos];
	
	return 0;
}
