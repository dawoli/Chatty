#include<bits/stdc++.h>
using namespace std;
int a=1;
int sum1[15][15],sum2[15][15],sum3[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cin >> sum1[i][j];
			sum3[a] = sum1[i][j];
			a ++;
		}
	}
	a = 1;
	int num = sum1[1][1];
	sort(sum3+1,sum3+n*m+1);
	for(int i = n;i >= 1;i --){
		for(int j = m;j >= 1;j --){
			sum1[i][j] = sum3[a];
			a ++;
		}
	}
	/*
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cout << sum1[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(i % 2 == 1){
				sum2[i][j] = sum1[i][j];
			}
			else{
				sum2[i][j] = sum1[i][m+1-j];
			}
		}
	}
	/*
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cout << sum2[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(sum2[i][j] == num){
				cout << i << " " << j;
			}
		}
	}
	return 0;
}
