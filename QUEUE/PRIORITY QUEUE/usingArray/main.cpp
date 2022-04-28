#include<iostream>
#define N 20
using namespace std;
int Q[N],Pr[N];
int r = -1,f = -1;
void enqueue(int data,int p){
    int i;
    if((f==0)&&(r==N-1)){
        cout<<"Queue is full";
    }
    else{
        if(f==-1){
            f = r = 0;
            Q[r] = data;
            Pr[r] = p;

        }
        else if(r == N-1){
            for(i=f;i<=r;i++) {
                Q[i-f] = Q[i];
                Pr[i-f] = Pr[i];
                r = r-f;
                f = 0;
                for(i = r;i>f;i--){
                    if(p>Pr[i]){
                        Q[i+1] = Q[i];
                        Pr[i+1] = Pr[i];
                    }
                    else
                        break;
                    Q[i+1] = data;
                    Pr[i+1] = p;
                    r++;
                }
            }
        }
        else{
            for(i = r; i>=f; i--){
                if(p>Pr[i]){
                    Q[i+1] = Q[i];
                    Pr[i+1] = Pr[i];
                }
                else{
                    break;
                }
            }
            Q[i+1] = data;
            Pr[i+1] = p;
            r++;
        }
    }

}
void print(){
    int i;
    for(i=f; i<=r; i++){
        cout<<"Element :  "<<Q[i]<<" Priority : "<<Pr[i]<<endl;
    }
}
int dequeue(){
    if(f == -1){
        cout<<"Queue is Empty";
    }
    else{
        cout<<"Element Deleted : "<<Q[f]<<" Priority : "<<Pr[f]<<endl;
        if(f==r){
            f = r = -1;
        }
        else{
            f++;
        }
    }
}
int main(){
    int opt,n,i,data,p;

    do{
        cout<<"\n              MENU                  "<<endl;
        cout<<"          1. Insert    "<<endl;
        cout<<"          2. Display "<<endl;
        cout<<"          3. Delete "<<endl;
        cout<<"          4. Quit    "<<endl;
        cout<<"Enter Your Choice:  "<<endl;
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"How many numbers do you want to insert ? "<<endl;
                cin>>n;

                i=0;
                while(i<n){
                    cout<<"Enter the "<<i+1<<" Element  "<<endl;
                    cin>>data;
                    cout<<" Enter the priority for the  "<<i+1<<" Element "<<endl;
                    cin>>p;
                    enqueue(data,p);
                    i++;
                }
                break;
            case 2:
                print();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                break;
            default:
                cout<<"Incorrect Choice"<<endl;

        }
    }while(opt!=0);
    return 0;
}