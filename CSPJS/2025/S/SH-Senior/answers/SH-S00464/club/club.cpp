#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5];
int club[5][N];
int num[5];
int insort;
bool cmp(int x,int y){
	int xx=-(a[x][insort]-(a[x][1]+a[x][2]+a[x][3]-a[x][insort]));
	int yy=-(a[y][insort]-(a[y][1]+a[y][2]+a[y][3]-a[y][insort]));
	return xx<yy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=3;i++)num[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int minn=min(a[i][1],min(a[i][2],a[i][3]));
			ans+=minn;
			a[i][1]-=minn;
			a[i][2]-=minn;
			a[i][3]-=minn;
			int maxx=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==maxx){
				num[1]++;
				club[1][num[1]]=i;
			}else if(a[i][2]==maxx){
				num[2]++;
				club[2][num[2]]=i;
			}else if(a[i][3]==maxx){
				num[3]++;
				club[3][num[3]]=i;
			}
			//cout<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<endl;
		}
		//cout<<ans<<endl;
		for(int i=1;i<=3;i++){
			if(num[i]>n/2){
				insort=i;
				int p=num[i];
				sort(club[i]+1,club[i]+p+1,cmp);
				//for(int j=1;j<=num[i];j++)cout<<-(a[club[i][j]][insort]-(a[club[i][j]][1]+a[club[i][j]][2]+a[club[i][j]][3]-a[club[i][j]][insort]))<<' ';
				while(num[i]>n/2){
					//cout<<a[club[i][num[i]]][1]<<' '<<a[club[i][num[i]]][2]<<' '<<a[club[i][num[i]]][3]<<' '<<-(a[club[i][num[i]]][insort]-(a[club[i][num[i]]][1]+a[club[i][num[i]]][2]+a[club[i][num[i]]][3]-a[club[i][num[i]]][insort]))<<endl;
					if(i==1)ans+=a[club[i][num[i]]][2]+a[club[i][num[i]]][3];
					if(i==2)ans+=a[club[i][num[i]]][1]+a[club[i][num[i]]][3];
					if(i==3)ans+=a[club[i][num[i]]][1]+a[club[i][num[i]]][2];
					num[i]--;
				}
			}
		}
		for(int i=1;i<=3;i++)for(int j=1;j<=num[i];j++)ans+=a[club[i][j]][i];
		cout<<ans<<endl;
	} 
	return 0;
}

