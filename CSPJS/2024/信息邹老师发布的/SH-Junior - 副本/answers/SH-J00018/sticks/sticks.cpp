#include<bits/stdc++.h>
using namespace std;
int s[100009];
int t[10];
int ans[59];
int n,a;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	t[0]=6,t[1]=2,t[2]=5,t[3]=5,t[4]=4,t[5]=5,t[6]=6,t[7]=3,t[8]=7,t[9]=6;
	for(int i=1;i<=100009;i++){
		int x=i;
		while(x>0){
			s[i]+=t[x%10];
			x/=10;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==1){
			ans[i]=-1;
			continue;
		}
		for(int j=1;j<=100009;j++)
		    if(s[j]==a){
		        ans[i]=j;
		        break;
		    }
	}
	for(int i=1;i<=n;i++)
	    cout<<ans[i]<<endl;
	return 0;
}
