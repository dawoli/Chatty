#include <iostream>
#include <cmath>
#include <unistd.h>
const int MAXN = 1e+5 + 10;
const int MAXL = 1e+6 + 10;
int T;
int n, m, L, V;
int d[MAXN], v[MAXN], a[MAXN];
int p[MAXN];
int max_depth;
int check_first[MAXN];
struct seg{
	int left;
	int right;
	int mid;
	int total;
	int father;
};
seg sgt[MAXL * 20 + 100000];
void generate_tree(int l,int r,int from, int start){
	if(l == r){
		sgt[start] = {l,l,l,0,from};
		return ;
	}
	int mid = (l + r) >> 1;
	sgt[start] = {l,r,mid,0, from};
	generate_tree(l, mid, start, start << 1);
	generate_tree(mid + 1, r, start, (start << 1) + 1);
	
}
void add(int p){
	int index = (1 << max_depth) + p;
	while(index){
		sgt[index].total++;
		index = sgt[index].father;
	}
}
int search1(int l, int r){
	int depth = 1;
	bool flag = true;
	while (l < r){
		//std::cout << l << " " << r << " " << depth << std::endl;
		if(sgt[depth].mid <= r && sgt[depth].mid >= l){
			if(sgt[depth << 1].total > 0){
				r = sgt[depth].mid, depth = depth << 1;
			}
			else if(sgt[1 + (depth << 1)].total > 0){
				l = sgt[depth].mid + 1, depth = 1 + (depth << 1);
			}
			else{
				flag = false;
				break;
			}
		}
		else if (sgt[depth].mid >= r && sgt[depth << 1].total > 0){
			depth = depth << 1;
		}
		else if (sgt[depth].mid < l && sgt[1 + (depth << 1)].total > 0){
			depth = 1 + (depth << 1);
		}
		else{
			flag = false;
			break;
		}
	}
	return flag ? sgt[depth].left : -1;
}
int search2(int l, int r){
	int depth = 1;
	bool flag = true;
	while (l < r){
		if(sgt[depth].mid <= r && sgt[depth].mid >= l){
			if(sgt[1 + (depth << 1)].total > 0){
				l = sgt[depth].mid + 1, depth = 1 + (depth << 1);
			}
			else if(sgt[depth << 1].total > 0){
				r = sgt[depth].mid, depth = depth << 1;
			}
			else{
				flag = false;
				break;
			}
		}
		else if (sgt[depth].mid <= l && sgt[1 + (depth << 1)].total > 0){
			depth = 1 + depth << 1;
		}
		else if (sgt[depth].mid + 1 >= r && sgt[(depth << 1)].total > 0){
			depth = (depth << 1);
		}
		else{
			flag = false;
			break;
		}
	}
	return flag ? sgt[depth].right : -1;
}
bool check(int n){
	int left = d[n], right = a[n] >= 0 ? L : std::min(L, int(d[n] + (v[n] * v[n] * -0.5) / a[n]));
	int pos_first;
	if(a[n] <= 0)
		pos_first = search1(left, right);
	else if(a[n] > 0)
		pos_first = search2(left, right);
	//std::cout << n << ": " << left << " "<< right <<" " << pos_first << std::endl;
	if(pos_first > 0){
		int dv = v[n] * v[n] + 2 * a[n] * (pos_first - d[n]);
		if(dv > V * V){
			return true;
		}
	}
	return false;
}
void solve(){
	max_depth = int(log2(L)) + 1;
	generate_tree(0,L,0,1);
	for(int i = 0;i < m; ++i)
		add(p[i]);
	//for(int i = 0;i <= L * 2 + 1;++i)
		//if(sgt[i].total)
	//		std::cout << i << "   " << sgt[i].left << "-" << sgt[i].right << "(m: " << sgt[i].mid << ") total: " << sgt[i].total << std::endl;

	int cnt = 0;
	for(int i = 0;i < n;++i){
		if(check(i))
			cnt++;
	}
	std::cout << cnt << std::endl;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	std::cin >> T;
	for(int i = 0;i < T;++i){
		std::cin >> n >> m >> L >> V;
		for(int j = 0;j < n;++j)
			std::cin >> d[j] >> v[j] >> a[j];
		for(int j = 0;j < m;++j){
			std::cin >> p[j];
		}
		solve();
	}
	return 0;
}
