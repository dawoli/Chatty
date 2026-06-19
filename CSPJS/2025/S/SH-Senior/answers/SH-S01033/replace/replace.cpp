#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pc(x) putchar(x)
inline int gt(){int r=0;char c=gc;while(c<48||c>57) c=gc;while(c>47&&c<58) r=r*10+(c^48),c=gc;return r;}
inline string gs(){string s="";char c=gc;while(c<97||c>122) c=gc;while(c>96&&c<123) s+=c,c=gc;return s;}
inline void ot(int x){if(x<10) pc(x^48);else ot(x/10),pc((x%10)^48);}
typedef unsigned long long ll;
int n,q,l,cc,dd,ee,c[200009],d[200009],e[200009];
string x,y,u[200009],v[200009];
ll gg,hh,aa[5000009],bb[5000009],g[200009],h[200009],a[200009],b[200009];
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	n=gt(),q=gt();
	for(int i=0;i<n;++i) u[i]=gs(),v[i]=gs();
	//if(n*(ll)q<=100000000){//1~8,13,14
		for(int i=0;i<n;++i){
			if(u[i]==v[i]) continue;
			int _=0,__=u[i].length()-1;
			while(u[i][_]==v[i][_]) ++_,++c[i];
			for(int j=_-1;j>=0;--j) a[i]=a[i]*131+u[i][j];
			while(u[i][__]==v[i][__]) --__;
			while(_<=__) g[i]=g[i]*131+u[i][_],h[i]=h[i]*131+v[i][_],++_,++d[i];
			while(_<u[i].length()) b[i]=b[i]*131+u[i][_],++_,++e[i];
		}
		for(int i=0;i<q;++i){
			x=gs(),y=gs();
			int _=0,__=x.length()-1;
			gg=hh=aa[0]=bb[0]=0,cc=dd=ee=0;
			while(x[_]==y[_]) ++_,++cc;
			for(int j=_-1;j>=0;--j) aa[_-j]=aa[_-j-1]*131+x[j];
			while(x[__]==y[__]) --__;
			while(_<=__) gg=gg*131+x[_],hh=hh*131+y[_],++_,++dd;
			while(_<x.length()) bb[_-__]=bb[_-__-1]*131+x[_],++_,++ee;
			int ans=0;
			for(int j=0;j<n;++j) if(dd==d[j]&&gg==g[j]&&hh==h[j]&&cc>=c[j]&&ee>=e[j]&&aa[c[j]]==a[j]&&bb[e[j]]==b[j]) ++ans;
			ot(ans),pc('\n');
		}
	//}
	//else{//B(9,10,15,16)
	//	//lai bu ji xie le
	//}
	return 0;
}
