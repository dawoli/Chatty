#include<bits/stdc++.h>
using namespace std;
ifstream fin ("seat.in");
ofstream fout ("seat.out");
int a[109];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	int n , m;
	fin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++){
		fin >> a[i];
	}
	int b = a[1];
	sort(a + 1, a + n*m + 1, cmp);
	int ans = 1;
	for(int i = 1 ; i <= n*m ; i++){
		if(a[i] == b){
			break;
		}
		else{
			ans++;
		}
	}
	if(ans % n == 0){
		if((ans / n)% 2 ==0){
			fout << ans / n << " " << 1;
		} 
		else{
			fout << ans / n << " " << n; 
		} 
	}
	else{
		if((ans / n + 1) % 2 == 0){
			fout << ans / n + 1 << " " << n - ans % n + 1;
		}
		else{
			fout << ans / n + 1 << " " << ans % n; 
		}
	}
	return 0;
}
