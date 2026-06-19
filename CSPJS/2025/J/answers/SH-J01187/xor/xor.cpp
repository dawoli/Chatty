#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int l[n];
	int flag=0;
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(l[i]==0 && flag!=2){
			flag=1;
		}
		if(l[i]>1){
			flag=2;
		}
	}
	if(flag==0){
		cout<<n/2;
		return 0;
	}
	else if(flag==1){
		int ans=0;
		if(k==0){
			for(int i=1;i<n;i++){
				if(l[i-1]==l[i] && l[i-1]==1){
					ans++;
					i++;
				}
				if(l[i]==0){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
		else if(k==1){
			for(int i=1;i<n;i++){
				if(l[i-1]!=l[i]){
					ans++;
					i++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	else{
		int ans=0,flag2=1;
		int f[n][n]={},vis[n][n]={};
		for(int i=0;i<n;i++){
			f[0][i]=l[i];
		}
		for(int i=1;i<n;i++){
			f[1][i]=l[i-1]^l[i];
		}
		for(int i=2;i<n;i++){
			for(int j=i;j<n;j++){
				f[i][j]=f[i-1][j-1]^f[i-2][j];
			}
		}
		
		/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<"("<<f[i][j]<<",";
				if(i>j){
					vis[i][j]=1;
				}
				cout<<vis[i][j]<<") ";
			}
			cout<<"\n";
		}
		*/
		
		for(int i=n;i>=0;i--){
			for(int j=n;j>=i;j--){
				//选择当前区间并修改访问记录 
				if(f[i][j]==k && vis[i][j]==0){
					ans++;
					for(int x=i;x>=0;x--){
						for(int y=j;y>=0;y--){
							vis[x][y]=1;
						}
					}
				}
				
				/*
				for(int x=0;x<n;x++){
					for(int y=0;y<n;y++){
						cout<<"("<<f[x][y]<<",";
						cout<<vis[x][y]<<") ";
					}
					cout<<"\n";
				}
				*/
				
			}
		}
		cout<<ans;
	}
	return 0;
}
