#include<bits/stdc++.h>
using namespace std;
#define N 100007
int n;
struct node{
	int a,b,c,k,g;
	bool operator <(const node &bb)const{
		return k>bb.k;
	}
}p[N];
int get(node x){
	int l=max(max(x.a,x.b),x.c);
	int k[4];
	k[0]=x.a,k[1]=x.b,k[2]=x.c;
	sort(k,k+3);
	return k[2]-k[1];
}
bool cmp1(node x,node y){
	return x.k>y.k;
}
void solve(){
	int suma=0,sumb=0,sumc=0,ans0=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].a>>p[i].b>>p[i].c;
		p[i].k=get(p[i]);
		p[i].g=max(max(p[i].a,p[i].b),p[i].c);
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i){
		//cout<<p[i].k<<'\n';
		if(p[i].a==p[i].g&&suma<n/2){
			++suma;
			ans0+=p[i].a;
		}
		else if(p[i].a==p[i].g){
			ans0+=max(p[i].b,p[i].c);
		}
		else if(p[i].b==p[i].g&&sumb<n/2){
			++sumb;
			ans0+=p[i].b;
		}
		else if(p[i].b==p[i].g){
			ans0+=max(p[i].a,p[i].c);
		}
		else if(p[i].c==p[i].g&&sumc<n/2){
			++sumc;
			ans0+=p[i].c;
		}
		else if(p[i].c==p[i].g){
			ans0+=max(p[i].a,p[i].b);
		}
	}
	cout<<ans0<<'\n';
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
//我不知道这样行不行 

//别假了 

	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!
//1= please!!!!!!!!!!!!!

//luogu id: lhz2022 
