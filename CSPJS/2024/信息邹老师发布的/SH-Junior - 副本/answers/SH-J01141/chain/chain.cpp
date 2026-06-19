#include<bits/stdc++.h> 
using namespace std;
int t;
int n , v , q;
int s[1005][1005];
int r , c;
int ans;
void chain(int now , int jw ,int u){
	//u表第几轮，now表现在是第几个人，jw表现在的结尾
	if(ans == 1){
		return ;
	}
	if(u == 0){
		ans = 1;
		return ;
	}
	for(int i = 1; i <= n ; i ++){
		if(ans ==1){
			break;
		}
		if(now != i){
		
			for(int j = 1; j <= s[i][0]; j ++){
				if(ans == 1){
					break;
				}
				if(s[i][j] == jw && j >= 2){
					for(int k = 1; k < j ; k ++){
						if(ans == 1){
							break;
						}
						if(j - k+ 1 <= v){
							if(u == 1){
								if(s[i][k] == 1){	
									chain(i , s[i][k] , u - 1);
								}
							} else{
								chain(i , s[i][k] , u - 1);
							}
						}
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d" , &t);
	for (int q = 1; q <= t; q ++){
		scanf("%d%d%d" , &n,&v,&q);
		for(int i = 1; i <= n ; i ++){
			scanf("%d" , &s[i][0]);
			for(int j = 1; j <= s[i][0]; j ++){
				scanf("%d" , &s[i][j]);
			}
			
		}	
		for(int z = 1; z <= q; z ++){
			scanf("%d%d" , &r , &c);
			chain(0 , c , r);
			printf("%d\n" , ans);
			ans = 0;
		}
	}
	return 0;
}
