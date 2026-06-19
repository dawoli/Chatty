#include<bits/stdc++.h>
using namespace std;
string a[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i-1;j++){
			if(a[i]==a[j]){
				cnt--;
				break;
			}
		} 
		cnt++;
	}
	cout<<52-cnt;
	return 0;
}
