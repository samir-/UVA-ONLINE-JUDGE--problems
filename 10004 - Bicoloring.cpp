//samir idwy
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;





vector<int> adj[300];
int color[300];
void coloring_BFS(){
    
    queue<int> q ;
    q.push(0);
    color[0]=0;
    while (q.size()) {
        int temp = q.front();
        q.pop();
        for (int i = 0; i< adj[temp].size(); i++) {
            if( color[adj[temp][i]]==-1) {
                q.push(adj[temp][i]);
                color[adj[temp][i]]=(color[temp]+1)%2;
            }
            else if( color[adj[temp][i]]!=(color[temp]+1)%2) {
                cout<<"NOT BICOLORABLE."<<endl;
                
                return;
                
            }
        }
    }
    
    cout<<"BICOLORABLE."<<endl;
}


int main()
{
    
    while (1) {
        memset(color, -1, sizeof(color));
        int n ,edges,a,b;
        cin>>n;
        if(n==0) break;
        for (int i = 0; i<n ; i++) {
            adj[i].clear();
        }
        cin>>edges;
        for (int i = 0; i<edges; i++) {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        coloring_BFS();
        
        
    }
    return 0;
}


