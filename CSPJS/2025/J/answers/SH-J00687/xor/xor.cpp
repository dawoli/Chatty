#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct Node{
	string two;
}num[500005];
int dp[500005];
int ifcalc[22];
int a[500005];
int calc[22];
int cmp[22];
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool A=true;
	bool B=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			A=false;
			B=false;
		}
		else if(a[i]==0)A=false;
	}
	//A
	if(A){
		cout<<n/2;
		return 0;
	}
	//B
	if(B){
		if(k==1){
			int cnt1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt1++;
			}
			cout<<cnt1;
			return 0;
		}
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				int cnt=0;
				while(a[i]==1){
					i++;
					cnt++;
				}
				ans+=cnt/2;
				if(a[i]==0)ans++;
			}
			cout<<ans;
			return 0;
		}
	}
	//
	int pos=0;
	while(k){
		cmp[pos]=k%2;
		k/=2;
		pos++;
	}
	int left=1;
	for(int i=1;i<=n;i++){
		int f=a[i];
		while(f){
			num[i].two+=(char)f%2+'0';
			f/=2;
		}
		for(int p=0;p<num[i].two.size();p++){
			calc[p]+=num[i].two[p]-'0';
		}
		bool flag=true; 
		for(int p=0;p<pos;p++){
			if(calc[p]%2!=cmp[p]){
				flag=false;
				break;
			}
		}
		if(flag)dp[i]=dp[left-1]+1;
		for(int c=0;c<22;c++)ifcalc[c]=calc[c];
		for(int p=left;p<i;p++){
			for(int j=0;j<num[p].two.size();j++){
				ifcalc[j]-=num[p].two[j]-'0';
			}
			bool judge=true;
			for(int c=0;c<22;c++){
				if(ifcalc[c]%2!=cmp[c]){
					judge=false;
					break;
				}
			}
			if(judge){
//				if(dp[i]<dp[p]+1){
					dp[i]=dp[p]+1;
					left=p+1;
					for(int c=0;c<22;c++){
						calc[c]=ifcalc[c];
					}
//				}
			}
		}
	}
	cout<<dp[n];
	return 0; 
}
