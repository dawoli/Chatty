#include<bits/stdc++.h>
using namespace std;
long long T,n,A[200009];
string solve(long long k,long long time){
    long long temp[200009]={};
    string out;
    for(int i=0;i<n;i++){
        temp[i]=k%2;
        if(temp[i]==1)out+="1";
        else out+="0";
        k/=2;
    }
    return out;
}
long long zuo(string s,long long k){
	for(long long v=k-1;v>=0;v--){
		if(s[k]==s[v])return v;
	}
	return -1;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int p=0;p<T;p++){
        cin>>n;
        for(int q=0;q<n;q++)cin>>A[q];
        long long ans=0,N=1;
        for(long long q=1;q<n;q++)N*=2;
        for(long long q=0;q<N;q++){
            string s=solve(q,n);
            long long ans1=0;
            for(int i=0;i<n;i++){
            	long long temp=zuo(s,i);
            	if(temp!=-1&&A[temp]==A[i]){
            		ans1+=A[temp]; 
				}
			}
			ans=max(ans,ans1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
