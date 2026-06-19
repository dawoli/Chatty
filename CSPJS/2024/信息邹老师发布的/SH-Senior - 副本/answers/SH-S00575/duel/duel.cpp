#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0;
	bool f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f^=1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(f) return -x;
	return x;
}
void write(long long x){
	static int stk[23];
	int tp=0;
	if(x<0) putchar('-'),x=-x;
	while(x) stk[++tp]=x%10,x/=10;
	while(tp) putchar(stk[tp]+'0'),--tp;
}
void we(long long x){
	write(x);
	putchar('\n');
}
int n,a[100010],l;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	l=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[l]) ++l;
	}
	write(n-l+1);
	return 0;
} 
