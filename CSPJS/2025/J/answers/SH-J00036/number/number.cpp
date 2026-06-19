#include <stdio.h>
#include <algorithm>
const int MAXN=1e6+10;
char num[MAXN];
int ind=0;
void solve(){
    char c;
    for (;c!=EOF&&c!='\n';c=getchar()){
        if (c>='0'&&c<='9') num[++ind]=c;
    }
    std::sort(num+1,num+ind+1);
    for (int i=ind;i>=1;--i){
        putchar(num[i]);
    }
    putchar('\n');
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}