#include<iostream>
#include<algorithm>
#include<cstdio>
int r[100010];
bool at[100010]={false};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	std::cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)std::cin>>r[i];
	std::sort(r+1,r+n+1);
	int j=2;
	for(int i=1;i<n;i++){
		bool flag=true;
		while(flag==true and j<=n){
			if(r[i]<r[j] and !at[j]){
				ans--;
				at[j]=true;
				flag=false; 
			}
			j++;
		}
	}
	std::cout<<ans; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
