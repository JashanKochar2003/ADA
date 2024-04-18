#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std ;
template <typename T>


class graph {
    public:
    unordered_map<T,vector<pair<T,int>>> adj;
    vector<vector<int>> cost;

   graph(int n){
        cost.resize(n, vector<int>(n, INT16_MAX));
        cout << "done1" << endl;
    }
    
    void addEdge(T u, T v ,int w, int dir){
        adj[u].push_back(make_pair(v,w));
        cost[u][v]=w;
        if(dir == 0){
        adj[v].push_back(make_pair(u,w));
        cost[v][u]=w;
        }
    }

    void printGraph(){
        for(auto i : adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"["<<j.first<<","<<j.second<<"]"<<", ";
            }
            cout<<endl;
        }
    }

    void printCost(){
        for(int i=0;i<cost.size();i++){
            for(int j=0;j<cost[i].size();j++){
                cout<<cost[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};

void adding_multiple_edges(graph<int> &g,int vertices, int edges, int direction){
    int i=0;
    int p,w;
    cout<<"enter assembly line number : ";
    cin>>p;
    while(i<edges && p<vertices){
        cout<<"enter weight of edge : "<<endl;
        cin>>w;
            g.addEdge(p,i,w,direction);
            i++;
        }
    }

int opp(int arr[],int j){
    if(arr[j-1]==1)
    return 2;
    else
    return 1;
}

void assemblyLine(graph<int> a1, graph<int> a2 , graph<int> t1 , graph <int> t2, int n, int e1, int e2, int x1, int x2 , int& f_,int l_[]){
    int f1[n+1], f2[n+1], l1[n], l2[n];
    f1[0]=e1+a1.cost[1][0];
    f2[0]=e2+a2.cost[2][0];
    l1[0]=1;
    l2[0]=2;
    int cost1,cost2,side,other;
    for(int j=1;j<n;j++){
        if(l1[j-1]==1 && l2[j-1]==2){
            cost1 = a1.cost[1][j];
            cost2 = a2.cost[2][j];
            side = t2.cost[2][j-1];
            other = t1.cost[1][j-1];
        }
        else{
            cost2 = a1.cost[1][j];
            cost1 = a2.cost[2][j];
            side = t1.cost[1][j-1];
             other = t2.cost[1][j-1];
        }
        if(f1[j-1]<=f2[j-1]){
            if(cost1 <= other+cost2){
                f1[j]= f1[j-1]+cost1;
                l1[j]=l1[j-1];
                f2[j]= f2[j-1]+cost2;
                l2[j]=l2[j-1];
        }
            else{
                f1[j]=f1[j-1]+other+cost2;
                l1[j]=opp(l1,j);
                f2[j]=f2[j-1]+side+cost1;
                l1[j]=opp(l2,j);
            }
        }
        else{
            if(cost2 <= side+cost1){
                f1[j]= f1[j-1]+cost1;
                l1[j]=l1[j-1];
                f2[j]= f2[j-1]+cost2;
                l2[j]=l2[j-1];
        }
            else{
                f1[j]=f1[j-1]+other+cost2;
                l1[j]=opp(l1,j);
                f2[j]=f2[j-1]+side+cost1;
                l2[j]=opp(l2,j);
            }
        }
    }
    if(l1[n-1]==1){
        f1[n]= f1[n-1]+x1;
        f2[n]=f2[n-1]+x2;
    }
    else{
        f1[n]= f1[n-1]+x2;
        f2[n]=f2[n-1]+x1;
    }
    if(f1[n] < f2[n]){
        f_ = f1[n];
        for(int i=0;i<n;i++){
            l_[i]=l1[i];
        }
    }
    else{
     f_ = f2[n];
        for(int i=0;i<n;i++){
            l_[i]=l2[i];
        }
    }   
}

int main(){
    int e1,e2,x1,x2;
    cout<<"cost of starting and ending points : "<<endl;
    cin>>e1>>e2>>x1>>x2; 
    int f_ = 0;
    int n;
    int m;
    int dir;
    cout<<"enter number of nodes : ";
    cin>>n;
    cout<<"enter 1 for directed and 0 for undirected graph : ";
    cin>>dir;
     int l_[n];
    graph<int> a1(n);
    graph<int> a2(n);
    graph<int> t1(n);
    graph<int> t2(n);
    adding_multiple_edges(a1,n,n,dir);
    adding_multiple_edges(a2,n,n,dir);
    adding_multiple_edges(t1,n,n-1,dir);
    adding_multiple_edges(t2,n,n-1,dir);
    assemblyLine(a1,a2,t1,t2,n,e1,e2,x1,x2,f_,l_);
    cout<<"final minimum cost is : ";
    cout<<f_<<endl;
    cout<<"their path is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<l_[i]<<"\t";
    }

    return 0;
}
