#include<bits/stdc++.h>
using namespace std;

int n;
string s[100];
char hua[4] = {'D', 'C', 'H', 'S'};
char num[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
int main(){
	freopen("poker3.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> s[i];
	}
	int ans = 0;
	for(int i = 0;i<4;i++){
		for(int j = 0;j<13;j++){
			bool flag = 1; 
			for(int k = 0;k<n;k++){
				string ns = "";
				ns+=hua[i];
				ns+=num[j];
				if(s[k] == ns){
					flag = 0;
					break;
				}
			}
			if(flag) ans++;
		}
	}
	cout << ans;
	return 0;
}
