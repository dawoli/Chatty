#include<bits/stdc++.h>
using namespace std;
#define zyq 100005
int a[zyq],b[zyq],n,len,ans;
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
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=scan();
	for(int i=1;i<=n;i++){
		a[i]=scan();
		b[a[i]]++;
	}
	sort(a+1,a+n+1);
	len=unique(a+1,a+n+1)-a-1;
	for(int i=2;i<=len;i++){
		if(b[a[i]]>=b[a[i-1]]){
			b[a[i-1]]=0;
		}else{
			b[a[i-1]]-=b[a[i]];
		}
	}
	for(int i=1;i<=len;i++){
		ans+=b[a[i]];
	}
	print(ans);
	return 0;
}
