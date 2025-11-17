#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v1; //declaration d'un vectur de type int

    vector<double> v2(5, 10.5); //declaration d'un vector de type double
    vector<double> v3 = {1.2, 2.1, 3.2, 4.3};
    vector<vector<int>> v2D(4, vector<int>(2, 0)); // Vector 2D de 4 lignes et 2 colonnes, elements 0

    //ajouter un element a la fin
    v1.push_back(10);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    cout << v1[0] << endl;

    //taille vector
    int v1_size= v1.size();
    cout << v1_size << endl;

    //iteration sur vector 
    //avec indices
    for (int i = 0; i < v1_size; i++){
        cout << v1[0] << endl;
    }

    //avec des pointeurs
    for (auto it = v1.begin(); it != v1.end(); it++){
        cout << *it << endl;
    } //avec range based boucle for
    for(int value: v1){
        cout << value << endl;
    }
    //enlever le dernier element
    v1.pop_back();

    //ajouter un element sur un indice spécifique
    v1.insert(v1.begin()+1, 7);

    //elever un element sur un indice
    v1.erase(v1.begin()+1);

    //ordonner les elements
    sort(v1.begin(), v1.end());
    
    return 0;
}
