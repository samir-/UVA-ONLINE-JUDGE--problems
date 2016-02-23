#include <bits/stdc++.h>

using namespace std;


typedef long long  ll;

int inf = 1000000;

int comp(string a , string b){
    int y = 0;

    if (a.size()!=b.size()) {
        return inf ;
    }
    else{
        for (int i = 0;i<a.size(); i++) {
            if (a[i]!=b[i]) y++;
            if (y>1) {
                return inf;
            }
        }
    
    }
    return 1;
}


int main () {
    
    
    int u = 0; cin>>u;
    while (u--) {
        
    
    string a , b ;
    map<string, int > mp ;
    vector<string> vect;
    vect.push_back("--");
    int  t[300][300];
    memset(t, inf,sizeof(inf));
    int z=1;
    char input [100];
   while ( gets (input) && strcmp (input, "*") ) {
        if (input=="*")break;
        vect.push_back(input);
        mp[input]=z++;
    }
    
    for (int  i = 1; i<z; i++) {
        for (int j = i+1; j<z; j++) {
            t[i][j]=comp(vect[i], vect[j]);
            t[j][i]=comp(vect[i], vect[j]);
        }
    }
    for (int i = 1 ; i<z; i++) {
        t[i][i]=0;
    }
    
    
    //we apply the bellman ford
    
    for (int  k = 1; k<z; k++) {
    for (int  i = 1; i<z ; i++) {
        for (int  j = 1; j<z; j++) {
            t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
        }
    }
    }
        while ( gets (input) && strlen (input) ) {
            char *pch;
            string a, b;
            pch = strtok(input, " ");
            a = pch;
            pch = strtok (NULL, " ");
            b = pch;
        cout<<a<<" "<<b<<" "<<t[mp[a]][mp[b]]<<endl;
    }
       if(u!=0) cout<<endl;
    }
      return 0;
}
