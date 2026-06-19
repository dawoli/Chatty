#include<bits/stdc++.h>
using namespace std;
struct Gs{
    int a;
    bool v1=false,v2=false;
};
int minn;
Gs gs[100001];
bool cmp(Gs a,Gs b) {
	return a.a<b.a;
}
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>gs[i].a;
    minn=n;
    sort(gs+1,gs+1+n,cmp);
   	for(int i=1;i<n;i++) {
   		for(int j=i+1;j<=n;j++) {
   			if(gs[i].a==gs[j].a||gs[i].v2||gs[j].v1||gs[j].v2) continue;
   			gs[i].v2=true;
   			gs[j].v1=true;
   			minn--;
   			break;
		}
	}
    cout<<minn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
