#include<bits/stdc++.h>

using namespace std;

int stick_cnt[] = {6,2,5,5,4,5,6,3,7,6};

void pf(string x, int cnt){
	while(cnt){
		if(cnt % 2) cout << x;
		cnt /= 2;
		x = x + x;
	}
} // 快速堆叠输出（二分法） 

int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		
		// 唯一一种拼不成数的情况 
		if(n == 1) printf("-1");
		// 特判和 7 相关的
		else if(n % 7 == 0){
			pf("8",n/7);
		} 
		else if(n % 7 == 1){
			printf("10");
			pf("8",n/7-1);
		}
		else if(n % 7 == 2){
			printf("1");
			pf("8",n/7);
		}
		
		printf("\n"); // 结尾换行 
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
