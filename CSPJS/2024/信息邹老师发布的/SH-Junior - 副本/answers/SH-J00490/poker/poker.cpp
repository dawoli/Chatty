#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int sum=52-n;
	string a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		if (a[i]!="00"){
			for (int j=i+1;j<n;j++){
			    if (a[i]==a[j]){
				    sum++;
				    a[j]="00";
			    }
		    }
		}
	}
	cout<<sum;
	return 0;
}
