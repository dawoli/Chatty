#include<bits/stdc++.h>
using namespace std;

//用1-52代表各张不同的牌 
int card[60];
//const int D = 0 , C = 13 , H = 26 , S = 39;

int main(){
	freopen("poker.in" , "r" , stdin);
	freopen("poker.out" , "w" , stdout);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
    	char c , num;
    	cin >> c >> num;
    	int id = 0;
    	if(c == 'C') id += 13;
    	if(c == 'H') id += 26;
    	if(c == 'S') id += 39;
    	
    	if('2' <= num && num <= '9') id += (num - '0');
    	if(num == 'A') id ++;
    	if(num == 'T') id += 10;
    	if(num == 'J') id += 11;
    	if(num == 'Q') id += 12;
    	if(num == 'K') id += 13;
    	
    	card[id] ++;
	}
	int cnt = 0;
	for(int i = 1 ; i <= 52 ; i ++){
		if(!card[i]) cnt ++;
	}
	cout << cnt;
	
	
	return 0;
}
