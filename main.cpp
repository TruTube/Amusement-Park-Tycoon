#include <iostream>
#include <string>
#include <vector>

class amusement_park {

public: 

//Variables:
  //money:
    int *money;
    int daily_profit;
    int maintenance_cost;

  //number of:
    int *num_of_visitors;
    int num_of_employees; 
    int num_of_attractions;
    
//Functions:


};

//Random function:
//   // int random(int lo, int hi) {
//   //   thread_local std::random_device rd;
//   //   thread_local std::mt19937 gen(rd());
//   //   std::uniform_int_distribution<int> dis(lo, hi);
//   //   return dis(gen); //don't know how this works, someone gave it to me
// }

int main(){
  //variables:
    //input:
      int userinput;

    //money:
      int money = 500;
  
    //other:
      std::string amusement_park_name;
      int num_of_visitors = 0;
      std::vector<std::string> attractions;
      int *values[5];
  
  //initialization
    amusement_park ap;
    ap.money = &money;
    ap.num_of_visitors = &num_of_visitors;
  
  //Startup screen:
  std::cout << "Welcome to Amusement Park Tycoon\n\nTo start, enter the name of the amusement park\n";
  std::cin >> amusement_park_name; //Taking name for park
  system("clear");
  
  //Pre-Menu:
  std::cout << "Welcome to " << amusement_park_name;
  std::cout << "\nYou have $" << money; //Showing amount of money
  std::cout << "\nThere are " << num_of_visitors << " visitors\n"; //Showing number of visitors
  
  //Menu:
  std::cout << "What do you want to do?\n";
  std::cout << " 1. Add Attraction\n";
  std::cout << " 2. Hire Employees\n";
  std::cout << " 3. Next Day\n";
  std::cout << " 4. Show Stats\n";
  std::cout << " 5. Show Park\n";
  std::cout << " 6. Help\n";
  std::cin >> userinput;

  //Choices:
  switch (userinput){
    case 1: //Add attraction
    break;

    case 2: //Hire employees
    break; 

    case 3: //Next day
    break;

    case 4: //Show stats
    break;

    case 5: //Show park
    break;

    case 6: //Help
    break;
  }
}