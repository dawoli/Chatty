#include<bits/stdc++.h>
using namespace std;
char rec[1000009];
int len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	while(cin>>s){
		if(s>='0'&&s<='9')
			rec[++len]=s;
	}
	sort(rec+1,rec+len+1);
	for(int i=len;i>0;i--)
		cout<<rec[i];
	return 0;
}
//rp++
