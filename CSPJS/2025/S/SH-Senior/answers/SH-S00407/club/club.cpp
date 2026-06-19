#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
int a[100005][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int Max=-1,MaxPos;
			int Second=-1,SecondPos;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>Max){
					Max=a[i][j];
					MaxPos=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=MaxPos){
					if(a[i][j]>Second){
						Second=a[i][j];
						SecondPos=j;
					}
				}
			}
			if(MaxPos==1){
				q1.push(Max-Second);
				ans+=Max;
				if(q1.size()>n/2){
					int Minus=q1.top();
					q1.pop();
					ans-=Minus;
				}
			}
			if(MaxPos==2){
				q2.push(Max-Second);
				ans+=Max;
				if(q2.size()>n/2){
					int Minus=q2.top();
					q2.pop();
					ans-=Minus;
				}
			}
			if(MaxPos==3){
				q3.push(Max-Second);
				ans+=Max;
				if(q3.size()>n/2){
					int Minus=q3.top();
					q3.pop();
					ans-=Minus;
				}
			}
		}
		printf("%d\n",ans);
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();
	}
	return 0;
}
