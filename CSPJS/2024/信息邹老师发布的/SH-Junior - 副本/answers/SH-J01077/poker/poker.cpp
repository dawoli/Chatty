#include <bits/stdc++.h>
using namespace std;
int a[10][30];//»¨-µã DCHS
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		string s;
		cin >> s;
		int ai=0,aj=0;
		switch(s[0]){
			case 'D':ai=1; break;
			case 'C':ai=2; break;
			case 'H':ai=3; break;
			case 'S':ai=4; break;
		}
		switch(s[1]){
			case 'A':aj=1; break;
			case 'T':aj=10;break;
			case 'J':aj=11;break;
			case 'Q':aj=12;break;
			case 'K':aj=13;break;
		}
		if (aj==0){
			aj=s[1]-'0';
		}
		a[ai][aj]++;
	}
	int ans=0;
	for (int i=1; i<=4; i++){
		for (int j=1; j<=13; j++){
			if (a[i][j]==0){
				ans++;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
} 
