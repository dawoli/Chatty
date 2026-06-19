#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int swap;
	int a[1000000];
	long long int n=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-48;
			n++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<=a[j]){
				swap=a[i];
				a[i]=a[j];
				a[j]=swap;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	return 0;
}
