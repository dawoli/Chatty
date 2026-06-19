#include<bits/stdc++.h>
using namespace std;

int res[50005] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
 	freopen("sticks.in", "r", stdin);
 	freopen("sticks.out", "w", stdout);
	for(int i = 10;i <= 50000;i++){
		long long tmp = i;
		while(tmp){
		    int other = tmp % 10;
		    tmp /= 10;
		    res[i] += res[other];
		}
	}
	long long T;
	scanf("%lld", &T);
	while(T--){
		int flag = 0;
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= 50000;i++){//因为0不是正整数，不符合题意，从1开始 
			if(res[i] == n){
				printf("%d", i);
				flag = 1;
				break;
			}
		}
		if(!flag){
			cout << -1;
		}
	}
 	fclose(stdin);
 	fclose(stdout);
	return 0;
}
