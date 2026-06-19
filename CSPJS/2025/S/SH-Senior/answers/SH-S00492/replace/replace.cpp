#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;
long long n, q, midx, idx, snx[1200010][26], sny[1200010][26], typ[5200010], ycnt[5200010];
long long rtx, rty, ans[200010];
struct strpr{
	string x, y;
	bool operator<(const strpr &t)const{
		return x < t.x || (x == t.x && y < t.y);
	}
};
map<strpr, long long> mp;
strpr tl[200010], qs[200010], mt[200010], mq[200010];
vector<long long> mdid[200010], qmdid[200010], edx[5200010], qedx[5200010], tmp;
void dfs(long long p){
	for(auto v : edx[p]){
		ycnt[typ[v]]++;
	}
	for(auto v : qedx[p]){
		string y = mq[v].y;
		long long ly = y.length();
		long long pp = rty; 
		ans[v] += ycnt[rty];
		for(int i = 0; i <= ly - 1; i++){
			if(!sny[pp][y[i] - 'a']){
				break;
			}
			pp = sny[pp][y[i] - 'a'];
			ans[v] += ycnt[pp];
		}
	}
	for(int i = 0; i <= 25; i++){
		if(snx[p][i]){
			dfs(snx[p][i]);
		}
	}
	for(auto v : edx[p]){
		ycnt[typ[v]]--;
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%lld%lld", &n, &q);
	for(int i = 1; i <= n; i++){
		cin >> tl[i].x >> tl[i].y;
	}
	for(int i = 1; i <= q; i++){
		cin >> qs[i].x >> qs[i].y;
	}
	for(int i = 1; i <= n; i++){
		long long l = 0, r = tl[i].x.length() - 1, sl = tl[i].x.length() ;
		while(l <= r && tl[i].x[l] == tl[i].y[l]){
			l++;
		}
		if(l == r + 1){
			continue;
		}
		while(r >= l && tl[i].x[r] == tl[i].y[r]){
			r--;
		}
		strpr md = {"", ""};
		for(int j = l; j <= r; j++){
			md.x += tl[i].x[j];
			md.y += tl[i].y[j];
		}
		mt[i] = {"", ""};
		for(int j = l - 1; j >= 0; j--){
			mt[i].x += tl[i].x[j]; 
		}
		for(int j = r + 1; j <= sl - 1; j++){
			mt[i].y += tl[i].x[j];
		}
		if(mp[md] != 0){
			long long mi = mp[md];
			mdid[mi].push_back(i); 
		}
		else{
			midx++;
			mp[md] = midx;
			mdid[midx].push_back(i); 
		}
	}
	for(int i = 1; i <= q; i++){
		long long l = 0, r = qs[i].x.length() - 1, sl = qs[i].x.length() ;
		while(l <= r && qs[i].x[l] == qs[i].y[l]){
			l++;
		}
		if(l == r + 1){
			continue;
		}
		while(r >= l && qs[i].x[r] == qs[i].y[r]){
			r--;
		}
		strpr md = {"", ""};
		for(int j = l; j <= r; j++){
			md.x += qs[i].x[j];
			md.y += qs[i].y[j];
		}
		mq[i] = {"", ""};
		for(int j = l - 1; j >= 0; j--){
			mq[i].x += tl[i].x[j]; 
		}
		for(int j = r + 1; j <= sl - 1; j++){
			mq[i].y += tl[i].x[j];
		}
		if(mp[md] != 0){
			long long mi = mp[md];
			qmdid[mi].push_back(i); 
		}
		else{
			continue; 
		}
	}
	long long idxx = 0, idxy = 0;
	for(int md = 1; md <= midx; md++){
		idxx++;
		idxy++;
		long long px = 0, py = 0;
		rtx = idxx, rty = idxy;
		for(auto tid : mdid[md]){
			string x = mt[tid].x, y = mt[tid].y;
			long long lx = x.length(), ly = y.length();
			long long p = rtx;
			for(int i = 0; i <= lx - 1; i++){
				if(!snx[p][x[i] - 'a']){
					idxx++;
					snx[p][x[i] - 'a'] = idxx;
				}
				p = snx[p][x[i] - 'a'];
			}
			edx[p].push_back(tid);
			p = rty; 
			for(int i = 0; i <= ly - 1; i++){
				if(!sny[p][y[i] - 'a']){
					idxy++;
					sny[p][y[i] - 'a'] = idxy;
				}
				p = sny[p][y[i] - 'a'];
			}
			typ[tid] = p; 
		}
		
		for(auto qid : qmdid[md]){
			string x = mq[qid].x, y = mq[qid].y;
			long long lx = x.length(), ly = y.length();
			long long p = rtx;
			for(int i = 0; i <= lx - 1; i++){
				if(!snx[p][x[i] - 'a']){
					break;
				}
				p = snx[p][x[i] - 'a'];
			}
			qedx[p].push_back(qid); 
		}
		
		dfs(rtx);
	}
	for(int i = 1; i <= q; i++){
		printf("%lld\n", ans[i]);
	}
	return 0;
}
