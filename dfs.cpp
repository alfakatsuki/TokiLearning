#include <bits/stdc++.h>

using namespace std;

char d[1000][1000];

bool visit[1000][1000];


int dfs(int i, int j, int x, int y){

	if(i<1 || j<1) return false;


	if(i>x || j>y) return false;

	if(visit[i][j]==true) return false;

	if(d[i][j]=='#') return false;

	visit[i][j] = true;
	cout << "jelajah" << " " << i <<" " <<j << "\n"; 
	if(dfs(i+1,j,x,y)==true) return true;
	if(dfs(i-1,j,x,y)==true) return true;
	if(dfs(i,j+1,x,y)==true) return true;
	if(dfs(i,j-1,x,y)==true) return true;
}

int main(int argc, char const *argv[])
{
	
    int x, y;
    cin >> x >> y;
    
    for(int i=1;i<=x;i++){

        for(int j=1;j<=y;j++){
            while(1){
                cin.get(d[i][j]);
                if(d[i][j]!='\n') break;

            }

            cout << d[i][j];
        }
        cout << "\n";
    }
    cout << "\n";




	bool s = true;

	for(int i=1; i<=y;i++){
			dfs(1,i, x, y);
			
	}

	for(int i=1; i<=x;i++){
			dfs(i,1,x, y);
			
	}

	for(int i=1; i<=x;i++){
			dfs(i,y, x, y);
			
	}

	for(int i=1; i<=y;i++){
			dfs(x,i, x, y);
			
	}

	for(int i=2; i<=x-1;i++){
		for (int j = 2; j <= y-1; ++j)
		{
			if(d[i][j] == '#') continue;
			if(visit[i][j] == !true){
				s=false;
				break;
			}
		}
	}

	for(int i=1;i<=x;i++){

        for(int j=1;j<=y;j++){
            
        	if(d[i][j]=='#') {
        	cout << '#';
        	continue;}
            if(visit[i][j]) cout << '~';
            else cout << ' ';

        }
        cout << "\n";
    }
    cout << "\n";


	if(!s){
		cout << "Ada yang tidak banjir\n";
	}
	else {

		cout << "Banjir semua\n";
	}



	//start from 1,1 finish x,y





	return 0;
}
