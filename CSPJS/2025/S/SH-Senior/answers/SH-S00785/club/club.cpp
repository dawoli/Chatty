#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >p1,p2,p3;
int n,na,nb,nc,a,b,c,mx,mn,md; 
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		sum=0;
		na=0,nb=0,nc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			mx=max(a,max(b,c));
			mn=min(a,min(b,c));
			md=a+b+c-mx-mn;
			//cout<<"TEST1 "<<a<<" "<<b<<" "<<c<<" "<<mx<<" "<<md<<" "<<mn<<" "<<endl;
			sum+=mx;
			if(mx==a){
				p1.push(mx-md);
				na++;
				if(na>n/2){
					sum-=p1.top();
					p1.pop();
					na--;
				}
			}else if(mx==b){
				p2.push(mx-md);
				nb++;
				if(nb>n/2){
					sum-=p2.top();
					p2.pop();
					nb--;
				}
			}else{
				p3.push(mx-md);
				nc++;
				if(nc>n/2){
					sum-=p3.top();
					p3.pop();
					nc--;
				}
			}
			//cout<<"TEST2 "<<sum<<" "<<na<<" "<<nb<<" "<<nc<<endl;
		}
		cout<<sum<<'\n';
		while(!p1.empty())p1.pop();
		while(!p2.empty())p2.pop();
		while(!p3.empty())p3.pop();
	}
	return 0;
}

