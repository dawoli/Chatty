#include<bits/stdc++.h>
using namespace std;
struct node {
	int l1,l2,l3;
	int q;
	int s1;
	int s2;
	int s3;
}love[100005];
bool cmp1(node x, node y) {
	return x.s1<y.s1;
}
bool cmp2(node x, node y) {
	return x.s2<y.s2;
}
bool cmp3(node x, node y) {
	return x.s3<y.s3;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int a1=0,a2=0,a3=0,ans=0;
		for(int i = 1; i <= n; i++) {
			
			cin >> love[i].l1 >> love[i].l2 >> love[i].l3;
			if(love[i].l1>love[i].l2){
				if(love[i].l3 > love[i].l1){
					a3++;
					ans+=love[i].l3;
					love[i].q = 3;
					love[i].s3 = min(love[i].l3-love[i].l2,love[i].l3-love[i].l1);
				} else {
					a1++;
					ans+=love[i].l1;
					love[i].q = 1;
					love[i].s1 = min(love[i].l1-love[i].l2,love[i].l1-love[i].l3);
				}
			} else {
				if(love[i].l3>love[i].l2) {
					a3++;
					ans+=love[i].l3;
					love[i].q = 3;
					love[i].s3 = min(love[i].l3-love[i].l2,love[i].l3-love[i].l1);
				}
				else{
					a2++;
					ans+=love[i].l2;
					love[i].q = 2;
					love[i].s2 = min(love[i].l2-love[i].l3,love[i].l2-love[i].l1);
				}
			}
		}
		if(a1 > n/2){
			int end = 0;
			sort(love+1,love+n+1,cmp1);
			for(int i = 1; i <= n;i++){
				if(love[i].q == 1 && end<a1-n/2){
					ans-=love[i].s1;
					end++;
				}
			}
		}
		else if(a2 > n/2){
			int end = 0;
			sort(love+1,love+n+1,cmp2);
			for(int i = 1; i <= n;i++){
				if(love[i].q == 2 && end<a2-n/2){
					ans-=love[i].s2;
					end++;
				}
			}
		}
		else if(a3 > n/2){
			int end = 0;
			sort(love+1,love+n+1,cmp3);
			for(int i = 1; i <= n;i++){
				if(love[i].q == 3 && end<a3-n/2){
					ans-=love[i].s3;
					end++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
