#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long c=1,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			c=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9){
		write(x/10);
	}
	putchar('0'+x%10);
	return;
}
const long long N=100005;
long long n,cnt[N],ans,maxn;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		long long a=read();
		cnt[a]++;
		maxn=max(maxn,a);
	}
	for(int i=1;i<=maxn;i++){
		ans=max(0ll,ans-cnt[i])+cnt[i];
	}
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
