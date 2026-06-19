#include<bits/stdc++.h>
using namespace std;
struct node{
    int num,color;
};
long long maxn;
int n;
vector<node> A;
long long score() {
    vector<int> C(n);
    long long sum=0;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(A[j].num==A[i].num&&A[j].color==A[i].color) {
                C[i]=A[i].num;
                sum+=C[i];
            }else C[i]=0;
        }
    }
    return sum;
}
void dfs(int cnt) {
    if(cnt==n) {
        maxn=max(maxn,score());
        return;
    }
    for(int i=0;i<2;i++) {
        A[cnt].color=i;
        dfs(cnt+1);
    }
}
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        cin>>n;
        A.reserve(0);
        A.resize(n);
        for(int j=0;j<n;j++) cin>>A[j].num;
        maxn=0;
        dfs(0);
        cout<<maxn<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
