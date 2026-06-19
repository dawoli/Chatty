#include<bits/stdc++.h>
using namespace std;
const int N=1000006;
string s,num="0123456789";
int shu[N],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int n=s.length();
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++){
			if(s[i]==num[j]){
				shu[k++]=s[i]-'0';
				break;
			}
		}
		
	}
	sort(shu,shu+k);
	for(int i=k-1;i>=0;i--)
		cout<<shu[i];
	return 0;
} 
