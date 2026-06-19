#include<bits/stdc++.h> 
using namespace std;
int n;
int used[255],cnt,ans=52;
char s[155][5];
int main(){ 
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
    cin>>n;
    for(int i=1;i<=n;i++){
	cin>>s[i];
	cnt=0;
	if(s[i][0]=='D'){
		cnt=1;
	}
	if(s[i][0]=='C'){
		cnt=2;
	}
	if(s[i][0]=='H'){
		cnt=3;
	}
	if(s[i][0]=='S'){
		cnt=4;
	}
	cnt*=20;
	if(s[i][1]=='A'){
	cnt++;
	}
	if(s[i][1]>='1'&&s[i][1]<='9') cnt+=s[i][1]-'0';
	if(s[i][1]=='T'){
	cnt+=10;
	}
	if(s[i][1]=='J'){
	cnt+=11;
	}
	if(s[i][1]=='Q'){
	cnt+=12;
	}
	if(s[i][1]=='K'){
	cnt+=13;
	}
	if(used[cnt]==0){
	used[cnt]=1;
	ans--;	
	}
}
cout<<ans;
    return 0;
}

