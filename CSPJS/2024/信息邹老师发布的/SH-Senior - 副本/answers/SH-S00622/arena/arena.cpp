#include<bits/stdc++.h>
using namespace std;
int T,n,m,ax[100010],k,x[10],c[100010];
bool d[100][100010];
struct info{
	int l,r,v;
}a[100010];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ax[i],a[i].l=i-1,a[i].r=i+1;
	a[1].l=1;a[n].r=n;
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;pow(2,i)<n;i++)k=i;
	k++;
	for(int i=1;i<=k;i++){
		char c;
		for(int j=1;j<=pow(2,k-i);j++)cin>>c,d[i][j]=c-'0';
	//	cin.ignore();
	}
	cin>>T;
	while(T--){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		int ans=0;
		for(int i=1;i<=n;i++)a[i].v=(ax[i]^x[i%4]);
		int now=1;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++)a[i].l=i-1,a[i].r=i+1;
			a[1].l=1;a[n].r=n;
			int l,ppl=c[i];now=1;
			for(int j=1;pow(2,j)<=ppl;j++)l=j;
		//	cout<<l<<"\n\n";
			for(int R=1;R<=l;R++){
				for(int G=1;G<=ppl/2;G++){
					if(d[R][G]==0){
						if(a[now].v>=R){
							a[now].r=a[a[now].r].r;
							a[a[now].r].l=now;
						//	now=a[now].r;
						}
						else{
							now=a[now].r;
							a[now].l=a[a[now].l].l;
							a[a[now].l].r=now;
						//	now=a[now].r;
						}
					}
					else{
						now=a[now].r;
						if(a[now].v>=R){
							a[now].l=a[a[now].l].l;
							a[a[now].l].r=now;
					//		now=a[now].r;
						}
						else{
							now=a[now].l;
							a[now].r=a[a[now].r].r;
							a[a[now].r].l=now;
					//		now=a[now].r;
						}
					}
					cout<<now<<' ';
				//	now=a[now].r;
				}
			//	cout<<'\n';
				ppl/=2;
			}
		//	 cout<<"FINAL"<<now<<"\n\n";
			ans^=now*i;
		}
		cout<<ans;
	}
	return 0;
}
//Z*L#LH%9

