
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Stop{
    string stopName;
    int price;
    string arrival;
    Stop *next;
}*head = NULL;
void createStop(Stop value[],int length){
    struct Stop *lastStop;
    head = new Stop;
    head->stopName = value[0].stopName;
    head->arrival = value[0].arrival;
    head->price = value[0].price;
    head->next = head;
    lastStop = head;
    struct Stop *temporaryStop;

    for(int i=1; i<length; i++){
        temporaryStop = new Stop;
        temporaryStop->stopName = value[i].stopName;
        temporaryStop->price = value[i].price;
        temporaryStop->arrival = value[i].arrival;
        temporaryStop->next = lastStop->next;
        lastStop->next= temporaryStop;
        lastStop = temporaryStop;

    }
}

void displayStops(Stop * startingStop){
    do{
        cout<<" Name :  "<<startingStop->stopName<<" Price :  "<<startingStop->price<<"  Arrival : "<<startingStop->arrival<<endl;
        startingStop = startingStop->next;
    } while (startingStop != head);
}

void insertAtTheBegginning(){
Stop * newStop = new Stop;
    if(newStop == NULL){
        cout<<" No enough memory for the new Node "<<endl;
    }
        newStop->stopName = "Mombasa";
        newStop->price = 200;
        newStop->arrival = "8:30 PM";
        newStop->next = head;
        Stop * tempStop = head;

    while (tempStop->next != head){
        tempStop = tempStop->next;
    }
    tempStop->next = newStop;
    head = newStop;

};
void insertAtTheEnd(){
    Stop * newStop = new Stop;
    if(newStop == NULL){
        cout<<" No enough memory for your new Stop";
    }
    newStop->stopName = "Johannseburg";
    newStop->price = 300;
    newStop->arrival = "8:00 PM";
    newStop->next = head;
    Stop * tempStop = head;
    while (tempStop->next != head){
        tempStop = tempStop->next;
    }
    tempStop->next = newStop;

}
void deleteAtTheHead(){
    Stop * tempStop = new Stop;
    if(tempStop == NULL){
        cout<<" No enough memory for your new Stop";
    }
    tempStop = head;
    while (tempStop->next !=head){
        tempStop = tempStop->next;
    }

    tempStop->next = head->next;
    delete head;
    head = tempStop->next;
}
void deleteAtTheEnd(){
    Stop * tempStop,* previousStop = new Stop;
    tempStop = head;
    while (tempStop->next != head){
        previousStop = tempStop;
        tempStop = tempStop->next;
    }
    previousStop->next = tempStop->next;
    delete tempStop;
}
int main(){
    Stop flights[5] = {
            {"Kigali", 150, "7:30 PM"},
            {"Entebbe", 500, "8:15 PM"},
            {"Bruxelles",800, "5:45 AM"},
            {"Newark", 1400, "4:00 PM"},
            {"Logan", 1600, "5:00 PM"}
    };
    createStop(flights,5);
    displayStops(head);
    insertAtTheBegginning();
    cout<<endl;
    cout << " AFTER INSERTING AT THE BEGINNING OF THE LIST  "<<endl<<endl;
    displayStops(head);
    insertAtTheEnd();
    cout<<endl;
    cout <<"  AFTER INSERTING AT THE END OF THE LIST "<<endl;
    displayStops(head);
    cout<<endl;
    deleteAtTheHead();
    cout<<endl;
    cout<<" AFTER DELETING AT THE HEAD OF THE LIST "<<endl;
    displayStops(head);
    cout<<endl;
    deleteAtTheEnd();
    cout<<endl;
    cout<<"  AFTER DELETING AT THE END OF THE LIST "<<endl;
    displayStops(head);
    cout<<endl;

    return 0;
}
