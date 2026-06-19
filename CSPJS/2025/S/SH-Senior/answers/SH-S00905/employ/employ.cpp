#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=509,M=509,sn=109;
const ll MOD=998244353;
int n,m;
int f[N][N][N];
string s;
int c[N];
int numl[2*N],numr[2*N];
struct Node{
	bool type;int num;
} d[2*N];
bool cmp(const Node &a,const Node &b){
	return a.num<b.num;
}

void print(){
	for(int i=1;i<=2*n;i++,cout<<endl<<endl){
		for(int x=0;x<=n;x++,cout<<endl)
			for(int y=0;y<=n;y++)
//				cout<<i<<" "<<x<<" "<<y<<" "<<f[i][x][y]<<endl;
				cout<<f[i][x][y]<<" ";
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0,tmp=0;i<n;i++){
		d[i+1].type=0,d[i+1].num=tmp;
		tmp+=s[i]=='0';
	}
	for(int i=1;i<=n;i++){
		cin>>d[n+i].num;
		d[n+i].type=1;d[n+i].num--;
	}
	sort(d+1,d+2*n+1,cmp);
	for(int i=1;i<=2*n;i++)cout<<d[i].type<<" "<<d[i].num<<endl;
	for(int i=1;i<=2*n;i++){
		numl[i]=numl[i-1],numr[i]=numr[i-1];
		if(d[i].type==0)numl[i]++;
		else numr[i]++;
	}
	f[0][0][0]=1;
	for(int i=1;i<=2*n;i++){
		int a=numl[i],b=numr[i];
		if(!d[i].type){
			for(int x=1;x<=a;x++)
				for(int y=0;y<=b;y++)
					f[i][x][y]=f[i-1][x-1][y];
		}
		else{
			for(int x=0;x<=a;x++)
				for(int y=1;y<=b;y++)
					f[i][x][y]=f[i-1][x][y-1];
			for(int x=0;x<=a;x++)
				for(int y=0;y<=b;y++){
					f[i][x][y]+=x*f[i-1][x+1][y];
					f[i][x][y]%=MOD;
				}
		}
	}
//	print();
	ll ans=0;
	for(int x=0;x<=n-m;x++)
		for(int y=0;y<=n-m;y++)
			ans=(ans+f[2*n][x][y])%MOD;
	cout<<ans<<endl;
	return 0;
}

