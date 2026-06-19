#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
int t;
int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club1.out","w",stdout);
	cin>>t;
	for(int p=0;p<t;p++){
		int n;
		cin>>n;
		vector<int>a,b,c;
		int x=0,y=0,z=0,ans=0;
		priority_queue<pair<int,int>> a1,b1,c1;
		for(int i=1;i<=n;i++){
			int q,w,e;
			cin>>q>>w>>e;
			a.push_back(q);b.push_back(w);c.push_back(e);
		}
		if(n>=1000){
			if(b[0]==0&&c[0]==0){
				sort(a.begin(),a.end());
				for(int i=n/2;i<n;i++){
					ans+=a[i];
				}
				cout<<ans<<endl;
				continue;
			}
			else{
				for(int i=0;i<n;i++){
					ans+=max({a[i],b[i],c[i]});
				}
			}
		}
		for(int i=0;i<n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				x++;
				ans+=a[i];
				if(x>(n/2)){
					int j=a1.top().second;
					if((a[i]-a[j]+max(b[j],c[j]))>(max(b[i],c[i]))){
						ans=ans+max(b[j],c[j])-a[j];
						a1.push({0-a[i],i});
						if(b[j]>c[j]){
							b1.push({0-b[i],i});
							y++;
						}
						else{
							c1.push({0-c[i],i});
							z++;
						}
						x--;
						a1.pop();
					}
					else{
						ans=ans-a[i]+max(b[i],c[i]);
						if(b[i]>=c[i]){
							b1.push({0-b[i],i});
							y++;
						}
						else{
							c1.push({0-c[i],i});
							z++;
						}
					}
				}
				else{
					a1.push({0-a[i],i});
				}
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				y++;
				ans=ans+b[i];
				cout<<b[i]<<endl;
				if(y>(n/2)){
					cout<<6;
					int j=b1.top().second;
					if((b[i]-b[j]+max(a[j],c[j]))>(max(a[i],c[i]))){
						ans=ans+max(a[j],c[j])-b[j];
						b1.push({0-b[i],i});
						if(a[j]>c[j]){
							a1.push({0-a[i],i});
							x++;
						}
						else{
							c1.push({0-c[i],i});
							z++;
						}
						y--;
						b1.pop();
					}
					else{
						ans=ans-b[i]+max(a[i],c[i]);
						if(a[i]>=c[i]){
							a1.push({0-a[i],i});
							x++;
						}
						else{
							c1.push({0-c[i],i});
							z++;
						}
					}
				}
				else{
					b1.push({0-b[i],i});
				}
			}
			else if(c[i]>=b[i]&&c[i]>=a[i]){
				z++;
				ans+=c[i];
				if(z>(n/2)){
					int j=c1.top().second;
					if((c[i]-c[j]+max(b[j],a[j]))>(max(b[i],a[i]))){
						ans=ans+max(b[j],a[j])-c[j];
						a1.push({0-c[i],i});
						if(b[j]>a[j]){
							b1.push({0-b[i],i});
							y++;
						}
						else{
							a1.push({0-a[i],i});
							x++;
						}
						z--;
						c1.pop();
					}
					else{
						ans=ans-c[i]+max(b[i],a[i]);
						if(b[i]>=a[i]){
							b1.push({0-b[i],i});
							y++;
						}
						else{
							a1.push({0-a[i],i});
							x++;
						}
					}
				}
				else{
					c1.push({0-c[i],i});
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
