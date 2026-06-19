#include <bits/stdc++.h>
using namespace std;
long long t,n,a1,a2,a3,ans1,ans2,ans3;
long long ans,cnt1,cnt2,cnt3;
struct node{
	int club1,club2,club3;
}a[100005];
bool cmp1(node x, node y){
	return x.club1-max(x.club2,x.club3)>y.club1-max(y.club2,y.club3);
}
bool cmp2(node x, node y){
	return x.club2-max(x.club1,x.club3)>y.club2-max(y.club1,y.club3);
}
bool cmp3(node x, node y){
	return x.club3-max(x.club1,x.club2)>y.club3-max(y.club2,y.club1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		for (int i=1;i<=100000;i++){
			a[i].club1=0;
			a[i].club2=0;
			a[i].club3=0;
		}
		ans1=0,ans2=0,ans3=0;
		cnt1=0,cnt2=0,cnt3=0;
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> a[i].club1 >> a[i].club2 >> a[i].club3;
			a1=a[i].club1;
			a2=a[i].club2;
			a3=a[i].club3;
			if (a1 >= a2 && a1>= a3){
				cnt1++;
				ans1+=a1;
			}
			else if (a2 >= a3 && a2>=a1){
				cnt2++;
				ans2+=a2;
			}
			else{
				cnt3++;
				ans3+=a3;
			}
		}
		if (cnt1<=n/2 && cnt2 <=n/2 && cnt3 <= n/2){
			cout << ans1+ans2+ans3 << endl;
		}
		else{
			ans=ans1+ans2+ans3;
			if (cnt1>n/2){
				sort(a+1,a+n+1,cmp1);
				for (int i=n/2+1;i<=cnt1;i++){
					ans-=a[i].club1-max(a[i].club2,a[i].club3);
				}
			}
			else if (cnt2>n/2){
				sort(a+1,a+n+1,cmp2);
				for (int i=n/2+1;i<=cnt2;i++){
					ans-=a[i].club2-max(a[i].club1,a[i].club3);
				}
			}
			else{
				sort(a+1,a+n+1,cmp3);
				for (int i=n/2+1;i<=cnt3;i++){
					ans-=a[i].club3-max(a[i].club2,a[i].club1);
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
