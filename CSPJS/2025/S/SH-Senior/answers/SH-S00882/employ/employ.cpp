#include<bits/stdc++.h>
using namespace std;
int n,m,c[105],vis[105],ans=0;
string s; 
void check(int depth,int fff,int km){
	
	if(n-km<m)return ;
	if(depth==n+1){
		ans++;
		return ;
	}
	
		
				
	int failn=fff;
	
	
	if(s[depth-1]=='0'){
		failn++;
		
		
	}
	
	
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			
			if(failn>=c[i]||s[depth-1]=='0'){
				
				vis[i]=1;
				check(depth+1,failn,km+1);
				vis[i]=0;
			}
			else{
				vis[i]=1;
				check(depth+1,failn,km);
				vis[i]=0;
			}
			
		}
		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	check(1,0,0);
	cout<<ans; 
	return 0;
} 
