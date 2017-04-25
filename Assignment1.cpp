/*Maria Sanchez
 * 1/30/17
 *
 *
 *
 */

#include<iostream>
#include<cctype>


using namespace std;


// Function Declarations
void money(int input);
void age(int input);
void digits(int input);
void armstrong(int input);
void factorial(int input);
void hailstoneSequence(int input);
void prime(int input);
void numToWord(int var);




int main()
{
    
    bool keepRunning = true;
    
    do{
        int input; // Number used for manipulation
        char response; // char used to determine whether or not to run again
        
        cout << "Enter a positive integer > 0 and < 200 --->   ";
        cin >> input;
        
        if( input > 199 || input < 1)
        {
            cout << endl << "ERROR *** Must be between > 0 and < 200" << endl;
            cout << "Would you like to try another number?" << endl;
            cout << "Enter y || Y for yes or n || N for no --->   ";
            cin >> response;
            
            // Response check (MakeUpper?)
            if(response == 'n' || response == 'N'){
                keepRunning = false;
            }
            
        }
        
        if(keepRunning == true){
            cout << endl << "Entering Money!!" << endl;
            money(input);
            cout << endl << "Entering Age!!" << endl;
            age(input);
            cout << endl << "Entering DIGITS!!" << endl;
            digits(input);
            cout << endl << "Entering armstrong!!" << endl;
            armstrong(input);
            cout << endl << "Entering factorial!!" << endl;
            factorial(input);
            cout << endl << "Entering prime!!" << endl;
            prime(input);
            cout << "\nThe sequence of hailstone starting at " << input << " is" << endl;
            cout << input << "   ";
            hailstoneSequence(input);
        }
        
        cout << "\nWould you like to try another number?" << endl;
        cout << "Enter y || Y for yes or n || N for no --->   ";
        cin >> response;
        
        // Response check (MakeUpper?)
        if(response == 'n' || response == 'N'){
            keepRunning = false;
        }
        
    } while(keepRunning);
    
    
}

void money(int num){
    int temp = num * 100; // prevent manipulating input and provide easier calculations for cents
    
    cout << "$" << num << " is equivalent to:" << endl << endl;
    // QUARTERS
    int q = temp / 25;
    cout << q << " Quarter/s" << endl;
    // DIMES
    int d = temp / 10;
    cout << d << " Dime/s" << endl;
    // NICKELS
    int n = temp / 5;
    cout << n << " Nickel/s" << endl;
    // PENNIES
    int p = temp / 1;
    cout << p << " Penny/s" << endl;
}

void age(int num){
    int temp = num;
    
    cout << "Assuming that you are " << num << " years old, then " << endl << endl;
    
    // MONTHS
    int month = num * 12;
    cout << "You are " << month << " months old" << endl;
    // DAYS
    int day = num * 365;
    cout << "You are " << day << " days old" << endl;
    // HOURS
    long hour = day * 24;
    cout << "You are " << hour << " hours old" << endl;
    // MINUTES
    long minute = hour * 60;
    cout << "You are " << minute << " minutes old" << endl;
    // SECONDS
    long second = minute * 60;
    cout << "You are " << second << " seconds old" << endl;
    
}

void digits(int num){
    int temp = num;
    
    if(temp < 10){
        
        cout << num << endl;
        numToWord(num);
    }
    if(temp < 100 && temp > 9){
        int ones = num % 10;
        temp = temp - ones;
        int tens = temp / 10;
        
        cout << tens <<  "       " << ones << endl;
        numToWord(tens);
        numToWord(ones);
    }
    if(temp > 99){
        int ones = num % 10;
        temp = temp - ones;
        int tens = (temp / 10) % 10;
        temp = temp - tens * 10;
        int hundreds = 1;
        
        
        cout << hundreds << "       " << tens << "       " << ones << endl;
        numToWord(hundreds);
        numToWord(tens);
        numToWord(ones);
    }
    
}

void numToWord(int var){
    // Prints Output for digits function
    switch(var){
        case 0 :
            cout << "Zero   ";
            break;
        case 1 :
            cout << "One    ";
            break;
        case 2 :
            cout << "Two    ";
            break;
        case 3 :
            cout << "Three  ";
            break;
        case 4 :
            cout << "Four   ";
            break;
        case 5 :
            cout << "Five   ";
            break;
        case 6 :
            cout << "Six    ";
            break;
        case 7 :
            cout << "Seven  ";
            break;
        case 8:
            cout << "Eight  ";
            break;
        case 9 :
            cout << "Nine   ";
            break;
        default :
            cout << "Something is Broken";
    }
}

void armstrong(int input)
{
    int sum, temp, a;
    a = input;
    sum = 0;
    while (input!= 0)
    {
        temp = input %10;
        sum = sum + temp * temp * temp;
        input = input /10;
    }
    
    if(sum == a)
    {
        cout<< endl;
        cout<< a << " " << "is an Armstrong Number" << endl;
    }
    else
    {
        cout<< a << " " << "is NOT an Armstrong Number" << endl;
    }
    
}

void factorial(int num){
    long long total = 1;
    
    for(int i = num;i > 0; i--){
        total = total * i;
    }
    
    cout << "Factorial of " << num << " = " << total << endl << endl;
}

void prime (int input)
{
    int temp = 0;
    for (int i = 2; i < input; i++)
    {
        if (input % i == 0)
         	  temp = 1;
    }
    
    if (temp == 0)
    {
        cout<< input << "is a prime number" <<endl;
    }
    
    else
    {
        cout<< input << " " << "is not a prime number" <<endl;
    }
    cout<< endl;
    cout<<"\nThe prime numbers between 1 and "<< input <<" is:";
    
    for (int j = 2; j< input; j++)
    {
        temp = 0;
        for (int i = 2; i < j; i++)
        {
            if(j % i == 0)
                temp = 1;
        }
        
        if(temp == 0)
        {
            cout<<j<<" is a prime number" <<endl;
        }
        
    }
}


void hailstoneSequence(int num){
    
    
    if(num != 1){
        if(num % 2 == 0){
            num = num / 2;
            if(num == 1)
                cout << num << endl;
            else{
                cout << num << "    ";
                // RECURSIVE CALL
                hailstoneSequence(num);
            }
        }
        else{
            num = (num * 3) + 1;
            cout << num << "    ";
            // RECURSIVE CALL
            hailstoneSequence(num);
        }
    }
    
}
