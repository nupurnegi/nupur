#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std; 

vector<vector <int>> graph; 

//connect two edges
void addEdge(){
  int v,w;
  cout<<"Enter the First Vertex: ";
  cin>>v;
  cout<<endl;
  cout<<"Enter the Second Vertex: ";
  cin>>w;
  cout<<endl;
  graph[v].push_back(w); 
  graph[w].push_back(v);
}

//add empty vertex
void addEmpty(){
  graph.push_back({});
}

//print neighbours of a vertex
void print(){
  int v;
  cout<<"Enter the Vertex you want to Print: ";
  cin>>v;
  cout<<endl;
  for (int i = 0; i < graph[v].size(); i++){ 
    cout<< graph[v][i] << " "<<endl; 
  } 
}

//Depth First Search
void dfs(int ver, stack <int> s, bool visited[]){
  if(!visited[ver]){
    s.push(ver);
    visited[ver]=true;
    cout<<ver<<" ";
  }
  for(int j=0;j<graph[ver].size();j++){
    if(!visited[graph[ver][j]]){
      ver=graph[ver][j];
      dfs(ver,s,visited);
    }
    if(visited[graph[ver][j]] && j==(graph[ver].size()-1)){
      s.pop();
    }
  }
  if(!s.empty()){
    dfs(s.top(),s,visited);
  }
}

//Breath First Search
void bfs(int ver, queue <int> q, bool visited[]){
  visited[ver]=true;
  cout<<ver<<" ";
  for(int j=0;j<graph[ver].size();j++){
    if(!visited[graph[ver][j]]){
      q.push(graph[ver][j]);
    }
  }
  while(visited[ver] && !q.empty()){
    ver=q.front();
    q.pop();
  }
  if(!visited[ver]){
    bfs(ver,q,visited);
  }
}

//Print seperate graphs
void connectedComponents(int ver, stack <int> s, bool visited[]){
  for(int x=0;x<graph.size();x++){
    if(!visited[x]){
      dfs(x,s,visited);
      cout<<endl;
    }
  }
}

//Check if cycle exits
bool cyclic(int ver,stack <int> s,bool visited[]){
  if(!visited[ver]){
    s.push(ver);
    visited[ver]=1;
  }
  if(visited[ver]){
    return true;
  }
  for(int j=0;j<graph[ver].size();j++){
    if(!visited[graph[ver][j]]){
      ver=graph[ver][j];
      cyclic(ver,s,visited);
    }
    if(visited[graph[ver][j]] && j==(graph[ver].size()-1)){
      s.pop();
    }
  }
  if(!s.empty()){
    cyclic(s.top(),s,visited);
  }
  return false;
}

int main() {
  cout<<"Welcome to Graph Data Structure"<<endl;
  cout<<"-------------------------------"<<endl;
  int ask=1;
  while(ask!=0){
    cout<<"[1] Add a New Empty Vertex"<<endl;
    cout<<"[2] Add an Edge with Two Vertices"<<endl;
    cout<<"[3] Print the Adj Vertices"<<endl;
    cout<<"[4] DFS"<<endl;
    cout<<"[5] BFS"<<endl;
    cout<<"[6] Find connected components"<<endl;
    cout<<"[7] Is it a Cyclic Graph?"<<endl;
    cout<<"Choose One Option: ";
    int opt;
    cin>>opt;
    switch(opt){
      case 1:
        addEmpty();
        cout<<endl;
        break;
      case 2:
        addEdge();
        cout<<endl;
        break;
      case 3:
        print();
        cout<<endl;
        break;
      case 4:
      {
        cout<<"Enter the Starting Vertex: ";
        int ver;
        cin>>ver;
        cout<<endl;
        stack <int> s;
        bool visited[graph.size()];
        for (int i = 0; i < graph.size(); i++) 
          visited[i] = false;  
        dfs(ver,s,visited);
        cout<<endl;
        break;
      }
      case 5: 
      {
        cout<<"Enter the Starting Vertex: ";
        int ver;
        cin>>ver;
        cout<<endl;
        queue <int> q;
        bool visited[graph.size()];
        for (int i = 0; i < graph.size(); i++) 
          visited[i] = false;  
        bfs(ver,q,visited);
        break;
      }
      case 6:
      {
        cout<<"Enter the Starting Vertex: ";
        int ver;
        cin>>ver;
        cout<<endl;
        stack <int> s;
        bool visited[graph.size()];
        int cc[graph.size()];
        for (int i = 0; i < graph.size(); i++) 
          visited[i] = false;  
        connectedComponents(ver,s,visited);
        int x=0;    
        break;
      }
      case 7:
      {
        int ver=graph[0][0];
        stack <int> s;
        bool visited[graph.size()];
        for (int i = 0; i < graph.size(); i++) 
          visited[i] = false;
        if(cyclic(ver,s,visited))
          cout<<"Yes"<<endl;
        else
          cout<<"No"<<endl;
        cout<<endl;
        break;
      }
      default:
        cout<<"Not a Valid Number."<<endl;
        break;
    }
  }
}
