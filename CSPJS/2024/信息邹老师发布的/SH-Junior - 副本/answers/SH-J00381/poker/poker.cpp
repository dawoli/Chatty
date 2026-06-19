#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n, v[5][14], cnt;
string s;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%d", &n);
	for(int k=1; k<=n; k++){
		cin >> s;
		int i, j;
		switch(s[0]){
			case'D':i=1; break;
			case'C':i=2; break;
			case'H':i=3; break;
			case'S':i=4; break;
		}
		if(s[1] >= '2' && s[1] <= '9') j=s[1]-'0';
		else{
			switch(s[1]){
				case'A':j=1; break;
				case'T':j=10; break;
				case'J':j=11; break;
				case'Q':j=12; break;
				case'K':j=13; break;
			}
		}
		if(!v[i][j]){
			cnt++;
			v[i][j] = 1;
		}
	}
	printf("%d", 52-cnt);
	return 0;
}
