#include <bits/stdc++.h>
using namespace std;
int n,m,targf,postar;
int g[1009];
bool mycmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n*m;i++) cin >> g[i];
	targf = g[0];
	sort(g,g+n*m,mycmp);
	for(int i = 0;i<n*m;i++){
		if(g[i] == targf){
			postar = i;
			break;
		}
	}
	int a = postar/n;
	int b = postar%n + 1;
	if(a % 2 == 1)
		b =  n - b + 1;
	a = a + 1;
	cout << a <<" " << b;
	
	return 0;
}
