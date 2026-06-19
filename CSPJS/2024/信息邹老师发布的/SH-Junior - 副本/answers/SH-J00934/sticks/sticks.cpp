#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int n,ch[(int)1e5/2+2],flag=0,cnt,ans[(int)1e5/2+2],len=INT_MAX;
bool compare(int cnt,int len){
	if(len>cnt)	return 1;
	else if(len<cnt)	return 0;
	else{
		for(int i=len;i>=0;i++){
			if(ch[i]>ans[i])	return 0;
			else if(ch[i]<ans[i])	return 1;
		}
	}
}
void dfs(int d,int cnt){
	if(cnt>len)	return;
	if(d==n){
		if(ch[0]!=0){
			if(compare(cnt,len)){
				len=cnt;
				memset(ans,0,sizeof(ans));
				for(int i=0;i<cnt;i++){
					ans[i]=ch[i];
				}
			}
			flag=1;
			return;
		}
	}
	for(int i=0;i<10;i++){
		if(d+num[i]<=n){
			ch[cnt++]=i;
			dfs(d+num[i],cnt);
			cnt--;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=0;i<(int)n/7;i++)	cout<<8;
			cout<<endl;
			continue;
		}
		else if(n%7==1){
			cout<<1<<0;
			for(int i=0;i<(int)(n-8)/7;i++)	cout<<8;
			cout<<endl;
			continue;
		}
		memset(ch,0,sizeof(ch));
		memset(ans,0x3f,sizeof(ans));
		len=INT_MAX;
		cnt=0; 
		if(n<=30){
			dfs(0,0);
			if(flag==0)	cout<<-1;
			else{
				for(int i=0;i<len;i++){
					cout<<ans[i];
				}
				cout<<endl;
			}
			continue;
		}
		else if(n>30){
			int t=n;
			int ti=t/7;
			n%=7;
			if(n==2){
				cout<<1;
			}
			else if(n==3){
				cout<<7;
			}
			else if(n==4){
				cout<<4;
			}
			else if(n==5){
				cout<<2;
			}
			else if(n==6){
				cout<<6;
			}
			for(int i=0;i<ti;i++)	cout<<8;
			cout<<endl;
		}
	}
	return 0;
}
