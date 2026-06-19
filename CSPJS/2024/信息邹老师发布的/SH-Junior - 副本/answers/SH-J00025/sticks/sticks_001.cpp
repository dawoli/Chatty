#include<bits/stdc++.h>
using namespace std;
int H[10]={-1,-1,1,7,4,2,0,8};
int H1[10]={6,2,5,5,4,5,6,3,7,6};
int s[10009];
long long k;
bool dfs(long long n,long long cnt){
	if(cnt==k-1){
		if(n>7||n==1||n==0)return 0;
		s[cnt]=H[n];
		return 1;
	}
	for(int i=0;i<=9;i++)
		if(dfs(n-H1[i],cnt+1)){
			s[cnt]=i;
			return 1;
		}
	return 0;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long n;
		cin>>n;
		k=n/7;
		//cout<<k<<endl;
		if(k*7==n){
			for(int i=1;i<=k;i++)cout<<"8";
			cout<<endl;
			continue;
		}
		if(k==0){
			if(n==6)cout<<"6"<<endl;
			else cout<<H[n]<<endl;
			continue;
		}
		if(n-k*7==1){
			cout<<"10";
			for(int i=1;i<=k-1;i++)cout<<"8";
			cout<<endl;
			continue;
		}
		k++;
		if(k==2){
			for(int i=1;i<=9;i++)
				if(H[n-H1[i]]!=-1){
					cout<<i<<H[n-H1[i]]<<endl;
					break;
				}
			continue;
		}
		for(int i=1;i<=n;i++){
			if(dfs(n-H1[i],1)){
				s[0]=i;
				break;
			}
		}
		for(int i=0;i<k;i++)cout<<s[i];
		cout<<endl;
	}
	return 0;
}
