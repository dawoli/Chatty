#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n;
	k=(n*(n+1))/2;
	srand(time(0));
	int x=rand()%k;
	cout<<x<<endl;
	return 0;
}
