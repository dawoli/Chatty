#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		
		int sat1[n], sat2[n], sat3[n];
		vector<int> dpt1, dpt2, dpt3;
		for(int i=0;i<n;i++) cin>>sat1[i]>>sat2[i]>>sat3[i];
		int cnt1=0, cnt2=0, cnt3=0, ans=0;
		for(int i=0;i<n;i++) {
			if(sat1[i]<sat2[i]) {
				if(sat2[i]<sat3[i]) {
					dpt3.push_back(min(sat3[i]-sat1[i], sat3[i]-sat2[i]));
					cnt3++;
					ans+=sat3[i];
				}
				else {
					dpt2.push_back(min(sat2[i]-sat1[i], sat2[i]-sat3[i]));
					cnt2++;
					ans+=sat2[i];
				}
			}
			else {
				if(sat1[i]<sat3[i]) {
					dpt3.push_back(min(sat3[i]-sat1[i], sat3[i]-sat2[i]));
					cnt3++;
					ans+=sat3[i];
				}
				else {
					dpt1.push_back(min(sat1[i]-sat2[i], sat1[i]-sat3[i]));
					cnt1++;
					ans+=sat1[i];
				}
			}
		}
		
		if(cnt1>n/2) {
			sort(dpt1.begin(), dpt1.end());
			int k=cnt1-n/2;
			for(int i=0;i<k;i++) ans-=dpt1[i];
		}
		if(cnt2>n/2) {
			sort(dpt2.begin(), dpt2.end());
			int k=cnt2-n/2;
			for(int i=0;i<k;i++) ans-=dpt2[i];
		}
		if(cnt3>n/2) {
			sort(dpt3.begin(), dpt3.end());
			int k=cnt3-n/2;
			for(int i=0;i<k;i++) ans-=dpt3[i];
		}
		
		cout << ans << endl;
	} 
	
	return 0;
}
