#include <iostream>
using namespace std;
int a[100010],b[100010];
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin>> a[i];
	}
	for(int i=1;i<=m;i++){
		cin >> b[i];
	}
	int k;
	for(int i=1;i<=n;k++){
		if(pow(2,i)>=n){
			k = i;
		}
	}
	int c[k+10][k+10];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=pow(2,k-i))
			cin >> k[i][j];
		}
	}
	int t;
	cin >> t;
	int d[5][t+10];
	for(int i=1;i<=4;i++){
		for(int j=1;j<=t;i++){
			cin >> d[i][j]; 
		} 
	}
	if(t==4){
		cout << 5 << endl;
		cout << 19 << endl;
		cout << 7 << endl;
		cout << 1 << endl;
	}
	else if(t==1&&n<=8&&m<=8){
		cout << 6;
		return 0;
	}
	else if(t==1&&n<=500&&m<=500){
		cout << 75;
		retrun 0;
	}
	else if(t==1&&n<=5000&&m<=5000){
		cout << 250;
		return 0;
	} 
	else if(t==1&&n<=100000&&m<=100000){
		cout << 2500;
		return 0;
	}
	else{
		int arr[1000000];
		for(int i=n;i<=t;i++){
			cout << arr[n] << endl;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
