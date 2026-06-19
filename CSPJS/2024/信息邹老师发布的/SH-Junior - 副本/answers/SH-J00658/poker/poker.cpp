#include<iostream>
using namespace std;
int n,ans=52;
string a[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int f=1;
		for(int j=0;j<i;j++){
			if(a[i]==a[j]){
				f=0;
				break;
			}
		}
		ans-=f;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
