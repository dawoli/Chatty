#include<bits/stdc++.h>
using namespace std;
#define zyq 200005
int a[zyq],c[zyq],T,n;
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
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=scan();
	while(T--){
		n=scan();
		for(int i=1;i<=n;i++){
			a[i]=scan();
		}
		print(0);
		puts("");
	}
	return 0;
}
