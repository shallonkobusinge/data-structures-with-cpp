#include <iostream>

int main() {
    int scores[9] = {10,13,40,23,67,26,19,45,100};
    int k = 3, length=9, j=length-1;
    int item = 180;
    while(j>k){
        scores[j+1] = scores[j];
        j = j -1;

        scores[k] = item;
    }
    for(int i=0; i<=length; i++){
        std::cout<<" "<<scores[i]<<" ";
    }
        return 0;
}
