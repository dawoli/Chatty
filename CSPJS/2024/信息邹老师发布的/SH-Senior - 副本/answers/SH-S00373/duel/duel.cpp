#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
bool vis[N];
int cnt=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int k=a[i];
		int m=lower_bound(a+1,a+n+1,k)-a;
		while(vis[m]==1 || k==a[m]){
			m++;
		}
		if(m>=1 && m<=n){
			a[i]=0;
			vis[m]=1;
		}
	
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0) cnt++;
	}
	cout << cnt << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
