#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	srand(time(0));
	long long a=1;
	for(int i=0;i<31;i++){
		a*=2;
	}
	a--;
	int b=a;
	cout<<rand()%b;
	return 0;
}

