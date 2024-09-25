/*  Assignment 1 :
    Consider a student database of SY COMP class (at least 15 records). Database contains different 
    fields of every student like Roll No, Name and SGPA
    a). Design a roll call list, arrange list of students according to roll numbers in ascending order 
    using Insertion Sort
    b). Arrange list of students alphabetically using shell sort 
    
    PRN No - 123B1B186
    Name - Prathmesh Marathe
    class  & Div - SY BTech & C */
 
#include <iostream>
using namespace std;

class student{
    int rollno;
    string name;
    public:
    void inputdata(student s[], int n);
    void insertionsort(student s[], int n);    
    void shellsort(student s[], int n);     
    void showdata(student s[], int n);
};

void student::inputdata(student s[], int n){
    cout << endl;
    for(int i=0; i<n; i++){
        cout << "Enter Details of student " << i+1 << " : " << endl;
        cout << "Roll No : " ;      cin >> s[i].rollno;
        cout << "Name : ";          cin >> s[i].name;
    } 
}

void student::insertionsort(student s[], int n){
    for(int i=1; i<n; i++){
        int j=i-1;
        student val = s[i];
        while(j>=0 && s[j].rollno > val.rollno){
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = val;
    }
}

void student::shellsort(student s[], int n){
    int gap = n/2;
    while(gap>=1){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i=i-gap){
                if(s[i+gap].name > s[i].name){
                    break;
                }
                else{
                    student temp = s[i+gap];
                    s[i+gap] = s[i];
                    s[i] = temp;
                }
            }
        }
        gap = gap/2;
    }
}

void student::showdata(student s[], int n){
    cout << endl;
    for(int i=0; i<n; i++){
        cout << endl << "Details of Employees are..." << endl;
        cout << "Roll No : "  << s[i].rollno << endl;      
        cout << "Name : " << s[i].name << endl;          
    } 
}

int main(){
    int n;
    student s[50], x;

    int choice;
    bool ch = true;
    do{
        cout << endl;
        cout << "1.input data\n2.perform insertion sort\n3.perform shell sort\n4.show data\n5.Exit\nEnter Choice : ";
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Enter No.of students : ";
            cin >> n;
            x.inputdata(s, n);
            break;

            case 2:
            x.insertionsort(s, n);
            break;

            case 3:
            x.shellsort(s, n);
            break;

            case 4:
            x.showdata(s, n);
            break;

            case 5:
            ch = false;
            break;
        }
    }while(ch==true);

    return 0;
}
