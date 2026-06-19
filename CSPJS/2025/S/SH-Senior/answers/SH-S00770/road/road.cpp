#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct node{
	int u , v;
	long long w;
};
int n , m , k , u , v , c , f[10001];
long long w , ans , t[1001][1001] , a[1001][1001];
vector <node> edges;
bool cmp(node x , node y){
	return x.w < y.w;
}
int find(int x){
	if (f[x] == x){
		return x;
	}
	return f[x] = find(f[x]);
}
void marge(int x , int y){
	f[x] = y;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &k);
	memset(a , 127 , sizeof(a));
	for (int i = 1 ; i <= m ; i++){
		scanf("%d%d%lld" , &u , &v , &w);
		if (u > v){
			swap(u , v);
		}
		a[u][v] = w;
	}
	for (int i = 1 ; i <= k ; i++){
		scanf("%d" , &c);
		for (int j = 1 ; j <= n ; j++){
			scanf("%lld" , &w);
			t[i][j] = w;
		}
		for (int j = 1 ; j <= n ; j++){
			for (int k = j + 1 ; k <= n ; k++){
				a[j][k] = min(a[j][k] , t[i][j] + t[i][k] + c);
			}
		}
	}
	for (int i = 1 ; i <= n ; i++){
		for (int j = i + 1 ; j <= n ; j++){
			if (a[i][j] != 9187201950435737471LL){
				edges.push_back({i , j , a[i][j]});
			}
		}
	} 
	sort(edges.begin() , edges.end() , cmp);
	for (int i = 1 ; i <= n ; i++){
		f[i] = i;
	}
	for (auto i : edges){
		if (find(i.u) != find(i.v)){
			marge(i.u , i.v); 
			ans += i.w;
		}
	}
	printf("%lld" , ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
