//целый тип, линейный 
//однонаправленный список, обменять местами 
//(k − 1) -й и (k + 1) -й элементы списка 
//(k задается в качестве параметра)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int val;
} elem;

void get_table ( elem **aa, int N ) {

	int i, a1;
    cout << "Введите элементы: ";
    cout << endl;
	*aa = (elem *)malloc( N *sizeof(elem) );
	elem *a = *aa;

	for (i=0; i<N; i++) {
		cin >> a1;
		a[i].val = a1;
	}
	
};

void print_table ( elem *a, int N ) {

	int i;
	cout << "Таблица:";

	for (i=0; i<N; i++)
	    cout << (a[i]).val;
	
}

void schet ( elem *a, int N ) {

	int i;
	int k;

	for (i=0; i<N; i++){
		k = k + 1;
	}
		

	cout << k;
	
}

int main()
{
    elem *t;
    
    int N;
    cout << "Введите кол-во элементов: ";
    cin >> N;
    get_table ( &t, N );
    //cout << "Введите элементы: ";
    cout << endl;
    vector<int> mas;
    
    for (int i = 0; i < N; i++) {
        mas.push_back(t[i].val);
    }
   
    int k;
    
    cout << "Введите параметр k: ";

    
    cin >> k;
    int a = k-1;
    int b = k+1;
    cout << "Было: ";
    
    for (int i = 0; i < N; i++) {
        cout << mas[i] << " ";
    }
    
    for (int i = 0; i < N; i++) {
        
        if (i == a and k < (N-1)) {
            int pus = mas[i];
            mas[i] = mas[i + 2];
            mas[i + 2] = pus;
        }
        
    }
    
    cout << endl;
    cout << "Стало: ";
    for (int i = 0; i < N; i++) {
        cout << mas[i] << " ";
    }
}