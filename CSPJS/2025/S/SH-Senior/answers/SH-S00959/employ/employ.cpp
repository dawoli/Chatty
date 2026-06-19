#include<iostream>
#include<random>
#include<time.h>
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::mt19937 rng(std::random_device{}()^time(0));
	std::uniform_int_distribution<> dist(0,998244352);
	printf("%d\n",dist(rng));
	return 0;
}
