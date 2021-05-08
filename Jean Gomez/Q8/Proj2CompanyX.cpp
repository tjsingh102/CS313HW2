#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
// Company X generally processes orders based on a first come, first serve basis.
// Sometimes a client will ask for rush processing and will be awarded a number based on
// the urgency. If they pay extra they will receive a 3 priority, if they have a bulk order they
// will receive a 2 priority, and if they know someone in the company and ask for a favor
// they will receive the highest priority, a 1. Design a system that accepts orders from
// clients and processes these orders based on no priority or somewhere on the priority
// scale. Show how the system will work for random orders with a random processing time.

void ProcessOrder(int arr1[],int arr2[], int arr3[], int arrNo[] ) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    for(a = 0; a < 5; a++) {
        if (arr1[a] != 0)
        {
            cout<<"Priority order level 1 going out #"<<arr1[a]<<endl;
        }
        else{
            break;
        }
        
    }

    for(b = 0; b < 5; b++) {
        if (arr2[b] != 0) {
            cout<<"Priority order level 2 going out #"<<arr2[b]<<endl;
        }
        else{
            break;
        }
    } 

    for (c = 0; c < 5; c++) {
        if(arr3[c] != 0) {
            cout<<"Priority order level 3 going out #"<<arr3[c]<<endl;
        }
        else{ break; }
    }

    for( d = 0; d < 5; d++) {
        if(arrNo[d] != 0) {
            cout<<"No priority level delivery going out #"<<arrNo[d]<<endl;
        }
    }
    cout<<endl;
}

int main() {
    int num;
    int array1[5] = {0,0,0,0,0};
    int array2[5] {0,0,0,0,0};
    int array3[5] {0,0,0,0,0};
    int NoPriority[5] {0,0,0,0,0};
    srand(time(nullptr));
    cout<<"Company X will proccess a total of 5 orders. Enter priority number. 4 being the lowest and 1 being highest level priority \n";
    cout<<"Level-'4'-No priority\nLevel-'3'-priority\nLevel-'2'-priority\nLevel-'1'-priority\n";
    int a = 0;
    int b = 0;
    int c =0;
    int d = 0;

    for(int i = 0; i < 5; i++) {
        int OdrNum = rand() % 90000+ 10000;
        cout<<"\nPriority level for this order:\t";
        cin>>num; 

        // arrayOrders[i] = num;

        if(num == 1) {
            array1[a] = OdrNum;
            cout<<"Your order number is #"<<OdrNum<<endl;
            a++;
        }      
        else if (num == 2){
            array2[b] = OdrNum;
            cout<<"Your order number is #"<<OdrNum<<endl;
            b++;
        }
        else if (num == 3) {
            array3[c] = OdrNum;
            cout<<"Your order number is #"<<OdrNum<<endl;
            c++;
        }
        else {
            NoPriority[d] = OdrNum;
            cout<<"Your order number is #"<<OdrNum<<endl;
            d++;
        }  
    }
    cout<<endl;

    cout<<"\nDELIVERY ORDERS GOING FROM FIRST TO LAST\n";
    ProcessOrder(array1, array2, array3, NoPriority);
    
}