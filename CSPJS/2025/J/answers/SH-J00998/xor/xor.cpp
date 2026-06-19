#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,poscnt,left;
int num[N],sum[N],pos[N];
int ans;
int dfs(int lft,int rit){
	for(int i=lft;i<=rit-1;i++){
		for(int j=lft+1;j<=rit;j++){
			int summ=num[i];
			for(int k=i+1;k<=j;k++){
				summ=summ^num[k];
			}
			//cout<<summ<<" ";
			if(summ==k)	return j;
		}
	}
	return -1;
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=1;
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(num[i]!=1)	flag=0;
	}
	if(k==0&&flag==1){
		cout<<floor(n/2);
		return 0;
	}
	if(k<=1){
		int anum=0;
		for(int i=0;i<n;i++)
			if(num[i]==k)	anum++;
		cout<<anum;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(num[i]==k)	pos[poscnt++]=i;
	}
	pos[poscnt]=n-1;
	int left=0;
	for(int i=0;i<=poscnt;i++){
		while(left<pos[i]){
			int result=dfs(left,pos[i]-1);
			if(result==-1){
				left=pos[i]+1;
				break;
			}
			else left=result,ans++;
		}
		left=pos[i]+1;cout<<pos[i]<<" "<<left;
	}
	cout<<ans+poscnt;
	return 0;
}
