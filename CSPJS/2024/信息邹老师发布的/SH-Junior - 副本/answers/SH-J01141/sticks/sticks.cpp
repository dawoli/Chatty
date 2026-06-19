#include<bits/stdc++.h>
using namespace std;
int t , n , ans = 1e9;
struct s{
	int num , cost;
}b[8];
void dfs(int lose , int number){
	if(number > ans){
		return ;
	}
	if(lose == 1){
		return ;
	}
	if(lose == 0){
		if(number < ans){
			ans = number;
		}
		return ;
	}
	for(int i = 1; i <= 7; i ++){
		if(lose >= b[i].cost){
			if(b[i].num == 0){
				if(number == 0){
					continue;
				}
			}
			dfs(lose - b[i].cost , number * 10 + b[i].num);
		}
	}
}
int main(){
	b[3].num = 0;b[3].cost=6;
	b[2].num = 6;b[2].cost = 6;
	b[1].num = 8;b[1].cost = 7;
	b[6].num = 7;b[6].cost = 3;
	b[4].num = 2;b[4].cost = 5;
	b[7].num = 1;b[7].cost = 2;
	b[5].num = 4;b[5].cost = 4;
	scanf("%d" , &t);
	for(int i = 1; i <= t; i ++){
		scanf("%d" , &n);
		if(n == 1){
			printf("-1\n");
			continue;
		} 
		dfs(n , 0);
		printf("%d\n" , ans);
		ans = 1e9;
	}
	return 0;
} /*

*/
