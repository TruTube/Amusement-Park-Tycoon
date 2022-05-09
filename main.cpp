#include <iostream>
#include <string>
#include <vector>

class amusement_park {

public: 

//Variables:
  //money:
    int money = 500;
    int daily_profit = 0;
    int maintenance_cost = 0;

  //number of:
    int num_of_visitors = 0;
    int num_of_employees = 0; 
    int num_of_attractions = 0;
    
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
int save_num;
std::cout << "What save are you using?\n Save 1\n Save 2\n Save 3\n";
std::cin >> save_num;
  //variables:
    //input:
      int userinput;
  
    //other:
      std::string amusement_park_name;
      std::vector<std::string> attractions;
      int *values[6];
  
  //initialization
    amusement_park ap_saves[3];
    values[0] = &ap_saves[save_num].money;
    values[1] = &ap_saves[save_num].num_of_visitors;
    values[2] = &ap_saves[save_num].num_of_employees;
    values[3] = &ap_saves[save_num].daily_profit;
    values[4] = &ap_saves[save_num].maintenance_cost;
    values[5] = &ap_saves[save_num].num_of_attractions;
  
  //Startup screen:
  std::cout << "Welcome to Amusement Park Tycoon\n\nTo start, enter the name of the amusement park\n";
  std::cin >> amusement_park_name; //Taking name for park
  system("clear");
  
  //Pre-Menu:
  std::cout << "Welcome to " << amusement_park_name;
  std::cout << "\nYou have $" << *values[0]; //Showing amount of money
  std::cout << "\nThere are " << *values[1] << " visitors\n"; //Showing number of visitors
  
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