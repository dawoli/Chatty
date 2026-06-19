#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct node{
	int l , r;
};
int n , k , a[500001] , x[500001] , l , r , ans;
vector <node> v;
bool f[500001] , b;
bool cmp(node x , node y){
	return x.r - x.l < y.r - y.l;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	scanf("%d%d" , &n , &k);
	for (int i = 1 ; i <= n ; i++){
		scanf("%d" , &a[i]);
		x[i] = x[i - 1] ^ a[i];
	}
	for (int i = 1 ; i <= n ; i++){
		for (int j = i ; j <= n ; j++){
			if ((x[j] ^ x[i - 1]) == k){
				v.push_back({i , j});
				break;
			}
		}
	}
	sort(v.begin() , v.end() , cmp);
	for (auto i : v){
		b = 0;
		for (int j = i.l ; j <= i.r ; j++){
			if(f[j]){
				b = 1;
			}
		}
		if (!b){
			ans++;
			for (int j = i.l ; j <= i.r ; j++){
				f[j] = 1;
			}
		}
	}
	printf("%d" , ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
