#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,flag,f,cnt,r[100005],v[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>r[i],flag=(r[i]>2);
        if(r[i]==1)
        cnt++;
	}
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++)
        if(r[i]==r[i+1])
            f=1;
    if(!flag)
        cout<<max(cnt,n-cnt);
    else if(!f)
        cout<<n/2;
    else{
    	int ans=n;
    	for(int i=1;i<=n;i++)
    		for(int j=i+1;j<=n;j++)
    			if(r[i]<r[j]&&v[j]==0){
    				ans--;
    				v[j]=1;
    				break;
				}
		cout<<ans;
	}
	return 0; 
} 
