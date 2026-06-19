#include<bits/stdc++.h>
using namespace std;
int t[52]={0};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;cin>>n;for(int i=0;i<n;i++){
		int p=0;char a;
		cin>>a;if(a=='C')p+=13;else if(a=='H')p+=26;else if(a=='S')p+=39;
		cin>>a;if(a>='2'&&a<='9')p+=int(a)-49;else if(a=='T')p+=9;else if(a=='J')p+=10;else if(a=='Q')p+=11;else if(a=='K')p+=12;
		t[p]++; 
	}
	n=0;for(int i=0;i<52;i++)n+=t[i]?1:0;
	cout<<52-n;
	return 0;
}
