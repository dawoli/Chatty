#include<bits/stdc++.h>
using namespace std;
int t,n; 
long long ans=INT_MAX;
int w11[10]={0,1,2,2,4,2,0,7,8,0};
int w22[10]={0,1,2,2,4,2,6,7,8,6};
int a[10]={6,2,5,5,4,5,6,3,7};
void search(int s,bool x,long long dans){	
	if(s==0){
		ans=min(ans,dans);
		return ;
	}
	if(s<2){
		return ;
	}
	if(x){
		for(int i=8;i>0;i--){
			if(i!=5 && i!=3 && s>=a[i]){
				search(s-a[i],0,dans*10+i);
			}
			
		}
	}
	else{
		for(int i=8;i>=0;i--){
			if(i!=5 && i!=3 && i!=6 && s>=a[i]){
				search(s-a[i],0,dans*10+i);
			}
			
		}
	}
	
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		ans=INT_MAX;
		cin>>n;
		search(n,1,0);
		if(ans==INT_MAX){
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;	
		}
	
	}
	return 0;
}

