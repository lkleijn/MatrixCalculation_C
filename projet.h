#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED

void OnQuitter(GtkWidget* widget, gpointer data);

void Taille_Matrice_Addition(GtkWidget *widget, gpointer data);
void Taille_Matrice_Soustraction(GtkWidget *widget, gpointer data);
void Taille_Matrice_Multiplication(GtkWidget *widget, gpointer data);
void Taille_Matrice_Systeme(GtkWidget *widget, gpointer data);
void Taille_Matrice_Inverse(GtkWidget *widget, gpointer data);
void Taille_Matrice_Puissance(GtkWidget *widget, gpointer data);
void Taille_Matrice_Trace(GtkWidget* widget, gpointer data);
void Taille_Matrice_Determinant(GtkWidget *widget, gpointer data);
void Taille_Matrice_Enregistrer(GtkWidget *widget, gpointer data);

void Addition(GtkWidget* widget, gpointer data);
void Soustraction(GtkWidget* widget, gpointer data);
void Multiplication(GtkWidget* widget, gpointer data);
void Saisir_Matrice_Systeme(GtkWidget *widget, gpointer data);
void Saisir_Matrice_Inverse(GtkWidget *widget, gpointer data);
void Puissance(GtkWidget *widget, gpointer data);
void Trace(GtkWidget* widget, gpointer data);
void Saisir_Matrice_Determinant(GtkWidget *widget, gpointer data);
void Saisir_Enregistrer_Matrice(GtkWidget *widget, gpointer data);

void Resultat_Addition(GtkWidget *widget,gpointer data);
void Resultat_Soustraction(GtkWidget* widget, gpointer data);
void Resultat_Multiplication(GtkWidget* widget, gpointer data);
void Calcul_Systeme(GtkWidget *widget, gpointer data);
void Calcul_Inverse(GtkWidget *widget, gpointer data);
void Resultat_Puissance(GtkWidget *widget, gpointer data);
void Resultat_Trace(GtkWidget* widget, gpointer data);
void Calcul_Determinant(GtkWidget *widget, gpointer data);
void Boite_Dialogue_Enregistrer_Matrice(GtkWidget *widget, gpointer data);

void Enregistrer_Matrice(GtkWidget *widget, gpointer data);
void Enregistrer_Resultat_Addition_Soustraction(GtkWidget* widget, gpointer data);
void Enregistrer_Resultat_Multiplication(GtkWidget* widget, gpointer data);

void Boite_dialogue_fichier(GtkWidget *widget, gpointer data);
void Boite_dialogue_fichier_addition_soustraction(GtkWidget *widget, gpointer data);
void Boite_dialogue_fichier_multiplication(GtkWidget *widget, gpointer data);

void Retour(GtkWidget *widget, gpointer data);

typedef struct Structure
    {
    FILE *fichier;
    GtkWidget *pWindowMain;
    GtkWidget *pWindowTaille;
    GtkWidget *pWindowDonnees;
    GtkWidget *pWindowResultat;
    GtkWidget *pWindowEnregistrer;
    GtkWidget *pVBox;
    GtkWidget *pHBox;
    GtkWidget *pMenuBar;
    GtkWidget *pMenu;
    GtkWidget *pMenuItem1;
    GtkWidget *pMenuItem2;
    GtkWidget *pLabel;
    GtkWidget *Nombre_Colonne;
    GtkWidget *Nombre_Ligne;
    GtkWidget *Button;
    GtkWidget *Label_Puissance;
    GtkWidget *Entry;
    GtkWidget *Entry_Nombre_Colonne;
    GtkWidget *Entry_Nombre_Colonne1;
    GtkWidget *Entry_Nombre_Colonne2;
    GtkWidget *Entry_Nombre_Ligne;
    GtkWidget *Entry_Nombre_Ligne1;
    GtkWidget *Entry_Nombre_Ligne2;
    GtkWidget *Entry_Dim;
    GtkWidget *pBox;
    GtkWidget *pTable1;
    GtkWidget *pTable2;
    GtkWidget *pTable_Result;
    GtkWidget *Destroy;
    GtkWidget *Case1[100][100];
    GtkWidget *Case2[100][100];
    gfloat Valeur1[100][100];
    gfloat Valeur2[100][100];
    gfloat Valeur_Resultat[100][100];
    gfloat Valeur_Tempo[100][100];
    gfloat Valeur_Result;
    GList *pList;
    guint Nbr_Col;
    guint Nbr_Col1;
    guint Nbr_Col2;
    guint Nbr_Lig;
    guint Nbr_Lig1;
    guint Nbr_Lig2;
    guint Puissance;
    gfloat max, multiplicateur;
    guint ii;
    gfloat echange;
    gfloat deter;
    guint Dim;
    guint i;
    guint j;
    guint k;
    guint l;
    gchar* Text;
    gchar* sNom;
    }Structure;

#endif // PROJET_H_INCLUDED
