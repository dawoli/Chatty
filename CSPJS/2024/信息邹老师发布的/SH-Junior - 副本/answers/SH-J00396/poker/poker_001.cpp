#include<bits/stdc++.h>
using namespace std;
int all[9][19];
int n,ans = 0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++){
		char hs,num;
		cin>>hs>>num;
		int a,b;
		
		if (hs == 'D') a = 1;
		else if (hs == 'C') a = 2;
		else if (hs == 'H') a = 3;
		else if (hs == 'S') a = 4;
		
		if (num == 'A') b = 1;
		else if (num == 'T') b = 10;
		else if (num == 'J') b = 11;
		else if (num == 'Q') b = 12;
		else if (num == 'K') b = 13;
		else b = num - '0';
		
		all[a][b]++;
	}
	
	for (int i = 1;i <= 4;i++){
		for (int j = 1;j <= 13;j++){
			if (all[i][j] == 0) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
