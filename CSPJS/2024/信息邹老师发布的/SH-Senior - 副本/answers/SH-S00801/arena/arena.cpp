#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9,M=N,K=log2(N)+2;
int n,m,a[N],c[M],k,t,x[4],b[N];//a-x->b
bool d[K][N];
int id[N];
bool lo[N];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	k=log2(n);
	if(1<<k<n) k++;
	//cout<<"k="<<k<<endl;
	for(int i=1;i<=k;i++){
		//cout<<i<<":"<<(1<<(k-i))<<endl;
		for(int j=1;j<=(1<<(k-i));j++){
			char c;
			cin>>c;
			d[i][j]=(c=='1');
		}
	}
	cin>>t;
	//cout<<"t="<<t<<endl;
	while(t--){
		//cout<<"###############\n";
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++) b[i]=a[i]^x[i%4];
		//cout<<"a':\n";
		//for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		//cout<<endl;
		ans=0;
		for(int q=1;q<=m;q++){
			memset(id,0,sizeof(id));
			memset(lo,0,sizeof(lo));
			//cout<<"question "<<q<<":\n";
			int cc=c[q];//1~ccÑ¡ÊÖ 
			int kk=log2(cc);
			if(cc>1<<kk) kk++;
			for(int i=1;i<=1<<kk;i++) id[i]=i;
			for(int i=1;i<=1<<kk;i++) lo[i]=0;
			//cout<<"cc="<<cc<<" kk="<<kk<<endl;
			//cout<<"id:\n";
			//for(int i=1;i<=1<<kk;i++) cout<<id[i]<<" ";
			//cout<<endl;
			for(int i=1;i<=kk;i++){//ÂÖ 
				//cout<<"roll "<<i<<endl;
				for(int j=1;j<=(1<<(kk-i));j++){
					//cout<<"game "<<j<<":\n";
					int x,y;
					if(d[i][j]==0) x=j*2-1,y=j*2;
					else x=j*2,y=j*2-1;
					int idx=id[x],idy=id[y];
					//cout<<"host:"<<x<<"("<<idx<<","<<b[idx]<<")"<<endl;
					id[x]=id[y]=cc+1;
					if(idx<=cc){
						if(b[idx]>=i){
							id[j]=idx;
						//	cout<<"win\n";
							lo[idy]=1;
						}
						else{
							lo[idx]=1;
							id[j]=idy;
						//	cout<<"lose\n";
						}
					}
				}
				//cout<<"nowid:\n";
				//for(int j=1;j<=1<<(kk-i);j++) cout<<id[j]<<" ";
				//cout<<endl;
				//cout<<"lose:";
				//for(int j=1;j<=1<<kk;j++) cout<<lo[j];
				//cout<<endl;
			}
			ll now=0;
			if(id[1]<=cc) now=id[1];
			else for(int i=1;i<=1<<kk;i++)
				if(!lo[i]) now+=i;//,cout<<i<<" ";
			//cout<<"now="<<now<<endl;
			ans^=q*now;
		}
		cout<<ans<<endl;
	}
	return 0;
}
