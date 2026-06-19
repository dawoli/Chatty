#include <bits/stdc++.h>
//#Shang4Shan3Ruo6Shui4
using namespace std;
int n,k;
int a[200005];
struct ksk{
	int l,r;
}posis[2000005];
bool mys(ksk a,ksk b){
	return a.r < b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++)cin >> a[i];
	int n_ind = 1;
	for (int i=1;i<=n;i++){
		int n_ans = 0;
		int st = i;
		for (int j=i;j<=n;j++){
			n_ans = n_ans^a[j];
			if (n_ans == k){
				n_ans = 0;
				posis[n_ind].l = st;
				posis[n_ind].r = j;
				st = j+1;
				n_ind += 1;
			}
		}
	}
	sort(posis+1,posis+n_ind,mys);
	int n_e = 0,ans = 0;
	for (int i=1;i<n_ind;i++){
		if (posis[i].l > n_e){
			ans ++;
			n_e = posis[i].r;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
