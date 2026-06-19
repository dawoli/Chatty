#include<bits/stdc++.h>
using namespace std;
#define zyq 100005
int d[zyq],v[zyq],a[zyq],p[zyq],T,n,m,l,vv,ans1,ans2;
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
int v1(int v0,int a,int t){
	return v0+a*t;
}
double s(int v0,int t,int a){
	return v0*t+0.5*a*t*t;
}
double ssv(int v0,int a,int ss){
	return sqrt(v0*v0+2*a*ss);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=scan();
	while(T--){
		n=scan(),m=scan(),l=scan(),vv=scan();
		for(int i=1;i<=n;i++){
			d[i]=scan(),v[i]=scan(),a[i]=scan();
		}
		for(int i=1;i<=m;i++){
			p[i]=scan();
		}
		for(int i=1;i<=n;i++){
			if(a[i]>vv&&d[i]<=p[m]){
				ans1++;
			}
		}
		print(ans1);putchar(' ');print(ans2);
	}
	return 0;
}
