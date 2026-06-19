#include<bits/stdc++.h>
using namespace std;
int T[1000010],s,i=0,j=0;
int compare(int a,int b){
	return a>b;
}
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(('a'<=a[i]&&a[i]<='z')||('0'<=a[i]&&a[i]<='9')){
		if('0'<=a[i]&&a[i]<='9'){
			T[j]=a[i]-'0';
			j++;
		}
		i++;
	}
	sort(T,T+j,compare);
	for(int k=0;k<j;k++){
		cout<<T[k];
	}
	return 0;
}
