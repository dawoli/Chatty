#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,dep,sat;
}a[300005];
bool cmp(node x,node y){
	return x.sat>y.sat;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==2){
			int X,Y,Z,M,N,W;
			cin>>X>>Y>>Z>>M>>N>>W;
			cout<<max(max(X+N,X+W),max(max(Y+M,Y+W),max(Z+M,Z+N)))<<endl;
			continue;
		}
		bool flag=true;
		for(int i=1;i<=3*n;i++){
			cin>>a[i].sat;
			if(i%3==0)a[i].num=i/3;
			else a[i].num=i/3+1;
			a[i].dep=i%3+1;
			if((a[i].dep==2||a[i].dep==3)&&a[i].sat!=0)flag=false;
		}
		if(flag){
			int ans=0;
			sort(a+1,a+3*n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].sat;
			}
			cout<<ans;
			continue;
		}
		sort(a+1,a+3*n+1,cmp);
		bool people[100005]={},A=true,B=true,C=true;
		int x=0,y=0,z=0,ans=0;
		for(int i=1;i<=3*n;i++){
			if(a[i].dep==1){
				if(people[a[i].num]==0&&A==true){
					ans+=a[i].sat;
					people[a[i].num]=1;
					x++;
					if(x==n/2)A=false;
				}
			}
			else if(a[i].dep==2){
				if(people[a[i].num]==0&&B==true){
					ans+=a[i].sat;
					people[a[i].num]=1;
					y++;
					if(y==n/2)B=false;
				}
			}
			else{
				if(people[a[i].num]==0&&C==true){
					ans+=a[i].sat;
					people[a[i].num]=1;
					z++;
					if(z==n/2)C=false;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
