#include<bits/stdc++.h>
using namespace std;
int m;
string s[55];
int main(){
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>s[i];
	}
	
	int sum=0;
	
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(s[i]==s[j]) s[i]="0",sum++;
		}
	}
	
	cout<<52-m+sum<<endl;
	
	return 0;
}
