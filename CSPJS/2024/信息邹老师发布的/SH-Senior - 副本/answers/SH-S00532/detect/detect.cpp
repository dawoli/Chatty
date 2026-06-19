#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
long long d[N],a[N],v[N];
long long di[N];
long long n,m,l,V;
long long cur[N]; 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		long long k = 0;
		long long count = 1;
		cin >> n >> m >> l >> V;
		for(int i = 1; i <= n; i++){
			cin >> d[i] >> v[i] >> a[i];
			if(v[i] > V){
				k++;
				cur[k] = d[i];
			}
		}
		for(int i = 1; i <= m; i++){
			cin >> di[i];  
		} 
	//我们需要di[1]作为辅助算出超速人数
		bool flag = true; 
		for(int i = 1; i <= k && flag; i++){
			if(cur[i] > di[1]){
				count = k - i + 1;
				flag = false;
				//如果是第一个就小于的话，那么就是所有的 
				//也就是说，如果a[i] > di[i]的话，那么最后的count数量就是k-i+1 
			} 
		}
		cout << count << " " << count - 1 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
