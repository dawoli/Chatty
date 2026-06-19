#include<bits/stdc++.h>
using namespace std;
int a[11][21]={},n,ans=0,s1,t1;
char s,t;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		if(s=='D'){
			s1=1;
		}
		if(s=='C'){
			s1=2;
		}
		if(s=='H'){
			s1=3;
		}
		if(s=='S'){
			s1=4;
		}
		if(t=='T'){
			t1=10;
		}
		if(t=='J'){
			t1=11;
		}
		if(t=='Q'){
			t1=12;
		}
		if(t=='K'){
			t1=13;
		}
		if(t=='A'){
			t1=1;
		}
		if(t=='2'){
			t1=2;
		}
		if(t=='3'){
			t1=3;
		}
		if(t=='4'){
			t1=4;
		}
		if(t=='5'){
			t1=5;
		}
		if(t=='6'){
			t1=6;
		}
		if(t=='7'){
			t1=7;
		}
		if(t=='8'){
			t1=8;
		}
		if(t=='9'){
			t1=9;
		}
		a[s1][t1]=1;
		//cout<<s1<<" "<<t1<<endl;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]!=1){
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
