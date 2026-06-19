#include<iostream> 
#include<cstdio>
#include<vector>
using namespace std;
int n,k;
int a[500005];
int pre[500005];
int ans=0;
vector<int>vx;
vector<int>vy;
void dfs(int zx,int zy,int key,int num){
	bool flag=0;
	//cout<<zx<<" "<<zy<<" "<<num<<endl;
	for(int i=key+1;i<vx.size();i++){
		if(vx[i]>zy){
			dfs(vx[i],vy[i],i,num+1);
			flag=1;
		}
	}
	if(!flag){
		ans=max(num,ans);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			pre[i]=a[i];
		}else{
			pre[i]=pre[i-1] xor a[i];
		}
	}
	if(k<=1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}	
		}else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
	} else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((pre[j] xor pre[i-1])==k){
					vx.push_back(i);
					vy.push_back(j);
				}	
			}
		}
		for(int i=0;i<vx.size();i++){
			dfs(vx[i],vy[i],i,1);
		}
	}
	cout<<ans;
	return 0;
}
