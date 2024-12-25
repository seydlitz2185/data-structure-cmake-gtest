#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cout;
using std::string;
using std::pair;
using std::vector;
using std::map;
using std::make_pair;

struct vertex 
{
    typedef pair<int, vertex*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    string name;
    vertex(string s) : name(s) {}
};

class graph
{
public:
    typedef map<string, vertex *> vmap;
    vmap work;
    void addvertex(const string&);
    void addedge(const string& from, const string& to, double cost);
    void printvertex();
    void printedge();
};

void graph::addvertex(const string &name)
{
    vmap::iterator itr = work.find(name);
    if (itr == work.end())
    {
        vertex *v;
        v = new vertex(name);
        work[name] = v;
        return;
    }
    cout << "\nVertex already exists!";
}

void graph::addedge(const string& from, const string& to, double cost)
{
    vertex *f = (work.find(from)->second);
    vertex *t = (work.find(to)->second);
    pair<int, vertex *> edge = make_pair(cost, t);
    f->adj.push_back(edge);
}


void graph::printvertex(){
    cout <<"vertices: ";
    for(vmap::iterator itr = work.begin();itr !=work.end(); ++itr){
        cout << itr->first << " ";
    } 
    cout <<"\n";
}

void graph::printedge(){
    cout <<"edges: (format: from vertex --cost-->to vertex)\n";
    for(vmap::iterator itr = work.begin();itr !=work.end(); ++itr){
        for(int i=0;i<itr->second->adj.size();i++){
             cout <<itr->first << "--"<< itr->second->adj[i].first <<"-->"<< itr->second->adj[i].second->name<< "\n";
        }
    } 
}