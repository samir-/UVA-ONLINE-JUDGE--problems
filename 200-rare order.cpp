//AUTHOR : SAMIR IDWY
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
int visited[30];
vector<int> adj[30];
int no_parents[30];
stack<int> stak ;

void topologicalsort(int x ){
    visited[x]=1;
    //cout<<adj[x].size()<<"   --\n";
    for (int i =0 ; i<adj[x].size(); i++) {
        int temp =adj[x][i];
        if(visited[temp]==0){
            topologicalsort(temp);
        }
    }
    stak.push(x);
    return;
}

int main()
{
    memset(no_parents,1, sizeof(no_parents));
    memset(visited,0, sizeof(visited));
    string s ;
    vector<string> data;
    cin>>s;
    while (s!="#") {
        data.pb(s);
        cin>>s;
    }
    int kk =1 ;
    map<char, int > mp ;
     for (int i = 1; i<data.size(); i++) {
        for (int  j =0 ; j<min(data[i].size(),data[i-1].size()); j++) {
            if (data[i][j]!=data[i-1][j]) {
                if (mp[data[i][j]]==0)mp[data[i][j]]=kk++;
                if (mp[data[i-1][j]]==0)mp[data[i-1][j]]=kk++;
                int first_node = mp[data[i-1][j]];
                int second_node =mp[data[i][j]];
                adj[first_node ].push_back(second_node);
                no_parents[second_node]=0;
                break;
            }
        }
    }
    for (int i = 1; i< kk; i++) {
        if (no_parents[i]) {
            topologicalsort(i);
        }
    }
    char out[30];
    for (int i = 0; i<26; i++) {
        out[mp['A'+i]]='A'+i;
    }
    
    while (stak.size()) {
        cout<<out[stak.top()];
        stak.pop();
    }
    printf("\n");

    return 0;
}



