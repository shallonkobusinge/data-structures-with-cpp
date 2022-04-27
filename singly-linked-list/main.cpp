#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Stop  {
    string stopName;
    float price;
    string arrival;
    Stop *next;
}*initial = NULL, *secondInitial ;

void createStop(Stop value[],int length){
    struct Stop *lastStop;
    initial = new Stop;
    initial->stopName = value[0].stopName;
    initial->arrival = value[0].arrival;
    initial->price = value[0].price;
    initial->next = NULL;
    lastStop = initial;
    struct Stop *temporaryStop;

    for(int i=1; i<length; i++){
        temporaryStop = new Stop;
        temporaryStop->stopName = value[i].stopName;
        temporaryStop->price = value[i].price;
        temporaryStop->arrival = value[i].arrival;
        temporaryStop->next = NULL;
        lastStop->next= temporaryStop;
        lastStop = temporaryStop;
    }
}

void createdSecondStop(Stop value[],int length){
    struct Stop *lastStop;
    secondInitial = new Stop;
    secondInitial->stopName = value[0].stopName;
    secondInitial->arrival = value[0].arrival;
    secondInitial->price = value[0].price;
    secondInitial->next = NULL;
    lastStop = secondInitial;
    struct Stop *temporaryStop;

    for(int i=1; i<length; i++){
        temporaryStop = new Stop;
        temporaryStop->stopName = value[i].stopName;
        temporaryStop->price = value[i].price;
        temporaryStop->arrival = value[i].arrival;
        temporaryStop->next = NULL;
        lastStop->next= temporaryStop;
        lastStop = temporaryStop;
    }
}

void printStop(Stop *startPoint){
    while(startPoint !=NULL){
        cout<<"     Name :  "<<startPoint->stopName<<"    Arrival : "<<startPoint->arrival<<"     Price : "<<startPoint->price<<endl;
        startPoint = startPoint->next;
    }
}



Stop * searchStop(Stop *pointHold, float priceKey){
    while(pointHold != NULL){
        if( pointHold->price == priceKey){
            cout<< " Successful Search !  "<<"  on  "<<pointHold->stopName<<" Stop  which has the price of : "<<pointHold->price<<endl;
            return pointHold;
        }
        pointHold = pointHold->next;
    }
}
int countStops(Stop *initialStop){
    int counter = 1;
    while (initialStop->next != NULL ){
        counter++;
        initialStop = initialStop->next;
    }
    cout<<" There are :  "<<counter<<"  stops "<<endl;
    return counter;
}
Stop * returnStopWithMaxPrice(Stop *initialStop){
    Stop * tempStop = new Stop;
    tempStop->price = 0;
    while (initialStop != NULL){
        if(initialStop->price > tempStop->price){
            tempStop = initialStop;
        }
        initialStop = initialStop->next;
    }
    cout  << " The Stop with max price is :  "<<tempStop->stopName<<" and the price is : "<<tempStop->price<<endl;
    return tempStop;

}
Stop * insertAtTheBegginning(Stop * startingStop){
    Stop * tempStop = new Stop;
    tempStop->stopName = "Amsterdam";
    tempStop->price = 400;
    tempStop->arrival = "6:30 PM";
    tempStop->next = startingStop;
    startingStop = tempStop;
    cout<<tempStop->stopName<<"  INSERTED AT THE BEGINNING  "<<endl<<endl;
    cout<<"  AFTER INSERTING AT THE BEGINNING     "<<endl;
    printStop(startingStop);
    cout<<endl;
    return tempStop;

}
Stop * insertAtTheEnd(Stop * startingPoint){
    Stop * newStop = new Stop;
    newStop->stopName = "Boston";
    newStop->price = 300;
    newStop->arrival = "6:00 PM";
    newStop->next = NULL;
    Stop * tempStop = new Stop;
    tempStop = startingPoint;
    while (tempStop->next != NULL){
        tempStop = tempStop->next;
    }
    tempStop->next = newStop;
    cout<<newStop->stopName<<"  INSERTED AT THE END  "<<endl<<endl;
    cout<<"  AFTER INSERTING AT THE END     "<<endl;
    printStop(startingPoint);
    cout<<endl;
    return newStop;
}
Stop * insertInTheMiddle(Stop * startingStop, int searchPrice){
    if(startingStop == NULL){
        cout<<" The list is empty  "<<endl;
        return nullptr;
    }
    Stop * newStop = new Stop;
    newStop->stopName = "Denver";
    newStop->price = 350;
    newStop->arrival = "3:00 PM";
    newStop->next = NULL;
    Stop * tempStop = new Stop;
    Stop * previousStop = new Stop;
    tempStop= startingStop;

    while(previousStop->price != searchPrice){
        previousStop = tempStop;
        tempStop = tempStop->next;
    }
    previousStop->next = newStop;
    newStop->next = tempStop;
    cout<<newStop->stopName<<"  INSERTED IN THE MIDDLE  "<<endl<<endl;
    cout<<" AFTER INSERTING IN THE MIDDLE     "<<endl;
    printStop(startingStop);
    cout<<endl;
    return newStop;


}
void deletingAtTheBeggining(Stop * startingStop){
    Stop * tempStop = startingStop;
    startingStop = startingStop->next;
    tempStop->next = NULL;
    cout<<tempStop->stopName<<"  DELETED AT THE BEGINNING  "<<endl;
    delete tempStop;

    cout <<endl;
    cout<<"   AFTER DELETING AT THE BEGINNING     "<<endl;
    printStop(startingStop);
    cout<<endl;
//    free(tempStop);
}
void deletingFromTheEnd(Stop * startingStop){
    Stop * tempStop, *previousStop = new Stop;
    tempStop = startingStop;
    while(tempStop->next != NULL){
        previousStop =tempStop;
        tempStop = tempStop->next;
    }
    previousStop->next = NULL;
    cout<<tempStop->stopName<<"  DELETED AT THE END   "<<endl;
    delete tempStop;
    cout<<endl;
    cout<<"   AFTER DELETING AT THE END     "<<endl;
    printStop(startingStop);
    cout<<endl;

}
void  deleteInTheMiddle(Stop * startingStop, int searchPrice){
    while (startingStop == NULL){
        cout<<" The node list is empty ";
    }
    Stop * tempStop, *previousStop = new Stop;
    tempStop = startingStop;
    while(previousStop->price != searchPrice){
        previousStop = tempStop;
        tempStop = tempStop->next;
    }
    previousStop->next = tempStop->next;
    cout<<tempStop->stopName<<"  DELETED IN THE MIDDLE  "<<endl;
    delete tempStop;

    cout<<endl;
    cout<<"   AFTER DELETING IN THE MIDDLE  "<<endl;
    printStop(startingStop);
    cout<<endl;
}
void concatenate(Stop * startingStop, Stop * secondStop){
    if (startingStop == NULL || secondStop == NULL){
        cout<<"  The node list is empty  "<<endl;
        return;
    }

    Stop * tempStop;
    tempStop = startingStop;
    while(tempStop->next != NULL){
        tempStop = tempStop->next;
    }
    tempStop->next = secondStop;
    cout<<endl;
    cout<<"   AFTER CONCATENATING "<<endl;
    printStop(startingStop);
    cout<<endl;
}
int main(){
    Stop flights[5] = {
            {"Kigali", 150, "7:30 PM"},
            {"Entebbe", 500, "8:15 PM"},
            {"Bruxelles",800, "5:45 AM"},
            {"Newark", 1400, "4:00 PM"},
            {"Logan", 1600, "5:00 PM"}
    };
    Stop secondFlight[5] = {
            {"Bruxelles", 150, "7:30 PM"},
            {"Entebbe", 500, "8:15 PM"},
            {"Kigali",800, "5:45 AM"},
            {"Newark", 1400, "4:00 PM"},
            {"Logan", 1600, "5:00 PM"}
    };
    createdSecondStop(secondFlight, 5);
    createStop(flights,5);
//
//
//    insertAtTheBegginning(initial);
//    insertAtTheEnd(initial);
//    insertInTheMiddle(initial,800);
//    searchStop(initial,800);
//    deletingAtTheBeggining(initial);
//    int numberOfStops = countStops(initial);
//

//    deletingFromTheEnd(initial);
//    deleteInTheMiddle(initial,800);
//    concatenate(initial, secondInitial);

    printStop(initial);

    string toContinue;
    cout<<endl<<endl;
    do {


        cout<<" 1. Insert a stop at the beginning           "<<endl;
        cout<<" 2. Insert a stop at the End                  "<<endl;
        cout<<" 3. Insert a stop in the middle               "<<endl;
        cout<<" 4. Search a stop with a 800 price             "<<endl;
        cout<<" 5. Get A stop with maximum price              "<<endl;
        cout<<" 6. Number of stops                            "<<endl;
        cout<<" 7. Delete A stop at the beginning             "<<endl;
        cout<<" 8. Delete from the End                        "<<endl;
        cout<<" 9. Delete in the middle                       "<<endl;
        cout<<" 10. Concatenate first stop with the second    "<<endl;

        int choice;
        cout<<"Choice : ";
        cin>>choice;
        cout<<endl;
        switch (choice) {
            case 1:
                insertAtTheBegginning(initial);
                break;
            case 2:
                insertAtTheEnd(initial);
                break;
            case 3:
                insertInTheMiddle(initial,800);
                break;
            case 4:
                searchStop(initial,800);
                break;
            case 5:
                returnStopWithMaxPrice(initial);
                break;
            case 6:
                countStops(initial);
                break;
            case 7:
                deletingAtTheBeggining(initial);
                break;
            case 8:
                deletingFromTheEnd(initial);
                break;
            case 9:
                deleteInTheMiddle(initial,800);
                break;
            case 10:
                concatenate(initial, secondInitial);
                break;
            default:
                cout<<"Invalid choice "<<endl;
        }
        cout<<"Do you want to continue ? Y/N "<<endl;
        cin>>toContinue;
    } while (toContinue=="y" || toContinue=="y");


    return 0;
}
