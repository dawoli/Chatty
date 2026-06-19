#include<bits/stdc++.h>
using namespace std;
int n;
string s[105]; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	int sum=n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<i;j++){
			if(s[j]==s[i]){
				sum--;	
			}	
		}
	}
	cout<<52-sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

