#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,score[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>score[i];
	int sr=score[1],id;
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(score[i]==sr){
			id=i;
			break;
		}
	}
	cout<<(id-1)/n+1<<" ";
	if(((id-1)/n)%2==0) cout<<(id-1)%n+1;
	else cout<<n-(id-1)%n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
