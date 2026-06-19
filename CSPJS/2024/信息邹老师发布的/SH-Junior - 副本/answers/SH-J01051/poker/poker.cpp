#include <iostream>
#include <string>
using namespace std;
string color = "DCHS";
string nm = "A23456789TJQK";

int main()
{
	int n=0, clr=0, num=0, cnt=0;
	char card[2];
	int cards[52]={};
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> card;
		for(int j=0;j<4;j++) if(color[j] == card[0]) clr=j;
		for(int k=0;k<13;k++) if(nm[k] == card[1]) num=k;
		cards[clr*13+num] = 1;
	};
	for(int l = 0; l < 52; l++) cnt+= 1 - cards[l];
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
