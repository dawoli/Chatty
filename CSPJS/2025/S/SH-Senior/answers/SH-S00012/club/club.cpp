#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	int a1, a2, a3, maxa, max;
}li[100010];
int nums[10]; // 部门人数 
int nexa1[100010], nexa2[100010], nexa3[100010];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		memset(nums, 0, sizeof(nums));
		memset(nexa1, -1, sizeof(nexa1));
		memset(nexa2, -1, sizeof(nexa2));
		memset(nexa3, -1, sizeof(nexa3));
		for (int i = 1; i <= n; i++){
			cin >> li[i].a1 >> li[i].a2 >> li[i].a3;
			if (li[i].a1 >= li[i].a2 && li[i].a1 >= li[i].a3){
				li[i].maxa = 1; li[i].max = li[i].a1;
				if (li[i].a2 >= li[i].a3){
					nexa1[i] = li[i].a1 - li[i].a2;
				} else {
					nexa1[i] = li[i].a1 - li[i].a3;
				}
			} else if (li[i].a2 >= li[i].a1 && li[i].a2 >= li[i].a3){
				li[i].maxa = 2; li[i].max = li[i].a2;
				if (li[i].a1 >= li[i].a3){
					nexa2[i] = li[i].a2 - li[i].a1;
				} else {
					nexa2[i] = li[i].a2 - li[i].a3;
				}
			} else if (li[i].a3 >= li[i].a1 && li[i].a3 >= li[i].a1){
				li[i].maxa = 3; li[i].max = li[i].a3;
				if (li[i].a1 >= li[i].a2){
					nexa3[i] = li[i].a3 - li[i].a1;
				} else {
					nexa3[i] = li[i].a3 - li[i].a2;
				}
			} 
//			else if (li[i].a1 == li[i].a2 && li[i].a1 == li[i].a3){
//				li[i].maxa = 0;
//			} else if (li[i].a1 == li[i].a2){
//				li[i].maxa = 4;
//			} else if (li[i].a1 == li[i].a3){
//				li[i].maxa = 5;
//			} else if (li[i].a2 == li[i].a3){
//				li[i].maxa = 6;
//			}
			
		}
		for (int i = 1; i <= n; i++){
			nums[li[i].maxa]++;
		}
		int flow_num = 0; // 记录超过的人数 
		int flag = 114514; // 记录是否满足每个部门人数都小于n/2 
		for (int i = 1; i <= 3; i++){
			// cout << nums[i] << " "; 
			if (nums[i] > n / 2){
				// 否则记录该部门(易知人数超过n/2的部门只能有一个)
				flag = i;
				flow_num = nums[i] - n / 2;
			}
		}
		ll sum = 0;
		for (int i = 1; i <= n; i++){
			sum += li[i].max;
		}
		if (flag == 114514){
			cout << sum << endl;
			continue;
		}
		if (flag == 1){
			sort(nexa1 + 1, nexa1 + n + 1);
			int cnt = 0;
			for (int i = 1; cnt < flow_num; i++){
				if (nexa1[i] >= 0){
					cnt++;
					sum -= nexa1[i];
				}
			}
			cout << sum << endl;
		} else if (flag == 2){
			sort(nexa2 + 1, nexa2 + n + 1);
			int cnt = 0;
			for (int i = 1; cnt < flow_num; i++){
				if (nexa2[i] >= 0){
					cnt++;
					sum -= nexa2[i];
				}
			}
			cout << sum << endl;
		} else if (flag == 3){
			sort(nexa3 + 1, nexa3 + n + 1);
			int cnt = 0;
			for (int i = 1; cnt < flow_num; i++){
				if (nexa3[i] >= 0){
					cnt++;
					sum -= nexa3[i];
				}
			}
			cout << sum << endl;
		}
		// 尽量让次大值比较大的给次大值(即最大值-次大值较小) 
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
