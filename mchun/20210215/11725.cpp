#include <iostream>
#include <vector>
using namespace std;

int parent[100001];
vector <int> visited[100001];

void dfs(int node){
    for(int i = 0; i < visited[node].size(); i++){
        if(!parent[visited[node][i]]){
            parent[visited[node][i]] = node;
            dfs(visited[node][i]);
        }
    }
}

int main(){
	int	n;
    int x,y;

    cin >> n;
    for(int i = 0; i< n-1; i++){
        cin >> x >> y;
        visited[x].push_back(y);
        visited[y].push_back(x);
    }

    dfs(1);
    for(int i = 2; i<= n; i++){
        cout << parent[i] << '\n';
    }
}
