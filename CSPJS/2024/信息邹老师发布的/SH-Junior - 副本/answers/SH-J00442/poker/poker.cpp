#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	int n,sum=1,x;
	cin>>n;
	string a[n+1],b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]="0";
	}
	b[1]=a[1];
	for(int j=1;j<=n;j++){
		
		for(int i=1;i<=j;i++){
			if(a[j]==b[i]){
				break;
			}
			if(i==j){
				b[sum]=a[j];
				sum+=1;
				
			}
        } 
        
    }
    
	cout<<52-sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
