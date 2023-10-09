//Выяснить, сколько студентов группы p имеют больше двух троек
#include <iostream>
#include <fstream> 
#include <string>    
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <cstring>


#define MAX_LINE_LEN 1000 
#define MAX_GRADES 4 

using namespace std;


int main()
{
    int roll_no;
    string group,mark1,mark2,mark3,mark4;
    
    fstream fout;
    

    fout.open("students.csv", ios::out);
    fout<<"group"<<";"<<"mark1"<<";"<<"mark2"<<";"<<"mark3"<<";"<<"mark4"<<"\n";
    
    cout<<"Введите информацию о пяти студентах: ";
    for(int i=1; i<=5; i++)
    {
        cout<<"\nГруппа студента "<<i<<" :";
        getline(cin,group);
        cout<<"Оценка1 "<<i<<" :";
        getline(cin,mark1);
        cout<<"Оценка2 "<<i<<" :";
        getline(cin,mark2);
        cout<<"Оценка3 "<<i<<" :";
        getline(cin,mark3);
        cout<<"Оценка4 "<<i<<" :";
        getline(cin,mark4);
        cin.ignore();   
    
        fout<<group<<";"<<mark1<<";"<<mark2<<";"<<mark3<<";"<<mark4<<"\n"; 
    }
    fout.close();
    fstream fin;
    string data;
    cout<<"Таблица успешно создана!";
    cout<<endl;
    
    
    fin.open("students.csv", ios::in);
    
    for(int i=0; i<=5; i++)
    {
  
        getline(fin,data);
        cout<<data<<"\n";
    }
    
    int p; 
    cout << "Введите номер группы: ";
    cin >> p;
    char filename[] = "students.csv"; 
    FILE* file = fopen(filename, "r"); 
    if (file == NULL) { 
        cout << "Ошибка открытия файла\n";
        return 1;
    }
    char line[MAX_LINE_LEN]; 
    cin.getline(line, MAX_LINE_LEN);
    int numStudents = 0; 
    int numStudentsWith = 0; 


    char s[100];
    cin.getline(s, 100);



    while (fgets(line, MAX_LINE_LEN, file)) { 
        char* token = strtok(line, ";"); 
        int studentGroup = atoi(token); 

        if (studentGroup == p) { 
            numStudents++;
            int numGrades = 0; 
            while (token != NULL) { 
                token = strtok(NULL, ";"); 
                if (token != NULL) { 
                    int grade = atoi(token);
                    if (grade == 3) { 
                        numGrades++; 

                    }
                }
            }
            if (numGrades > 2) { 
                numStudentsWith++; 
            }
        }
    }
    cout << "Количество студентов в группе P: " << numStudents;
    cout << endl;
    cout << "Количество студентов с больше чем двумя тройками: " << numStudentsWith;
    fclose(file);  

    return 0;
}