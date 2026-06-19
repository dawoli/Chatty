#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,u[1000005],v[1000005],w[1000005],c[15],a[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//  /7............................(/
	//  ./7..........................(/.
	//  ../7........................(/..
	//  .../7......................(/...
	//  ..../7....................(/....
	//	...../7..................(/.....
	//	....../7................(/......
	//	......./7..............(/.......
	//	......../7............(/........
	//	........./7..........(/.........
	//	........../7........(/..........
	//	.........../7......(/...........
	//	............/7....(/............
	//	............./7..(/.............
	//	..............|()|..............
	//	............./(../7.............
	//	............/(..../7............
	//	.........../(....../7...........
	//	........../(......../7..........
	//	........./(........../7.........
	//	......../(............/7........
	//	......./(............../7.......
	//	....../(................/7......
	//	...../(................../7.....
	//	..../(..................../7....
	//	.../(....................../7...
	//	../(......................../7..
	//	./(........................../7.
	//  /(............................/7
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		cnt+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<cnt<<endl;
	//akakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakakak
	//                                                                    luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang   luogu: liuxuchang luoguluogu
	return 0;
}
//lkjlkjlkjlkjlkjlkjlkjlkjlkjlkjlkjlkjlklkjlkjlkjlkjlkjlkj
//jhgjhgjhgjhgjhgjhgjhgjhgjhgjhgjhjhghjgjhghjgjhgjhgjhgjhg
//gdgfdgfdgfdgfdgfdgfdfgdgfdgfdgfdgfdfgdfgdgfdgfdgfdgfdgfdgfdgfdgfd
//gghghghghghgghghghghghghghghgghghghghgghghhghghghghghghghghghghghghg
//yuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyuyu
//fgfgfgfgfggfgfgfgfgfgfggfgfgfgfgfgf
//jhfgjhfgjhfgjhfgjhjhfgjhfgjhfgjhfgjhfgjhfgjhfgjhfgjhfgjhfjghjhfgjhfgjhfgjhfgjhfgjhfgjfgjhfgjhgfjhfgjhfgjhgfhjfghjgfhjgfhjgfhjgfhjgfhjgfjhgfhjgfhjgfhjgfjhgfh
//qwqwqwqwwqwqwqwqqwqwqwqw
//lkjhlkjhljkhkljhkljhkljhlkjhkljhkljhkljhlkjhlkjhkljh
//kjh
//lkj
//oiu
//poi
//uyt
//tre
//hgf
//lkjh
//oiuy
//lkjhlkjhkljhkljhlkjh
//jhgfjhgfjhgfjhgfjhgf
//nbvcbnvcnbvcnbvcnbc
//hgfdhgfdhgfdhgfdhgfd
//rewqrewqrewqerwqrewq
//kjhfdgkjhdfgkjhdgdkjhgdfkjhdfgkjhgfd
//kjhdfgkjhkjhdfgdkjhdfgkjhdfgkjdhgdkjhgdkjfhgdfkhgdfgkfgjhkgdfjhkdfg
//hjkdgfhjkgfdjkhfgdhjkfdghjkgfdkjhfgdjhkfgdjkhdfghjkdfgjhkdfgjhdgfdhjkdfgdgfjhkdfghjdfgkhjfdgkhjfg
//jhfgjhfgjhfgkjhdfgkjhdfgkjhdfgkjhdfgkjh
//lkjhsfdglkjhfgdslkjhfgds
//ngnnvjvvvfnnnjvvvvnfnnvjvvvnfnnvjvvvjhjjkhlkhjhgjhghghjgjkhghgjhgkhjgjghkhg
//fjihgjifdhjifjigfjihjifhjifjihfjihjifhijfjihijfhjifjihji
//eerertyertertyrtyeretyerytereryutyurteyurteyuretyurteyuretyutrejkfgjfgjkfgfgkjfgjkfjkfgcvmncvmnmcvnmvcmnvcmncvnmcvmnnvc
//dgshdgshajdgshajdgshajdgshajdgshajdgshajdgshaj
//shjhjhjhjhkdfdfdfdfd
//sddddddddbhghgggggggdjfhfhhfhhffhjdhf
//tyuioplkjhgf
//double maimai
//ooooooooo
//¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý ¡ü¡ý
