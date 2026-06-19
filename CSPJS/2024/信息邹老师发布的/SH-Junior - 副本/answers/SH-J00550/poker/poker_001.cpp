#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char aa,bb;
	cin>>aa>>bb;
	int a;
	char s1[a+5],s2[a+5];
	bool con=0;
	if(bb<='9' and bb>='0'){
	    a=(int(aa)-48)*10+int(bb)-48;
    }else{
    	a=int(aa)-48;
    	con=1;
	}
	if(con==1){
		s1[1]=bb;
		cin>>s2[1];
		for(int i=2;i<=a;i++){
			cin>>s1[i]>>s2[i];
		}
	}else{
	    for(int i=1;i<=a;i++){
		    cin>>s1[i]>>s2[i];
        }
    }
	int ans=a;
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			if(s1[i]==s1[j] and s2[i]==s2[j] and i!=j){
				ans--;
			}
		}
	}
	int sum=52-ans;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//52 DA CA HA SA D2 C2 H2 S2 D3 C3 H3 S3 D4 C4 H4 S4 D5 C5 H5 S5 D6 C6 H6 S6 D7 C7 H7 S7 D8 C8 H8 S8 D9 C9 H9 S9 DT CT HT ST DJ CJ HJ SJ DQ CQ HQ SQ DK CK HK SK
