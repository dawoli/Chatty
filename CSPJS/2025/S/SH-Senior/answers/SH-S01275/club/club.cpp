#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
int t,n,ans;
int go[100];
int peo[100005][3],delta[100005],deltamid[100005],del;
bool dp[100005][3];
void sum_up(){
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			if(dp[i][j]) ans+=peo[i][j];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ew=0;ew<t;ew++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>peo[i][0]>>peo[i][1]>>peo[i][2];
		}
		int maxn=0,k;
		for(int i=0;i<n;i++){
			int maxn=-19198101;
			for(int j=0;j<3;j++){
				if(peo[i][j]>maxn){
					maxn=peo[i][j];
					k=j;
				}
			}
			dp[i][k]=1;
		}
		/*调试一下*
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++) cout<<dp[i][j]<<" ";
			cout<<endl; 
		}*/
		/*倘若加入同一个组的人数超标,必然其余两个组不超标
		只需将超标的组重新排列即可，直接丢给同行第二大的即可 
		*/
		//先确定那一列超标 
		int wrong=91;
		for(int i=0;i<3;i++){
			int app=0;
			for(int j=0;j<n;j++){
				if(dp[j][i]==1) app++;
			}
			if(app>(n/2)) wrong=i;
		}
		if(wrong==91){
			sum_up();
		}else{
			for(int i=0;i<n;i++){
				int minn=1e9,maxx=-1e9,midd,o,p;
				if(dp[i][wrong]==1){
					for(int j=0;j<3;j++){
						if(peo[i][j]<minn){
							minn=min(peo[i][j],minn);
							o=j;
						}if(peo[i][j]>maxx){
							maxx=max(peo[i][j],maxx);
							p=j;
						}
						
					}for(int j=0;j<3;j++){
						if(j!=o && j!=p) midd=peo[i][j];
					}
					delta[i]=maxx-midd;
					deltamid[i]=midd;
				}else delta[i]=-1;
			}
			for(int i=0;i<n;i++){
				if(dp[i][wrong]==1) del++;
			}
			/*while(del>(n/2)){
				int mindelta=1e9,minn=1e9,maxx=-1e9,o,p,line,midd;//temp是行数 
				for(int i=0;i<n;i++){
					if(mindelta<delta[i]){
						mindelta=min(mindelta,delta[i]);
						line=i;
					}
				}
				for(int i=0;i<3;i++){
					if(peo[line][i]<minn){
						minn=min(peo[line][i],minn);
						o=i;
					}if(peo[line][i]>maxx){
						maxx=max(peo[line][i],maxx);
						p=i;
					}
				}
				for(int j=0;j<3;j++){
					if(j!=o && j!=p) midd=peo[line][j];
				}
				cout<<midd<<"　"; 
				dp[line][wrong]=0;
				dp[line][midd]=1;
				del--;
			}*/
			int nu=0;
			while(del>(n/2)){
				//找到最小的处于wrong列的数
				int minline,minn=1e9;
				for(int i=0;i<n;i++){
					for(int it=0;it<nu;it++){
						if(i==go[it]) continue;
					}
					if(minn>delta[i] && delta[i]>0){
						minn=delta[i];
						minline=i;
					}
				}
				go[nu]=minline;
				nu++;
				cout<<go[nu]<<" ";
				//接下来找line行的中间大的数的索引位置
				int temp[3];
				for(int i=0;i<3;i++){
					temp[i]=peo[minline][i];
				}
				sort(temp,temp+3);
				int middnum=temp[1];
				int maxxnum=temp[2];
				int midd,maxx;
				for(int i=0;i<3;i++){
					if(peo[minline][i]==middnum) midd=i;
					if(peo[minline][i]==maxxnum) maxx=i;
				}
				dp[minline][maxx]=0;
				dp[minline][midd]=1;
				del--;
			}
			//接下来开始调整，使得最优解
			sum_up(); 
		}//delta表示能赚的最多的
		cout<<endl<<ans<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	ans=0;
	return 0;
	/*
	
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0
	
	*/
} 
