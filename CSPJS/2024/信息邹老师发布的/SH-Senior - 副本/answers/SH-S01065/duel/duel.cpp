#include<bits/stdc++.h>
using namespace std;
int n,cc[(int)1e5+9],r[(int)1e5+9],mx,ans,ps[(int)1e5+9];
bool use[(int)1e5+9],out[(int)1e5+9];
int used(int num){
    for(int i=ps[num];i<n;i++){
    	if(r[i]==num&&!use[i])return i;
    	if(r[i]>num) break;
	}
	return -1;
}
int find(int num){
    for(int i=ps[num];i<n;i++){
    	if(r[i]==num&&out[i]==0)return i;
    	if(r[i]>num) break;
	}
	return -1;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>cc[i];
    sort(cc,cc+n);
    ps[1]=0;
    r[0]=1;
    for(int i=1;i<n;i++){
    	if(cc[i-1]==cc[i])r[i]=r[i-1];
    	else r[i]=r[i-1]+1,ps[r[i-1]+1]=i;
	}
	mx=r[n-1];
	if(mx==1){
		cout<<n<<endl;
		return 0;
	}
	for(int i=2;i<=mx;i++){
		int pos=used(i);
		while(pos!=-1){
			int tgt=i-1;
			int tpos=find(tgt);
			while(tpos==-1&&tgt>=1){
				tgt--;
				tpos=find(tgt);
			}
			use[pos]=1;out[tpos]=1;
			pos=used(i);
		}
	}
	for(int i=0;i<n;i++){
		if(out[i])ans++;
	}
	cout<<n-ans<<endl;
	return 0; 
}
