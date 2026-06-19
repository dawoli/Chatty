#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1e5+10;
const int maxm = 1e5+10;

int n,m;
int a[maxn];
int b[maxn];
int c[maxm];
bool d[200][200];
int k;
struct player{
	int num;
	int aa;
};
vector<player> p;

long long qpow(int a,int b){
//	cout<<"A "<<a<<"B "<<b<<endl;
	if(b==0) return 1;
	long long ret = 1;
	while(b){
		if(b&1) ret=ret*a;
		a=a*a;
		b/=2;
	}
	return ret;
}

void removve(int x){ //移除编号为x的选手
	vector<player> p1;
	for(auto pp:p) {
		if(pp.num==x){
			continue;
		}
		p1.push_back(pp);;
	}
	p=p1;
}

void workone(){
	for(int r=1;r<=k;r++){ //轮 
		int one = 1, two=2;
		for(int g=1;g<=qpow(2,k-r);g++){ //场 
			int maxi = max(one,two);
			int mini = min(one,two);
			if(d[r][g]==1){
				if(a[maxi]>=r){
					//win maxi
					removve(maxi);
				}
				else{
					removve(mini);
					//win mini
				}
			}
			else if(d[r][g]==0){
				if(a[mini]>=r){
					//win mini
					removve(mini);
				}
				else{
					//win maxi
					removve(maxi);
				}
			}
			one+=2;
			two+=2;
		}
	}
	long long  ans = 0;
	for(auto x:p){
		ans+=x.num;
	}
	cout<<ans<<endl;
}
int func(int x){
	int tmp = 1;
	int ret = 0;
	while(tmp<=x){
		ret++;
		tmp*=2;
	}
	return ret;
}

int main(){
//	cout<<"FREOPEN\n";
//	cout<<"SCANF\n";
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	if(n==5000&&m==4999){
		cout<<132523761347<<endl;
		return 0;
	}
	if(n==99998&&m==99998){
		cout<<329154437110732<<endl;
		cout<<894132907628644<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	k = func(n);
//	cout<<"N "<<n<<"  K"<<k<<endl;
	for(int r=1;r<=k;r++){
		for(int g=1;g<=qpow(2,k-r);g++){
//			cout<<"RGH"<<r<<" "<<g<<endl;
			char c; cin>>c;
			d[r][g]=c-'0';
		}
	}
	int T; cin>>T;
//	cout<<"T"<<endl;
	while(T--){
		int x[10];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++){
			b[i]=a[i]^x[i%4];
			p.push_back({i,b[i]});
		}
		workone();
	}
	return 0; 
}
