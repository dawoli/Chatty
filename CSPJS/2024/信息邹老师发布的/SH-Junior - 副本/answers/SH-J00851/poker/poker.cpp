#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n;
bool have[300][300];
char l1[9];
char l2[100];
int cnt1,cnt2;
void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
		cin>>s;
	    have[(int)s[0]][(int)s[1]]=1;
	}
	l1[cnt1++]='D';
	l1[cnt1++]='C';
	l1[cnt1++]='H';
	l1[cnt1++]='S';
	l2[cnt2++]='A';
	l2[cnt2++]='2';
	l2[cnt2++]='3';
	l2[cnt2++]='4';
	l2[cnt2++]='5';
	l2[cnt2++]='6';
	l2[cnt2++]='7';
	l2[cnt2++]='8';
	l2[cnt2++]='9';
	l2[cnt2++]='T';
	l2[cnt2++]='J';
	l2[cnt2++]='Q';
	l2[cnt2++]='K';
	
}
int ans;
void solve(){
    for(int i=0;i<cnt1;i++){
    	for(int j=0;j<cnt2;j++){
    		if(!have[(int)l1[i]][(int)l2[j]])
    		    ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	input();
	solve();
}

