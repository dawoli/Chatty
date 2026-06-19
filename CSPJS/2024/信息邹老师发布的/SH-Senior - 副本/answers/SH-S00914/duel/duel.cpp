#include <bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int bucket[100100];
int ans = 0;
int main(){
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);
	scanf("%d" , &n);
	for(register int i = 1 ; i <= n ; ++i){
		scanf("%d" , &a[i]);
		bucket[a[i]]++;
	}
	sort(a + 1 , a + n + 1);
	ans = bucket[a[n]];
	int tmp = -1 , remained_num = 0;
	for(register int i = 100010 ; i >= 1 ; --i){
		if(!bucket[i]) continue;
		if(tmp == -1){
			tmp = bucket[i] , remained_num = 0;
			continue;
		}
		if(tmp + remained_num < bucket[i]){
			remained_num = bucket[i] - (tmp + remained_num);
			tmp = bucket[i];
		}
		else{
			remained_num = 0;
		}
		ans += remained_num;
	}
	printf("%d" , ans);
    return 0;
}
