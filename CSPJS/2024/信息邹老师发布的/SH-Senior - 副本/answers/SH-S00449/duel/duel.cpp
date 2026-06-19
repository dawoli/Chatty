#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int a[100005];
int cnt = 0;
vector <pair<int, int> > b;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	for(int i = 1;i <= n;i++){
		if(!b.size()){
			b.push_back(make_pair(a[i], 1));
		}else{
			if(b[b.size()-1].first == a[i]){
				b[b.size()-1].second++;
			}else{
				b.push_back(make_pair(a[i], 1));
			}
		}
	}
	for(int i = 0;i < b.size();i++){
		cnt = b[i].second+max(cnt-b[i].second, 0);
	}
	printf("%d\n", cnt);
	return 0;
}