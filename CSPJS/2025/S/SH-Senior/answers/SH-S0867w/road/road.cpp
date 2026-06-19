#include<bits/stdc++.h>
using namespace std;
#define forRange(i1,_a,_b) for(i1 = _a; i1 < _b; i1 ++)

const long long MAXN = 1e4 + 10ll;
const long long MAXM = 1e6 + 10ll;
const long long MAXK = 10 + 10ll;

long long low[MAXN + MAXK], viscnt;
long long n,m,k;
long long ans = 0ll,ians = 0ll;

struct edge{
	long long u;
	long long v;
	long long w;
}road[MAXM + MAXK * MAXN];

bool cmp(edge m,edge n){
	return m.w < n.w;
}

void _init_(){
	int i;
	forRange(i, 0, n + k){
		low[i] = i;
	}
	viscnt = 1ll;
	ians = 0ll;
	return;
}

long long getlow(long long fro){
	if(fro == low[fro]) return fro;
	low[fro] = getlow(low[fro]);
	return low[fro];
}

void addedge(long long fro, long long des){
	long long lowdes = getlow(des), lowfro = getlow(fro);
	if(lowdes != lowfro && des < n && fro < n){
		viscnt ++;
	} 
	low[lowdes] = lowfro;
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,l;
	cin >> n >> m >> k;
	forRange(i, 0, m + k * n){
		road[i].u = -1ll;
		road[i].v = -1ll;
		road[i].w = 0ll;
	}
	forRange(i, 0, m){
		cin >> road[i].u >> road[i].v >> road[i].w;
		road[i].u--;
		road[i].v--;
	}
	_init_();
	sort(road, road + m, cmp);
	forRange(i, 0, m){
		if(getlow(road[i].u) == getlow(road[i].v)) continue;
		ans += road[i].w;
		addedge(road[i].u, road[i].v);
		if(viscnt >= n) break;
	}
	long long in1;long long in2;
	long long add = 0ll;
	
	forRange(l, 0, k){
		_init_();
		cin >> in1;
		forRange(j, 0, n){
			cin >> in2;
			road[m + add * n + j].u = j;
			road[m + add * n + j].v = n + add;
			road[m + add * n + j].w = in2;
		}
		add++;
		sort(road, road + add * n + m, cmp);
		forRange(i, 0, m + add * n){
			if(getlow(road[i].u) == getlow(road[i].v)) continue;
			ians += road[i].w;
			addedge(road[i].u, road[i].v);
			if(viscnt >= n) break;
		}
		if(ians + in1 < ans){
//			cout << "change ans in ians+in1 : " << ians << "+" << in1 << " which is bigger then " << ans << " then add "<< add <<"\n";
			ans = ians + in1;
		}
		else add--;
	}
	
	cout << ans;
	
	
	
	
	
//	fclose(stdin);
//	checkanswers();
	
	return 0;
} 



/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
