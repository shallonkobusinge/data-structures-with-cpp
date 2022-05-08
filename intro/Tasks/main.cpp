#include <iostream>
#include <stack>
#include <string>
using namespace std;


/*
 *
 * REVERSE A STRING WITHOUT REVERSING AN INDIVIDUAL WORD
 *
 * */

void reverseWord(string &word){
   stack<string> reversed;
   int low=0, high=0;
   for(int i=0; i<word.length(); i++){
       if(word[i] == ' '){
           reversed.push(word.substr(low,high - low+1));
           low = high = i+1;
       }else{
           high = i;
       }
   }
    reversed.push(word.substr(low));
    word.clear();

    while (!reversed.empty()){
        word.append(reversed.top()).append(" ");
        reversed.pop();
    }
    word.erase(prev(word.end()));
}


int main() {
    string word;
    cout<<" Enter the word to reverse "<<endl;
    getline(cin,word);
//    reverse(word.begin(),word.end());
   reverseWord(word);
   cout<<" "<<word<<endl;

    return 0;
}
