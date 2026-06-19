#include <bits/stdc++.h>
using namespace std;
char sa[1000005];
int a[1000005];
int cnt = 1;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", sa);
	for(int i = 0; sa[i] != 0; i++){
		if(sa[i] >= '0' && sa[i] <= '9'){
			a[cnt++] = sa[i] - '0';
		}
	}
	sort(a+1, a+cnt+1);
	for(int i = cnt; i > 1; i--){
		printf("%d", a[i]);
	}
	return 0;
}
