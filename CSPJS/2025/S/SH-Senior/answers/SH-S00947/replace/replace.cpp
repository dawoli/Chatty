#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool ok;
char c;
ll n,q,le[200020],l,cnt,sr;
vector<ll> ane[200020],bne[200020],sl,el;
string a[200020],b[200020],x,y,px,py;
ll read(){
	ll ne=1,a=0;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-')ne=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return ne*a;
}
void write(ll a){
	if(a<0)putchar('-');
	if(a>9)write(a/10);
	putchar(a%10+'0');
}
bool ck(ll idx,ll st){
	for(int i=st;i<st+le[idx];i++){
		x[i]=b[idx][i-st+1];
	}
	return x==y;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		a[i]=" ";
		while(c<'a'||c>'z')c=getchar();
		while('a'<=c&&c<='z'){
			a[i]+=c;
			le[i]++;
			c=getchar();
		}
		b[i]=" ";
		while(c<'a'||c>'z')c=getchar();
		while('a'<=c&&c<='z'){
			b[i]+=c;
			c=getchar();
		}
		ane[i].push_back(0);
		ane[i].push_back(0);
		for(int j=2,k=0;j<=le[i];j++){
			while(a[i][j]!=a[i][k+1]&&k)k=ane[i][k];
			if(a[i][j]==a[i][k+1])k++;
			ane[i].push_back(k);
		}
		bne[i].push_back(0);
		bne[i].push_back(0);
		for(int j=2,k=0;j<=le[i];j++){
			while(b[i][j]!=b[i][k+1]&&k)k=bne[i][k];
			if(b[i][j]==b[i][k+1])k++;
			bne[i].push_back(k);
		}
	}
	while(q--){
		cnt=0;
		l=0;
		x=" ";
		while(c<'a'||c>'z')c=getchar();
		while('a'<=c&&c<='z'){
			x+=c;
			l++;
			c=getchar();
		}
		y=" ";
		while(c<'a'||c>'z')c=getchar();
		while('a'<=c&&c<='z'){
			y+=c;
			c=getchar();
		}
		px=x;
		py=y;
		for(int i=1;i<=n;i++){
			if(le[i]>l)continue;
			x=px;
			sl.clear();
			for(int j=1,k=0;j<=l;j++){
				while(x[j]!=a[i][k+1]&&k)k=ane[i][k];
				if(x[j]==a[i][k+1])k++;
				if(k==le[i]){
					sl.push_back(j-le[i]+1);
				}
			}
			el.clear();
			for(int j=1,k=0;j<=l;j++){
				while(y[j]!=b[i][k+1]&&k)k=bne[i][k];
				if(y[j]==b[i][k+1])k++;
				if(k==le[i]){
					el.push_back(j-le[i]+1);
				}
			}
			for(int j=0,k=0;j<sl.size()&&k<el.size();j++,k++){
				while(el[k]<sl[j]&&k<el.size())k++;
				if(k==el.size())break;
				while(sl[j]<el[k]&&j<sl.size())j++;
				if(j==sl.size())break;
				if(ck(i,sl[j])){
					cnt++;
				}
				x=px;
			}
		}
		write(cnt);
		putchar('\n');
	}
	return 0;
}
