/*  Assignment 7 :
    Implement a browser history management system using a stack data structure to track the user's 
    browsing history. The system should support the following functionalities:
    a). Add visited page
    b). Navigate back
    c). View current page
    d). Check if history is empty or not
    Assume no upper bound on number of pages visited

    PRN No - 123B1B186
    Name - Prathmesh Marathe
    class  & Div - SY BTech & C */

#include <iostream>
using namespace std;

class History{
    int top1 = -1, top2 = -1;
    string stk1[100], stk2[100];
    public :
    void addPage(string str);
    void navigateBack();
    void currPage();
    bool isEmpty();
    void showHistory();
};

void History :: addPage(string str){
    top1++;
    stk1[top1] = str;
}

void History :: navigateBack(){
    if(!isEmpty()){
        if(top1 >=1){
            top2++;
            stk2[top2] = stk1[top1];
            top1--;
            cout << stk1[top1] << endl;
        }
        else
            cout << "Oops!...Page Not Found..." << endl;
    }
}

void History :: currPage(){
    if(!isEmpty())
        cout << stk1[top1] << endl;
}

bool History :: isEmpty(){
   if(top1 == -1){
    cout << "Oops!...No History Found..." << endl;
    return true;
   }
   cout << "History is Not Empty...";
   return false;
}

void History :: showHistory(){
    cout << endl;
    if(!isEmpty()){
        if(top2 >= 0){
            for(int j = 0; j <= top2; j++){
                cout << stk2[j] << endl;
            }
        }

        for(int i = top1; i >= 0; i--){
            cout << stk1[i] << endl;
        }
    }
}

int main(){
    History h;
    bool choice = true;
    string str;
    int ch;
    do{ 
        cout << "1. Add visited page\n2.Navigate back\n3.View current page\n4.Check if history is empty or not\n5.Show Browser History\n6.Exit\nEnter Choice :  ";
        cin >> ch;
        switch(ch){
            case 1 :
            cin >> str;
            h.addPage(str);
            break;

            case 2 :
            h.navigateBack();
            break;

            case 3 :
            h.currPage();
            break;

            case 4 :
            h.isEmpty();
            break;

            case 5 :
            h.showHistory();
            break;

            case 6 :
            choice = false;
            break;
        }
        cout << endl;
    }while(choice == true);
    return 0;
}