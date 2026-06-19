#include<bits/stdc++.h>
using namespace std;
#define forRange(i1,_a,_b) for(i1 = _a; i1 < _b; i1 ++)

const int MAXN = 1e5 + 10;
int n,T;
int to[MAXN],p[3];
long long ans = 0;

struct Happiness{
	long long fir;
	long long sec;
	long long thi;
	long long to_sort[3];
	long long to_use[3];
}h[MAXN],in[MAXN];

bool cmp(int m, int n){
	if(h[m].to_sort[1] != h[n].to_sort[1])
		return h[m].to_sort[1] > h[n].to_sort[1];
	return h[m].to_sort[2] > h[n].to_sort[2];
}



void _init_(int n){
	int i;long long maxn;
	p[0] = 0;p[1] = 0;p[2] = 0;
	forRange(i, 0, n){
		maxn = max(max(in[i].fir, in[i].sec), in[i].thi);
		h[i].fir = maxn - in[i].fir;
		h[i].sec = maxn - in[i].sec;
		h[i].thi = maxn - in[i].thi;
//		cout << "for " << i << " fir: " << h[i].fir << " sec: " << h[i].sec << " thi: " << h[i].thi << "\n";
		h[i].to_sort[0] = 0;
		h[i].to_sort[1] = h[i].fir + h[i].sec + h[i].thi - max(h[i].fir, max(h[i].sec, h[i].thi));
		h[i].to_sort[2] = max(h[i].fir, max(h[i].sec, h[i].thi));
		if(h[i].fir <= h[i].sec && h[i].fir <= h[i].thi) {
			h[i].to_use[0] = 0;
			h[i].to_use[1] = (h[i].sec <= h[i].thi ? 1:2);
			h[i].to_use[2] = (h[i].sec <= h[i].thi ? 2:1);
		}else
		if(h[i].fir >= h[i].sec && h[i].sec <= h[i].thi) {
			h[i].to_use[0] = 1;
			h[i].to_use[1] = (h[i].fir <= h[i].thi ? 0:2);
			h[i].to_use[2] = (h[i].fir <= h[i].thi ? 2:0);
		}else
		if(h[i].thi <= h[i].sec && h[i].thi <= h[i].fir) {
			h[i].to_use[0] = 2;
			h[i].to_use[1] = (h[i].fir <= h[i].sec ? 0:1);
			h[i].to_use[2] = (h[i].fir <= h[i].sec ? 1:0);
		}
//		cout << "for " << i << " to_sort: {" << h[i].to_sort[0] << ", " << h[i].to_sort[1] << ", " << h[i].to_sort[2] << "}\n";
//		cout << "for " << i << " to_use : {" << h[i].to_use[0]  << ", " << h[i].to_use[1]  << ", " << h[i].to_use[2]  << "}\n";
		to[i] = i;
	}
	return;
}

//void checkanswers(){
//	
//	return 0;
//	
//	
//	
//}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,k,l;
	
	
	
	for(cin >> T; T; T --){
		ans = 0;
		cin >> n;
		forRange(i, 0, n){
			cin >> in[i].fir >> in[i].sec >> in[i].thi;
		}
		_init_(n);
		sort(to, to + n, cmp);
		forRange(i, 0, n){
//			cout << i << " : " << to[i] << "\n";
		}
		forRange(i, 0, n){
			if(p[h[to[i]].to_use[0]] <= n / 2 - 1){
//				cout << "put in " << h[to[i]].to_use[0] << " to " << p[h[to[i]].to_use[0]] << "\n";
				p[h[to[i]].to_use[0]] ++;
				ans += max(max(in[to[i]].fir, in[to[i]].sec), in[to[i]].thi) - h[to[i]].to_sort[0];
			}else if(p[h[to[i]].to_use[1]] <= n / 2 - 1){
//				cout << "put in " << h[to[i]].to_use[1] << " to " << p[h[to[i]].to_use[1]] << "\n";
				p[h[to[i]].to_use[1]] ++;
				ans += max(max(in[to[i]].fir, in[to[i]].sec), in[to[i]].thi) - h[to[i]].to_sort[1];
			}else{
//				cout << "put in " << h[to[i]].to_use[2] << " to " << p[h[to[i]].to_use[2]] << "\n";
				p[h[to[i]].to_use[2]] ++;
				ans += max(max(in[to[i]].fir, in[to[i]].sec), in[to[i]].thi) - h[to[i]].to_sort[2];
			}
		}
		cout << ans << "\n";
	}
	
	
	
//	fclose(stdin);
//	checkanswers();
	
	return 0;
} 
