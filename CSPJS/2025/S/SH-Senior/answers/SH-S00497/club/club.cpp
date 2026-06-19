#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int a1[N],a2[N],a3[N];
int n,limit;
int bottle1[N],bottle2[N],bottle3[N];
int k1=1,k2=1,k3=1;
int s[19],anss=-1e9,as=0;
int co(int a){
	int num=0;
	if(a==1){
	for(int i=1;i<=n;i++){
		if(bottle1[i]!=0){
		num++;
	    }
	    }
	}
	if(a==2){
	for(int i=1;i<=n;i++){
		if(bottle2[i]!=0){
		    num++;
		    }
	    }
	}
	
	if(a==3){
	for(int i=1;i<=n;i++){
		if(bottle3[i]!=0){
		    num++;
		 }
	    }
	}
	return num;
}
void solve2(){
	s[1]=a1[1]+a2[2];
	s[2]=a1[1]+a2[3];
	s[3]=a1[2]+a2[1];
	s[4]=a1[2]+a2[3];
	s[5]=a1[3]+a2[1];
	s[6]=a1[3]+a2[2];
	for(int i=1;i<=6;i++){
		anss=max(s[i],anss);
	}
	cout<<anss;
}
void solve3(){
	
	for(int i=1;i<=n;i++){
		int amax=max(max(a1[i],a2[i]),a3[i]);
		if(amax==a1[i]&&co(1)<limit){
			bottle1[k1]=amax;
			amax=0;
			k1++;
			continue;
		}
		else if(amax==a2[i]&&co(2)<limit){
			bottle2[k2]=amax;
			
			amax=0;
			k2++;
			continue;
		}
		else if(amax==a3[i]&&co(3)<limit){
			bottle3[k3]=amax;
			amax=0;
			k3++;
			continue;
		}//>n/2
	} 
	int ans=0;
	
	
	for(int i=1;i<=n;i++){
		ans+=bottle1[i]+bottle2[i]+bottle3[i];
	}
	cout<<ans<<endl;
}

bool cmp(int a,int b){
	return a>b;
}
void solve4(){
	sort(a1+1,a1+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i<limit){
			as+=a1[i];
		}
	}
	cout<<as<<endl;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	limit=n/2+1;
	for(int i=1;i<=n;i++){
		bottle1[i]=bottle2[i]=bottle3[i]=0;
		cin>>a1[i]>>a2[i]>>a3[i];
	}
	if(n==1){
		cout<<max(max(a1[1],a2[1]),a3[1])<<endl;
	}
	else if(n==2){
		solve2();
	}
	else if(n>2&&n<=200){
		solve3();
	}
	else {
		solve4();
	}
	
	
	return 0;
}
