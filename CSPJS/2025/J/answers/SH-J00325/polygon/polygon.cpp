#include <bits/stdc++.h>
using namespace std;
int n;
int a[5050];
int maxn;
const int MOD=998224353;
int main( ){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],maxn=max(maxn,a[i]);
	if(maxn*n*n*maxn>1000000){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(a[0]+a[1]+a[2]>(2*(max(a[0],max(a[1],a[2])))))
			cout<<"1";
		else
			cout<<"0";
		return 0;
	}
	else if(maxn!=1){
		int num[n+5][maxn+5][n*maxn+5]={ };
		for(int i=0;i<n-2;i++)
			for(int j=i+1;j<n-1;j++)
				for(int k=j+1;k<n;k++)
					if((a[i]+a[j]+a[k])>(2*(max(a[i],max(a[j],a[k])))))
						num[k][max(max(a[i],a[j]),a[k])][a[i]+a[j]+a[k]]++,num[k][max(max(a[i],a[j]),a[k])][a[i]+a[j]+a[k]]%=MOD;
			//		else
			//			cout<<a[i]+a[j]+a[k]<<" "<<2*(max(a[i],max(a[j],a[k])))<<endl;
		for(int i=0;i<n;i++){
			cout<<i<<":"<<endl;
			for(int j=0;j<=maxn;j++){
				for(int k=0;k<=n*maxn;k++)
					cout<<num[i][j][k]<<" ";
				cout<<endl;
			}
		}
		for(int l=0;l<n;l++)
			for(int i=0;i<l;i++)
				for(int j=1;j<=maxn;j++)
					for(int k=3;k<=maxn*(l+1);k++)
						if((k+a[l])>(max(j,a[l])*2))
							if(num[l][j][k+a[l]]==0)
								num[l][j][k+a[l]]=1,num[l][j][k+a[l]]%=MOD;
		long long ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<=maxn;j++)
				for(int k=0;k<=n*maxn;k++)
					ans+=num[i][j][k],ans%=MOD;
		cout<<endl<<ans;
	}
	else{
		long long ans=0;
		for(int i=3;i<=n;i++){
			for(int j=1;j<=(n-i+1);j++)
				ans+=(1+j-(j-1))*j/2+(j-1),ans%=MOD;
		}
		cout<<ans;
	}
	return 0;
}
