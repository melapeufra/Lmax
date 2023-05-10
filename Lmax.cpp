#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct tache {
    int ind;//nom de la tache
    int p;// temps de traitement 
    int l; //le retard
    int c; //date de fin de traitement 
    int d; //date echue
};

void tri_d(int n, tache T[]) {
    // tri des taches selon l'ordre croissant des dates echues 
    tache t;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (T[i].d > T[j].d) {
                t = T[i];
                T[i] = T[j];
                T[j] = t;
            }
        }
    }
}
int ordonnancer(int n, tache T[]) {
	float Lmax = -1000*n;
    //ordonnancement de la premiere tache qui commence a l'instant t=0
    T[0].c = T[0].p;
    T[0].l = T[0].c - T[0].d;
    if (Lmax < T[0].l){
    	Lmax = T[0].l;
	}
    //ordonnacement des autres tache avec i=1
    for (int i = 1; i < n; i++) {
    	T[i].c = T[i - 1].c + T[i].p;
        T[i].l = T[i].c - T[i].d;
        if ( Lmax < T[i].l) {
        	Lmax = T[i].l;
		}
    }
    return Lmax;
 }

void affichage(int n, tache T[]) {
    cout << setw(n) << " _________________________ " << endl;
    cout << setw(3) << " ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << "T" << T[i].ind;
    }
    cout << " " << endl;
    cout << setw(3) << "pj";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << T[i].p;
    }
    cout << " " << endl;
    cout << setw(3) << "dj";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << T[i].d;
    }
     cout << " " << endl;
    cout << setw(3) << "cj";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << T[i].c;
    }
     cout << " " << endl;
    cout << setw(3) << "lj";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << T[i].l;
    }
    cout << " " << endl;
    cout << setw(n) << " _________________________" << endl;
}



int main()
{
    const int n = 5;
    //creation de l'intance du 1| |Lmax
    //const int n = 5;
    tache T[n] = {{1,3,0,0,5}, {2,4,0,0,10}, {3,6,0,0,15}, {4,10,0,0,22}, {5,7,0,0,18}};
    
    //affichage de l'instance 
    //appel a la fonction affichage
    affichage(n, T);
    // resolution de probleme
    //appel a la fonction tri 
    tri_d(n, T);
    //ordonnacement des taches 
    //appel a la fonction ordonnancer 
    int Lmax = ordonnancer(n, T);
    //affichage de la solution avec details
    cout << "L'ordonnacement optimal est de valeur :" << Lmax << endl;
    for (int i = 0; i < n; i++) {
        cout <<"T" << T[i].ind << " : [" << T[i].c - T[i].p << ", " << T[i].c << "]." << endl;
    }

}
