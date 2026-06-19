#include<bits/stdc++.h>
using namespace std;
int f[100005],num[100005],n;
void js(){
	sort(f+1,f+n+1);
	int id=1,cnt=0,temp=f[1];
	for(int i=1;i<=n;i++){
		if(f[i]!=temp||f[i+1]==0){
			if(f[i+1]==0&&f[i]==temp){
				num[id]=++cnt;
				break;
			}
			num[id]=cnt;
			num[++id]=1;
			cnt=1;
			temp=f[i];
		}
		else cnt++;
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>f[i];
	js();
	int kill=0;
	for(int i=2;num[i]!=0;i++){
		if(num[i-1]>=num[i]){
			num[i-1]-=num[i];
			kill+=num[i];
		}
		else{
			num[i-1]=0;
			kill+=num[i];
		}
	}
	cout<<n-kill;
	return 0;
}
