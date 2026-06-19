#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string a[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=0;i<=52;i++){
		a[i]="EE";
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (a[i]==a[j]){
				a[i]="EE";
				break;
			}
		}
	}
	for(int i=1;i<=52;i++){
		if (a[i]=="EE"){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
