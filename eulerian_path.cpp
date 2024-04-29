#include<iostream>
#include<list>
using namespace std;

class graph
{
    int v;
    list<int> *adj;

    public:
    graph(int v){
        this->v =v; adj = new list<int>[v];

    }
    void add_edge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
   int isEulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};

void graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}
bool graph::isConnected(){
    bool visited[v];
    int i;
    for(i = 0; i < v; i++){
        visited[i] = false;
    }
    for(i = 0; i < v; i++){
        if(adj[i].size() != 0){
            break;
        }
    }
    if(i == v){
        return true;
    }
    DFSUtil(i, visited);
    for(i = 0; i < v; i++){
        if(visited[i] == false && adj[i].size() > 0){
            return false;
        }
    }
    return true;
}
int graph::isEulerian(){
    if(isConnected() == false){
        return 0;
    }
    int odd = 0;
    for(int i = 0; i < v; i++){
        if(adj[i].size() & 1){
            odd++;
        }
    }
    if(odd > 2){
        return 0;
    }
    return (odd)? 1 : 2;
}
void test(graph &g){
    int res = g.isEulerian();
    if(res == 0){
        cout<<"graph is not Eulerian";
    }
    else if(res == 1){
        cout<<"graph has a Euler path";
    }
    else{
        cout<<"graph has a Euler cycle";
    }
}
int main(){
    graph g1(5);
    g1.add_edge(1, 0);
    g1.add_edge(0, 2);
    g1.add_edge(2, 1);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);
    test(g1);
    cout<<endl;
    graph g2(5);
    g2.add_edge(1, 0);
    g2.add_edge(0, 2);
    g2.add_edge(2, 1);
    g2.add_edge(0, 3);
    g2.add_edge(3, 4);
    g2.add_edge(4, 0);
    test(g2);
    cout<<endl;
    graph g3(5);
    g3.add_edge(1, 0);
    g3.add_edge(0, 2);
    g3.add_edge(2, 1);
    g3.add_edge(0, 3);
    g3.add_edge(3, 4);
    g3.add_edge(1, 3);
    test(g3);
    cout<<endl;
    graph g4(3);
    g4.add_edge(0, 1);
    g4.add_edge(1, 2);
    g4.add_edge(2, 0);
    test(g4);
    cout<<endl;
    graph g5(3);
    g5.add_edge(0, 1);
    g5.add_edge(1, 2);
    test(g5);
    return 0;
}

