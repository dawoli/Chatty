#include <iostream>
using namespace std;
int main(){
	int t, n, m, L, V, d, v, a, p, num;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> m >> L >> V;
		for(int j = 1; j < n; j++){
			cin >> d >> v >> a;
			if(a==0){
				if(v>V)	num++;
			}
			else if(a>0 && (a+v)>V)	num++;
			else{
				if((a+v)>=V)	num++;
			}
		}
		for(int j = 1; j < m; j++){
			cin >> p;
		}
		cout << num << " "<< m-num+1;
	} 
	return 0;
} 
