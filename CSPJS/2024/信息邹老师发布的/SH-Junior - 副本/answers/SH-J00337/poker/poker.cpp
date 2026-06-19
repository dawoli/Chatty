#include<bits/stdc++.h>
using namespace std;
bool is[13][4];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string card;int cnt = 52;
	int n;
	cin>>n;
	while(n--){
		cin>>card;
		char color = card[0];
		char number = card[1];
		int co,no;
		switch(color){
			case 'D':
				co = 0;
				break;
			case 'C':
				co = 1;
				break;
			case 'H':
				co = 2;
				break;
			case 'S':
				co = 3;
				break;
		}
		switch(number){
			case 'A':
				no = 0;break;
			case 'T':
				no = 9;break;
			case 'J':
				no = 10;break;
			case 'Q':
				no = 11;break;
			case 'K':
				no = 12;break;
			default:
				no = number-'1';break;
		}
		if(is[no][co]){
			continue;
		}else{
			is[no][co]=1;
			cnt--;
		}
	}
	cout<<cnt;
	return 0;
}
