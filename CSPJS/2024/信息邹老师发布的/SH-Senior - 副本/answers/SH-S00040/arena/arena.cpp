#include<bits/stdc++.h>
using std::fstream;
using std::endl;
using std::cerr;

typedef long long ll;

#define int ll

fstream fin("arena.in",std::ios::in);
#define cin fin
fstream fout("arena.out",std::ios::out);
//#define fout std::cout // for the time being

int n,m;
const int N=1e5+100,M=1e5+100;

int aa[N];
int c[M];
char s[20][N];

int a[N];

int cur[N];

ll testtest(int x) {
	int k=0;while((1<<k)<x)k++;
	for(int i=1;i<=x;i++) cur[i]=i;
	for(int i=x+1;i<=(1<<k);i++) assert(0);
	for(int j=1;j<=k;j++) {
		for(int i=1;i<=x;i++) {
			if(s[j][i]!='1') std::swap(cur[i*2],cur[i*2-1]);
			if(cur[i*2]>=j) cur[i]=cur[i*2];
			else cur[i]=cur[i*2-1];
		}
	}
	return cur[1];
}

void test() {
	int x[4];
	for(int i=0;i<4;i++) cin>>x[i];
	for(int i=1;i<=n;i++) a[i]=aa[i]^x[i%4];
	
	ll ans=0;
	for(int j=1;j<=m;j++) ans^=j*1ll*testtest(c[j]);
	fout<<ans<<endl;
}

signed main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>aa[i];
	for(int j=1;j<=m;j++) cin>>c[j];
	
	for(int i=0;(1<<i)<n;i++) cin>>s[i];
	int t;
	cin>>t;
	while(t--)test();
	
	return 0;
}
/*
输入O(NT)都费劲了，那么说明可能不需要求出所有的。 
*/ 
/*
输入O(NT)都费劲了，那么说明可能不需要求出所有的。
it's already too late. 
but i'll try my best. 
not debugged yet, so i would do that afterwards. 
*/ 

// duipai.cpp
/*
#include<bits/stdc++.h>
using std::fstream;
using std::endl;
using std::cout;
using std::cerr;
using std::string;

typedef long long ll;

// #define int ll

#define name "color"

signed main() {
	for(int i=1;i<=2;i++) {
		string in=name;in+=char('0'+i);in+=".in";
		string ot=name;ot+=char('0'+i);ot+=".ans";
		cout<<in<<' '<<ot<<endl;
		system(("copy "+in+" "+name+".in").c_str());
		printf("start\n");
		system(name ".exe");
		printf("end\n");
		
//		string command="comp " name ".out "+ot;
//		cout<<command<<endl;
//		int ans=system(command.c_str());
//		if(!ans) printf("AC\n");
//		else printf("WA\n"); // \r\n与\n之争 
		
		system("start " name ".out"); // 肉眼比对法 
		system(("start "+ot).c_str());
		
		system("pause");
	}	
	
	return 0;
}
*/
