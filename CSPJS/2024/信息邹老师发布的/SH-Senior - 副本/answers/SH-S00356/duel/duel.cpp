#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,x,c;
int a[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<100009;i++){
		c=max(a[i]-1,c);
	}
	cout<<n/2-c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
