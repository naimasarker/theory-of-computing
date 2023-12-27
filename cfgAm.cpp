#include <bits/stdc++.h>
using namespace std;

int found = 0;
string path, path2;
void cfg(vector<string> &base, string output, string target, string currpath)
{
    if (found == 2)
        return;

    if (output.size() > target.size() + 2)
        return;

    if (output.find('S') == string::npos && output != " ")
    {
        while (output.find('e') != string::npos)
        {

            if (output.find('e') != string::npos)
            {
                string temp = output.substr(0, output.find('e'));
                temp += output.substr(output.find('e') + 1);
                output = temp;
            }
        }

        if (output == target)
        {
            found++;
            //cout << "Path uploading: " << currpath << found << endl;
            if (found == 1)
                path = currpath;

            if (found == 2)
            {
                path2 = currpath;
                //cout << "path2 printing: " << path2 << endl;
            }
        }
        return;
    }

    for (string x : base)
    {
        if (output.find('S') != string::npos)
        {
            string temp = output.substr(0, output.find('S'));
            temp += x;
            temp += output.substr(output.find('S') + 1);
            x = temp;
        }
        //cout << x << endl;
        cfg(base, x, target, currpath + "->" + x);
        if (found == 2)
            return;
    }
}

int main(){

    vector<string> base = {"e", "aS", "aSbS"};
    string s;
    cin >> s;
    cfg(base, "S", s, path);

    //cout << "path1 printing: " << path << endl;
    //cout << " path2 printing: " << path2 << endl;
    if (found == 2)
    {
        if (path.find('e') != string::npos)
        {
            string temp = path.substr(0, path.find('e'));
            temp += path.substr(path.find('e') + 1);
            path = temp;
        }

        while (path.find('e') != string::npos)
        {

            if (path.find('e') != string::npos)
            {
                string temp = path.substr(0, path.find('e'));
                temp += path.substr(path.find('e') + 1);
                path = temp;
            }
        }
        while (path2.find('e') != string::npos)
        {

            if (path2.find('e') != string::npos)
            {
                string temp = path2.substr(0, path2.find('e'));
                temp += path2.substr(path2.find('e') + 1);
                path2 = temp;
            }
        }

        cout<<endl<< "Path-1: " << "S" + path << endl;
        cout << "Path-2: "<<"S" + path2 << endl;
    }
    (found == 2) ? cout << "This grammar is ambiguous." : cout << "This grammar is not ambiguous.";
    cout << endl;

    return 0;
}
