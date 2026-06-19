#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 10;
struct node{
	int begin, end;
}pairs[N];
int T, A[N], C[N], colorA[N], p = 0;
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T--){
		int n, ans = 0;
		p = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> A[i];
			C[i] = 0;
			colorA[i] = 0;
		}
		for (int i = n; i >= 1; i--){
			int maxn = 0, maxid = -1;
			for (int j = i - 1; j >= 1; j--){
				if (A[j] == A[i] && A[j] > maxn){
					maxn = A[j];
					maxid = j;
				}
			}
			if (maxid != -1){
				pairs[p++] = {maxid, i};
			}
		}
		p--;
		for (int i = 0; i <= p; i++){
			node cnt = pairs[i];
			for (int j = cnt.begin + 1; j < cnt.end; j++){
				colorA[j] = (colorA[cnt.end] + 1) % 2;
				colorA[cnt.begin] = colorA[cnt.end];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = i - 1; j >= 1; j--){
				if (A[i] == A[j] && colorA[i] == colorA[j]){
					C[i] = A[i];
					break;
				}else{
					C[i] = 0;
				}
			}
		}
		for (int i = 1; i <= n; i++){
			ans += C[i];
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
