#include<bits/stdc++.h>
using namespace std;
int n,t,a[500],b[500],ans;
char s[5];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1)cout<<-1<<endl;
		else{
			int m=(n+6)/7,k=n%7;
			if(n<7){
			    if(n==2)ans=1;
			    if(n==3)ans=7;
			    if(n==4)ans=4;
    			if(n==5)ans=2;
	    		if(n==6)ans=6;
			}else{
			if(k==1)ans=10;
			if(k==2)ans=18;
			if(k==3)ans=22;
			if(k==4)ans=20;
			if(k==5)ans=28;
			if(k==6)ans=68;
			if(k==0)ans=8;
			}
			for(int i=2;i<m;i++)ans=ans*10+8;
			printf("%d\n",ans);
		}
	}
	return 0;
}
