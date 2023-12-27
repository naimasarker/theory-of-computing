#include <bits/stdc++.h>
using namespace std;

// char input_alphabet[] = {'0', '1'};
// char stack_alphabet[] = {'0', '1', 'z'};
// char pda_states[] = {'A', 'B', 'C'};
// char starting_state = 'A';
// char final_state = 'C';

stack<char> pda_stack;
string input_string;

void clear_pda_stack(){
    while(pda_stack.top() !='Z'){
        pda_stack.pop();
    }
}

void print_pda_stack(){
    stack<int> temp;
    while (pda_stack.empty() == false)
    {
        temp.push(pda_stack.top());
        pda_stack.pop();
    }

    while (temp.empty() == false)
    {
        char t = temp.top();
        cout << t << " ";
        temp.pop();

        pda_stack.push(t);
    }
}

int main(void){
    cout<<"Enter a string: ";
    cin>>input_string;
    cout<<endl;

    pda_stack.push('Z');
    int input_length = input_string.length();
    int flag = 0;
    int accepting_index;

    for(int middle = 0; middle<input_length; middle++){
        clear_pda_stack();
        int i;
        for(i=0; i<middle; i++){
            pda_stack.push(input_string[i]);
        }

        pda_stack.push(input_string[i]);

        i++;
        int j;
        for(j = i;j<input_length; j++){
            char c = input_string[j];
            if(pda_stack.top()==c){
                pda_stack.pop();
            }
            else
                break;
        }

        if(pda_stack.top()=='Z' && j==input_length){
            flag = 1;
            accepting_index = middle;
        }
    }
    cout<<accepting_index<<"\n";
    // Accepted or Rejected?
    if(flag == 1){
        cout<<"\nAccepted!"<<endl;
        // Now print
        cout<<"From  Using  To\t Current Stack\n";
        cout<<"----- -----  --\t -------------\n";
        clear_pda_stack();
        for(int i=0; i<accepting_index; i++){
            cout<<" A >>> "<<input_string[i]<<" >>> A";
            pda_stack.push(input_string[i]);
            cout<<"\t Current stack :";
            print_pda_stack();
            cout<<endl;
        }

        cout<<" A >>> "<<input_string[accepting_index]<<" >>> B";
        pda_stack.push(input_string[accepting_index]);
        cout<<"\t Current stack :";
        print_pda_stack();
        cout<<endl;

        for(int j=accepting_index+1; j<input_length; j++){
            cout<<" B >>> "<<input_string[j]<<" >>> B";
            cout<<"\t Current stack :";
            pda_stack.pop();
            print_pda_stack();
            cout<<endl;
        }
    }
    else
        cout<<"\nRejected!\n";

    return 0;
}