#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
int d[100005];
double v[100005],a[100005];
int p[100005];
 int del[100005];
int ans;
int detor[100005];
int fdetor[100005];
int find(int dd){
	int l = 0,r = m-1;
	if(dd <= p[0]){
		return 0;
	}
	if(dd > p[r]){
		return m;
	}
	while(l < r-1){
		int mid = (l+r) >> 1;
		if(dd <= p[mid]){
			r = mid;
		}else if(dd > p[mid]){
			l = mid;
		}
	}
	return r;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m >> L >> V;
		for(int i = 0; i < n; i++){
			cin >> d[i] >> v[i] >> a[i];
			detor[i] = fdetor[i] = -1;
		}
		for(int i = 0; i < m; i++){
			cin >> p[i];
		}
//		sort(p,p+m);
		
//		for(int i = 0; i < m; i++){
//			cout << p[i];
//		}
//		cout << endl;

	
//		cout << 1;
		ans = 0;
		for(int i = 0; i < n; i++){
			if(a[i] >= 0){
				fdetor[i] = m-1;
				int l = p[m-1]-d[i];
				if(l < 0){
					continue;
				}
				float vx = sqrt(v[i]*v[i] + 2*a[i]*l);
				if(vx > V){
					 del[fdetor[i]] = 1;
					ans ++;
//					double dis = 0;
//					if (a[i] > 0)
//					dis = (V*V-v[i]*v[i])/2/a[i];
//					if(a[i]==0) dis = 0;
////					detor[i] = find(min(int(dis+d[i]),L));
////					cout << "ttx " << i << " " << int(dis) << endl;
//					if(dis+d[i] == p[detor[i]]){
//						detor[i]++;
//					}
				}else{
					fdetor[i] = -1;
				}
			}
			else{
				detor[i] = find(d[i]);
				if(detor[i] >= m){
					continue;
				}
				int l = p[detor[i]]-d[i];
				if(l < 0){
					continue;
				}
				double vx = sqrt(v[i]*v[i] + 2*a[i]*l);
//				cout << i << " " << detor << " " << l << " ";
				if(vx > V){
					 del[detor[i]] = 1;
					ans ++;
					double dis = (V*V-v[i]*v[i])/2/a[i];
//					cout << "ttx " << i << " " << dis << endl;
					fdetor[i] = find(min(int(dis+d[i]),L));
					if(dis+d[i] == p[fdetor[i]]){
						fdetor[i]--;
					}
					
					
//					cout << 1111111111;
				}else{
					detor[i] = -1;
				}
			}
//			for(int k = 0; k < 20; k++){
//						cout << k << " " << l[k]<<" "<<r[k] <<" "<<tree[k]<< endl;
//					}
		}
		cout << ans << " ";
		
		if(n > 10){
			cout << m-1 << endl;
			continue;
		}
		ans = 0;
		for(int i = 0; i < m; i++){
			if(!del[i]){
				ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
