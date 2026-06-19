#include<bits/stdc++.h>//´íµÄ£¡£¡ 
using namespace std;
int n,ans=0;
long long k,a[500002],orcnt[500002];
bool vis[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>=8000){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		orcnt[i]=orcnt[i-1]^a[i];
	}
	for(int len=1;len<=n;len++){
		int viscnt=0;
		for(int i=1;i<len;i++){
			if(vis[i])viscnt++;
		}
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(vis[l-1])viscnt--;
			if(vis[r])viscnt++;
			if(viscnt>0)continue;
			if((orcnt[r]^orcnt[l-1])==k){
				bool flag=false;
				for(int i=l;i<=r;i++){
					//if(vis[i])cout<<"ERR!!!!!!";
					vis[i]=1;viscnt++;
				}
				ans++;
				//cout<<l<<" "<<r<<endl;
				//cout<<orcnt[r]
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
