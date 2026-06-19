#include<iostream>
#include<algorithm>
using namespace std;
struct c{
	int x,v=0;
}cl[100005];
bool cmp(int a,int b){
	return a<b;
}
bool cmpc(c a,c b){
	return a.x<b.x;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,r[100005]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r[i];
		cl[i].x=r[i];
	}
	int cnt=0;
	while(cnt<n){
		sort(r,r+n,cmp);
		sort(cl,cl+n,cmpc);
//		for(int i=0;i<n;i++){
//			cout<<cl[i].x<<" ";
//		}
//		cout<<endl;
		int i=0,j=1;
		while(r[i]==r[j]||cl[j].v>0){
			j++;
			if(j>=n){
				j=1;
				break;
			}
		}
		if(r[i]<r[j]){
			cnt+=1;
			r[i]=-1;
			cl[i].x=cl[i].v=-1;
			swap(r[i],r[n-1]);
			swap(cl[i],cl[n-1]);
			n--;
			cl[j].v++;
		}else{
			cnt+=1;
		}
	}
	cout<<n<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
