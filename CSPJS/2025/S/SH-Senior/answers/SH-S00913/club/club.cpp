#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
struct People{
	int cha,gp;
}p[100005];
int group[5];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		priority_queue<int, vector<int>, greater<int> > que;
		int ans=0;
		cin>>n;
		int x,y,z;
		for(int i=1;i<=3;i++)group[i]=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			int tmp=max(x,max(y,z));
			ans+=tmp;
			if(x==tmp){
				p[i].gp=1;
				group[1]++;
			}else if(y==tmp){
				p[i].gp=2;
				group[2]++;
			}else{
				p[i].gp=3;
				group[3]++;
			}
			
			if(y<z)swap(y,z);
			if(x<y)swap(x,y);
			if(y<z)swap(y,z);
			p[i].cha=x-y;
		}
		if(group[1]>n/2){
			for(int i=1;i<=n;i++){
				if(p[i].gp==1){
					que.push(p[i].cha);
				}
			}
			for(int i=1;i<=(group[1]-n/2);i++){
				int tmp=que.top();
				que.pop();
				ans-=tmp;
			}
		}
		else if(group[2]>n/2){
			for(int i=1;i<=n;i++){
				if(p[i].gp==2){
					que.push(p[i].cha);
				}
			}
			for(int i=1;i<=(group[2]-n/2);i++){
				int tmp=que.top();
				que.pop();
				ans-=tmp;
			}
		}
		else if(group[3]>n/2){
			for(int i=1;i<=n;i++){
				if(p[i].gp==3){
					que.push(p[i].cha);
				}
			}
			for(int i=1;i<=(group[3]-n/2);i++){
				int tmp=que.top();
				que.pop();
				ans-=tmp;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

