#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	int s , id;
}a[101];
int n , m , s[11][11] , k;
bool cmp(node x , node y){
	return x.s > y.s;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n * m ; i++){
		scanf("%d" , &a[i].s);
		a[i].id = i;
	}
	sort(a + 1 , a + n * m + 1 , cmp);
	for (int i = 1 ; i <= m ; i++){
		if (i & 1){
			for (int j = 1 ; j <= n ; j++){
				s[j][i] = a[++k].id;
				if (s[j][i] == 1){
					printf("%d %d" , i , j);
				}
			}
		}else{
			for (int j = n ; j ; j--){
				s[j][i] = a[++k].id;
				if (s[j][i] == 1){
					printf("%d %d" , i , j);
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
