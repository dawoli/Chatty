#include<bits/stdc++.h>
using namespace std;
string a[10009];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				cnt+=0;
				i++;
			}
		}
		cnt++;
	}
	cout<<52-cnt;
	return 0;
} 
