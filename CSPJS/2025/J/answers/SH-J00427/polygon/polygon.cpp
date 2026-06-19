#include<iostream>
#include<random>
int a[10000000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	std::cout<<2*n-1;
}
