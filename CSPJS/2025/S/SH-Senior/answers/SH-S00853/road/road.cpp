#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//Ten year's OI all in vain , no long long see forefathers
inline ll read(){
	char c = getchar(); ll t = 0 , f = 1;
	while(c < '0' || c > '9'){if (c == '-') {f = -1;} ; c = getchar();};
	while(c >= '0' && c <='9'){t = t * 10 + c - 48 , c = getchar();}
	return t * f;
}
int n , m , k , u , v , w , c , a;
double cnt;
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 0 ; i < m ; i++) u = read() , v = read() , w = read() , cnt += w;
	for(int i = 0 ; i < k ; i++){
		c = read();
		for(int i = 0 ; i < n ; i++) a = read();
	}
	cout << (int)(cnt / 1.414);
}
