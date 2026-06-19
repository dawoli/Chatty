#include<bits/stdc++.h>
 using namespace std;
 int n,t;//Ì°ÐÄ 
 struct Node{
 	int f,fid,s,sid,cha;
 };
 vector<Node> v;

 bool cmp(Node x,Node y){
 	return x.cha<y.cha;
 }
 int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	cin>>t;
 	while(t--){
 		v.clear();
		long long ans=0;
 		int ct[10]={0};
 	 	cin>>n;
	 	for(int i=1;i<=n;i++){
	 		int a,f=0,s=0,fid=0,sid=0;
	 		for(int j=1;j<=3;j++){
		 		cin>>a;
			 	if(a>=f){
			 		s=f;
			 		sid=fid;
			 		f=a;
			 		fid=j;
				}else if(a>=s){
				 	s=a;
				 	sid=j;
				}		
			 }
			 ct[fid]++;
			ans+=f;
	 		v.push_back({f,fid,s,sid,f-s});
		}
//cout<<ct[1]<<" "<<ct[2]<<" "<<ct[3]<<endl;
		if(max({ct[1],ct[2],ct[3]})<=n/2){
			cout<<ans<<endl;
			continue;
		}
		
		int chang;
		if(ct[1]>ct[2]&&ct[1]>ct[3]){
			chang=1;
		}
		if(ct[2]>ct[1]&&ct[2]>ct[3]){
			chang=2;
		}
		if(ct[3]>ct[2]&&ct[3]>ct[1]){
			chang=3;
		}
		sort(v.begin(),v.end(),cmp);
		bool f=0;
		for(Node x:v){
			if(ct[chang]<=n/2){
				f=1;
				cout<<ans<<endl;
				break;
			}
			if(x.fid!=chang) continue;
			ans-=x.cha;
			ct[x.fid]--;
			ct[x.sid]++;
	 	}if(f==0) cout<<ans<<endl;
	}
	return 0;
 }//		for(Node x:v){
//			cout<<x.f<<" "<<x.s<<" "<<x.cha<<endl;
//		}	
//		
//		cout<<ans<<endl;	
