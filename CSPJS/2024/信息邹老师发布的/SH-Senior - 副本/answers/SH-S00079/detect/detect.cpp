#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int T,d[100005],v[100005],a[100005],p[100005],k[100005];
struct nod{
	int l1,r1;
};
nod z[100005];
bool cmp(nod x,nod y){
	return x.l1 < y.l1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T; 
	while(T--){
		memset(k,0,sizeof k);
		int n,m,l,V,cnt = 0,q = 0,step = 0;
		cin >> n >> m >> l >> V;
		bool flag = 0;
		for(int i = 1;i <= n;i++){
			cin >> d[i] >> v[i] >> a[i];
			if(a[i] < 0) flag = 1;
		}
		for(int i = 1;i <= m;i++)
			cin >> p[i];
		for(int i = 1;i <= n;i++){
			int l = 1,r = m,ans = 0;
			while(l <= r){
				int mid = (l + r) / 2;
				if(p[mid] >= d[i]){
					r = mid - 1;
					ans = mid;
				}
				else {
					l = mid + 1;
				}
			}
			if(sqrt(1.0 * v[i] * v[i] + 1.0 * 2 * a[i] * (p[ans] - d[i])) > V || sqrt(1.0 * v[i] * v[i] + 2.0 * a[i] * (p[m] - d[i])) > V){
				k[++step] = i;
				cnt++;
			}
		}
		for(int i = 1;i <= step;i++){
			if(a[i] >= 0){
				int l = 1,r = m,ans = 0;
				while(l <= r){
					int mid = (l + r) / 2;
					if(sqrt(1.0 * v[i] * v[i] + 1.0 * 2 * a[i] * (p[mid] - d[i])) > V){
						r = mid - 1;
						ans = mid;
					}
					else {
						l = mid + 1;
					}
				}
				z[i].l1 = ans;
			}
			else if(a[i] < 0){
				int l = 1,r = m,ans = 0;
				while(l <= r){
					int mid = (l + r) / 2;
					if(sqrt(1.0 * v[i] * v[i] + 1.0 * 2 * a[i] * (p[mid] - d[i])) > V){
						r = mid - 1;
						ans = mid;
					}
					else {
						l = mid + 1;
					}
				}
				l = 1,r = m;
				int ans1 = 0;
				while(l <= r){
					int mid = (l + r) / 2;
					if(sqrt(1.0 * v[i] * v[i] + 1.0 * 2 * a[i] * (p[mid] - d[i])) <= V){
						l = mid + 1;
						ans1 = mid;
					}
					else {
						r = mid - 1;
					}
				}
				z[i].l1 = ans;
				z[i].r1 = ans1;
			}
		}
		sort(z + 1,z + step + 1,cmp);
		int last = 0;
		for(int i = 1;i <= step;i++){
			if(z[i].l1 >= last) q++;
			last = max(last,z[i].r1);
		}
		cout << cnt << " " << step - q << endl;
	}
	return 0;
}
