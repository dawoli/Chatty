#include<bits/stdc++.h>
using namespace std;
int p[14][5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string a[60];
	int ans=52,cnt=1;
	int n;
	cin>>n;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		int f=1;
		for(int j=0;j<i;j++){
			if(a[i]==a[j]){
				f--;
				
				break;
			}
			
		}if(f==1){
				cnt++;
			}
		
}
	cout<<ans-cnt;
	return 0;
}
