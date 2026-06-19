#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
using namespace std;

const int MXN = 1e5+5;
int t;
int n;
int ai1, ai2, ai3;
int v[MXN][4];
int dp[MXN];
int cnt[4];
int mxans;

bool vis[MXN];
int mina[4];
int cont;


void dfs(int x, int cnt1, int cnt2, int cnt3, int ans){
	if (x == n+1){
		mxans = max(ans, mxans);
	}
	if (cnt1 < n / 2){
		dfs(x+1, cnt1+1, cnt2, cnt3, ans+v[x][1]);
	}
	if (cnt2 < n / 2){
		dfs(x+1, cnt1, cnt2+1, cnt3, ans+v[x][2]);
	}
	if (cnt3 < n / 2){
		dfs(x+1, cnt1, cnt2, cnt3+1, ans+v[x][3]);
	}
} 

struct node{
	int satis, num;
	bool operator <(const node& a)const{
		return satis > a.satis;
	}
};



int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while (t > 0){
		t--;
		cin>>n;
		if (n <= 30){
			
			mxans = 0;
			cnt[0] = cnt[1] = cnt[2] = 0;
			for (int i = 1; i <= n; i++){
				cin>>ai1>>ai2>>ai3;
				v[i][1] = ai1;
				v[i][2] = ai2;
				v[i][3] = ai3;
			}
			dfs(1, 0, 0, 0, 0);
			cout<<mxans<<"\n";
			continue;
		}
		priority_queue<node> a1;
		priority_queue<node> a2;
		priority_queue<node> a3;
		memset(cnt, 0, sizeof(cnt));
		mxans = 0;
		for (int i = 1; i <= n; i++){
			cin>>ai1>>ai2>>ai3;
			v[i][1] = ai1;
			v[i][2] = ai2;
			v[i][3] = ai3;
			if (ai1 >= ai2 && ai1 >= ai3){
				a1.push({ai1, i});
				mxans += ai1;
				cnt[1]++;
				continue;
			}
			if (ai2 >= ai3 && ai2 >= ai1){
				a2.push({ai2, i});
				mxans += ai2;
				cnt[2]++;
				continue;
			}
			if (ai3 >= ai2 && ai3 >= ai1){
				a3.push({ai3, i});
				mxans += ai3;
				cnt[3]++;
				continue;
			}
		}
		if (cnt[1] > n / 2){
			while (cnt[1] > n / 2){
				int qq = a1.top().num;
				int qv = a1.top().satis;
				a1.pop();
				mxans -= qv;
				mxans += max(v[qq][2], v[qq][3]);
				cnt[1]--;
			}
			cout<<mxans<<"\n";
			continue;
		}
		if (cnt[2] > n / 2){
			while (cnt[2] > n / 2){
				int qq = a2.top().num;
				int qv = a2.top().satis;
				a2.pop();
				mxans -= qv;
				mxans += max(v[qq][1], v[qq][3]);
				cnt[2]--;
			}
			cout<<mxans<<"\n";
			continue;
		}
		if (cnt[3] > n / 2){
			while (cnt[3] > n / 2){
				int qq = a3.top().num;
				int qv = a3.top().satis;
				a3.pop();
				mxans -= qv;
				mxans += max(v[qq][2], v[qq][1]);
				cnt[3]--;
			}
			cout<<mxans<<"\n";
			continue;
		}
	
		
		/*for (int i = 1; i <= n; i++){
			for (int j = n; j >= 0; j--){
				for (int k = 1; k <= 3; k++){
					if (j - v[i][k] >= 0 && ){
						
					}
				}
			}
		}*/
	}
	
	
	
	return 0;
}
