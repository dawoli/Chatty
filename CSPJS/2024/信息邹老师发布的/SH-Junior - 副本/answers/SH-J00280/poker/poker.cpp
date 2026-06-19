#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ans = 0,tmp1,tmp2,poker[15][5]={0};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;string a;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a;
		if (a[1]-'0' < 10){
			tmp1 = a[1] - '0';
			
		}else if (a[1] == 'A'){
			tmp1 = 1;
		}else if (a[1] == 'T'){
			tmp1 = 10;
		}else if (a[1] == 'J'){
			tmp1 = 11;
		}else if (a[1] == 'Q'){
			tmp1 = 12;
		}else if (a[1] == 'K'){
			tmp1 = 13;
		}
		if (a[0] == 'D'){
			tmp2 = 1;
		}else if (a[0] == 'C'){
			tmp2 = 2;
		}else if (a[0] == 'H'){
			tmp2 = 3;
		}else{
			tmp2 = 4;
		}
		poker[tmp1][tmp2]++;
	}
	for (int i=1;i<=13;i++){
		for (int j=1;j<=4;j++){
			if (poker[i][j] == 0) ans++;
		}
	}
	cout << ans;
	return 0;
}
