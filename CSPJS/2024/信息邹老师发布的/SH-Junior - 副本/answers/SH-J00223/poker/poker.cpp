#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,ss=0;
string s[60];
string a;
bool ex(string a){
    for(int j=0;j<ss;j++){
        if(s[j]==a)return 1;
    }
    return 0;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a; 
        if(!ex(a)) s[ss++]=a;
    }
    cout<<52-ss;
    return 0;
} 
