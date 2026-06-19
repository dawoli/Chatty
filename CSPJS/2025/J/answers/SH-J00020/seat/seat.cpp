#include <bits/stdc++.h>
using namespace std;
int n,m;
int x,y,xy,n1,m1;
int a[110];
bool cmp(int x,int y){
	return x > y;
} 
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	int f = n * m;
	for(int i = 1 ; i <= f ; i++){
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1 , a + f + 1 , cmp);
	if(n == 1 || m == 1){
		if(n == 1 && m == 1){
			cout << "1" << " " << "1";
		}else if(n == 1){
			for(int i = 1 ; i <= f ; i++){
				if(a[i] == x){
					cout << "1" << " " << i;
				}
			}
		}else{
			for(int i = 1 ; i <= f ; i++){
				if(a[i] == x){
					cout << i << " " << "1";
				}
			}
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i = 1 ; i <= f ; i++){
		if(x == a[i]){
			y = i;
			break;
		}
	}
	if(y % n == 0){
		m1 = y / n;
	}else{
		m1 = y / n + 1;
	}
	if(m1 % 2){
		n1 = y % m;
		if(y % m == 0){
			n1 = n;
		}
	}else{
		n1 = n - y % n;
		if(n % 2 == 0){
			n1 ++;
		}
	}
	cout << m1 << " " << n1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

