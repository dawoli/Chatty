#include <bits/stdc++.h>
inline int read() {
	char op=getchar();
	int w=1;
	while(op<'0'||op>'9') {
		if(op=='-') w=-1;
		op=getchar();
	}
	int as=0;
	while(op>='0'&&op<='9') {
		as=as*10+op-'0';
		op=getchar();
	}
	return w*as;
}
int N,v[100009];
signed main(void) {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	N=read();
	for(int i=1;i<=N;i++) v[read()]++;
	int as=0;
	for(int i=0;i<=100000;i++) as=std::max(as,v[i]);
	printf("%d",as);
} 
