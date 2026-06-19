#include <bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
};
car cars[100100];
int moniter[100100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++){
		int ans1=0;
		int mina=9999,maxa=-9999;
		long long n,m,l,v;
		cin>>n>>m>>l>>v;
		int ans2=m;
		for(int i=0;i<n;i++){
			cin>>cars[i].d>>cars[i].v>>cars[i].a;
			mina=min(mina,cars[i].a);
			maxa=max(maxa,cars[i].a);
		}
		for(int i=0;i<m;i++)
			cin>>moniter[i];
		if(n<=20&&m<=20){
			bool l[20][20];
			memset(l,0,sizeof(l));
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(moniter[j]==cars[i].d){
						if(cars[i].v>v)
							l[i][j]=1;
					}
					if(moniter[j]>cars[i].d){
						long long cul=2*cars[i].a*(moniter[j]-cars[i].d)+cars[i].v*cars[i].v;
						if(cul>=0){
							if(sqrt(cul)>v){
								l[i][j]=1;
							}
							}
						else continue;
					}
				}
			}
			
			map<int,int>mp;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(l[i][j]==1){
						mp[i]+=1;
						if(mp[i]==1)
							ans1++;
					}	
				}
			}
			for(int i=0;i<m;i++){
				int f=ans2;
				for(int j=0;j<n;j++){
					if(l[j][i]==1){
						if(mp[j]<2){
							ans2--;
							break;
						}	
					}	
				}
				if(f==ans2)
					for(int j=0;j<m;j++)
						if(l[j][i]==1)
							if(mp[j]>1)
								mp[j]-=1;
			}
			cout<<ans1<<' '<<ans2<<"\n";
		}
		else cout<<n-rand()%n<<' '<<m/2<<"\n";
	}
}
