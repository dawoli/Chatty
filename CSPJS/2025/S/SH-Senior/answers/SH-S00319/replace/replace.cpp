#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f;
//struct node{
//	long long val[3];
//	long long st, nd;
//	bool operator <(node other){
//		return st - nd < other.st - other.nd;
//	}
//};
//int T;
//int n;
//long long ans;
//node a[MAXN];
//vector<node> clubs[3];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	scanf("%d", &T);
//	while(T--){
//		for(int i = 0;i < 3;i++){
//			clubs[i].clear();
//		}
//		ans = 0;
//		scanf("%d", &n);
//		for(int i = 1;i <= n;i++){
//			scanf("%lld%lld%lld", &a[i].val[0], &a[i].val[1], &a[i].val[2]);
//			a[i].st = max(max(a[i].val[0], a[i].val[1]), a[i].val[2]);
//			if(a[i].st == a[i].val[0]){
//				a[i].nd = max(a[i].val[1], a[i].val[2]);
//				clubs[0].push_back(a[i]);
//				ans += a[i].st;
//			}else if(a[i].st == a[i].val[1]){
//				a[i].nd = max(a[i].val[0], a[i].val[2]);
//				clubs[1].push_back(a[i]);
//				ans += a[i].st;
//			}else{
//				a[i].nd = max(a[i].val[0], a[i].val[1]);
//				clubs[2].push_back(a[i]);
//				ans += a[i].st;
//			}
//		}
//		if(clubs[0].size() > (n >> 1)){
//			sort(clubs[0].begin(), clubs[0].end());
//			for(int i = 0;i < clubs[0].size() - (n >> 1);i++){
//				ans -= clubs[0][i].st - clubs[0][i].nd;
//			}
//		}else if(clubs[1].size() > (n >> 1)){
//			sort(clubs[1].begin(), clubs[1].end());
//			for(int i = 0;i < clubs[1].size() - (n >> 1);i++){
//				ans -= clubs[1][i].st - clubs[1][i].nd;
//			}
//		}else if(clubs[2].size() > (n >> 1)){
//			sort(clubs[2].begin(), clubs[2].end());
//			for(int i = 0;i < clubs[2].size() - (n >> 1);i++){
//				ans -= clubs[2][i].st - clubs[2][i].nd;
//			}
//		}
//		printf("%lld\n", ans);
//	}
	return 0;
}
