#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,k=0;
	cin >> s;
	if(s<=10){
		cout << s;
		return 0;
	}
	while(s>=10){
		s/=10;
		k++;
	}
	int a[k+1],i=0;
	while(s>=10){
		a[i]=s%10;
		s-=a[i];
		s/=10;
		i++;
	}
	sort(a,a+k+1);
	for(int i = 0;i<k+1;i++){
		cout<< a[i];
	}
	return 0;
}
