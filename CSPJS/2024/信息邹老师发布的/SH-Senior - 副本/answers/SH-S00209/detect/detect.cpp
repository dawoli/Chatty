#include <bits/stdc++.h>
using namespace std;
struct s{
	int d;
	int v;
	int a;
};
int sd(int v,int a,int t){
	return v + a * t;
}
double lc(int v,int t,int a){
	return v * t + 0.5 * (1.0 * a) * (1.0 * t * t);
}
double cs(int V,int v,int a){
	return 1.0 * (V*V-v*v) / (2 * a);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin >> T;
	for(int sss = 0;sss < T;sss++){
		int n,m,L,V,ans = 0;
		cin >> n >> m >> L >> V;
		s ca[n];
		int jc[m],jc2[m];
		for(int i = 0;i < n;i++)
			cin >> ca[i].d >> ca[i].v >> ca[i].a;
		for(int i = 0;i < m;i++){
			cin >> jc[i];
			jc2[i] = 0;
		}
		sort(jc,jc+m);
		for(int i = 0;i < n;i++){
			if (ca[i].a == 0 && ca[i].v > V + 1){
				cout << 1 << endl;
				for(int j = 0;j < m;j++){
					if (ca[i].d < jc[j]){
						jc2[j]++;
						ans++;
					}
				}
			}
			else if (ca[i].a == 0){
				continue;
				cout << 2 << endl;
			}
			else{
				double jl = cs(V,ca[i].v,ca[i].a) + 1.0 * ca[i].d;
				if (ca[i].a > 0){
					cout << 3 << endl;
					for(int j = 0;j < m;j++){
						if (jl > 1.0 * jc[j]){
							jc2[j]++;
							ans++;
						}
					}
				}
				else {
					cout << 4 << endl;
					for(int j = 0;j < m;j++){
						if (jl < 1.0 * jc[j]){
							jc2[j]++;
							ans++;
						}
					}
				}
			}
		}
		int temp = 0;
		for(int i = 0;i < m;i++){
			if (jc2[i] > temp) temp = jc2[i];
		}
		cout << temp << endl;
		cout << ans-1 << ' ' << temp + ans-1 - temp << endl;
	}
	return 0;
}
