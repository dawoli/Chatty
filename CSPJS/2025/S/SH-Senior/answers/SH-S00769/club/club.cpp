#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		multiset<int> a,b,c;
		multiset<int>::iterator it;
		bool flag=0;
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				a.insert(min(x-y,x-z));
				ans+=x;
				if(a.size()>n/2){
					it=a.begin();
					ans-=*it;
					a.erase(it);
				}
			}
			else if(y>=x&&y>=z){
				b.insert(min(y-x,y-z));
				ans+=y;
				if(b.size()>n/2){
					it=b.begin();
					ans-=*it;
					b.erase(it);
				}
				
			}
			else if(z>=y&&z>=x){
				c.insert(min(z-y,z-x));
				ans+=z;
				if(c.size()>n/2){
					it=c.begin();
					ans-=*it;
					c.erase(it);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//忘记小根堆怎么写，差点爆炸
//rp++ 
