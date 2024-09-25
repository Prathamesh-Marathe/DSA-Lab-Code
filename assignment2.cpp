/*  Assignment 2 :
    Consider Employee database of PCCOE (at least 20 records). Database contains different fields of 
    every employee like EMP-ID, EMP-Name and EMP-Salary. 
    a). Arrange list of employees according to EMP-ID in ascending order using Quick Sort
    b). Arrange list of Employee alphabetically using Merge Sort 
    
    PRN No - 123B1B186
    Name - Prathmesh Marathe
    class  & Div - SY BTech & C */

#include <iostream>
using namespace std;

class employee {
    int id, salary;
    string name;
    public :
    void input(employee e[], int n);
    void quickSort(employee e[], int F, int L);
    void mergeSort(employee e[], int n, int l, int r);
    void merge(employee e[], int l, int mid, int r);
    void show(employee e[], int n);
};

void employee :: input(employee e[], int n){
     for(int i=0; i<n; i++){
        cout << endl;
        cout << "Enter Details of Employee " << i+1 << " : " << endl;
        cout << "ID : " ;           cin >> e[i].id;
        cout << "Name : ";          cin >> e[i].name;
        cout << "Salary : ";        cin >> e[i].salary;
    } 
}

void employee :: quickSort(employee e[], int F, int L){
    int i, j;
    int pivot;
    if(F < L){
        i = F+1;
        j = L;
        pivot = F;
        while(i<j){
            while(e[i].id < e[pivot].id)
                i++;
            while(e[j].id > e[pivot].id)
                j--;
            if(i < j){
                employee temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
            else{
                break;
            }
        }
        employee temp = e[j];
        e[j] = e[pivot];
        e[pivot] = temp;
        quickSort(e, F, j-1);
        quickSort(e, j+1, L);
    }
}

void employee :: mergeSort(employee e[], int n, int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(e, n, l, mid);
        mergeSort(e, n, mid+1, r);
        merge(e, l, mid, r);
    }
    else
        return;
}

void employee :: merge(employee e[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    employee e1[n1], e2[n2];

    for(int i=0; i<n1; i++){
        e1[i] = e[l+i];
    }
    for(int j=0; j<n2; j++){
        e2[j] = e[mid+1+j];
    }

    int i=0, j=0, k=l;
    while(i < n1 && j < n2){
        if(e1[i].name <= e2[j].name){
            e[k]=e1[i];
            i++;
        }
        else{
            e[k]=e2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        e[k]=e1[i];
        i++; k++;
    }
    while(j<n2){
        e[k]=e2[j];
        j++,k++;
    }
}


void employee :: show(employee e[], int n){
    cout << endl << "Details of Employees are..." << endl;
    for(int i=0; i<n; i++){
        cout << endl;
        cout << "ID : "  << e[i].id<< endl;      
        cout << "Name : " << e[i].name << endl;  
        cout << "Salary : " << e[i].salary << endl;          
    } 
}

int main(){
    int n, F, L;
    employee e[50], x;
    int l, r;

    int choice;
    bool ch = true;
    do{
        cout << endl;
        cout << "1.input data\n2.perform Quick sort\n3.Perform Merge Sort\n4.show data\n5.Exit\nEnter Choice : ";
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Enter No.of Employees : ";
            cin >> n;
            F = 0, L = n-1;
            x.input(e, n);
            break;

            case 2 :
            x.quickSort(e, F, L);
            break;

            case 3 : 
            l=0, r=n-1;
            x.mergeSort(e, n, l, r);
            break;

            case 4:
            x.show(e, n);
            break;

            default:
            ch = false;
            break;
        }
    }while(ch==true);
    return 0;
}