#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in",r,stdin);
	freopen("poker.ans",w,stdout);
    int n,sum=52;
    string s[55];
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>s[i];
	}
	sum-=n;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s[i]==s[j]) sum++;
		}
	}
	cout<<sum;
	return 0;
}

