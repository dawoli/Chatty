#include<bits/stdc++.h>
using namespace std;
long long n,m,L,V;
long long d[100009],v[100009],a[100009],p[100009];
void solve_a0(){
	long long cntv = 0;
	for(long long i = 0;i < n;i++){
		if(d[i] <= p[m - 1] and v[i] > V){
			cntv++;
		}
	}
	if(cntv == 0){
		m++;
	}
	cout<<cntv<<' '<<m - 1<<endl;
	return;
}
void solve_ad0(){
	long long cntv = 0;
	for(long long i = 0;i < n;i++){
		if(d[i] <= p[m - 1]){
			long long s = p[m - 1] - d[i];
			float vv = sqrt(float(s * 2 * a[i] + v[i] * v[i]));
			if((vv - float(V)) > 0.000001){
				cntv++;
			}
		}
	}
	if(cntv == 0){
		m++;
	}
	cout<<cntv<<' '<<m - 1<<endl;
	return;
}
void input(){
	cin>>n>>m>>L>>V;
	bool a0 = 1,ad0 = 1;
	for(long long i = 0;i < n;i++){
		cin>>d[i]>>v[i]>>a[i];
		if(a[i] != 0){
			a0 = 0;
		}
		if(a[i] <= 0){
			ad0 = 0;
		}
	}
	for(long long i = 0;i < m;i++){
		cin>>p[i];
	}
	sort(p,p + m);
	if(a0 == 1){
		solve_a0();
	}else if(ad0 == 1){
		solve_ad0();
	}
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int i = 0;i < T;i++){
		input();
	}
	return 0;
}
