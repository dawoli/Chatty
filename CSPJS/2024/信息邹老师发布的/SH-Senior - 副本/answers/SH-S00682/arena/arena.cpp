#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=111110;
int n,m,t,x[4];
int ap[N],a[N],c[N],pk[N];
bool f[65536][16];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>ap[i];
	for(int j=0;j<m;j++)cin>>c[j];
	int K=ceil(log2(m));
	for(int i=0;i<K;i++)for(int j=0;j<=K/(int)(pow(2.0,i));j++){char c;cin>>c;f[i][j]=c-48;}
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		for(int t=0;t<4;t++)cin>>x[t];
		for(int i=0;i<n;i++)a[i]=ap[i]^x[i%4];
		int res=0;
		for(int j=0;j<m;j++){
			int k=ceil(log2(c[j]));
			for(int i=0;i<k;i++)pk[i]=i;
			for(int i=0;i<k;i++){
				for(int h=0;h<k/(int)(pow(2.0,i));h++){
					if(f[i][h]){
						pk[h]=a[pk[h*2+1]]<i+1?pk[h*2]:pk[h*2+1];
					}
					else{
						pk[h]=a[pk[h*2]]<i+1?pk[h*2+1]:pk[h*2];
					}
				}
			}
			res^=(j+1)*(pk[0]+1);
		}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
