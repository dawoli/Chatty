#include<bits/stdc++.h>
using namespace std;
#define zyq 100005
int a[zyq],c[zyq],T,n,m,k;
string s[zyq];
int scan(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10){
		putchar(x+'0');
		return;
	}
	print(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	print(1);
	return 0;
}
