#include<iostream>
using namespace std;

int n,m,k = 1;
int a,p;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for(int i = 1;i < n*m;i++){
		cin >> p;
		if(p > a) k++;
	}
	c = k / n;
	if(k % n == 0){
		if(c % 2 == 0) r = 0;
		else r = n;
	}
	else{
	if(c % 2 == 0) r = n - (k % n);
	else r = k % n;
	}
	cout << c << ' ' << r;
	return 0;
}
