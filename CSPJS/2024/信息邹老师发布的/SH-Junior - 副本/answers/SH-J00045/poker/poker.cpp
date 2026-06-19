#include<bits/stdc++.h>
using namespace std;
string a[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,c=52;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int d=0;
		for(int j=1;j<i;j++){
			string b=a[i];
			if(b==a[j]){
				a[i]=i;
				a[j]=i;
				d++;
			}
		}
		if(d==0) c--;
	}
	cout<<c;
	return 0;
}
