#include <iostream>
#include "CheckoutLine.cpp"
#include <string>

using namespace std;

int main(){

    CheckoutLine test1(15);
    char name = 'a';
    vector<string> output;
    for(int i=0;i<13;i++){
        string input_name(1,name);
        output.push_back(input_name);
        if (!test1.joinCheckoutLine(input_name,1,1)){
            cout<< "Joining process failed" << endl;
            return 0;
        }

        name= name+1;
    }

    for(int i=0;i<13;i++){
        string input_name(1,name);
        output.push_back(input_name);
        if (!test1.joinCheckoutLine(input_name,2,1)){
            cout<< "Joining process failed" << endl;
            return 0;
        }
        name= name+1;
    }
    bool array[10];
    string input_name(1,name);
    output.push_back(input_name);
    array[0]=test1.joinCheckoutLine(input_name,1,1);
    name= name+1;
    string input_name1(1,name);
    output.push_back(input_name1);
    array[1]=test1.joinCheckoutLine(input_name1,2,1);
    name= name+1;
    string input_name2(1,name);
    output.push_back(input_name2);
    array[2]=test1.joinCheckoutLine(input_name2,1,1);
    name= name+1;
    string input_name3(1,name);
    output.push_back(input_name3);
    array[3]=test1.joinCheckoutLine(input_name3,2,1);
    name= name+1;
    for(int i=0;i<4;i++){
        if(!array[i]){
            cout<< "Joining process failed" << endl;
            return 0;
        }
    }
   for(int i=0;i<13;i++){

        string input_name(1,name);
        if (test1.joinCheckoutLine(input_name,2,1) || test1.joinCheckoutLine(input_name,1,1)){
           cout<< "Joining process failed" << endl;
            return 0;
        }
    }
    test1.serveCheckoutLine(1);
    vector<string> a;
    a = test1.history(30);
    for(int i=0;i<30;i++){
        if(a[i] != output[i]){
            cout << "Serving System 1 failed" << endl;
            return 0;
        }
    }

    vector<string> output2;
    name = 'a';
    for(int i=0;i<10;i++){
        string input_name(1,name);
        output2.push_back(input_name);
        if (!test1.joinCheckoutLine(input_name,1,2)){
            cout<< "Joining process failed" << endl;
            return 0;
        }
        name= name+1;
        string input_name1(1,name);
        output2.push_back(input_name1);
        if(!test1.joinCheckoutLine(input_name1,2,2)){

            cout<< "Joining process failed" << endl;
            return 0;
        }
        name= name+1;
    }
     for(int i=0;i<5;i++){
        string input_name(1,name);
        output2.push_back(input_name);
        if (!test1.joinCheckoutLine(input_name,1,2)){
            cout<< "Joining process failed" << endl;
            return 0;
        }
        name= name+1;
    }
    for(int i=0;i<13;i++){
        string input_name(1,name);
        if (test1.joinCheckoutLine(input_name,1,2)){
            cout<< "Joining process failed" << endl;
            return 0;
        }
    }

    test1.serveCheckoutLine(2);
    vector<string> b;
    b = test1.history(25);
    for(int i=0;i<25;i++){
        if(b[i] != output2[i]){
           cout << "Serving System 2 failed" << endl;
           return 0;
        }
    }

    cout<< "Test passed" << endl;
    return 0;
}
