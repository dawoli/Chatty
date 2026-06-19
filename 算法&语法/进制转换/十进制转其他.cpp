#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char s[10000];
	_itoa(n, s, 8);
	printf("%s",s);	
	return 0;
}
