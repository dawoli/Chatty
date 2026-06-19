#include <bits/stdc++.h>

static unsigned short const hex[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

inline unsigned int calc(register unsigned int arg){
	register unsigned int result = 1;
	for(register unsigned short i = 1; i < arg; i++){
		result = result * 10 + 1;
	}
	return result;
}

inline bool process(register unsigned int arg1, register unsigned int arg2){
	register unsigned int sum = 0;
	while(arg1){
		arg2 -= hex[arg1 % 10];
		arg1 /= 10;
	}
	if(arg2)
		return 0;
	else
		return 1;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	register unsigned int t, n;
	std::cin >> t;
	for(register unsigned short i = 0; i < t; i++){
		std::cin >> n;
		for(register unsigned short j = 1; j <= calc((n + 1) / 2); j++){
			if(process(j, n)){
				std::cout << j << "\n";
				goto end;
			}
		}
		std::cout << -1 << "\n";
		end:
		0;
	}
	return 0;
} 
