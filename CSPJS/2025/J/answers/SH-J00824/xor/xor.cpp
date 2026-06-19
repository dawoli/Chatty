#include<bits/stdc++.h>
using namespace std;
int a[500000+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0,i=1;
	while(i<=n){
		int md=0,p=0;
		for(int j=i;j<=n;j++){
			md=(md^j);
				
			if(md==k){
				cnt++;
				p=j;
				break;
			}
		}
		if(k==md&&(md!=0||i!=1)){
			i+=p;
		}else{
			i++;
		}
	}
	
	if(k==0){
		cout<<cnt;
	}else{
		cout<<cnt+1;
	}
		
	fclose(stdin);
	fclose(stdout);
    
     
	return 0;
}
