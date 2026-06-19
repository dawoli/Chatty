#include <bits/stdc++.h>
int t;
int x[51]={0,-1,1,7,4,2,6,8,10,18,40,20,28,80,88,108,188,408,208,288,808};
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	std::cin>>t;
	for(int i=1; i<=t; i++) {
		int n;
		std::cin>>n;
		if(n==1)
			std::cout<<"-1";
		else if(n%7==0) {
			for(int i=1; i<=n/7; i++)
				std::cout<<8;
			std::cout<<"\n";
		} else if(n%7==1) {
			std::cout<<1;
			for(int i=1; i<=(n-1)/7; i++)
				std::cout<<0;
			std::cout<<"\n";
		} else {
			std::cout<<x[n]<<"\n"; 
		}
	}
	return 0;
}
