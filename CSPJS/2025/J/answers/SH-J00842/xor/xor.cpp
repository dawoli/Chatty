#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005]={};
int s[1005][1005]={};
int num=1,ans=0,ansm=0;
/*int dfs(int dep){
	for(int i=dep;i<=n;i++){
		if(s[dep][i]==k){
			ans++;
			ansm=max(ansm,ans);
			dfs(i+1);
			ans--;
		}
	}
	return 0;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			s[i][j]=s[i][j-1]^a[j];
			//cout<<s[i][j]<<" ";
		}
		//cout<<endl;
	}
	/*for(int i=1;i<=n;i++){
		dfs(i);
	}*/
	for(int i=1;i<=n;i++){
		num=i;
		ans=0;
		while(1){
			bool f=false;
			for(int j=num;j<=n;j++){
				if(s[num][j]==k){
					num=j+1;
					ans++;
					f=true;
					break;
				}
			}
			if(f==false){
				break;
			}
		}
		ansm=max(ansm,ans);
	}
	cout<<ansm;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
