#include <bits/stdc++.h>

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	register unsigned short n, poker[4][13], sum = 0;
	std::memset(poker[0], 0, 26);
	std::memset(poker[1], 0, 26);
	std::memset(poker[2], 0, 26);
	std::memset(poker[3], 0, 26);
	register char temp1, temp2;
	std::cin >> n;
	for(register unsigned short i = 0; i < n; i++){
		std::cin >> temp1 >> temp2;
		if(temp2 == 'A'){
			temp2 = 1;
		}
		else if(temp2 == 'T'){
			temp2 = 10;
		}
		else if(temp2 == 'J'){
			temp2 = 11;
		}
		else if(temp2 == 'Q'){
			temp2 = 12;
		}
		else if(temp2 == 'K'){
			temp2 = 13;
		}
		else{
			temp2 -= '0';
		}
		temp2 -= 1;
		switch(temp1){
			case 'D':
				poker[0][temp2] = 1;
				break;
			case 'C':
				poker[1][temp2] = 1;
				break;
			case 'H':
				poker[2][temp2] = 1;
				break;
			case 'S':
				poker[3][temp2] = 1;
				break;	
		}
	}
	for(register unsigned short i = 0; i < 4; i++){
		for(register unsigned short j = 0; j < 13; j++){
			if(!poker[i][j]){
				sum++;
			}
		}
	}
	std::cout << sum;
	return 0;
}
