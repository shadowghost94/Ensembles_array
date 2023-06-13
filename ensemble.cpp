#include <iostream>
using namespace std;

#define Vmax 100
typedef struct monEnsemble monEnsemble;
struct monEnsemble
{
    int container[Vmax];  //tableau ayant pour valeur maximale Vmax
    int nbrElem;            //nombre totale d'éléments de container
};

void initialisation(monEnsemble * instance)
{
    instance->nbrElem = 0;  /*initilisation du nombre d'éléments à zero vu que le tableau ne contient rien à cet instant précis*/
};

/*void decalerDroite(A[], int position)
{
    int i=;
    while(i>=position)
        {
            A[i+1]
        }
}*/

void Ajoutsimple(monEnsemble *instance, int element)
{
    instance->container[instance->nbrElem]=element;
    instance->nbrElem+=1;
};

void AjoutPosition (monEnsemble * instance, int element, int position)
{
    int i=instance->nbrElem;
    while(  i>=position)
        {
            instance->container[i+1]= instance->container[i];
            i--;
        }
    instance->container[position]=element;
    instance->nbrElem+=1;
};

void affichage(monEnsemble instance)
{
    int i=0;
    while(i<instance.nbrElem)
    {
        cout<<"monEnsemble["<<i<<"]= "<<instance.container[i]<<endl;
        i++;
    }
};

int main()
{
    monEnsemble instance0;       //creation d'une instance de la structure monEnsemble
    initialisation(&instance0);  /*initialisation de l'instance en lui transmettant l'adresse de notre instance*/
    Ajoutsimple(&instance0, 8);
    Ajoutsimple(&instance0, 9);
    Ajoutsimple(&instance0, 10);
    Ajoutsimple(&instance0, 3);
    Ajoutsimple(&instance0, 1);
    Ajoutsimple(&instance0, 12);
    Ajoutsimple(&instance0, 13);


    //Affiche du contenu de l'instance en faisant appel à la fonction d'affichage
    affichage(instance0);

    //essait de la fonction AjoutPosition
    AjoutPosition(&instance0, 5, 2);
    AjoutPosition(&instance0, 4, 3);

    cout<<"reaffichage du contenu de l'instance ..."<<endl;
    affichage(instance0);
}
