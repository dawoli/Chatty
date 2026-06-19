#include <bits/stdc++.h>
using namespace std;
struct poker{
	char huase;
	char shuzi;
}p[60];
int main(){
	freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
	    p[i].huase=str[0];
	    p[i].shuzi=str[1];
	    for(int j=0;j<i;j++){
	    	if((p[i].huase==p[j].huase) && (p[i].shuzi==p[j].shuzi)){
	    		cnt++; 
	    		break;
			}
		}
	}
	cout<<52-n+cnt;
	return 0;
}
