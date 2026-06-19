#include<bits/stdc++.h>
using namespace std;

int n=0;
int moster[100005];
int killed[100005];
int time1,time2=0;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>moster[i];
		if (moster[i]==1){
			time1=time1+1 ;
		}
		if (moster[i]==2){
			time2=time2+1;
		}
		if (n<=30&&((time1+time2)!=i)){
		
		if (moster[i]<moster[i-1])
		{ 
			int a=i;	
			while(moster[a]<moster[a-1])
			{
			int c=moster[a-1];
			moster[a-1]=moster[a];
			moster[a]= c ;
			a=a-1;
			}
		}}
	}
	if (n<=30&&((time1+time2)!=n)){int num=n;
	for(int i=1;i<=n;i++){
			for(int k=1;k<i;k++){
				if (moster[i]>moster[k]&&killed[k]==0){
					num=num-1;
					killed[k]=1;
					break;
				}
			}
	}
	cout<<num;}
	else {	if(time1>time2)cout<<n-time2;
	else if (time1<time2)cout<<time2;
	}
	return 0;
}
