#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3005, M = 1e5 + 5;

struct car{
	double d, v, a, ovl = 1e9 , ovr;
	double det(int pos){
		return (pos > d) ? (v * v + 2 * a* (pos - d) > 0 ? sqrt(v * v + 2 * a* (pos - d)) : 0) : 0;
	}
}c[N]; 

int T;
ll n, m, L, V;
double p[N];
int cnt;
int sum;
int det[M];

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin>> T;
	while(T--){
		cin>> n>> m>> L>> V;
		for(int i = 1; i<= n; i++)
			cin>> c[i].d>> c[i].v>> c[i].a;
		for(int i = 1; i<= m; i++)
			cin>> p[i];
		cnt = 0;
		sum = m;
		for(int i = 1; i<= n; i++){
			bool flag = 1;
			for(int j = 1; j<= m; j++){
				if(c[i].det(p[j]) > 1.0* V){
					flag= 0; 
					c[i].ovl = min(c[i].ovl, p[j]);
					c[i].ovr = p[j];
				}
			}
			if(flag == 0) cnt++;
		}
		
		for(int i = 1; i<= n; i++){
			
		}
		if(cnt != 0)
			cout<< cnt<< " " <<m - 1 <<endl;
		else
			cout<< cnt<< " "<< m<< endl;
	}
	return 0;
} 
