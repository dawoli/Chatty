#include<cstdio>
#include<string>
using namespace std;
int n , q , ans;
char x[5000001] , y[5000001];
string c[200001][2] , a , b , d , aa;
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	scanf("%d%d" , &n , &q);
	for (int i = 1 ; i <= n ; i++){
		scanf("%s%s" , x , y);
		c[i][0] = x;
		c[i][1] = y;
	}
	while (q--){
		ans = 0;
		scanf("%s%s" , x , y);
		a = x;
		b = y;
		for (int i = 1 ; i <= n ; i++){
			aa = a;
			int l = aa.find(c[i][0]);
			if (l == string::npos){
				break;
			}
			d = aa.substr(l , c[i][0].size());
			if (d == c[i][0]){
				for (int j = 0 ; j < d.size() ; j++){
					aa[l + j] = c[i][1][j];
				}
			}
			if (aa == b){
				ans++;
			}
		}
		printf("%d\n" , ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
