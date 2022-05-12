#include <iostream>
#include <string>
#include <vector>
#include <random>

class amusement_park {

public: 

//Variables:
  //money:
    int money = 500;
    int maintenance_cost = 0;
    int daily_employee_cost = 0;

  //number of:
    int num_of_visitors = 0;
    int num_of_employees = 0; 
    int num_of_attractions = 0;
    int num_of_visitors_upper;
    int num_of_visitors_lower;

  //other:
    std::vector<std::string> attractions;
    int attraction_visitor_increase = 0;
    std::string amusement_park_name;
    int day = 0;
    float employee_visitor_increase = 0;
    
//Functions:
  bool add_attractions(int attraction_added){
    if (attraction_added == 1 && money > 100){
      money -= 100;
      maintenance_cost += 25;
      attraction_visitor_increase += 5;
      attractions.push_back("RC");
      num_of_attractions += 1;
      return true;
    }
    else{
      return false;
    }
    if (attraction_added == 2 && money > 85){
      money -= 85;
      maintenance_cost += 15;
      attraction_visitor_increase += 3;
      attractions.push_back("TD");
      num_of_attractions += 1;
      return true;
    }
    else{
      return false;
    }
    if (attraction_added == 3 && money > 80){
      money -= 80;
      maintenance_cost += 3;
      attraction_visitor_increase += 2;
      attractions.push_back("ME");
      num_of_attractions += 1;
      return true;
    }
    else{
      return false;
    }
  }

  bool hire_employees(int num_of_hires){
    if (money > num_of_hires * 25){
      money -= num_of_hires * 25;
      maintenance_cost -= num_of_hires*4;
      daily_employee_cost += 3 * num_of_hires;
      employee_visitor_increase += 0.05 * num_of_hires;
      num_of_employees += num_of_hires;
      return true;
    }
    else{
      return false;
    }
  }

  void next_day(){
    money -= maintenance_cost;
    money -= daily_employee_cost;
    num_of_visitors_upper = attraction_visitor_increase * (1.25 + employee_visitor_increase);
    num_of_visitors_lower = attraction_visitor_increase * 0.5;
    num_of_visitors = random(num_of_visitors_lower, num_of_visitors_upper);
    money += num_of_visitors * 5;
    day += 1;
  }


  //Random function:
  int random(int lo, int hi) {
    thread_local std::random_device rd;
    thread_local std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(lo, hi);
    return dis(gen); //don't know how this works, someone gave it to me

  
}
  
    

};


int main(){
  int save_num;
  //Save choice:
    std::cout << "What save are you using?\n";
    std::cout << " 1. Save 1\n";
    std::cout << " 2. Save 2\n";
    std::cout << " 3. Save 3\n";
    std::cin >> save_num;
    system("clear");
  //variables:
    //input:
      int user_input;
      int user_input_2;
  
    //other:
      std::vector<std::string> *attractions;
      bool enough_money;
  
  //initialization
    amusement_park ap_saves[3];
    int *money = &ap_saves[save_num].money;
    int *num_of_visitors = &ap_saves[save_num].num_of_visitors;
    int *num_of_employees = &ap_saves[save_num].num_of_employees;
    int *daily_employee_cost = &ap_saves[save_num].daily_employee_cost;
    int *maintenance_cost = &ap_saves[save_num].maintenance_cost;
    int *num_of_attractions = &ap_saves[save_num].num_of_attractions;
    attractions = &ap_saves[save_num].attractions;
    int *day = &ap_saves[save_num].day;
    std::string *amusement_park_name = &ap_saves[save_num].amusement_park_name;
    int *attraction_visitors_increase = &ap_saves[save_num].attraction_visitor_increase;
    float *employee_visitor_increase = &ap_saves[save_num].employee_visitor_increase;
    int *num_of_visitors_upper = &ap_saves[save_num].num_of_visitors_upper;
    int *num_of_visitors_lower = &ap_saves[save_num].num_of_visitors_lower;
  //Startup screen:
  std::cout << "Welcome to Amusement Park Tycoon\n\nTo start, enter the name of the amusement park\n";
  std::cin >> *amusement_park_name; //Taking name for park
  system("clear");
  
  //Pre-Menu:
  while (*money != 0){
    //resetting variables:
      enough_money = true;
      user_input = 0;
    
    std::cout << "Welcome to " << *amusement_park_name;
    std::cout << "\nYou have $" << *money;     //Showing amount of money
    std::cout << "\nThere are " << *num_of_visitors << " visitors"; //Showing number of visitors
    std::cout << "\nIt is day " << *day; //Day number
  
    //Menu:
      std::cout << "\n\nWhat do you want to do?\n";
      std::cout << " 1. Add Attraction\n";
      std::cout << " 2. Hire Employees\n";
      std::cout << " 3. Next Day\n";
      std::cout << " 4. Show Stats\n";
      std::cout << " 5. Show Park\n";
      std::cout << " 6. Help\n";
      std::cin >> user_input;

    //Choices:
      switch (user_input){
        case 1: //Add attraction
          system("clear");
          std::cout << "What attraction are you adding?\n 1. Roller Coaster - $100\n 2. Tower Drop - $85\n 3. Movie Experience - $80\n";
          std::cin >> user_input_2;
          enough_money = ap_saves[save_num].add_attractions(user_input_2);
          if (enough_money == false){
            std::cout << "Not enough money\n";
          }
          std::cout << "Press Enter";
          std::cin.ignore();
          std::cin.ignore();
          system("clear");
        break;

        case 2: //Hire employees
          system("clear");
          std::cout << "How many employees do you want to hire?\n";
          std::cin >> user_input_2;
          enough_money = ap_saves[save_num].hire_employees(user_input_2);
          if (enough_money == false){
            std::cout << "Not enough money\n";
          }
          std::cout << "Press Enter";
          std::cin.ignore();
          std::cin.ignore();
          system("clear");
        break; 

        case 3: //Next day
          ap_saves[save_num].next_day();
          system("clear");
        break;

        case 4: //Show stats
          system("clear");
          std::cout << "You have $" << *money;
          std::cout << "\nThere are " << *num_of_attractions << " attractions\n";
          std::cout << "The maintenance cost is $" << *maintenance_cost;
          std::cout << "\nThere are " << *num_of_employees << " employees\n";
          std::cout << "The daily employee cost is $" << *daily_employee_cost;
          std::cout << "\nThere are " << *num_of_visitors << " visitors\n";
          std::cout << "The visitor increase from attractions is " << *attraction_visitors_increase;
          std::cout << "\nThe visitor increase from employees is x" << *employee_visitor_increase;
          std::cout << "\nThe upper limit for the possible number of visitors is " << *num_of_visitors_upper;
          std::cout << "\nThe lower limit for the possible number of visitors is " << *num_of_visitors_lower;
          std::cout << "\n\nPress Enter to return";
          std::cin.ignore();
          std::cin.ignore();
          system("clear");
          
        break;

        case 5: //Show park
        break;

        case 6: //Help
        break;
      }
  }
}