#include<bits/stdc++.h>


using namespace std;
string s;
long long n;
long long cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			cnt[x]++;
			
		}
	}
	for(int j=9;j>=0;j--){
		for(int i=1;i<=cnt[j];i++){
			
			printf("%d",j);
		}
	}
	
	return 0;
}
