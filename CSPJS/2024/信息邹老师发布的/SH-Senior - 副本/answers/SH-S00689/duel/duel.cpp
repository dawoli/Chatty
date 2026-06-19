#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
int n;
int a[maxn];
int buc[maxn];
bool used[maxn];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		buc[a[i]]++;
	}
	int tot=n;
	sort(a+1,a+n+1);
	int r=1;//ÓÒÖ¸Õë 
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) r+=buc[a[i]];
		for(int j=r;j<=n;j++){
			if(a[j]>a[i]&&used[j]==false){
				tot--;
				used[j]=true;
				break;
			}
		}
	}
	write(tot);
	putchar('\n');
	return 0;
}
