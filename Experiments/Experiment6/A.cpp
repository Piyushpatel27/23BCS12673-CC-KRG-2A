#include<bits/stdc++.h>
using namespace std;

vector<int>adj[26];
vector<int>vis(26, 0);  // 0 = unvisited, 1 = visiting, 2 = visited
string ans= "";
bool cycle=false;

void dfs(int node){
    vis[node] = 1;

    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it);
        }
        else if(vis[it]==1){
            cycle=true;
        }
    }

    vis[node]=2;
    ans+=char(node+'a');
}

int main(){
    int n; cin>>n;

    vector<string> words(n);
    for(int i=0;i<n; i++) cin>>words[i];

    for(int i=0;i<n-1; i++){
        string s1=words[i];
        string s2=words[i+1];

        int len=min(s1.size(), s2.size());
        bool found=false;

        for(int j=0; j<len; j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                found=true;
                break;
            }
        }

        if(!found && s1.size()>s2.size()){
            cout<<"Not possible";
            return 0;
        }
    }

    for(int i=0; i<26; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    if(cycle){
        cout<<"Not possible";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;

    return 0;
}