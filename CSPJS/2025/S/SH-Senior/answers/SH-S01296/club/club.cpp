#include<utility>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
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
const int N=100010;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int _=read();_--;){
		int n=read(),lim=n>>1,res=0;	static int vv[N][3];
		priority_queue<PII,vector<PII>,greater<PII>> q0,q1,q2;
		for(int i=1;i<=n;i++){
			int a=read(),b=read(),c=read();
			vv[i][0]=a;	vv[i][1]=b;	vv[i][2]=c;
			if((a>=b)&&(a>=c)){
				res+=a;	q0.emplace(a-max(b,c),i);
			}
			else if(b>=c){
				res+=b;	q1.emplace(b-max(a,c),i);
			}
			else{
				res+=c;	q2.emplace(c-max(a,b),i);
			}
		}
		while((q0.size()>lim)||(q1.size()>lim)||(q2.size()>lim)){
			if(q0.size()>lim){
				for(;q0.size()>lim;q0.pop()){
					res-=q0.top().first;	int i=q0.top().second;
					int a=vv[i][0],b=vv[i][1],c=vv[i][2];
					if((b<=a)&&(c<=a))
						(b>=c)?q1.emplace(b-c,i):q2.emplace(c-b,i);
				}
			}
			else if(q1.size()>lim){
				for(;q1.size()>lim;q1.pop()){
					res-=q1.top().first;	int i=q1.top().second;
					int a=vv[i][0],b=vv[i][1],c=vv[i][2];
					if((a<b)&&(c<=b))
						(a>=c)?q0.emplace(a-c,i):q2.emplace(c-a,i);
				}
			}
			else{
				for(;q2.size()>lim;q2.pop()){
					res-=q2.top().first;	int i=q2.top().second;
					int a=vv[i][0],b=vv[i][1],c=vv[i][2];
					if((a<c)&&(b<c))
						(a>=b)?q0.emplace(a-b,i):q1.emplace(b-a,i);
				}
			}
		}
		write(res);
	}
	flush();	return 0;
}
