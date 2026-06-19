#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+20;
long long n,q;
struct node2{
	string a,b;
}man[N];
struct node{
	int step;
	string pos;
};
void bfs(string start,string end){
	queue<node>q;
	q.push((node){0,start});
	while(!q.empty()){
		string pos=q.front().pos;
		int step=q.front().step;
		q.pop();
		if(pos==end){
			cout<<step<<"\n";
			return;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j+man[i].a.size()-1<n;j++){
				string re;
				bool f=false;
				for(int k=j;k<=j+man[i].a.size()-1;k++){
					if(man[i].a[k-j]!=pos[k]){
						f=true;
						break;
					}
				}
				if(f==false){
					long long iii=0;
					for(int k=0;k<n;k++){
						if(k<j||k>j+man[i].a.size()-1){
							re[k]=pos[k+iii];
						}else{
							for(int ok=0;ok<man[i].b.size();ok++){
								re[k+ok]=man[i].b[ok];
								if(ok>=man[i].a.size()){
									iii++;
								}
							}
						}
					}
					q.push((node){step+1,re});
				}
			}
		}
	}
	return;
}
int main(){
//	//取消注释!!!!!!!!
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	//取消注释!!!!!!!!
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>man[i].a>>man[i].b;
	}
	for(int k=1;k<=q;k++){
		string start,end;
		cin>>start>>end;
		bfs(start,end);
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb
//
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a
