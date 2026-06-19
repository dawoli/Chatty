#include<bits/stdc++.h>
using namespace std;
int answer[25]{0,
	-1,1,7,4,2,6,8,10,18,22,
	20,28,80,88,108,188,200,208,288,688
};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int t,n;
	cin>>t;
	for(int t2=1;t2<=t;t2++){
		cin>>n;
		if(n==1) cout<<-1<<endl;
		else if(n%7==0){
			for(int i=n/7;i>=1;i--){
				printf("%d",8);
			}
			cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=n/7;i>1;i--) printf("%d",8);
			cout<<endl;
		}
		else if(n<=20) cout<<answer[n]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
