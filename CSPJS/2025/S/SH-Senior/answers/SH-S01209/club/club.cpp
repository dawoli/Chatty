#include <bits/stdc++.h>

using namespace std;

int T;
struct student{
	int satis_1, satis_2, satis_3;
};
bool cmp(student x, student y){
	if(x.satis_1 != y.satis_1) return x.satis_1 > y.satis_1;
	if(x.satis_2 != y.satis_2) return x.satis_2 > y.satis_2;
	return x.satis_3 > y.satis_3;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		
		vector<student> v;
		for(int i = 0; i < n; i++){
			int s1, s2, s3;
			cin >> s1 >> s2 >> s3;
			v.push_back({s1, s2, s3}); 
		}
		
		sort(v.begin(), v.end(), cmp); 
		int dp[100005][4] = {};
		int cnt[4] = {};
		dp[0][1] = v[0].satis_1, dp[0][2] = v[0].satis_2, dp[0][3] = v[0].satis_3;
		for(int i = 0; i < n; i++){
			int var;
			if(cnt[1] < n / 2 && cnt[2] < n / 2 && cnt[3] < n / 2){
				if(max(max(v[i].satis_1, v[i].satis_2), v[i].satis_2) == v[i].satis_2) cnt[1]++;
				else if(max(max(v[i].satis_1, v[i].satis_2), v[i].satis_3)== v[i].satis_2) cnt[2]++;
				else cnt[3]++;
				var = max(max(v[i].satis_2, v[i].satis_2), v[i].satis_3);
			}
			else if(cnt[1] < n / 2 && cnt[2] < n / 2){
				if(max(v[i].satis_1, v[i].satis_2)== v[i].satis_1) cnt[1]++;
				else cnt[2]++;
				var = max(v[i].satis_1, v[i].satis_2);
			}
			else if(cnt[1] < n / 2 && cnt[3] < n / 2){
				if(max(v[i].satis_1, v[i].satis_3) == v[i].satis_1) cnt[1]++; 
				else cnt[3]++;
				var = max(v[i].satis_1, v[i].satis_3);
			}
			else if(cnt[2] < n / 2 && cnt[3] < n / 2){
				if(max(v[i].satis_1, v[i].satis_2) == v[i].satis_2) cnt[2]++;
				else cnt[3]++;
				var = max(v[i].satis_2, v[i].satis_3);
			}
			else if(cnt[1] < n / 2){
				var = v[i].satis_1;
			}
			else if(cnt[2] < n / 2){
				var = v[i].satis_2;
			}
			else{
				var = v[i].satis_3;
			}
			dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + var);
			dp[i + 1][2] = max(dp[i + 1][2], dp[i][2] + var);
			dp[i + 1][3] = max(dp[i + 1][3], dp[i][3] + var);
		}
		cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
