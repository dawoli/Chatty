#include<bits/stdc++.h>
const int N=1e5+9;
using std::cin;
using std::cout;
int T,n;
struct Cluber{
	int a,b,c;
}ppl[N];
bool flgA=1,flgB=1;
long long ans;
long long res[209][209][209];
void solveA(){
	ans=0;
	std::sort(ppl+1,ppl+n+1,
		[](const Cluber&x,const Cluber&y)->bool{return x.a>y.a;});
	for(int i=1;i<=(n>>1);i++)ans+=ppl[i].a;
}
void solveB(){
	ans=0;int cnta=0,cntb=0;
	std::sort(ppl+1,ppl+n+1,
		[](const Cluber&x,const Cluber&y)->bool{return abs(x.a-x.b)>abs(y.a-y.b);});
	int i=1;
	do{
		if(ppl[i].a<ppl[i].b)ans+=ppl[i].b,cntb++;
		else ans+=ppl[i].a,cnta++;
		i++;
	}while(cnta<(n>>1)&&cntb<(n>>1)&&i<=n);
	if(cnta>=(n>>1)){
		while(i<=n)
			ans+=ppl[i++].b;
	}else{
		while(i<=n)
			ans+=ppl[i++].a;
	}
}
long long f(int cnta,int cntb,int cntc){
	if(res[cnta][cntb][cntc])return res[cnta][cntb][cntc];
	int m=cnta+cntb+cntc;
	if(!m)return 0;
	if(cnta)res[cnta][cntb][cntc]=std::max(res[cnta][cntb][cntc],f(cnta-1,cntb,cntc)+ppl[m].a);
	if(cntb)res[cnta][cntb][cntc]=std::max(res[cnta][cntb][cntc],f(cnta,cntb-1,cntc)+ppl[m].b);
	if(cntc)res[cnta][cntb][cntc]=std::max(res[cnta][cntb][cntc],f(cnta,cntb,cntc-1)+ppl[m].c);
	return res[cnta][cntb][cntc];
}
void solveN(){
	ans=0;
	for(int cnta=0;cnta<=(n>>1);cnta++)
		for(int cntb=std::max(0,(n>>1)-cnta);cntb<=(n>>1);cntb++)
			ans=std::max(ans,f(cnta,cntb,n-cnta-cntb));
}
void solve(){
	ans=0;int cnta=0,cntb=0,cntc=0;
	std::sort(ppl+1,ppl+n+1,
		[](const Cluber&x,const Cluber&y)->bool{
		return std::max(x.a,std::max(x.b,x.c))-std::min(x.a,std::min(x.b,x.c))
		>std::max(y.a,std::max(y.b,y.c))-std::min(y.a,std::min(y.b,y.c));});
	int i=1;
	do{
		if(ppl[i].a<ppl[i].b){
			if(ppl[i].b<ppl[i].c)ans+=ppl[i].c,cntc++;
			else ans+=ppl[i].b,cntb++;
		}else{
			if(ppl[i].a<ppl[i].c)ans+=ppl[i].c,cntc++;
			else ans+=ppl[i].a,cnta++;
		}
		i++;
	}while(cnta<(n>>1)&&cntb<(n>>1)&&cntc<(n>>1)&&i<=n);
	if(cnta>=(n>>1)){
		std::sort(ppl+i,ppl+n+1,
			[](const Cluber&x,const Cluber&y)->bool{return abs(x.b-x.c)>abs(y.b-y.c);});
		while(cntb<(n>>1)&&cntc<(n>>1)&&i<=n){
			if(ppl[i].b<ppl[i].c)ans+=ppl[i].c,cntc++;
			else ans+=ppl[i].b,cntb++;
			i++;
		}
		if(cntb>=(n>>1)){
			while(i<=n)
				ans+=ppl[i++].c;
		}else{
			while(i<=n)
				ans+=ppl[i++].b;
		}
	}else if(cntb>=(n>>1)){
		std::sort(ppl+i,ppl+n+1,
			[](const Cluber&x,const Cluber&y)->bool{return abs(x.a-x.c)>abs(y.a-y.c);});
		while(cnta<(n>>1)&&cntc<(n>>1)&&i<=n){
			if(ppl[i].a<ppl[i].c)ans+=ppl[i].c,cntc++;
			else ans+=ppl[i].a,cnta++;
			i++;
		}
		if(cnta>=(n>>1)){
			while(i<=n)
				ans+=ppl[i++].c;
		}else{
			while(i<=n)
				ans+=ppl[i++].a;
		}
	}else{
		std::sort(ppl+i,ppl+n+1,
			[](const Cluber&x,const Cluber&y)->bool{return abs(x.a-x.b)>abs(y.a-y.b);});
		while(cnta<(n>>1)&&cntb<(n>>1)&&i<=n){
			if(ppl[i].a<ppl[i].b)ans+=ppl[i].b,cntb++;
			else ans+=ppl[i].a,cnta++;
			i++;
		}
		if(cnta>=(n>>1)){
			while(i<=n)
				ans+=ppl[i++].b;
		}else{
			while(i<=n)
				ans+=ppl[i++].a;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);std::ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ppl[i].a>>ppl[i].b>>ppl[i].c;
		}
		for(int i=1;i<=n&&flgB;i++)
			if(ppl[i].c)flgA=flgB=0;
		for(int i=1;i<=n&&flgA;i++)
			if(ppl[i].b)flgA=0;
		if(flgA)solveA();
		else if(flgB)solveB();
		else if(n<=200){
			memset(res,0,sizeof res);
			solveN();
		}else solve();
		cout<<ans<<'\n';
	}
	return 0;
}

