#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
const int N=505;
vector<int>a;
char s[N];
int c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        a.push_back(i);
    int ans=0;
    do{
        int cnt=0;
        for(int i=0;i<n;i++)
            if(s[i]=='0'||cnt>=c[a[i]]){
                cnt++;
                if(n-cnt<m)
                    break;
            }
        if(n-cnt>=m)
            ans++;
    }while(next_permutation(a.begin(),a.end()));
    printf("%d\n",ans);
    return 0;
}