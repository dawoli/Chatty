#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int t,n,m[N][4],sec[N],ans,sp[4],sum[4],k[N][4];
struct CLUB{
	int sat,num;
}sm[4][N];
bool cmp(CLUB a,CLUB b){
	return a.sat<b.sat;
}
int ans_cal(){
	int ans_p=0;
	for(int i=1;i<=3;i++){
			for(int j=sp[i];j<sp[i]+sum[i];j++){
				ans_p+=sm[i][j].sat;
			}
		}
	return ans_p;
}
void solve(){
	bool flag=1;
		while(flag){
			vector<int> ch;
			for(int i=1;i<=3;i++)
				sort(sm[i],sm[i]+sum[i],cmp);
			/*
			for(int i=1;i<=3;i++){
				for(int j=sp[i];j<sp[i]+sum[i];j++)
					cout<<sm[i][j].sat<<" "<<sm[i][j].num<<endl;
				cout<<endl;
			}
			*/
			flag=0;
			for(int i=1;i<=3;i++){
				while(sum[i]>n/2){
					flag=1;
					CLUB u=sm[i][sp[i]];
					sp[i]++;
					sum[i]--;
					m[u.num][i]=-1;
					ch.push_back(u.num);
				}
			}
			for(int i=0;i<ch.size();i++){
				int v=ch[i];
				int u=m[v][1],un=1;
				for(int j=2;j<=3;j++)
					if(m[v][j]>u) u=m[v][j],un=j;
				sm[un][sum[un]]={u,i};
				sum[un]++;
				//cout<<v<<" "<<un<<" "<<u<<endl;
			}
			//cout<<"下一轮"<<endl;
		}
	ans=max(ans,ans_cal());
	return;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int yl=1;yl<=t;yl++){
		cin>>n;
		for(int i=1;i<=n;i++) sec[i]=0;//初始化 
		for(int i=1;i<=3;i++) sp[i]=sum[i]=0;
		for(int i=1;i<=3;i++)
			for(int j=0;j<=n;j++)
				sm[i][j]={0,0};
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>k[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				m[i][j]=k[i][j];
		for(int i=1;i<=n;i++){
			int u=m[i][1],un=1;
			for(int j=2;j<=3;j++)
				if(m[i][j]>u) u=m[i][j],un=j;
			sm[un][sum[un]]={u,i};
			sum[un]++;
			//cout<<i<<" "<<un<<" "<<u<<endl;
		}
		solve();
		for(int i=1;i<=n;i++) sec[i]=0;//初始化 
		for(int i=1;i<=3;i++) sp[i]=sum[i]=0;
		for(int i=1;i<=3;i++)
			for(int j=0;j<=n;j++)
				sm[i][j]={0,0};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				m[i][j]=k[i][j];
		for(int i=1;i<=n;i++){
			sm[2][sum[2]]={m[i][2],i};
			sum[2]++;
		}
		solve();
		for(int i=1;i<=n;i++) sec[i]=0;//初始化 
		for(int i=1;i<=3;i++) sp[i]=sum[i]=0;
		for(int i=1;i<=3;i++)
			for(int j=0;j<=n;j++)
				sm[i][j]={0,0};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				m[i][j]=k[i][j];
		for(int i=1;i<=n;i++){
			sm[1][sum[1]]={m[i][1],i};
			sum[1]++;
		}
		solve();
		for(int i=1;i<=n;i++) sec[i]=0;//初始化 
		for(int i=1;i<=3;i++) sp[i]=sum[i]=0;
		for(int i=1;i<=3;i++)
			for(int j=0;j<=n;j++)
				sm[i][j]={0,0};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				m[i][j]=k[i][j];
		for(int i=1;i<=n;i++){
			sm[3][sum[3]]={m[i][3],i};
			sum[3]++;
		}
		solve();
		cout<<ans<<"\n";
	}
	return 0;
}


