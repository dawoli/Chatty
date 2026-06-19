#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	int a[100010];
	int avai[100010];
	int ans = n;
	memset(a,0,sizeof(a));
	int ma = 0;
	for(int i = 0;i < n;i++){
		int k;
		cin >> k;
		ma = max(ma,k);
		a[k]++;
		avai[k]++;
	}
	for(int i = 0;i < ma;i++){
		while(a[i] >= 1){
			for(int j = i + 1;j < ma + 1;j++){
				while(avai[j] > 0 && a[i] > 0){
					ans--;
					a[i]--;
					avai[j]--;	
				}
			}
			break;
		}
	}
	cout << ans << endl;
	return 0;
} 
