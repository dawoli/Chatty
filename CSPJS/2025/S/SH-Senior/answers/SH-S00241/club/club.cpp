#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,t,ch[114514],cnt[5],cho[114514];
struct st{
	int mi1,mi2,mi3,cho;
}a[114514];
struct stc{
	int nm,delt;
}b[114514];
int add(int x[]){
	int as1=0;
	for(int i=1;i<=n;i++)
	as1+=x[i];
	return as1;
}
bool gt(stc a,stc b){
	return a.delt<b.delt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		cnt[1]=0;cnt[2]=0;cnt[3]=0;
		for(int i=1;i<=n;i++){
		cin>>a[i].mi1>>a[i].mi2>>a[i].mi3;
		ch[i]=max(max(a[i].mi1,a[i].mi2),a[i].mi3);
		if(a[i].mi1==ch[i]){
			cnt[1]++;cho[i]=1;
			continue;
		    }
		else if(a[i].mi2==ch[i]){
			cnt[2]++;cho[i]=2;
			continue;
		    }
		else{
			cnt[3]++;cho[i]=3;
	        } 
	    }
	    int g=max(max(cnt[1],cnt[2]),cnt[3]),r=0,j=1,ti=add(ch);
	    int q=g-n/2;
	    if(cnt[3]==g)r=3;
	    if(cnt[2]==g)r=2;
	    if(cnt[1]==g)r=1;
	    if(g*2<=n)
		cout<<ti<<endl;
		else if(r==3){
			for(int i=1;i<=n;i++)
			if(cho[i]==r)
			b[j].delt=ch[i]-max(a[i].mi1,a[i].mi2);
			sort(b+1,b+g+1,gt);
			for(int i=1;i<=q;i++)
			ti-=b[i].delt;
			cout<<ti<<endl;
		}
		else if(r==1){
			for(int i=1;i<=n;i++)
			if(cho[i]==r)
			b[j].delt=ch[i]-max(a[i].mi2,a[i].mi3);
			sort(b+1,b+g+1,gt);
			for(int i=1;i<=q;i++)
			ti-=b[i].delt;
			cout<<ti<<endl;
		}
		else{
			for(int i=1;i<=n;i++)
			if(cho[i]==r)
			b[j].delt=ch[i]-max(a[i].mi3,a[i].mi1);
			sort(b+1,b+g+1,gt);
			for(int i=1;i<=q;i++)
			ti-=b[i].delt;
			cout<<ti<<endl;
		}
    }
}
