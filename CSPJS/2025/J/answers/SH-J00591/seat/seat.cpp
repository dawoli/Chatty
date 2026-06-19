#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int nm = n * m;
	int R;
	cin >> R;
	for(int i = 1;i <= nm - 1;i++){
		cin >> a[i];
	}
	sort(a + 1,a + nm);
	int q = upper_bound(a + 1,a + nm,R) - a;
	q = nm - q + 1;
	cout << (q - 1) / n + 1 << " ";
	if(((q - 1) / n) % 2 == 0){
		if(q % n == 0){
			cout << n;
		}
		else{
			cout << q % n;
		}
	}
	else{
		if(q % n == 0){
			cout << 1;
		}
		else{
			cout << (n + 1) - q % n;
		}
	}
	return 0;
}
