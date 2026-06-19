#include<bits/stdc++.h>
using namespace std;
int ans,n,r[100005],f[100005];
int m[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>r[i];
	sort(r,r+n);
	for(int i=0;i<n;i++) m[r[i]]=i;
	ans=n;
	for(int i=0;i<n;i++)
	    for(int j=m[r[i]]+1;j<n;j++)
	    	if(f[j]==0){
				//cout<<r[j]<<"->"<<r[i]<<endl;
				f[j]=1;
				ans--;
				break;
			}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;  
}
