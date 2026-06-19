#include<bits/stdc++.h>
using namespace std;
int ch(char a){
	if('2'<=a&&a<='9')return int(a-'0');
	if(a=='A')return 1;
	if(a=='T')return 10;
	if(a=='J')return 11;
	if(a=='Q')return 12;
	if(a=='K')return 13;
}
int n;
int ans=52;
bool h[14]['S'-'C'+1];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		string p;
		cin>>p;
		char c;
		int num;
		c=p[0];num=ch(p[1]);
		if(h[num][c-'C'])continue;
		h[num][c-'C']=1;
		ans--;
		if(ans==0)break;
	}
	cout<<ans<<endl;
	for(int i=1;i<=13;i++){
		if(h[i][0])cout<<i<<'C'<<endl;
		if(h[i][1])cout<<i<<'D'<<endl;
		if(h[i]['H'-'C'])cout<<i<<'H'<<endl;
		if(h[i]['S'-'C'])cout<<i<<'S'<<endl;
	}
	return 0;
} 
