//sticks
#include<bits/stdc++.h>
using namespace std;
int t,n,s[10]={1,5,2,2,3,2,1,4,0,1};
int num[20002]={};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		int k=(n+6)/7,r=7*k-n;
		for(int i=0;i<k;++i){
			num[i]=8;
		}
		for(int i=1;i<10;++i){
			if(r>=s[i]){
				num[0]=i;
				r-=s[i];
				break;
			}
		}
		for(int i=1;i<k;++i){
			for(int j=0;j<10;++j){
			    if(r>=s[j]){
				    num[i]=j;
				    r-=s[j];
				    break;
			    }
		    }
		}
		for(int i=0;i<k;++i){
			cout<<num[i];
		}
		cout<<endl;
	}
}
