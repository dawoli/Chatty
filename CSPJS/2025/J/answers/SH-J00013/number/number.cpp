#include<bits/stdc++.h>
using namespace std;
char s[100001];
int n=0,a[100001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int js=0;
    for(int i=0;i<=strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            n++;js++;
            a[js]=s[i];
            if(s[i]=='0') a[js]=0;
            if(s[i]=='1') a[js]=1;
            if(s[i]=='2') a[js]=2;
            if(s[i]=='3') a[js]=3;
            if(s[i]=='4') a[js]=4;
            if(s[i]=='5') a[js]=5;
            if(s[i]=='6') a[js]=6;
            if(s[i]=='7') a[js]=7;
            if(s[i]=='8') a[js]=8;
            if(s[i]=='9') a[js]=9;
        }
    }
    for(int i=0;i<=js;i++)
        for(int j=0;j<=i;j++)
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
    for(int i=0;i<js;i++) printf("%d",a[i]);
    return 0;
}
