#include<bits/stdc++.h>
using namespace std;
int T,n,f[10],ret[10],minn=100005;
int a[10]={6,2,5,4,3,7};
int add(int pos,int ans){
	int ret2=0,ret3=10;
	for(int i=0;i<=10;i++) f[i]=0,ret[i]=0;
	for(int i=1;i<=pos;i++){
		f[ans%10]++;
		ans/=10;
	}
	for(int i=1;i<=10;i++){
		if(f[i]){
			if(i==6) ret[0]=f[i];
			else if(i==2) ret[1]=f[i],ret3=min(ret3,1);
			else if(i==5) ret[2]=f[i],ret3=min(ret3,2);
			else if(i==4) ret[4]=f[i],ret3=min(ret3,4);
			else if(i==3) ret[7]=f[i],ret3=min(ret3,7);
			else if(i==7) ret[8]=f[i],ret3=min(ret3,8);
		} 
	}
	if(ret3==10){
		ret2=6;
		ret[0]--;
		for(int i=1;i<=ret[0];i++){
			ret2=ret2*10+0;
		}
	}
	else for(int i=0;i<=8;i++){
		for(int j=1;j<=ret[i];j++){
			if(i==0 and j==1) ret2=ret3,ret[ret3]--;
			ret2=ret2*10+i;
		}
	} 
	return ret2;
}
void dfs(int pos,int num,int ans){
	if(num<=0){
		if(num==0){
			int h=add(pos,ans);
			minn=min(minn,h);
		}
		return;
	}
	for(int i=0;i<=5;i++){
		dfs(pos+1,num-a[i],ans*10+a[i]);
	}
} 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		minn=100005;
		dfs(0,n,0);
		if(minn!=100005) cout<<minn<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
