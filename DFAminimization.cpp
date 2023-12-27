#include<bits/stdc++.h>
using namespace std;

char states[100];
char trans[10];
char dfa[100][10];
char acc[10];
char nonAcc[10];
char table[100][100];

void tableFilling(int state, int transition,int accept,int in)
{

    for(int i = 0; i < state; i++)
    {
        for(int j = 0; j < state; j++)
        {
            table[i][j] ='=';
        }
    }

    for(int i = 0; i < state; i++)
    {
        for(int j = 0; j < state; j++)
        {
            if(i < j)
            {
                bool iIsAccepting = false, jIsAccepting = false;

                for(int k = 0; k < sizeof(acc); k++)
                {
                    if(states[i] == acc[k])
                    {
                        iIsAccepting = true;
                        break;
                    }
                }

                for(int k = 0; k < sizeof(acc); k++)
                {
                    if(states[j] == acc[k])
                    {
                        jIsAccepting = true;
                        break;
                    }
                }

                if((iIsAccepting && !jIsAccepting) || (!iIsAccepting && jIsAccepting))
                {
                    table[i][j] = 'X';
                    table[j][i] = 'X';
                }
            }
        }
    }

    bool conti = true;

    while(conti)
    {
        conti = false;

        for(int i = 0; i < state; i++)
        {
            for(int j = 0; j < state; j++)
            {
                if(i < j && table[i][j] == '=')
                {
                    for(int k = 0; k < transition; k++)
                    {
                        int iTrans = -1, jTrans = -1;

                        for(int l = 0; l < state; l++)
                        {
                            if(states[l] == dfa[i][k])
                            {
                                iTrans = l;
                            }
                            if(states[l] == dfa[j][k])
                            {
                                jTrans = l;
                            }
                        }
                        if(table[iTrans][jTrans] == 'X')
                        {
                            table[i][j] = 'X';
                            table[j][i] = 'X';
                            conti = true;
                        }
                    }
                }
            }
        }
    }
    cout<<"\nTable:\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    for(int i=0;i<state;i++){
            if(i!=0) cout<<states[i]<<"|";
        for(int j=0;j<i;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<" |";
      for(int i=0;i<state-1;i++){
        cout<<states[i]<<" ";
      }

    cout << "\n\nEquivalent states:\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    for(int i = 0; i < state; i++)
    {
        for(int j = i + 1; j < state; j++)
        {
            if(table[i][j] == '=')
            {
                cout << states[i] << " == " << states[j] << endl;
            }
        }
    }
}


int main()
{

    freopen("dfa.txt","r",stdin);
    cout<<"How many states are in dfa table?\n";
    int state;
    cin>>state;
    cout<<state<<"\n";
    cout<<"What are the states?\n";
    for(int i=0; i<state; i++)
    {
        cin>>states[i];
        cout<<states[i]<<" ";
    }
    cout<<"\nHow many transitions are there?\n";
    int transition;
    cin>>transition;
    cout<<transition;
    cout<<"\nWhat are the transitions?\n";

    for(int i=0; i<transition; i++)
    {
        cin>>trans[i];
        cout<<trans[i]<<" ";
    }
    cout<<"\nHow many accepting states are there?\n";
    int accept;
    cin>>accept;
    cout<<accept;
    cout<<"\nWhat are the accepting states?\n";

    for(int i=0; i<accept; i++)
    {
        cin>>acc[i];
        cout<<acc[i]<<" ";
    }
    int in=0;
    for(int i=0; i<state; i++)
    {
        int f=0;
        for(int j=0; j<accept; j++)
        {
            if(states[i]==acc[j])
            {
                f=-1;
            }
        }
        if(f!=-1)
        {
            nonAcc[in]=states[i];
            in++;
        }
    }

    cout<<"\nNon-Accepting states:\n";

    for(int i=0; i<in; i++)
    {
        cout<<nonAcc[i]<<" ";
    }

    cout<<"\n\nInput the dfa table:\n\n";

    cout<<"States\t";

    for(int i=-1; i<state; i++)
    {
        if(i!=-1)
        {
            cout<<states[i]<<"\t";
        }
        for(int j=0; j<transition; j++)
        {
            if(i==-1)
            {
                cout<<trans[j]<<"\t";
            }
            else
            {
                cin>>dfa[i][j];
                cout<<dfa[i][j]<<"\t";
            }
        }
        if(i==-1) cout<<"\n---------------------------------";
        cout<<"\n";
    }

    tableFilling(state,transition,accept,in);

}

/*
8
A B C D E F G H
2
a b
1
C
B F
G C
A C
C G
H F
C G
G E
G C
*/