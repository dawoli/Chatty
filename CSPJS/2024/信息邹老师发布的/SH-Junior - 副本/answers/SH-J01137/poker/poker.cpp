#include<bits/stdc++.h>
using namespace std;
int n,cnt=52;
char a,b;
bool x[55];
int num(char a){
	if(a=='A')
		return 0;
	if('2'<=a&&a<='9')
		return a-49;
	if(a=='T')
		return 9;
	if(a=='J')
		return 10;
	if(a=='Q')
		return 11;
	return 12;
}
int f(char a){
	if(a=='D')
		return 0;
	if(a=='C')
		return 1;
	if(a=='H')
		return 2;
	return 3;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("\n%c%c",&a,&b);
		if(!x[f(a)*13+num(b)]){
			x[f(a)*13+num(b)]=1;
			--cnt;
		}
	}
	printf("%d",cnt);
	return 0;
}
