#include<bits/stdc++.h>
using namespace std;

char alpha[4]= {'x','y','z','t'};

int findState(char ch)
{
    int in;
    for(int i=0; i<4; i++)
    {
        if(ch==alpha[i])
        {
            in=i;
        }
    }

    return in;

}

int main()
{

    printf("Enter String:\n");
    char s[2000];
    scanf("%s",s);

//NFA table

    char state[4][2][5]= {{"x","xy"},{"\0","z"},{"\0","t"},{"t","t"}};
    printf("\nNFA Transition Table:\n\n");
    printf("---------------------------\n");
    printf("State\t0\t1\n");
    printf("---------------------------\n");

    for(int i=0; i<4; i++)
    {
        printf("%c->\t",alpha[i]);
        for(int j=0; j<2; j++)
        {
            if(state[i][j][0]=='\0')  printf("null\t");
            else printf("%s\t",state[i][j]);
        }
        printf("\n-------------------------\n");
    }
    char start='x',acc='t';
    printf("Starting state->x\n");
    printf("Accepting state->t\n");

    int flag=0;

    for(int i=0; s[i]!='\0';)
    {
        if(s[i]=='0'&& flag==0)
        {
            printf("(x,0)->x\n");
            i++;
        }
        else if(s[i]=='0'&& flag==1)
        {
            printf("(t,0)->t\n");
            printf("String Accepted!\n");
            i++;
        }
        else if(s[i]=='1'&& flag==1)
        {
            printf("(t,1)->t\n");
            printf("String Accepted!\n");
            i++;
        }
        else if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='1')
        {
            flag=1;
            printf("(x,1)->y\n(y,1)->z\n(z,1)->t\n");
            i=i+3;
            printf("String Accepted!\n");
        }
        else if(s[i]=='1'&& flag==0)
        {
            printf("(x,1)->x\n");
            i++;
        }
        else i++;
    }

    if(flag==0) printf("String is not Accepted!\n");

//NFA to DFA

    vector<set<char>>v;
    set<char>init;
    init.insert(start);
    v.push_back(init);
    printf("\nCorresponding DFA: \n");
    printf("--------------------------------\n");

    for(int i=0; i<1000; i++)
    {
        set<char>temp1;
        set<char>temp2;

        if(i<v.size())
        {
            init=v[i];
            for(auto l:init)
            {
                for(int g=0; state[findState(l)][0][g]; g++)
                {
                    temp1.insert(state[findState(l)][0][g]);
                }
                for(int g=0; state[findState(l)][1][g]; g++)
                {
                    temp2.insert(state[findState(l)][1][g]);
                }
            }
            printf("(");
            for(auto ch:init)
            {
                printf("%c",ch);
            }
            printf(",0)-->");
            for(auto ch:temp1)
            {
                printf("%c",ch);
            }
            printf("\n");
            printf("(");
            for(auto ch:init)
            {
                printf("%c",ch);
            }
            printf(",1)-->");
            for(auto ch:temp2)
            {
                printf("%c",ch);
            }
            printf("\n");

            int fl=0;

            for(auto st:v)
            {
                if(temp1==st) fl=1;
            }
            if(fl==0) v.push_back(temp1);

            fl=0;

            for(auto b:v)
            {
                if(temp2==b) fl=1;
            }
            if(fl==0) v.push_back(temp2);

        }
    }
}