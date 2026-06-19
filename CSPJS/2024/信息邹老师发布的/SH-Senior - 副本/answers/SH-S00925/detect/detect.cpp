#include<bits/stdc++.h>
using namespace std;

int t,n,m,L,V,d[100010],v[100010],a[100010],p[100010],cnt,cur,ans;
double maxl[100010]; 
bool vis2[100010],vis3[100010];
bool visa=true,visb=true,visc=true;
bool del[100010],flag=true;
vector<int> vis[100010];
//d[i]初始位置 v[i]初始速度 a[i]加速度 

double cala(int x){
	if(v[x]>V&&a[x]>=0)return 0;
	if(v[x]<=V&&a[x]<=0)return -1;
	if(a[x]==0)return -1; 
	double g=V*V-v[x]*v[x];
	double h=2*a[x];
	return g/h;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis2,false,sizeof(vis2));
		memset(vis3,false,sizeof(vis3));
		cnt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			maxl[i]=cala(i);
			if(a[i]!=0)visa=false;
			if(a[i]<0)visb=false;
			if(a[i]>0)visc=false;
			//cout<<maxl[i]<<endl;
		}
		for(int i=1;i<=m;i++){
			vis[i].clear();
			cin>>p[i];
			for(int j=1;j<=n;j++){
				
				if((a[j]>0&&p[i]>maxl[j]+d[j]) || (a[j]<0&&p[i]<=maxl[j]+d[j]&&p[i]>d[j]) || (a[j]==0&&p[i]>=d[j]&&v[j]>V))
				{
					vis[i].push_back(j);
					vis3[i]=true;
				    if(vis2[j]==false){
				     	vis2[j]=true;
				    	cnt++;
				    }
				}
			}
		}
		cout<<cnt<<" ";
		if(visa==true||visb==true){
			cout<<m-1<<endl;
			continue;
		}
		ans=1e9;
        for(int s=0;s<(1<<m);s++){
        	cur=0;
        	memset(del,false,sizeof(del));
        	for(int i=1;i<=m;i++){
        		if((s>>i-1)&1){
        		//	cout<<1;
        			if(vis3[i]==false)break;
        			cur++; 
        			for(int j=0;j<vis[i].size();j++){
        				del[vis[i][j]]=true;
        			//	cout<<vis[i][j]<<" ";
					}
					
					
				}
				//cout<<0;
			}
			//cout<<endl;
			//cout<<" "<<cur<<endl;
			for(int i=1;i<=n;i++){
				//cout<<del[i]<<vis2[i]<<endl;
				if(del[i]==false&&vis2[i]==true){
					flag=false;
					break;
				}
			}
			//cout<<1414124<<endl;
			if(flag){
				ans=min(ans,cur);
			//	cout<<14312421<<endl;
			}
			flag=true;
			//cout<<endl;
		} 
		cout<<m-ans<<endl;
			
	}
	return 0;
}
