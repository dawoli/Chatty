#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
int n,k,tot;
int a[N],xsum[N];
struct Seg{
	int l,r;
	bool operator<(const Seg&x)const{
		return r < x.r || (r == x.r && l < x.l);
	}
}seg[1000009];
inline int qxor(int l,int r){
	return xsum[r] ^ xsum[l-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
		xsum[i] = xsum[i-1] ^ a[i];
	}
	int lst = n+1;
	for (int i = n;i >= 1;i--){
		for (int j = i;j <= n;j++){
			if (qxor(i,j) == k){
				seg[++tot].l = i;
				seg[tot].r = j;
				lst = j;
				break;
			}
			if (j > lst) break;
		}
	}
	sort(seg+1,seg+1+tot);
	int lstr = 0,ans = 0;
	for (int i = 1;i <= tot;i++){
		//cout<<i<<' '<<seg[i].l<<' '<<seg[i].r<<endl;
		if (seg[i].l > lstr){
			ans++;
			lstr = seg[i].r;
		}
	}
	cout<<ans<<endl;
	return 0;
}
