#include<algorithm>
#include<utility>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int SIZI=(1<<16)-1;
char bufi[SIZI];	char *Si=bufi,*Ti=bufi;
#define load() (Ti=bufi+fread(Si=bufi,1,SIZI,stdin))
#define gc() ((__builtin_expect(Si==Ti,false)&&(load(),Si==Ti))?EOF:(*Si++))
inline int read(){
	int x=0,f=1;	char ch=gc();
	for(;(ch<'0')||(ch>'9');ch=gc())
		(ch=='-')&&(f=-1);
	for(;(ch>='0')&&(ch<='9');ch=gc())
		x=x*10+ch-'0';
	return x*f;
}
const int SIZO=(1<<16)-1;
char bufo[SIZO];	int bufoidx;
#define flush() (fwrite(bufo,1,bufoidx,stdout),bufoidx=0)
#define pc(c) ((__builtin_expect(bufoidx==SIZO,false)&&flush()),bufo[bufoidx++]=c)
inline void write(int x){
	if(x<0){
		pc('-');	x=-x;
	}
	static int stk[20];	int top=0;
	do{
		stk[++top]=x%10;	x/=10;
	}
	while(x);
	for(;top;pc('0'+stk[top--]));
	pc('\n');	return;
}
typedef unsigned long long ULL;
typedef pair<ULL,ULL> PUU;
const int H=13331;
inline ULL hsh(string str){
	ULL res=0;
	for(char ch:str)
		res=res*H+ch-'a'+1;
	return res;
}
int n,q;
map<PUU,map<PUU,int>> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();	q=read();
	for(int i=1;i<=n;i++){
		string a,b;	char ch=gc();
		for(;(ch<'a')||(ch>'z');ch=gc());
		for(;(ch>='a')&&(ch<='z');ch=gc())
			a+=ch;
		for(;(ch<'a')||(ch>'z');ch=gc());
		for(;(ch>='a')&&(ch<='z');ch=gc())
			b+=ch;
		int idx=0,len=a.size();
		for(;(idx<len)&&(a[idx]==b[idx]);idx++);
		string c=a.substr(0,idx);
		reverse(c.begin(),c.end());
		if(idx==len){
			mp[PUU(0,0)][PUU(hsh(c),0)]++;
			continue;
		}
		ULL A=hsh(c),B;
		a=a.substr(idx);	b=b.substr(idx);
		idx=(len=a.size())-1;
		for(;(~idx)&&(a[idx]==b[idx]);idx--);
		B=(idx+1!=len)?hsh(a.substr(idx+1)):0;
		a=a.substr(0,idx+1);	b=b.substr(0,idx+1);
		mp[PUU(hsh(a),hsh(b))][PUU(A,B)]++;
	}
	while(q--){
		string a,b;	char ch=gc();
		for(;(ch<'a')||(ch>'z');ch=gc());
		for(;(ch>='a')&&(ch<='z');ch=gc())
			a+=ch;
		for(;(ch<'a')||(ch>'z');ch=gc());
		for(;(ch>='a')&&(ch<='z');ch=gc())
			b+=ch;
		if(a.size()!=b.size()){
			write(0);	continue;
		}
		int idx=0,len=a.size();
		for(;(idx<len)&&(a[idx]==b[idx]);idx++);
		string c=a.substr(0,idx);
		reverse(c.begin(),c.end());
		a=a.substr(idx);	b=b.substr(idx);
		idx=(len=a.size())-1;
		for(;(~idx)&&(a[idx]==b[idx]);idx--);
		string d=(idx+1!=len)?a.substr(idx+1):"";
		a=a.substr(0,idx+1);	b=b.substr(0,idx+1);
		ULL A=hsh(a),B=hsh(b);
		if(!mp.count(PUU(A,B))){
			write(0);	continue;
		}
		map<PUU,int> &cur=mp[PUU(A,B)];
		A=0;	B=0;	int res=0;
		if(cur.lower_bound(PUU(A,0))->first.first==A){
			cur.count(PUU(A,B))&&(res+=cur[PUU(A,B)]);
			for(char ch:d){
				B=B*H+ch-'a'+1;
				cur.count(PUU(A,B))&&(res+=cur[PUU(A,B)]);
			}
		}
		for(char ch:c){
			A=A*H+ch-'a'+1;	B=0;
			if(cur.lower_bound(PUU(A,0))->first.first>A)
				continue;
			cur.count(PUU(A,B))&&(res+=cur[PUU(A,B)]);
			for(char ch:d){
				B=B*H+ch-'a'+1;
				cur.count(PUU(A,B))&&(res+=cur[PUU(A,B)]);
			}
		}
		write(res);
	}
	flush();	return 0;
}
