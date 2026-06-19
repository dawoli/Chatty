#include <bits/stdc++.h>
using namespace std;
struct node{
	long long A,B,C;
};
node a[100010];
int cnt[5];
bool compare1(node x,node y){
	return (x.A-x.B)>(y.A-y.B);
}
bool compare2(node x,node y){
	return (max(x.A,max(x.B,x.C))-min(x.A,min(x.B,x.C)))>(max(y.A,max(y.B,y.C))-min(y.A,min(y.B,y.C)));
}
void solve(){
	memset(cnt,0,sizeof(cnt));
	bool flag = true;
	int n,one,two,three;
	long long ans = 0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i].A,&a[i].B,&a[i].C);
		if (a[i].C!=0){
			flag = false;
		}
	}
	if (n==2){
		ans = max(ans,a[1].A+a[2].B);
		ans = max(ans,a[1].A+a[2].C);
		ans = max(ans,a[1].B+a[2].A);
		ans = max(ans,a[1].B+a[2].C);
		ans = max(ans,a[1].C+a[2].A);
		ans = max(ans,a[1].C+a[2].B);
		printf("%lld\n",ans);
		return;
	}
	if (flag){
		sort(a+1,a+n+1,compare1);
		for (int i=1;i<=n/2;i++){
			ans = ans+a[i].A;
		}
		for (int i=n/2+1;i<=n;i++){
			ans = ans+a[i].B;
		}
		printf("%lld\n",ans);
		return;
	}
	sort(a+1,a+n+1,compare2);
	for (int i=1;i<=n;i++){
		int Max = max(a[i].A,max(a[i].B,a[i].C));
		int Min = min(a[i].A,min(a[i].B,a[i].C));
		if (a[i].A==Max){
			one = 1;
		}
		else if (a[i].B==Max){
			one = 2;
		}
		else if (a[i].C==Max){
			one = 3;
		}
		if (a[i].A==Min && one!=1){
			three = 1;
		}
		else if (a[i].B==Min && one!=2){
			three = 2;
		}
		else if (a[i].C==Min && one!=3){
			three = 3;
		}
		if ((one==1 && three==3) || (one==3 && three==1)){
			two = 2;
		}
		else if ((one==1 && three==2) || (one==2 && three==1)){
			two = 3;
		}
		else if ((one==2 && three==3) || (one==3 && three==2)){
			two = 1;
		}
		if (cnt[one]+1<=n/2){
			cnt[one]++;
			if (one==1){
				ans = ans+a[i].A;
			}
			else if (one==2){
				ans = ans+a[i].B;
			}
			else if (one==3){
				ans = ans+a[i].C;
			}
			continue;
		}
		if (cnt[two]+1<=n/2){
			cnt[two]++;
			if (two==1){
				ans = ans+a[i].A;
			}
			else if (two==2){
				ans = ans+a[i].B;
			}
			else if (two==3){
				ans = ans+a[i].C;
			}
			continue;
		}
		if (three==1){
			ans = ans+a[i].A;
		}
		else if (three==2){
			ans = ans+a[i].B;
		}
		else if (three==3){
			ans = ans+a[i].C;
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
