#include<bits/stdc++.h>
using namespace std;
int n,m,ii=1,jj=1;
struct score{
	int n,s;
};
score stu[105];
bool cmp(score a,score b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i].s;
		stu[i].n=i;
	}
	sort(stu+1,stu+n*m+1,cmp);
	int dq=1;
	while(1){
		while(ii<=m){
			if(stu[dq].n==1){
				cout<<jj<<" "<<ii<<endl;
				fclose(stdin);fclose(stdout);
				return 0;
			}
			dq++;
			ii++;
		}
		ii=m;
		jj++;
		if(stu[dq].n==1){
			cout<<jj<<" "<<ii<<endl;
			fclose(stdin);fclose(stdout);
			return 0;
		}
		while(ii>=1){
			if(stu[dq].n==1){
				cout<<jj<<" "<<ii<<endl;
				fclose(stdin);fclose(stdout);
				return 0;
			}
			ii--;
			dq++;
		}
		ii=1;
		jj++;
		if(stu[dq].n==1){
			cout<<jj<<" "<<ii<<endl;
			fclose(stdin);fclose(stdout);
			return 0;
		}
	}
}
