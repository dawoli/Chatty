#include<bits/stdc++.h>
using namespace std;
struct car{
	long long pos;
	long long sp;
	long long a;
	long long ospos;
	long long ls;
}c[100010];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	int n = 0,m = 0;
	int maxm = 0;
	long long l = 0,lim = 0;
	long long posm[100010]; 
	int ans1 = 0;
	for(int i = 0;i < t;i++){
		cin >> n >> m >> l >> lim;
		for(int j = 0;j < n;j++){
			cin >> c[j].pos >> c[j].sp >> c[j].a;
		} 
		for(int j = 0;j < m;j++){
			cin >> posm[j];
			if(posm[j] > posm[maxm]){
				maxm = j;
			}
		}
		for(int j = 0;j < n;j++){
			c[j].ls = sqrt(c[j].sp * c[j].sp + 2 * c[j].a * (posm[maxm] - c[j].pos));
			if(c[j].pos > posm[maxm]){
				continue;
			}
			else if(c[j].ls > lim){
				ans1++;
			}
		}
		cout << ans1 <<" "<< m - 1 << endl;
		n = 0;m = 0;l = 0;lim = 0;maxm = 0;memset(posm,0,sizeof(posm));ans1 = 0;
	}
	return 0;
} 
