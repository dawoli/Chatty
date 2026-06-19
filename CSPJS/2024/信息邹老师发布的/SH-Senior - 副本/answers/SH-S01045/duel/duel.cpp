#include<bits/stdc++.h>
using namespace std;
constexpr int S=1<<21;
char buf[S],*p1,*p2;
inline int nc(){
	if(p1==p2){
		p2=(p1=buf)+cin.read(buf,S).gcount();
		if(p1==p2)return EOF;
	}return *p1++;
}
inline int rd(){
	char ch;
	while(!isdigit(ch=nc()));
	int x=ch&0xf;
	while(isdigit(ch=nc()))x=x*10+(ch&0xf);
	return x;
}
constexpr int N=1e5+9;
int n,a[N],f[N],t;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	n=rd();
	for(int i=0;i<n;++i)a[i]=rd();
	sort(a,a+n);
	for(int i=0;i<n;++i)
		if(!t||a[i]<=f[t-1])f[t++]=a[i];
		else *upper_bound(f,f+t,a[i],greater<int>())=a[i];
	return cout<<t<<endl,0;
}
