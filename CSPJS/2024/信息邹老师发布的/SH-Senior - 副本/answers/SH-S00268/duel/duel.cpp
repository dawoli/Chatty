#include<iostream>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[100005],b[100005]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int e=0;
	while(e==1){
		for(int i=0;i<n;i++){
			if(b[n]==1){
				e=1;
			}else{
				e=0;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
