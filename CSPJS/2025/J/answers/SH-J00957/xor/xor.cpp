#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	int answer=0;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]==k){
			answer++;
		}
	}
	int sum;
	for(int i=0;i<n;i++){
		sum=0;
		if(a[i]==k){
			continue;
		} 
		for(int j=i;a[j]!=k;j++){
			sum^=a[j];
			if(sum==k){
				answer++;
				sum=0;
			}
		} 
	}
	cout<<answer;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
