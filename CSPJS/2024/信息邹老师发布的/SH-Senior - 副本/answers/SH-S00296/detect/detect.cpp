#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring> 
using namespace std;
const int MAXN = 1e5 + 5;
int read(){
	int input = 0;
	bool minus = 0;
	char tmp = getchar();
	while(tmp != '-' && (tmp > '9' || tmp < '0')){
		tmp = getchar();
	}
	if(tmp == '-'){
		minus = 1;
		tmp = getchar();
	}
	while(tmp >= '0' && tmp <= '9'){
		input *= 10;
		input += tmp - '0';
		tmp = getchar(); 
	}
	if(minus)input *= -1;
	return input;
}
int T, n, m, L, V;
int cnt, off, exceed;
int p[MAXN];
bool b[MAXN];
pair<int, int> r[MAXN]; 
int ceildiv(int a, int b){
	return (a % b) ? (a / b + 1) : (a / b);
} 
bool cmp(pair<int, int> p1, pair<int, int> p2){
	return p1.second < p2.second;
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	T = read();
	while(T--){
		memset(b, 0, sizeof(b));
		cnt = off = exceed = 0;
		n = read();
		m = read();
		L = read();
		V = read(); 
    	int d, v, a;
		for(int i = 1;i <= n;i++){
			d = read();
			v = read();
			a = read();
			if(a == 0){
				if(v > V){
					r[exceed++] = make_pair(d, L);
				}
		    }else if(a < 0){
	    		if(v > V){
	    			r[exceed++] = make_pair(d, d - 1 + ceildiv(V * V - v * v, 2 * a));
				}
			}else{ // a > 0
				if(v > V){
					r[exceed++] = make_pair(d, L);
				}else if(v == V){
					r[exceed++] = make_pair(d + 1, L);
				}else{
					if(V * V - v * v < 2 * a * (L - d)){
						r[exceed++] = make_pair(d + 1 + (V * V - v * v) / (2 * a), L);
					}else{
						r[exceed++] = make_pair(0, 0);
					}
				}
			}
		}
		sort(r, r + exceed, cmp);
		for(int i = 1;i <= m;i++){
			p[i] = read();
		}
		int curr = -1;
		for(int i = 0;i < exceed;i++){
			int tmp = lower_bound(p + 1, p + m + 1, r[i].first) - p;
			if(tmp <= m && p[tmp] <= r[i].second){
				cnt++;
		    	if(curr >= r[i].first){
		    		continue;
			    }
			    tmp = upper_bound(p + 1, p + m + 1, r[i].second) - p - 1;
			    b[tmp] = 1;
			    curr = p[tmp];
			}
		}
		for(int i = 1;i <= m;i++){
			off += !b[i]; 
		}
		printf("%d %d\n", cnt, off); 
	}
	return 0;
}
