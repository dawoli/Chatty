#include <bits/stdc++.h>
using namespace std;
char s[1000001];
char a[10000];
int main(){
	int num=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<1000001;i++){
		cin>>s[i];
		if(s[i]>='0' and s[i]<='9'){
			a[num]=s[i];
			num++;
		}
	}
//	for(int i=0;i<1000;i++){
//		cout<<a[i];
//	}
	for(int i=0;i<10000;i++){
		for(int j=0;j<10000;j++){
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}
	}
	for(int i=0;i<10000;i++){
		if(a[i]<'0')
			continue;
		cout<<a[i];
	}
//	cout<<a[0];
	return 0;
} 

