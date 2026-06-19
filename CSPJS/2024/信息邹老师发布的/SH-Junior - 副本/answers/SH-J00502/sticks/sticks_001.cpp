#include <bits/stdc++.h>

int main(){
	
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	
	int T;
	
	for (std::cin >> T;T--;){
		
		int n;
		
		std::cin >> n;
		if (n == 1) std::cout << -1;
		else if (n == 2) std::cout << 1;
		else if (n == 3) std::cout << 7;
		else if (n == 4) std::cout << 4;
		else if (n == 5) std::cout << 2;
		else if (n == 6) std::cout << 6;
		else if (n % 7 == 0){
			int k = n / 7;
			for (int i = 1;i <= k;i++) std::cout << 8;
		}
		else if (n % 7 == 1){
			int k = n / 7;
			std::cout << 10;
			for (int i = 1;i <= k - 1;i++) std::cout << 8;
		}
		else if (n % 7 == 2){
			int k = n / 7;
			std::cout << 1;
			for (int i = 1;i <= k;i++) std::cout << 8;
		}
		else if (n % 7 == 3){
			int k = n / 7;
			std::cout << 22;
			for (int i = 1;i <= k - 1;i++) std::cout << 8;
		}
		else if (n % 7 == 4){
			int k = n / 7;
			std::cout << 20;
			for (int i = 1;i <= k - 1;i++) std::cout << 8;
		}
		else if (n % 7 == 5){
			int k = n / 7;
			std::cout << 2;
			for (int i = 1;i <= k;i++) std::cout << 8;
		}
		else if (n % 7 == 6){
			int k = n / 7;
			std::cout << 6;
			for (int i = 1;i <= k;i++) std::cout << 8;
		}
		std::cout << '\n';
		
	}
	
	return 0;
}
