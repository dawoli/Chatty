for(int i=1;i<=t;i++){
		cin>>ns;
		bool flag = false;
		for(int j=1;j<=100000;j++){
			if(ns==stick[j]){
				cout<<j<<endl;
				flag = true;
				break;
			}
		}
		if(!flag){
			cout<<-1<<endl;
		}
	}
