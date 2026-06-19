#include <bits/stdc++.h>

using namespace std;
int n, inp[10000];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		scanf("%d", &inp[i]);
	}
	int great = -1, sum=0, ans, side;
	long long int time=1;
	for(int i=1;i<=n;i++){
		time *= 2;
	}
	for (int i=1;i<time;i++){
		side = 0;
		sum = 0;
		great = 0;
		for (int j=0; j<=n-1;j++){
			
			if ((i>>j)& 1){
//				cout << 1 << endl;
				sum+=inp[j+1];
//				cout << inp[j] << endl;
				if (inp[j+1]>great){
					great = inp[j+1];
				}
				side++;
				
			}else{
//				cout << 0 << endl;
			}
		}
//		cout << side;
		if (sum>(great*2)&& side >=3){
//			cout << great << endl;
//			cout << sum << endl;
			ans ++;
//			for (int j=0; j<=n-1;j++){
//			
//				if ((i>>j)& 1){
//					cout << j+1;		
//				}
//			
//			}
//			cout << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
