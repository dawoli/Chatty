#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct peo{
	int l,id;
};
int t,n;
peo a[100010][5];
vector<int> d[5];
bool cmp(peo x,peo y){
	return x.l>y.l;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].l;
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
			
			if(d[a[i][1].id].size()<(n/2)){
				d[a[i][1].id].push_back(i);
				ans+=a[i][1].l;
				
			}
			else{
				peo minn={1e9,1};
				for(int j=1;j<=d[a[i][1].id].size();j++){
					
					if(a[j][1].l-a[j][2].l<=minn.l && a[j][1].id==a[i][1].id){
						minn.l=a[j][1].l-a[j][2].l;
						
						minn.id=j;
					}
				}
				
				if(minn.l<a[i][1].l-a[i][2].l){
					ans-=minn.l;
					
					ans+=a[i][1].l;
					d[a[minn.id][2].id].push_back(minn.id); 
					
					d[a[i][1].id][minn.id-1]=i;
					
					
				}
				else{
					d[a[i][2].id].push_back(i);
					ans+=a[i][2].l;
				}
			
			
			}
			
		}
		
		cout<<ans<<endl;
	}
}
