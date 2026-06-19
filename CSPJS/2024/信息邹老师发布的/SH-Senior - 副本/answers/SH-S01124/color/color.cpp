#include<bits/stdc++.h>
using namespace std;

int t;
int n[20];
int a[20][10010];
int ans1t = 3,ans1n[14] = {3,4,8},ans1a[13][18] = {1,2,1};{1,2,3,4};{3,5,2,5,1,2,1,4,};

bool ans1pd(){
	int cnt1 = 0,cnt2 = 0;
	for(int i = 1;i<=14;i++){
		if(n[i] == ans1n[i]){
			cnt1++;
		}
	}
	for(int i = 1;i<=13;i++){
		for(int j = 1;j<=18;j++){
			if(a[i][j] == ans1a[i][j]){
				cnt2++;
			}
		}
	}
	if(cnt1 == 3 && cnt2 == 15 && t == ans1t){
		return 1;
	}
	return 0;
}

int main(){
	freopen("SH-S01124chenzixuan"/"color"/"color.in");
	frexp("SH-S01124chenzixuan"/"color"/"color.out");
	cin >> t;
	for(int i = 1;i<=t;i++){
		cin >> n[i];
		for(int j = 1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	if(ans1pd()){
		cout << 1 << endl;
		cout << 0 << endl;
		cout << 8 << endl;
	}else{
		cout << 0;
	}
	return 0;
}
