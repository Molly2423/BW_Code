//
//  main.cpp
//  Simich_BW_Code
//
//  Created by Molly Simich on 4/27/21.
//
//  Split 10 stocks among 3 accounts fairly (given variables number of accounts, number of stocks, and last account)

#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    //GIVEN Variables
    double accountNum=3; // number of accounts
    double stockNum=10; //number of stocks
    int lastAccount=0; //counter to track last account that got a higher stock percentage
    //Variables
    double division=0; //to keep decimal value of split stock
    int firstAccount=0; //to keep account number that is not getting the larger amount
    int secondAccount=0; //to keep the other account number that is not getting the larger amount
    
    std::cout << "Enter The Account Number That Received A Higher Percentage Previously: ";
    std::cin >> lastAccount; //input the account that received a lareger portion previously
    
    //if input is invalid get account number again
    if((std::cin.fail()) || lastAccount != 1 || lastAccount != 2 || lastAccount != 3)
    {
        std::cout << "Invalid Account Number\n";
        std::cout << "Please enter Account Number 1, 2, or 3\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cin >> lastAccount;
        
    }
    division = stockNum/accountNum; //stocks per account with decimal places
    //track which accounts get which amounts
    if(lastAccount==1)
    {
        firstAccount=1;
        lastAccount=2;
        secondAccount=3;
    }
    else if(lastAccount==2)
    {
        firstAccount=1;
        lastAccount=3;
        secondAccount=2;
    }
    else
    {
        firstAccount=2;
        lastAccount=1;
        secondAccount=3;
    }
    
    //output results
    std::cout << "\nAccount Number " << lastAccount << " receives " << std::fixed << std::setprecision(2) << stockNum-(division+division-0.01) << "\n\n";
    std::cout << "Account Number " << firstAccount << " receives " << std::fixed << std::setprecision(2) << division << "\n";
    std::cout << "Account Number " << secondAccount << " receives " << std::fixed << std::setprecision(2) << division << "\n";
    
    return 0;
}
