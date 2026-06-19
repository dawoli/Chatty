#include<bits/stdc++.h>
#define N 100009
#define ERR 0.001
using namespace std;

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*w;
}

int T;
int n,m,L,V;
struct Car{
	int d,v,a;
}car[N];
int p[N];

bool isConditionA(){
	for(int i=1;i<=n;i++)
		if(car[i].a!=0)
			return false;
	return true;
}
bool isConditionB(){
	for(int i=1;i<=n;i++)
		if(car[i].a<0)
			return false;
	return true;
}
bool isConditionC(){
	for(int i=1;i<=n;i++)
		if(car[i].a>=0)
			return false;
	return true;
}

void solveA(){
	int dtct=p[m],ans=0;
	for(int i=1;i<=n;i++){
		if(car[i].v>V&&car[i].d<=dtct)
			ans++;
	}
	cout<<ans<<" ";
	if(ans==0)
	    cout<<m<<endl;
	else
		cout<<m-1<<endl;
}
void solveB(){
	int dtct=p[m],ans=0;
	for(int i=1;i<=n;i++){
		if(car[i].d>dtct)
			continue;
		if(car[i].v>V){
			ans++;
			continue;
		}
		int s=dtct-car[i].d;
		double vt=sqrt(1.*car[i].v*car[i].v+2.*car[i].a*s);
		if(vt>V) ans++;
	}
	cout<<ans<<" ";
	if(ans==0)
		cout<<m<<endl;
	else
		cout<<m-1<<endl;
}
void solveC(){
	int dctc,ans=0;
	for(int i=1;i<=n;i++){
		dctc=-1;
		for(int j=1;j<=m;j++)
			if(p[j]>=car[i].d){
				dctc=p[j];
				break;
			}
		if(dctc==-1)
			continue;
		int s=dctc-car[i].d;
		double vt=sqrt(1.*car[i].v*car[i].v+2.*car[i].a*s);
		if(vt>V)
			ans++;
	}
	cout<<ans<<" ";
	if(ans==0)
		cout<<m<<endl;
	else
		cout<<m-1<<endl;
}
void solve(){
	cout<<0<<" "<<m-1<<endl;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=n;i++)
			car[i].d=read(),car[i].v=read(),car[i].a=read();
		for(int i=1;i<=m;i++)
			p[i]=read();
		if(isConditionA())
			solveA();
		else if(isConditionB())
			solveB();
		else if(isConditionC())
			solveC();
		else
			solve();
	}
	return 0;
}
