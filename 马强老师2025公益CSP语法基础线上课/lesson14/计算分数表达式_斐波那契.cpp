#include <bits/stdc++.h>
using namespace std;
int main() { 
	int n;
	cin>>n;
	double sum=0;
	sum=2;
	int a1=1,a2=1,a3=0;
	for(int i=3;i<=n;i++){
		a3=a1+a2;
		sum+=1.0/a3;
		a1=a2;
		a2=a3;
	}
	printf("%.3lf\n",sum);
	return 0;
}

