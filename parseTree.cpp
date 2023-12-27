#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    string label;
    vector<Node> children;
};

vector<Node>terminals;
int length,c=0;

Node buildB(string str, int pos)
{
    Node node {"B", {}};
    if (str[pos] == '0')
    {
        node.children.push_back({"0", {}});
        pos++;
        node.children.push_back(buildB(str, pos));
    }
    else if (str[pos] == '1')
    {
        node.children.push_back({"1", {}});
        pos++;
        node.children.push_back(buildB(str, pos));
    }
    else if(str[pos]=='\0')
    {
        node.children.push_back({"E", {}});
    }
    return node;
}

Node buildA(string str, int pos)
{
    Node node {"A", {}};
    if (str[pos] == '0')
    {
        node.children.push_back({"0", {}});
        pos++;
        node.children.push_back(buildA(str, pos));
    }
    else if(str[pos]=='\0')
    {
        node.children.push_back({"E", {}});
    }
    else if (str[pos] == '1')
    {   node.children.push_back({"E", {}});
        node.children.push_back({"1", {}});
        pos++;
        node.children.push_back(buildB(str, pos));
    }


    return node;
}

Node buildS(string str, int pos)
{
    Node node {"S", {}};
    node.children.push_back(buildA(str, pos));

    return node;
}

Node build__ParseTree(string str)
{
    int pos = 0;
    return buildS(str, pos);
}

void printParseTree(Node node, int depth)
{

    if (node.children.empty())
    {
        terminals.push_back(node);

    }
    cout << string(depth, ' ') << node.label << endl;
    for (Node child : node.children)
    {
        printParseTree(child, depth + 1);
    }
}

vector<string>trav;

bool is_accept(string str)
{

    cout<<"\nLeaf nodes:\n";
    cout<<"----------------------------\n";

    for (int i = 0; i < terminals.size(); i++)
    {
        cout << terminals[i].label <<"  ";
    }

    if(c==length) cout<<"1 "<<" E ";

    for (int i = 0; i < terminals.size(); i++)
    {
        if((terminals[i].label)!="E")
        {
            trav.push_back(terminals[i].label);
            //cout<<terminals[i].label;
        }
    }

    cout<<"\n";

    string tree_str = "";
    for (int i = 0; i < trav.size(); i++)
    {
        tree_str += trav[i];
    }

    if(c==length){
        tree_str +="1";
    }

       cout<<"\nString(By Traversing Parse tree)-->"<<tree_str<<"\n\n";
       cout<<"Given String-->"<<str<<"\n\n";

    if(tree_str==str) return true;

    return false;
}

int main()
{
    cout<<"Grammar:\n";
    cout<<"S->A1B\nS->0A|E\nS->0B|1B|E\n";

    cout<<"Enter String:\n";
    string str;
    cin>>str;
    length=str.size();

    Node root = build__ParseTree(str);
    printParseTree(root, 0);

    for(int i=0;i<str.size();i++){
        if(str[i]=='0') c++;
    }

    if(is_accept(str)) cout<<"Match!!So,String is Accepted\n";

    else
        cout<<"String is not Accepted\n";

    return 0;
}