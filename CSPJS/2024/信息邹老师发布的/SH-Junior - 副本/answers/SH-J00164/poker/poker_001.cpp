#include <bits/stdc++.h>
using namespace std;
int d[15],c[15], h[15], s[15], num = 52;
char x, y;
int find(char s)
{
	if(s == 'A'){
		return 1;
	}
	if(s == 'T'){
		return 10;
	}
	if(s == 'K'){
		return 13;
	}
	if(s == 'Q'){
		return 12;
	}
	if(s == 'J'){
		return 11;
	}
	return s - '0';
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w", stdout);//Îâ¼ÎÜø 
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		if(x == 'D'){
			d[find(y)]++;
		}
		if(x == 'C'){
			c[find(y)]++;
		}
		if(x == 'H'){
			h[find(y)]++;
		}
		if(x == 'S'){
			s[find(y)]++;
		}
	}
	for(int i = 1; i <= 13; i++){
		if(h[i]){
			num--;
		}
		if(d[i])
			num--;
		if(c[i]){
			num--;
		}
		if(s[i])
			num--;
	}
	cout << num << endl;
	return 0;
}
