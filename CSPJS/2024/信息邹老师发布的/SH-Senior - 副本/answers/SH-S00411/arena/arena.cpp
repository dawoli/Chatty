#include<fstream>
using namespace std;
ifstream fin("arena.in");
ofstream fout("arena.out");
int T;
int n,m;
int oria[100005];
int c[100005];
int X[4];
int a[100005];
char temp;
struct segment{
	int l,r,layer,index;
	int d;
	int bndtowin;
	void set(int lef,int rig,int lay,int ind){
		l=lef,r=rig,layer=lay,index=ind;
		fin>>temp;
		d=temp-'0';
	}
}tr[200005];
int k[100005];
int K=0;
long long ans;
int now=0,deci;
bool flag=1;
int main(){
	fin>>n>>m;
	for(int i=0;i<n;i++)fin>>oria[i];
	for(int i=1;i<=m;i++)fin>>c[i];
	while((1<<K)<n)K++;
	for(int R=1;R<=K;R++){
		for(int i=1<<(K-R);i<(1<<(K-R+1));i++){
			if(R==1)tr[i].set(i^(1<<(K-R))*2,(i^(1<<(K-R))+1)*2,1,i);
			else tr[i].set(tr[2*i].l,tr[2*i+1].r,R,i);
		}
	}
	for(int i=1;i<=m;i++)while(1<<k[i]<c[i])k[i]++;
	for(int i=1;i<=m;i++)if(c[i]!=(1<<k[i]))flag=0;
	fin>>T;
	for(int testcaseid=0;testcaseid<T;testcaseid++){
		fin>>X[0]>>X[1]>>X[2]>>X[3];
		for(int i=0;i<n;i++)a[i]=oria[i]^X[(i+1)%4];
		for(int R=1;R<=K;R++){
			for(int i=0;i<(1<<(K-R));i++){
				now=(1<<(K-R))+i,deci=tr[now].d;
				if(R==1)tr[now].bndtowin=(a[2*i+deci]>=1)?(2*i+deci):(2*i+1-deci);
				else tr[now].bndtowin=(a[tr[2*now+deci].bndtowin]>=R)?tr[2*now+deci].bndtowin:tr[2*now+1-deci].bndtowin;
			}
		}
		if(flag){
			for(int i=1;i<=m;i++)ans^=((long long)i*(tr[1<<(K-k[i])].bndtowin+1));
			fout<<ans<<endl;
		}
		else fout<<1<<endl;
	}
	return 0;
}
