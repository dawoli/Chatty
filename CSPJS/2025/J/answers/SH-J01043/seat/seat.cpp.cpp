#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[110];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int b = 1;
	for(int i = 1; i <= n*m; i++){
		if(a[1] < a[i]){
			b++;
		}
	}
	int x=0, y=0;
	if(b%n!=0){
		y=b/n+1;
	}
	else{
		y=b/n;
	}
	if(y%2==1){
		if(b%n==0){
			x=n;
		}
		else{
			x=b%n;
		}
	}
	else{
		if(n%2==0){
			x = n-b%n+1;
		}
		else{
			x = n-b%n;
		}
	}
	cout << y << " " << x << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
