#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int num1[10]={8,0,6,9,2,3,5,4,7,1};
int num2[10]={7,6,6,6,5,5,5,4,3,2};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		if(n<2)ans=-1;
		if(n==2)ans=1;
		if(n>2){
			while(n){
				
				for(int i=1;i<=9;i++){
				    if(n>=num2[i]){
					    n-=num2[i];
					    if(n==1){
					    	continue;
						}
					    ans+=ans*10+num1[i];
				    }
			    }
			}
		}
		if(ans==0)ans=6;
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
