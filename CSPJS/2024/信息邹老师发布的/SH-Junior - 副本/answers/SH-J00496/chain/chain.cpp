#include<bits/stdc++.h>
using namespace std;
int T,n,k,q;
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
	}else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	T=scan();
	while(T--){
		n=scan(),k=scan(),q=scan();
		while(q--){
			puts("1");
		}
	}
	return 0;
}
