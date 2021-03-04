#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
};

struct DynaTableau{
    int* donnees;
    int size;
    int nbElem;
};


void initialise(Liste* liste)
{
    liste->premier= nullptr;
}

bool est_vide(const Liste* liste)
{
    if(liste->premier == nullptr ){
        return true;
    }
    return false;
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* first;
    first->donnee = valeur;
    first->suivant = nullptr;
    if (liste->premier == nullptr){
            liste->premier = first;
    }
    else {
        Noeud* nd = liste->premier;
        while (nd->suivant != nullptr){
            nd = nd->suivant;
        }
        nd->suivant = first;
    }
}

void afficheN (const Noeud* noeud){
    while (noeud != nullptr) {
        cout << noeud->donnee;
        noeud = noeud->suivant;
    }
}

void affiche(const Liste* liste)
{
    afficheN(liste->premier);
}

int recupere(const Liste* liste, int n)
{
    Noeud* noeud = liste->premier;
    while (n !=1) {
        if (noeud->suivant != nullptr){
            noeud = noeud->suivant;
            n--;
        }
        else {
            return -1;
        }
    }
    return noeud->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* noeud = liste->premier;
    while (noeud != nullptr){
        if (noeud->donnee == valeur){
            return valeur;
        }
        noeud = noeud->suivant;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* noeud = liste->premier;
    int i = 1;
    while (n!=i){
        noeud = noeud->suivant;
    noeud->donnee = valeur;
}

}

void ajoute(DynaTableau* tableau, int valeur)
{
    int* donnees = tableau->donnees;
    if(tableau->nbElem<tableau->size){
        donnees[tableau->nbElem+1]= valeur;
        tableau->nbElem++;
    }
    else{
        int*tab2 = (int*) malloc (sizeof(int)*tableau->nbElem+1);
        for (int i; i<tableau->nbElem; i++){
            tab2[i] = donnees[i];
        }
        tab2[tableau->nbElem+1] = valeur;
        tableau->nbElem++;
        donnees = tab2;
    }
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->size=capacite;
    tableau->nbElem = 0;
    tableau->donnees = (int*) malloc (sizeof(int)*tableau->size);
}

bool est_vide(const DynaTableau* liste)
{
    if(liste->nbElem == 0){
        return true;
    }
    return false;
}

void affiche(const DynaTableau* tableau)
{
    int*donnees = tableau->donnees;
    for(int i =0; i>tableau->nbElem; i++){
        cout << donnees[i];
    }
}

int recupere(const DynaTableau* tableau, int n)
{
    int valeur =tableau->donnees[n];
    return valeur;
}

int cherche(const DynaTableau* tableau, int valeur)
{
    int* donnees = tableau->donnees;
    for(int i =0; i>tableau->nbElem; i++){
        if(donnees[i] == valeur){
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    tableau->donnees[n] = valeur;
}

void pousse_file(Liste* liste, int valeur)
{
     Noeud* file = liste->premier;
     while(file->suivant != nullptr){
         file = file->suivant;
     }
     Noeud* patrick;
     file->suivant = patrick;
     file = file->suivant;
     file->suivant = nullptr;
     file->donnee = valeur;
}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    Noeud* file = liste->premier;
    int valeur = file->donnee;
    liste->premier = file->suivant;
    return valeur;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    Noeud* file = liste->premier;
    while(file->suivant != nullptr){
        file = file->suivant;
    }
    Noeud* patrick;
    file->suivant = patrick;
    file = file->suivant;
    file->suivant = nullptr;
    file->donnee = valeur;
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    Noeud* file = liste->premier;
    while(file->suivant != nullptr){
        file = file->suivant;
    }
    int valeur = file->donnee;
    file = nullptr;
    return valeur;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&liste) && compteur > 0)
    {
        std::cout << retire_file(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_file(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
