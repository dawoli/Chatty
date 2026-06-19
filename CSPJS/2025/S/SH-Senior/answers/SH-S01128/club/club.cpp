/*
性质 A:
选则 a[i][1]前n/2大的


反悔贪心如下
考虑对于能拿的先拿
如果发现，当前最优的放置位置
已经有了n/2个 达到饱和，那么
考虑将其放入次优的 

 
*/

#include <bits/stdc++.h>
using namespace std;


const int kMAXN=1e5+5;
int inf=1000000007;

struct node{
	int num;
	int rm;
	bool operator <(node b)const {
		return num<b.num;
	}
};
int a[kMAXN][4];
int n,t;
priority_queue<node> pq1;
priority_queue<node> pq2;
priority_queue<node> pq3;

void cl(){
	int ans=0;
	//cout<<"-------"<<endl;
	while (!pq1.empty()){
		ans+=pq1.top().rm;
		//cout<<pq1.top().rm<<endl;
		pq1.pop();
	}
	//cout<<"-------"<<endl;
	while (!pq2.empty()){
		//cout<<pq2.top().rm<<endl;
		ans+=pq2.top().rm;
		pq2.pop();
	}
	//cout<<"-------"<<endl;
	while (!pq3.empty()){
		ans+=pq3.top().rm;
		pq3.pop();
	}
	//cout<<"-------"<<endl;
	cout<<ans<<endl;
	//cout<<"-------"<<endl;
}



int gfb(int i){
	int k=max({a[i][1],a[i][2],a[i][3]});
	if (k==a[i][1]){
		return 1;
	}else if (k==a[i][2]){
		return 2;
	}else{
		return 3;
	}
}

int gsb(int i){
	int k=gfb(i);
	if (k==1){
		if (a[i][2]>=a[i][3])return 2;
		else return 3;
	}else if (k==2){
		if (a[i][1]>=a[i][3])return 1;
		else return 3;
	}else{
		if (a[i][1]>=a[i][2])return 1;
		else return 2;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		cin>>n;
		int nn=n/2;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
			for (int i=1;i<=n;i++){
				int nfb=gfb(i);
				int nsb=gsb(i);
				int nx=a[i][nfb];
				int ny=a[i][nsb];
				if (nfb==1){
					if (pq1.size()<nn)pq1.push({ny-nx,nx});
					else{
						if (ny<nx+pq1.top().num){
							//cout<<"jing"<<endl;
							if (nsb==2){
								//cout<<"jing"<<endl;
								pq2.push({inf,pq1.top().num+pq1.top().rm});
								//cout<<pq2.top().rm<<endl;
							}else{
								pq3.push({inf,pq1.top().num+pq1.top().rm});
							}
							pq1.pop();
							pq1.push({ny-nx,nx});
						}else{
							if (nsb==2){
								pq2.push({inf,ny});
							}else{
								pq3.push({inf,ny});
							}
						}
					}
				}else if (nfb==2){
					if (pq2.size()<nn)pq2.push({ny-nx,nx});
					else{
						if (ny<nx+pq2.top().num){
							
							if (nsb==1){
								pq1.push({inf,pq2.top().num+pq2.top().rm});
							}else{
								pq3.push({inf,pq2.top().num+pq2.top().rm});
							}
							pq2.pop();
							pq2.push({ny-nx,nx});
						}else{
							if (nsb==1){
								pq1.push({inf,ny});
							}else{
								pq3.push({inf,ny});
							}
						}
					}
				}else if (nfb==3){
					if (pq3.size()<nn)pq3.push({ny-nx,nx});
					else{
						if (ny<nx+pq3.top().num){
							
							if (nsb==1){
								pq1.push({inf,pq3.top().num+pq3.top().rm});
							}else{
								pq2.push({inf,pq3.top().num+pq3.top().rm});
							}
							pq3.pop();
							pq3.push({ny-nx,nx});
						}else{
							if (nsb==1){
								pq1.push({inf,ny});
							}else{
								pq2.push({inf,ny});
							}
						}
					}
				}
			}
			cl();
		
	}
	
	
	
	
	
	return 0;
}
