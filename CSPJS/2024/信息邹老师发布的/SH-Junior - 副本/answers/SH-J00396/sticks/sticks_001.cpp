#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N = 1e6+9;
int num[10] = {6,2,5,5,4,5,6,3,7,6};
int nums[N];
void getnum(int x){
	int y = x;
	int t = 0;
	do{
		t = y % 10;
		nums[x] += num[t];
		y /= 10;
	}while(y);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	for (int i = 0;i < N;i++) getnum(i);
	while (T--){
		scanf("%d",&n);
		if (n <= 20){
			int ans = -1;
			if (n > 1){
				for (int i = 1;i < N;i++){
					if (nums[i] == n){
						ans = i;
						break;
					}
				}
			}		
			printf("%d\n",ans);
		}else{
			int nn = n / 7;
			int mm = n % 7;
			
			
			if (mm == 1){printf("%d",10); for (int i = 1;i <= nn-1;i++) printf("%d",8);}
			if (mm == 2){printf("%d",18); for (int i = 1;i <= nn-1;i++) printf("%d",8);}
			if (mm == 3){printf("%d",200); for (int i = 1;i <= nn-2;i++) printf("%d",8);}
			if (mm == 4){printf("%d",20); for (int i = 1;i <= nn-1;i++) printf("%d",8);}
			if (mm == 5){printf("%d",28); for (int i = 1;i <= nn-1;i++) printf("%d",8);}
			if (mm == 6){printf("%d",68); for (int i = 1;i <= nn-1;i++) printf("%d",8);}
			if (mm == 0){
				for (int i = 1;i <= nn;i++) printf("%d",8);
			}
			printf("\n");
		}
		
	}
	return 0;
}
