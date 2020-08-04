#include <bits/stdc++.h> 
using namespace std;
class Edge{
  public:
  int source;
  int destination;
  int weight;
};
bool condi(Edge e1, Edge e2){
  return e1.weight<e2.weight;
  //if return true sorting function will work else will not
}
int findParent(int vertex, int *parent){
//this would be a recursion function
//base condition
if(parent[vertex]==vertex)
  return vertex;
return findParent(parent[vertex], parent);

}
void kruskals(Edge *input, int n, int e){
  sort(input,input+e,condi);
  //we have to sort the edges based on their weight
  Edge *output = new Edge[n-1];
  int *parent=new int[n];
  //to record each vertices' parent vertex
  int i;
  for(i=0;i<n;i++){
    parent[i]=i;
    //initially all vertex will have parent marked as temselves
  }
  int count=0;
  i=0;
  while(count!=n-1){
    Edge currentEdge = input[i]; 
    //we have to chk if we can add the to the MST using Union Find algorithm
    int sourceParent=findParent(currentEdge.source,parent);
    int destiParent=findParent(currentEdge.destination,parent);
    if(sourceParent!=destiParent){
      output[count]=currentEdge;
      count++;
      //we have to make any of the vertex as a parent of another before moving to next edge
      parent[sourceParent]=destiParent;
    }
    i++;
  }
  //print MST
  for(int i=0;i<n-1;i++){
    cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
  }
}
int main(){
  int n,e;
  cin>>n>>e;
  Edge *input =new Edge[e];
  for(int i=0;i<e;i++){
    int s,d,w;
    cin>>s>>d>>w;
    input[i].source=s;
    input[i].destination=d;
    input[i].weight=w;
  }
  kruskals(input,n,e);
}
