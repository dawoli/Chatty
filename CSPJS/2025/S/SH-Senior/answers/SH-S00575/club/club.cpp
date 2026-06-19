#include<bits/stdc++.h>
using namespace std;
struct node{
	long long f,s,t;
	bool operator<(const node &x)const{
		return max(f,max(s,t))>max(x.f,max(x.s,x.t));
	}	
}g[100005];
long long num=0;
long long t,n;
bool cmp(node x,node y){
	return max(x.s,x.t)>max(y.s,y.t);
}
priority_queue<node> q[5];
priority_queue<long long>q1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		while(!q1.empty())q1.pop();
		for(int j=1;j<=3;j++){
			while(!q[j].empty())q[j].pop();
		}
		num=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>g[j].f>>g[j].s>>g[j].t;
			if(max(g[j].f,max(g[j].s,g[j].t))==g[j].f){
				q[1].push(g[j]);
				num+=g[j].f;
			}
			else if(max(g[j].f,max(g[j].s,g[j].t))==g[j].s)
			{
				q[2].push(g[j]);
				num+=g[j].s;
			}
			else {
				q[3].push(g[j]);
				num+=g[j].t;
			}
		}
		long long a=q[1].size(),b=q[2].size(),c=q[3].size();
		if(a>n/2){
			long long sss=a;
			for(int j=1;j<=a;j++){
				int x=q[1].top().f,y=q[1].top().s,z=q[1].top().t;
				q[1].pop();
				if(y-x>z-x){
					q1.push(y-x);
				}
				else q1.push(z-x);
			}
			for(int j=1;j<=sss-n/2;j++)
			{ 
				num+=q1.top();
				q1.pop(); 
			}
		}
		if(b>n/2){
			long long sss=b;
			for(int j=1;j<=b;j++){
				int x=q[2].top().f,y=q[2].top().s,z=q[2].top().t;
				q[2].pop();
				if(x-y>z-y){
					q1.push(x-y);
				}
				else q1.push(z-y);
			}
			for(int j=1;j<=sss-n/2;j++)
			{
				num+=q1.top();
				q1.pop(); 
			}
		}
		if(c>n/2){
			long long sss=c;
			for(int j=1;j<=c;j++){
				int x=q[3].top().f,y=q[3].top().s,z=q[3].top().t;
				q[3].pop();
				if(x-z>y-z){
					q1.push(x-z);
				}
				else q1.push(y-z);
			} 
			for(int j=1;j<=sss-n/2;j++)
			{ 
				num+=q1.top();
				q1.pop(); 
			}
		}
		cout<<num<<endl;
	}
}
