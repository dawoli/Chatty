#include<bits/stdc++.h>
using namespace std;
int n;
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
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	n=scan();
	print(52-n);
	return 0;
}
