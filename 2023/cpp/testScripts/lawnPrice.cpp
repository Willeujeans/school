#include <iostream>     //library for configuring Object Oriented style of programming
using namespace std;    //using standard names in library

int main()
{
    //INITIALIZING VARIABLES
    float lawnArea;
    int fertilizingApplications; 
    int treesPlanted;
    float costMowing;
    float costFertilizingApplications;
    float costTreesPlanted;
    float totalCost;

    //TAKING INPUT
    cout << "ENTER Area of Lawn: " <<endl;
    cin >> lawnArea; 
    cout << "ENTER Number of Fertilizing Applications: " <<endl;
    cin >> fertilizingApplications; 
    cout << "ENTER Number of Trees to be Planted: " <<endl;
    cin >> treesPlanted; 

   //CALCULATING VALUES
    costMowing = 35.00 * ceil(lawnArea/5000);  // we want to round up after division 
    costFertilizingApplications = fertilizingApplications* 30.00;
    costTreesPlanted = treesPlanted* 50.00;
    totalCost = costMowing+costFertilizingApplications+costTreesPlanted;

    //PRINTING RESULT
    cout << "Mowing Cost: " << costMowing  //console out, to print to console
         <<"Fertilizing Cost: "<< costFertilizingApplications
         <<"Tree Planting Cost: "<< costTreesPlanted
         <<"Total Bill: " << totalCost
         <<endl;
    return 0;	//The function requires something to get returned so I return 0
}
