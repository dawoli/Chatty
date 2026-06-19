#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int ans[10]={0};
int main(){
    int i=0,x;
    cin>>a;
    while(a[i]!='\0'){
        if(a[i]<='9'&&a[i]>='0'){
            x=int(a[i]-'0');
            ans[x]++;
        }
        i++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=ans[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}
