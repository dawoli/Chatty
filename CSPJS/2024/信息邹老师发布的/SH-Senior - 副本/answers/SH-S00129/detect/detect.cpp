#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ll long long
int n,m,l,V;
int d[N],v[N],a[N],p[N];
int cnt;
int ovsp[N];//加速度为负数的超速车辆编号
int leav[N];//超速车辆离开主干道的距离点（若离开点为小数则为其整数部分） 
int ove[25][25],ove2[25][25];//每辆车超速时段可监控到的仪器编码 
int num[25],num2[25];//每辆车超速被检测到总数 
int c1[25];bool inn[25];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;cin>>t;
	while(t--){
		memset(d,0,sizeof d);
		memset(v,0,sizeof v);
		memset(a,0,sizeof a);
		memset(p,0,sizeof p);
		cnt=0;
		scanf("%d%d%d%d",&n,&m,&l,&V);
		bool flag=0,flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]!=0)flag=1;
			if(a[i]<=0)flag1=1;
			if(a[i]>=0)flag2=1;
		}
		for(int i=1;i<=m;i++)scanf("%d",&p[i]);
		sort(p+1,p+1+m);
		if(!flag){//加速度为0 
			cnt=0;
			int dd=p[m];
			for(int i=1;i<=n;i++)
				if(v[i]>V&&d[i]<=dd)cnt++;
			ll ans=m-1;
			cout<<cnt<<" "<<ans<<endl;
			continue;
		}
		else if(!flag1){//加速度为正数 
			int dd=p[m];
			for(int i=1;i<=n;i++){
				if(d[i]>dd)continue;
				ll zuo=V*V-v[i]*v[i];
				ll you=2*a[i]*(dd-d[i]);
				if(zuo<you)cnt++;
			}
			ll ans=m-1;
			cout<<cnt<<" "<<ans<<endl;
			continue; 
		}
		else if(!flag2){//全为负数//
			int dd=0; 
			for(int i=1;i<=n;i++){
				if(v[i]>V){
					cnt++;
					ovsp[cnt]=i;
					double k=-v[i]*v[i]/2/a[i];
					//int kk=k;
					//if(k-kk!=0)kk++;
					leav[cnt]=(int)k;
					dd=max(dd,d[i]);
				}
			}
			int pcnt=1;
			sort(leav+1,leav+1+cnt);
			for(int i=1;i<=cnt;i++){
				if(leav[i]>dd&&d[ovsp[i]]>dd)continue;
				dd=leav[i];pcnt++;
			}
			cout<<cnt<<" "<<pcnt<<endl;
		}
		else{
			cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(d[i]>p[j])continue;
					int s=p[j]-d[i];
					bool f=0;
					if(s==0){
						if(v[i]>V){
							num[i]++;ove[i][num[i]]=j;
							num2[j]++;ove2[j][num2[j]]=i;
							if(!inn[i])cnt++,inn[i]=1;
						}
					}
					else if(a[i]!=0){
						ll zuo=V*V-v[i]*v[i];
						ll you=2*a[i]*s;
						if(zuo<you){
							num[i]++;ove[i][num[i]]=j;
							num2[j]++;ove2[j][num2[j]]=i;
							if(!inn[i])cnt++,inn[i]=1;
						}
					}
					else if(a[i]==0){
						if(v[i]>V){
							num[i]++;ove[i][num[i]]=j;
							num2[j]++;ove2[j][num2[j]]=i;
							if(!inn[i])cnt++,inn[i]=1;
						}
					}
				}
			}
			/*for(int i=1;i<=m;i++){
				for(int j=1;j<=num2[i];j++){
					if(!inn[ove2[i][j]])cnt++;
				}
			}*/
			/*for(int i=1;i<=n;i++){
				for(int j=1;j<=num[i];j++)
					cout<<ove[i][j]<<" ";
				cout<<endl;	
			}*/
			memset(inn,0,sizeof inn);
			int era=0;
			for(int i=1;i<=m;i++){
				bool f=0;
				for(int j=1;j<=num[i];j++){
					if(!inn[ove2[i][j]])inn[ove2[i][j]]=1,f=1;
				}
				if(!f)era++;
			}
			cout<<cnt<<" "<<era<<endl;
			int res=0;
		}
	}
}
