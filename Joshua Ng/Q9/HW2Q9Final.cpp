#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

//made a plane class for plane objects to use 
class plane{
    public: 
        int t, direction; //t represents time
        string n = ""; //n will be the name
        plane(int ti, string name){ //when instantiating the object we will manually input the time and name of plane
            n = name;
            t = ti;
            direction = rand() % 10; //direction will be from 0-9 to determine the percentile chances of each runway
            cout << direction << endl;
        };  

        void print(){
            cout << n; //will print the name of the plane
        }
};

int main(){
    //initialize the 4 different runway queues
    queue<plane> northRunway, eastRunway, southRunway, westRunway; 

    //instantiate the plane objects with their time and name
    //did 10 objects just for testing
    plane p1(1, "Plane 1");
    plane p2(2, "Plane 2");
    plane p3(3, "Plane 3");
    plane p4(4, "Plane 4");
    plane p5(5, "Plane 5");
    plane p6(6, "Plane 6");
    plane p7(7, "Plane 7");
    plane p8(8, "Plane 8");
    plane p9(9, "Plane 9");
    plane p10(10, "Plane 10"); 
    cout << "created all planes\n";
   
    //vector to store the plane objects to make it easier to iterate and add to the queues
    vector<plane> v1; 
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);
    v1.push_back(p6);
    v1.push_back(p7);
    v1.push_back(p8);
    v1.push_back(p9);
    v1.push_back(p10);
    cout << "vector filled\n";

    //iterate through the vector holding the planes
    for (int i = 0; i < 10; i++){
        if (v1[i].direction <= 6){ //if the plane created has 0-6 from 0-9 (70% chance) for its direction 
            northRunway.push(v1[i]); //then they are added to the north queue
            cout << v1[i].t << " was pushed on to north\n";
        }
        else if (v1[i].direction == 7 || v1[i].direction == 8){ //if the plane generated a 7 or 8 (20% chance) 
            if (northRunway.size() > eastRunway.size()){
                eastRunway.push(v1[i]); //add to the east queue
                cout << v1[i].t << " was pushed on to east\n";
            }
            else{ //however if the east is fuller than the north
                northRunway.push(v1[i]); //then add the plane to the north queue
                cout << v1[i].t << " was pushed on to north\n";
            }
        }
        else if (v1[i].direction == 9){ //if the number generated for the directionis 9 (10%) chance
            if (eastRunway.size() > southRunway.size()){ //if east is not the smallest
                if (southRunway.size() > westRunway.size()){ 
                    westRunway.push(v1[i]); //push on to west if the south is fuller
                    cout << v1[i].t << " was pushed on to west\n";
                }
                else{
                    southRunway.push(v1[i]); //push to the south if the west is fuller
                    cout << v1[i].t << " was pushed on to south\n";
                }
            }
            else {
                eastRunway.push(v1[i]); //add to the east only if it is the smallest queue
                cout << v1[i].t << " was pushed on to east\n";
            }
        }
    }

    //print each runway
    cout << "North Runway: \n";
    while (northRunway.size()){ //traverse through the queue as long as there are elements
        northRunway.front().print(); //call print function for the front element
        cout << endl;
        northRunway.pop(); //get rid of the first element
    }

    cout << "East Runway: \n";
    while (eastRunway.size()){
        eastRunway.front().print();
        cout << endl;
        eastRunway.pop();
    }

    cout << "South Runway: \n";
    while (southRunway.size()){
        southRunway.front().print();
        cout << endl;
        southRunway.pop();
    }

    cout << "West Runway: \n";
    while (westRunway.size()){
        westRunway.front().print();
        cout << endl;
        westRunway.pop();
    }
    
    //print according to time
    cout<< "Departure Schedule: \n";
    for (int i = 0; i < 10; i++){ //iterate through the vector that contains the planes with their times
        v1[i].print(); //call print function for the element
        cout << " leaves at " <<v1[i].t << " o' clock "<<endl;
    }

    return 0;

}