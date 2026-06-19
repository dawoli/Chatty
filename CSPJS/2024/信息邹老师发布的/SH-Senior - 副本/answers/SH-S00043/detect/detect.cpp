#include<bits/stdc++.h>
#define Max 100000
struct car{
    int d,v,a,st[Max],e;
    bool cs=false;
};
using namespace std;
int minn,N,M;
car c[Max];
bool F[Max];
void f(int st,int i) {
    if(i==N) {
       minn=min(st,minn);
       return;
    }else if(st>minn) return;
    bool flag=false;
    for(int j=0;j<c[i].e;j++) {
        if(F[c[i].st[j]]) {
            flag=true;
            break;
        }
    }
    if(flag) f(st,i+1);
    else {
        for(int j=0;j<c[i].e;j++) {
            F[c[i].st[j]]=true;
            f(st+1,i+1);
            F[c[i].st[j]]=false;
        }
    }
}
int main() {
    freopen("detect1.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        int L,V,st[Max],cnt=0;
        N=0;
        M=0;
        car a[Max]={};
        swap(c,a);
        delete(&a);
        cin>>N>>M>>L>>V;
        for(int j=0;j<N;j++) cin>>c[j].d>>c[j].a>>c[j].v;
        for(int j=0;j<M;j++) cin>>st[j];
        sort(st,st+M);
        for(int j=0;j<N;j++) {
        	if(c[j].a==0&&c[j].v>V) {
        		for(int k=0;k<M;k++) {
        			if(st[k]<c[j].d) continue;
        			c[j].st[c[j].e++]=k;
				}
			}else{
				for(int k=0;k<M;k++) {
					if(sqrt(pow(c[j].v,2)+2*c[j].a*st[k])>V) {
						if(!c[j].cs) cnt--;
						c[j].cs=true;
						c[j].st[c[j].e++]=k;
					}
				}
			}
        }
        minn=M;
        f(0,0);
        cout<<minn<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
