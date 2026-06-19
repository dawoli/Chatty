#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
char b[N];
bool cmp(char a,char b){
	return a>b; 
}
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	for(int i=0;i<N;i++)	b[i]=-1;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			b[i]=s[i];
		}
	}
	sort(b,b+s.size(),cmp);
	int k=0;
	while(b[k]>=0){
		cout << b[k];
		k++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
