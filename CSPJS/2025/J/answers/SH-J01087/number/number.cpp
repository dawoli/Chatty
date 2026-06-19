#include<bits/stdc++.h>
using namespace std;
char s[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100010];
	cin>>s;
	int l=strlen(s);
	int j=0;
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
//	sort(a,a+j-1);
//	for(int i=0;i<j;i++){
//			cout<<a[i]<<" ";
//		}
	for(int i=1;i<j;i++){
		for(int x=1;x<j;x++){
			if(a[x]>a[x-1])
			swap(a[x],a[x-1]);
		}
	}
	
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0; 
}

