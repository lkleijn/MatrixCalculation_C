#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>
#include "projet.h"

int main(int argc, char **argv)
{
    Structure prog;
    gtk_init(&argc, &argv);

    /* Création de la fenêtre */
    prog.pWindowMain = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog.pWindowMain), "Projet NF05 P13");
    gtk_window_set_default_size(GTK_WINDOW(prog.pWindowMain), 320, 200);
    g_signal_connect(G_OBJECT(prog.pWindowMain), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la Box qui contiendra les elements */
    prog.pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog.pWindowMain), prog.pVBox);

    /* Création du Texte */
    prog.pLabel = gtk_label_new("Bonjour!\n Pour commencer, veuillez selectionner une operation a effectuer.\n\nCe programme a ete code par:\n-Oriane Bouvier\n-Camille Benhaim\n-Louis Kleijn.");

    /* Création du menu */

    /* On connecte les differents objets du menu aux fonctions qui leur sont associés grace a la fonction g_signal_connect */
    /* Premier menu */
    prog.pMenuBar = gtk_menu_bar_new();
    prog.pMenu = gtk_menu_new();
    prog.pMenuItem1 = gtk_menu_item_new_with_label("Addition de 2 matrices");
    g_signal_connect(G_OBJECT(prog.pMenuItem1), "activate", G_CALLBACK(Taille_Matrice_Addition), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem1);
    prog.pMenuItem1 = gtk_menu_item_new_with_label("Soustraction de 2 matrices");
    g_signal_connect(G_OBJECT(prog.pMenuItem1), "activate", G_CALLBACK(Taille_Matrice_Soustraction), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem1);
    prog.pMenuItem1 = gtk_menu_item_new_with_label("Multiplication de 2 matrices");
    g_signal_connect(G_OBJECT(prog.pMenuItem1), "activate", G_CALLBACK(Taille_Matrice_Multiplication), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem1);
    prog.pMenuItem1 = gtk_menu_item_new_with_label("Resolution de systeme lineaire");
    g_signal_connect(G_OBJECT(prog.pMenuItem1), "activate", G_CALLBACK(Taille_Matrice_Systeme), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem1);
    prog.pMenuItem1 = gtk_menu_item_new_with_label("Quitter");
    g_signal_connect(G_OBJECT(prog.pMenuItem1), "activate", G_CALLBACK(OnQuitter),(GtkWidget*) prog.pWindowMain);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem1);
    prog.pMenuItem1 = gtk_menu_item_new_with_label("Operations sur 2 matrices");


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(prog.pMenuItem1), prog.pMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenuBar), prog.pMenuItem1);

    /* Second menu */

    prog.pMenu = gtk_menu_new();
    prog.pMenuItem2 = gtk_menu_item_new_with_label("Inverse d'une matrice");
    g_signal_connect(G_OBJECT(prog.pMenuItem2), "activate", G_CALLBACK(Taille_Matrice_Inverse), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem2);
    prog.pMenuItem2 = gtk_menu_item_new_with_label("Puissance de matrice");
    g_signal_connect(G_OBJECT(prog.pMenuItem2), "activate", G_CALLBACK(Taille_Matrice_Puissance), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem2);
    prog.pMenuItem2 = gtk_menu_item_new_with_label("Trace d'une matrice");
    g_signal_connect(G_OBJECT(prog.pMenuItem2), "activate", G_CALLBACK(Taille_Matrice_Trace), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem2);
    prog.pMenuItem2 = gtk_menu_item_new_with_label("Determinant d'une matrice");
    g_signal_connect(G_OBJECT(prog.pMenuItem2), "activate", G_CALLBACK(Taille_Matrice_Determinant), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem2);
    prog.pMenuItem2 = gtk_menu_item_new_with_label("Enregistrer une matrice");
    g_signal_connect(G_OBJECT(prog.pMenuItem2), "activate", G_CALLBACK(Taille_Matrice_Enregistrer), &prog);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem2);
    prog.pMenuItem2 = gtk_menu_item_new_with_label("Quitter");
    g_signal_connect(G_OBJECT(prog.pMenuItem2), "activate", G_CALLBACK(OnQuitter),(GtkWidget*) prog.pWindowMain);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenu), prog.pMenuItem2);
    prog.pMenuItem2 = gtk_menu_item_new_with_label("Operations sur 1 matrice");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(prog.pMenuItem2), prog.pMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(prog.pMenuBar), prog.pMenuItem2);

    /* Ajout du menu a la fenetre */
    gtk_box_pack_start(GTK_BOX(prog.pVBox), prog.pMenuBar, FALSE, TRUE, 0);


    gtk_box_pack_start(GTK_BOX(prog.pVBox), prog.pLabel, TRUE, FALSE, 0);

    gtk_widget_show_all(prog.pWindowMain);

    gtk_main(); /*Cette fonction permet de lancer la boucle évenementielle qui permet de faire tourner le programme "à l'infini" */

    return EXIT_SUCCESS;
}
    /* Fonction qui permet de quitter le programme */

void OnQuitter(GtkWidget* widget, gpointer data)
{
    GtkWidget *pQuestion;
    pQuestion = gtk_message_dialog_new(GTK_WINDOW(data),
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_QUESTION,
        GTK_BUTTONS_YES_NO,
        "Voulez vous vraiment\n"
        "quitter le programme?");

    switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
    {
        case GTK_RESPONSE_YES:
            gtk_main_quit();
            break;
        case GTK_RESPONSE_NONE:
        case GTK_RESPONSE_NO:
            gtk_widget_destroy(pQuestion);
            break;
    }
}

/* Fonction appelée lors du clic sur "Retourner au menu principal" */

void Retour(GtkWidget* widget, gpointer data)
{
    Structure *prog=(Structure *)data;  /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* détruit toutes les fenetres sauf le main et permet de revenir a la fenetre principale */

    gtk_widget_destroy(prog->pWindowResultat);
    gtk_widget_destroy(prog->pWindowDonnees);
    gtk_widget_destroy(prog->pWindowTaille);
    gtk_widget_show_all(prog->pWindowMain);
    gtk_main();
}

/* Fonction executee lors du signal "clicked" sur "Addition de 2 matrices*/

void Taille_Matrice_Addition(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille des matrices");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box contenant les differents elements */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* Création des zones de textes et des textes et insertion dans la box */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes des matrices a additionner");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes des matrices a additionner");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Addition),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fonction executée lors du clic sur "Ok!" */

void Addition(GtkWidget *widget,gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Récupération du nombre de lignes et colonnes */

    prog->Nbr_Col=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne));
    prog->Nbr_Lig=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne));

    /* Création d'une fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    /* Création de 2 tables permettant de saisir les differentes valeurs de la matrice. On insere le signe + entre les 2 */
    prog->pTable1=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    prog->pTable2=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    prog->pLabel = gtk_label_new("+");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable1, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable2, TRUE, FALSE, 0);

    /* On utilise une boucle for pour créer une case en fonction du nombre de lignes et colonnes qu'on insere dans la Table */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
            prog->Case2[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case2[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable2), prog->Case2[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);

        }
    }

    /* On insere un bouton qui va appeler la fonction donnant le resultat */

    prog->Button = gtk_button_new_with_label("Additionner!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Resultat_Addition), prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction donnant le résultat de l'addition. Appelée lors du clic sur le bouton "Additionner!" */

void Resultat_Addition(GtkWidget *widget,gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une nouvelle fenetre */

    prog->pWindowResultat = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowResultat), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowResultat), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowResultat), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création d'une nouvelle box */
    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowResultat), prog->pVBox);

    /* On crée une table qui affichera la matrice résultat */

    prog->pTable_Result=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);

    /* On utilise une boucle for pour calculer la somme des matrices case par case */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));
            prog->Valeur2[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case2[prog->i][prog->j]));
            prog->Valeur_Resultat[prog->i][prog->j]=prog->Valeur1[prog->i][prog->j]+prog->Valeur2[prog->i][prog->j];
            prog->Text = g_strdup_printf("%.2f", prog->Valeur_Resultat[prog->i][prog->j]);
            prog->pLabel = gtk_label_new(prog->Text);
            gtk_table_attach(GTK_TABLE(prog->pTable_Result), prog->pLabel,prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
            g_free(prog->Text);
        }
    }
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable_Result, TRUE, FALSE, 0);

    /* Création d'une box contenant 3 boutons */

    prog->pHBox=gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création des boutons */

    prog->Button = gtk_button_new_with_label("Enregistrer dans un fichier .txt");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Boite_dialogue_fichier_addition_soustraction),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Retourner au menu principal");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowResultat);


}

/* Pour la soustraction, la procédure est exactement la même sauf que l'on soustraie case par case */

void Taille_Matrice_Soustraction(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille des matrices");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(prog->pWindowTaille);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* On crée les différents éléments de zones de textes et textes puis on les insere dans la box selon l'affichage que l'on souhaite */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes des matrices a soustraire");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes des matrices a soustraire");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne, TRUE, FALSE, 0);

    /* Bouton qui appelle la fonction qui permet de saisir les valeurs */

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Soustraction),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fontion appelée lors du clic sur "Ok!" de la fonction précédente */

void Soustraction(GtkWidget* widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* On récupère les valeurs des lignes et colonnes pour créer les tables avec les bonnes dimensions */

    prog->Nbr_Col=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne));
    prog->Nbr_Lig=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne));

    /* Création de la fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création et insertion de la box dans la fenetre */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    /* Création des tables en fonction des valeurs précédentes et insertion dans la box */

    prog->pTable1=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    prog->pTable2=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    prog->pLabel = gtk_label_new("-");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable1, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable2, TRUE, FALSE, 0);

    /* on créé 2 tables de même dimensions grace à 2 boucles for */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
            prog->Case2[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case2[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable2), prog->Case2[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);

        }
    }

    /* Création du bouton qui va appeler la fonction donnant le résultat */

    prog->Button = gtk_button_new_with_label("Soustraire!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Resultat_Soustraction), prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction appelée par le clic sur "Soustraire!" */

void Resultat_Soustraction(GtkWidget* widget, gpointer data)
{
    Structure *prog=(Structure *)data;  /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une nouvelle fenêtre */

    prog->pWindowResultat = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowResultat), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowResultat), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowResultat), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowResultat), prog->pVBox);

    /* Création de la table résultat */

    prog->pTable_Result=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);

    /* On soustrait case par case grâce à 2 boucles for et on affiche le résultat dans la table résultat */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));
            prog->Valeur2[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case2[prog->i][prog->j]));
            prog->Valeur_Resultat[prog->i][prog->j]=prog->Valeur1[prog->i][prog->j]-prog->Valeur2[prog->i][prog->j];
            prog->Text = g_strdup_printf("%.2f", prog->Valeur_Resultat[prog->i][prog->j]);
            prog->pLabel = gtk_label_new(prog->Text);
            gtk_table_attach(GTK_TABLE(prog->pTable_Result), prog->pLabel,prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
            g_free(prog->Text);
        }
    }
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable_Result, TRUE, FALSE, 0);

    /* Création d'une box contenant 3 boutons */

    prog->pHBox=gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création des boutons */

    prog->Button = gtk_button_new_with_label("Enregistrer dans un fichier .txt"); //Permet d'appeler la fonction qui enregistre dans un fichier
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Boite_dialogue_fichier_addition_soustraction),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Retourner au menu principal");// Permet de revenir au menu principal
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter"); // Ouvre une boite de dialogue pour quitter le programme
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);
    gtk_widget_show_all(prog->pWindowResultat);
}

/* Fonction appelée lors du clic sur "Enregistrer dans un fichier .txt" */

void Boite_dialogue_fichier_addition_soustraction(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowEnregistrer = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowEnregistrer), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowEnregistrer), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowEnregistrer), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowEnregistrer), prog->pVBox);

    /* Création des différents éléments permettant de saisir le nom du fichier */

    prog->pLabel= gtk_label_new("Entrer le nom de votre fichier");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);

    prog->Entry= gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(prog->pVBox),prog->Entry, TRUE, FALSE, 0);

    /* Création du bouton appelant la fonction qui va créer le fichier et rentrer les valeurs dans celui-ci */

    prog->Button= gtk_button_new_with_label("Ok!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Enregistrer_Resultat_Addition_Soustraction),prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox),prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowEnregistrer);
}

/* Fonction appelée lors du clic sur "Ok!" */

void Enregistrer_Resultat_Addition_Soustraction(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Récupération du texte. On y ajoute l'extention .txt et on l'ouvre */

    prog->Text = gtk_entry_get_text(prog->Entry);
    prog->Text = g_strdup_printf("%s.txt", prog->Text);
    prog->fichier = fopen(prog->Text, "w+");

    /* On utilise 2 boucles for pour rentrer chaque valeur de la matrice */

    for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {
            prog->Text = g_strdup_printf("%.2f", prog->Valeur_Resultat[prog->i][prog->j]);
            fprintf(prog->fichier, "%.2f ", prog->Valeur_Resultat[prog->i][prog->j]);
        }
        fprintf(prog->fichier, "\n");
    }

    /* On ferme le fichier et la fenetre. On revient a la fenetre précédente et le fichier est enregistré !*/

    fclose(prog->fichier);
    gtk_widget_destroy(prog->pWindowEnregistrer);
    gtk_main();
}

/* Fonction demandant la taille des 2 matrices à multiplier. Appelée depuis le menu principal */

void Taille_Matrice_Multiplication(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille des matrices");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box contenant les differents elements */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* Création des zones de textes et des textes et insertion dans la box */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes de la premiere matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne1 = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne1, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes de la premiere matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne1 = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne1, TRUE, FALSE, 0);

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes de la deuxieme matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne2 = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne2, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes de la deuxieme matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne2 = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne2, TRUE, FALSE, 0);

    /* On demande la dimension commune qui est nécessaire, la multiplication n'est pas possible sinon ! Normalement, le nombre de colonnes de la premiere doit etre le même
    que le nombre de lignes de la deuxième */

    prog->pLabel = gtk_label_new("Entrer la dimension commune aux matrices a multiplier. Il est necessaire qu'il y en ai une, la multiplication n'est pas possible sinon!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);

    prog->Entry_Dim = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Dim, TRUE, FALSE, 0);

    /* Création du bouton appelant la fonction permettant de rentrer les valeurs */

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Multiplication),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fonction appelée lors du clic sur "Ok!" de la fonction précédente */

void Multiplication(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* On récupére toutes les valeurs saisies précédemment */

    prog->Nbr_Col1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne1));
    prog->Nbr_Lig1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne1));
    prog->Nbr_Col2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne2));
    prog->Nbr_Lig2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne2));
    prog->Dim=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Dim));


    /* Création de la fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    prog->pHBox = gtk_hbox_new(FALSE, 0);


    if(prog->Nbr_Col1 != prog->Nbr_Lig2)
    {
        prog->pLabel = gtk_label_new("La multiplication de ces 2 matrices ne peut pas etre faite, les dimensions ne sont pas correctes.");
        gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);
        prog->Button = gtk_button_new_with_label("Resaisir les dimensions");
        g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Taille_Matrice_Multiplication), prog);
        gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);
        prog->Button = gtk_button_new_with_label("Revenir au menu principal!");
        g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour), prog);
        gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);
        prog->Button = gtk_button_new_with_label("Quitter");
        g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter), (GtkWidget*) prog->pWindowDonnees);
        gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    }
    else
    {
        /* Grace aux valeurs, on créé 2 tables composées de boutons permettant de saisir des valeurs */

    prog->pTable1=gtk_table_new(prog->Nbr_Lig1,prog->Nbr_Col1, TRUE);
    prog->pTable2=gtk_table_new(prog->Nbr_Lig2,prog->Nbr_Col2, TRUE);
    prog->pLabel = gtk_label_new("*");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable1, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable2, TRUE, FALSE, 0);

    /* On utilise 2 boucles for pour créer la premiere table */

    for(prog->i=1; prog->i<=prog->Nbr_Lig1;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col1; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j], prog->j-1, prog->j,prog->i-1, prog->i,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        }
    }

    /* On utilise 2 boucles for pour créer la seconde table */

    for(prog->i=1; prog->i<=prog->Nbr_Lig2;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col2; prog->j++)
        {
            prog->Case2[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case2[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable2), prog->Case2[prog->i][prog->j], prog->j-1, prog->j,prog->i-1, prog->i,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        }
    }

    /* On créé un bouton qui va appeler la fonction donnant le résultat */

    prog->Button = gtk_button_new_with_label("Multiplier!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Resultat_Multiplication), prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);}
    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction appelée lors du clic sur "Multiplier!" */

void Resultat_Multiplication(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowResultat = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowResultat), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowResultat), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowResultat), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowResultat), prog->pVBox);

    /* On créé la table qui donne le résultat */

    prog->pTable_Result=gtk_table_new(prog->Nbr_Lig1,prog->Nbr_Col2, TRUE);

    /* On utilise 2 boucles for pour initialiser les valeurs à 0 */

    for(prog->i=1; prog->i<=prog->Nbr_Lig1;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col2; prog->j++)
        {
            prog->Valeur_Resultat[prog->i][prog->j]=0;
        }
    }

    /* On utilise 3 boucles for pour multiplier les valeurs des lignes et colonnes des matrices et on additionne ces valeurs entre elle pour obtenir la valeur d'une case.
    On repete l'opération pour chaque case. */

    for(prog->i=1; prog->i<=prog->Nbr_Lig1;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col2; prog->j++)
        {
            for (prog->k=1; prog->k<=prog->Dim; prog->k++)
            {
                prog->Valeur1[prog->i][prog->k]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->k]));
                prog->Valeur2[prog->k][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case2[prog->k][prog->j]));
                prog->Valeur_Resultat[prog->i][prog->j]=(prog->Valeur1[prog->i][prog->k]*prog->Valeur2[prog->k][prog->j])+prog->Valeur_Resultat[prog->i][prog->j];
            }
            prog->Text = g_strdup_printf("%.2f", prog->Valeur_Resultat[prog->i][prog->j]);
            prog->pLabel = gtk_label_new(prog->Text);
            gtk_table_attach(GTK_TABLE(prog->pTable_Result), prog->pLabel, prog->j-1, prog->j,prog->i-1, prog->i,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
            g_free(prog->Text);
        }
    }
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable_Result, TRUE, FALSE, 0);

    /* Création d'une box contenant 3 boutons */

    prog->pHBox=gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création des boutons */

    prog->Button = gtk_button_new_with_label("Enregistrer dans un fichier .txt"); //Appelle la fonction permettant d'enregistrer dans un fichier.
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Boite_dialogue_fichier_multiplication),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Retourner au menu principal");// Appelle la fonction Retour
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter");// Permet de quitter le programme en ouvrant une boite de dialoque
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);
    gtk_widget_show_all(prog->pWindowResultat);
}

/* Fonction appelée lors du clic sur "Enregistrer dans un fichier .txt" */

void Boite_dialogue_fichier_multiplication(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une nouvelle fenetre */

    prog->pWindowEnregistrer = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowEnregistrer), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowEnregistrer), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowEnregistrer), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création d'une nouvelle box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowEnregistrer), prog->pVBox);

    /* Création d'éléments permettant de saisir le nom du fichier */

    prog->pLabel= gtk_label_new("Entrer le nom de votre fichier");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);

    prog->Entry= gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(prog->pVBox),prog->Entry, TRUE, FALSE, 0);

    /* Création d'un bouton appelant la fonction qui va ouvrir/créer le fichier saisi et rentrer les valeurs dans le fichier */

    prog->Button= gtk_button_new_with_label("Ok!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Enregistrer_Resultat_Multiplication),prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox),prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowEnregistrer);
}

/* Fonction enregistrant une matrice résultant d'une multiplication dans un fichier */

void Enregistrer_Resultat_Multiplication(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* On récupére le texte, on ajoute ".txt" et on ouvre/créé le fichier correspondant */

    prog->Text = gtk_entry_get_text(prog->Entry);
    prog->Text = g_strdup_printf("%s.txt", prog->Text);
    prog->fichier = fopen(prog->Text, "w+");

    /* On rentre chaque valeur grâce à 2 boucles for */

    for(prog->i=1; prog->i<=prog->Nbr_Lig1;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col2; prog->j++)
        {
            prog->Text = g_strdup_printf("%.2f", prog->Valeur_Resultat[prog->i][prog->j]);
            fprintf(prog->fichier, "%.2f ", prog->Valeur_Resultat[prog->i][prog->j]);
        }
        fprintf(prog->fichier, "\n");
    }

    /* On ferme le fichier et la fenetre et le fichier est enregistré ! */

    fclose(prog->fichier);
    gtk_widget_destroy(prog->pWindowEnregistrer);
    gtk_main();
}

/* Fonction appelée depuis le menu principal permettant de saisir la taille de la matrice dont on va calculer la trace */

void Taille_Matrice_Trace(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille des matrices");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box contenant les differents elements */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* Création des zones de textes et des textes et insertion dans la box */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne, TRUE, FALSE, 0);

    /* Bouton appelant la fonction permettant de saisir les valeurs de la matrice */

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Trace),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fonction appelée lors du clic sur "Ok!" */

void Trace(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* On récupére les valeurs et on créé une table avec celles-ci */

    prog->Nbr_Col=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne));
    prog->Nbr_Lig=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne));

    /* Création de la fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    /* Création de la table grâce aux valeurs récupérées */

    prog->pTable1=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable1, TRUE, FALSE, 0);

    /* On utilise 2 boucles for pour créer la table */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        }
    }

    /* Création du bouton qui va permettre d'afficher le résultat */

    prog->Button = gtk_button_new_with_label("Calculer la Trace!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Resultat_Trace), prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction appelée lors du clic de "Calculer la Trace!" */

void Resultat_Trace(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une nouvelle fenetre */

    prog->pWindowResultat = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowResultat), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowResultat), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowResultat), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création d'une nouvelle box */
    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowResultat), prog->pVBox);

    /* On utilise une boucle for pour calculer la somme des cases de la diagonale */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            if(prog->i == prog->j)
            {
                prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));
                prog->Valeur_Result=prog->Valeur1[prog->i][prog->j]+prog->Valeur_Result;
            }
        }
    }

    /* Affichage de la valeur de la trace */

    prog->Text = g_strdup_printf("La valeur de la trace pour cette matrice est %.2f", prog->Valeur_Result);
    prog->pLabel = gtk_label_new(prog->Text);
    g_free(prog->Text);

    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);

    /* Création d'une box contenant 2 boutons */

    prog->pHBox=gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création des boutons */

    prog->Button = gtk_button_new_with_label("Retourner au menu principal"); // permet de retourner au menu principal
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter"); // Bouton permettant de quitter le programme
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowResultat);
}

/* Fonction appelée depuis le menu */

void Taille_Matrice_Enregistrer(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille de la matrice");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box contenant les differents elements */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* Création des zones de textes et des textes et insertion dans la box */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne, TRUE, FALSE, 0);

    /* Bouton appelant la fonction permmettant de saisir la matrice à enregistrer */

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Saisir_Enregistrer_Matrice),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fonction appelée lors du clic sur "Ok!" de la fonction précedente */

void Saisir_Enregistrer_Matrice(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Récupération des valeurs permettant de créer la table */

    prog->Nbr_Col=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne));
    prog->Nbr_Lig=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne));

    /* Création de la fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    /* Création d'une box horizontale pour les boutons */

    prog->pHBox = gtk_hbox_new(FALSE, 0);

    /* Création de la table grâce aux valeurs */

    prog->pTable1=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable1, TRUE, FALSE, 0);

    /* On utilise 2 boucles for pour créer le bon nombre de cases */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        }
    }

    /* Création des différents boutons */

    prog->Button = gtk_button_new_with_label("Enregistrer!"); // Appelle la fonction enregistrant la matrice
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Boite_Dialogue_Enregistrer_Matrice), prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Retourner au menu principal"); //Permet de retourner a la fenetre principale
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter"); //Permet de quitter le programme
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction appelée suite au clic sur "Enregistrer!" */

void Boite_Dialogue_Enregistrer_Matrice(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowEnregistrer = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowEnregistrer), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowEnregistrer), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowEnregistrer), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowEnregistrer), prog->pVBox);

    /* Création des éléments permettant de saisir le nom du fichier */

    prog->pLabel= gtk_label_new("Entrer le nom de votre fichier");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);

    prog->Entry= gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(prog->pVBox),prog->Entry, TRUE, FALSE, 0);

    /* Création du bouton appelant la fonction qui va stocker la matrice dans un fichier */

    prog->Button= gtk_button_new_with_label("Ok!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Enregistrer_Matrice),prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox),prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowEnregistrer);
}

/* Fonction appelée lors du clic sur "Ok!" */

void Enregistrer_Matrice(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Récupération du texte, ajout de .txt, ouverture du fichier */

    prog->Text = gtk_entry_get_text(prog->Entry);
    prog->Text = g_strdup_printf("%s.txt", prog->Text);
    prog->fichier = fopen(prog->Text, "w+");

    /* On utilise 2 boucles for pour stocker chaque case dans le bon ordre */

    for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {
            prog->Valeur_Resultat[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));
            prog->Text = g_strdup_printf("%.2f", prog->Valeur_Resultat[prog->i][prog->j]);
            fprintf(prog->fichier, "%.2f ", prog->Valeur_Resultat[prog->i][prog->j]);
        }
        fprintf(prog->fichier, "\n");
    }

    /* On ferme le fichier et la fenetre. Le fichier est enregistré ! */

    fclose(prog->fichier);
    gtk_widget_destroy(prog->pWindowEnregistrer);
    gtk_main();
}

/* Fonction calculant une matrice à la puissance n. appelée depuis le menu */

void Taille_Matrice_Puissance(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille de la  matrice");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(prog->pWindowTaille);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* Création des éléments permettant de saisir les dimensions de la matrice et la puissance */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne, TRUE, FALSE, 0);

    prog->Label_Puissance = gtk_label_new("Entrer la puissance a calculer");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Label_Puissance, TRUE, FALSE, 0);

    prog->Label_Puissance = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Label_Puissance, TRUE, FALSE, 0);

    /* Création du bouton qui va permettre de saisir la matrice */

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Puissance),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fonction appelée lors du clic sur "Ok!" de la fonction précédente */

void Puissance(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Récupération des valeurs */

    prog->Nbr_Col=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne));
    prog->Nbr_Lig=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne));
    prog->Puissance=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Label_Puissance));

    /* Création de la fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    /* Création de la table grâce aux valeurs récupérées */

    prog->pTable1=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable1, TRUE, FALSE, 0);

    /* Utilisation de 2 boucles for pour créer le bon nombre de cases */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j], prog->j-1, prog->j,prog->i-1, prog->i,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        }
    }

    /* Création du bouton permettant d'appeler la fonction qui va calculer et afficher le résultat */

    prog->Button = gtk_button_new_with_label("Multiplier!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Resultat_Puissance), prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction appelée suite au clic sur "Multiplier!" de la fonction précédente */

void Resultat_Puissance(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowResultat = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowResultat), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowResultat), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowResultat), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowResultat), prog->pVBox);

    /* Création de la table résultat */

    prog->pTable_Result=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);

    /* Utilisation de 2 boucles for pour initialiser les différentes variables nécessaires */

     for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {
            prog->Valeur_Resultat[prog->i][prog->j]=0;
            prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));
            prog->Valeur2[prog->i][prog->j]=prog->Valeur1[prog->i][prog->j];
            prog->Valeur_Tempo[prog->i][prog->j]=0;
        }
    }

    /* Utilisation de 4 boucles for. La premiere pour faire n fois la multiplication, la deuxieme et la troisieme pour se placer sur chaque case et la troisiéme
    pour multiplier les lignes et colonnes */

    for(prog->l=1; prog->l<prog->Puissance; prog->l++)
    {
        for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
        {
            for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
            {
                for (prog->k=1; prog->k<=prog->Nbr_Lig; prog->k++)
                {
                    prog->Valeur_Resultat[prog->i][prog->j]=(prog->Valeur1[prog->i][prog->k]*prog->Valeur2[prog->k][prog->j])+prog->Valeur_Tempo[prog->i][prog->j];
                    prog->Valeur_Tempo[prog->i][prog->j]= prog->Valeur_Resultat[prog->i][prog->j];

                }
                prog->Valeur_Tempo[prog->i][prog->j]=0;
            }
        }
        for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)// Cette boucle sert à avoir les bonnes valeurs pour les multiplications suivantes (n > 2)
        {
            for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
            {
                prog->Valeur2[prog->i][prog->j]=prog->Valeur_Resultat[prog->i][prog->j];
            }
        }
    }

    /* Utilisation de 2 boucles for pour afficher le résultat */

     for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {
            prog->Text = g_strdup_printf("%.2f", prog->Valeur_Resultat[prog->i][prog->j]);
            prog->pLabel = gtk_label_new(prog->Text);
            gtk_table_attach(GTK_TABLE(prog->pTable_Result), prog->pLabel, prog->j-1, prog->j,prog->i-1, prog->i,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
            g_free(prog->Text);
        }
    }
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable_Result, TRUE, FALSE, 0);

    /* Création d'une box contenant 3 boutons */

    prog->pHBox=gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création des boutons */

    prog->Button = gtk_button_new_with_label("Enregistrer dans un fichier .txt"); // Appelle la fonction permetant d'enregistrer la matrice. On utilise la meme que pour l'addition
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Boite_dialogue_fichier_addition_soustraction),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Retourner au menu principal"); // Appelle la fonction permettant de revenir au menu principal
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter"); // Appelle une boite de dialoque permettant de quitter le programme */
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);
    gtk_widget_show_all(prog->pWindowResultat);
}

/* Fonction appelée depuis le menu pour calculer le déterminant */

void Taille_Matrice_Determinant(GtkWidget *widget, gpointer data)
{
     Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille de la matrice");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box contenant les differents elements */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* Création des zones de textes et des textes et insertion dans la box */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Saisir_Matrice_Determinant),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fonction appelée lors du clic sur "Ok!" de la fonction */

void Saisir_Matrice_Determinant(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* On récupére les valeurs */

    prog->Nbr_Col=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne));
    prog->Nbr_Lig=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne));

    /* Création de la fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    /* Création de la table grâce aux valeurs récupérées */

    prog->pTable1=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable1, TRUE, FALSE, 0);

    /* Utilisation de 2 boucles for pour créer le bon nombre de cases */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        }
    }

    /* Création du bouton appelant la fonction permettant de calculer le déterminant et de l'afficher */

    prog->Button = gtk_button_new_with_label("Calculer!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Calcul_Determinant), prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction appelée suite au clic sur "Calculer!" de la fonction précédente */

void Calcul_Determinant(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowResultat = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowResultat), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowResultat), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowResultat), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowResultat), prog->pVBox);

    /* On utilise la méthode du pivot de Gauss pour trouver le déterminant. */

    prog->deter=1;

    for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {

            prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));


        }
    }

    for(prog->i = 1; prog->i <= prog->Nbr_Lig; prog->i++) // Recherche du plus grand terme de la colonne i en valeur absolue.
    {
        prog-> max = 0;

        prog->k = prog->i;
        for (prog->j = prog->i; prog->j <= prog->Nbr_Col; prog->j++)
        {
            if (fabs(prog->Valeur1[prog->i][prog->j]) > prog->max)
            {
                prog-> max = fabs(prog->Valeur1[prog->i][prog->j]);
                 prog->k = prog->j;
            }
        }

        if (prog->k != prog->i) // On échange les lignes pour que l'élément le plus grand (le pivot) soit sur la diagonale
        {
            for(prog->j=1;prog->j<=prog->Nbr_Col;prog->j++)
            {prog->echange = prog->Valeur1[prog->j][prog->i];
            prog->Valeur1[prog->j][prog->i] = prog->Valeur1[prog->j][prog->k];
            prog->Valeur1[prog->j][prog->k] = prog->echange;}
            prog->deter *= -1; // Échange de lignes : le déterminant est changé en son opposé

        }

        /* on ajoute à chaque ligne un multiple de la ligne pivot pour annuler les termes sous le pivot, ce qui ne modifie pas le déterminant */

        for (prog->j = prog->i+1; prog->j <= prog->Nbr_Col; prog->j++) //
        {
            prog->multiplicateur = -prog->Valeur1[prog->i][prog->j]/prog->Valeur1[prog->i][prog->i];
            for (prog->ii = prog->i; prog->ii <= prog->Nbr_Col; prog->ii++)
            {
                prog->Valeur1[prog->ii][prog->j] += prog->Valeur1[prog->ii][prog->i]*prog->multiplicateur;
            }

        }

        /* La matrice est triangulaire. Son déterminant est le produit des termes de la diagonale */

        prog->deter *= prog->Valeur1[prog->i][prog->i];
    }

    prog->Text = g_strdup_printf("La valeur du determinant pour cette matrice est %.2f", prog->deter);
    prog->pLabel = gtk_label_new(prog->Text);
    g_free(prog->Text);

    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);

    /* Création d'une box contenant 2 boutons */

    prog->pHBox=gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création des boutons */

    prog->Button = gtk_button_new_with_label("Retourner au menu principal"); // Appelle la fonction permettant de revenir au menu principal
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter"); // Affiche une boite de dialogue permettant de quitter l'application */
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowResultat);

}

/* Fonction appelée depuis le menu principal */

void Taille_Matrice_Inverse(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille de la matrice");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box contenant les differents elements */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* Création des zones de textes et des textes et insertion dans la box */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Saisir_Matrice_Inverse),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fonction appelée lors du clic sur "Ok!" de la fonction précédente */

void Saisir_Matrice_Inverse(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* On récupére les valeurs */

    prog->Nbr_Col=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne));
    prog->Nbr_Lig=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne));

    /* Création de la fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    /* Création de la table grâce aux valeurs récupérées */

    prog->pTable1=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable1, TRUE, FALSE, 0);

    /* Utilisation de 2 boucles for pour créer le bon nombre de cases */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        }
    }

    /* Création du bouton appelant la fonction permettant de calculer l'inverse de la matrice et de l'afficher */

    prog->Button = gtk_button_new_with_label("Calculer!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Calcul_Inverse), prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction appelée lors du clic sur "Calculer!" de la fonction précédente */

void Calcul_Inverse(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowResultat = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowResultat), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowResultat), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowResultat), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowResultat), prog->pVBox);

     prog->pTable_Result = gtk_table_new(prog->Nbr_Lig,1, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable_Result, TRUE, FALSE, 0);

    /* On utilise la méthode du pivot de Gauss pour trouver le déterminant. */

    prog->deter=1;

    for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {

            prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));


        }
    }

    for(prog->i = 1; prog->i <= prog->Nbr_Lig; prog->i++) // Recherche du plus grand terme de la colonne i en valeur absolue.
    {
       prog-> max = 0;

        prog->k = prog->i;
        for (prog->j = prog->i; prog->j <= prog->Nbr_Col; prog->j++)
        {
            if (fabs(prog->Valeur1[prog->i][prog->j]) > prog->max)
            {
                prog-> max = fabs(prog->Valeur1[prog->i][prog->j]);
                 prog->k = prog->j;
            }
        }

        if (prog->k != prog->i) // On échange les lignes pour que l'élément le plus grand (le pivot) soit sur la diagonale
        {
            for(prog->j=1;prog->j<=prog->Nbr_Col;prog->j++)
            {prog->echange = prog->Valeur1[prog->j][prog->i];
            prog->Valeur1[prog->j][prog->i] = prog->Valeur1[prog->j][prog->k];
            prog->Valeur1[prog->j][prog->k] = prog->echange;}
            prog->deter *= -1; // Échange de lignes : le déterminant est changé en son opposé

        }

        /* on ajoute à chaque ligne un multiple de la ligne pivot pour annuler les termes sous le pivot, ce qui ne modifie pas le déterminant */

        for (prog->j = prog->i+1; prog->j <= prog->Nbr_Col; prog->j++) //
        {
            prog->multiplicateur = -prog->Valeur1[prog->i][prog->j]/prog->Valeur1[prog->i][prog->i];
            for (prog->ii = prog->i; prog->ii <= prog->Nbr_Col; prog->ii++)
            {
                prog->Valeur1[prog->ii][prog->j] += prog->Valeur1[prog->ii][prog->i]*prog->multiplicateur;
            }
        }

        /* La matrice est triangulaire. Son déterminant est le produit des termes de la diagonale */

        prog->deter *= prog->Valeur1[prog->i][prog->i];
    }
    if (prog->deter==0){prog->pLabel = gtk_label_new("La matrice n'est pas inversible car le déterminant est égal à 0");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);}

    /* On utilise la méthode de l'élimination de Jordan pour trouver les solutions. */

    else
    {for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {

        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {
            prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));
            if (prog->i == prog->j)
            {prog->Valeur_Resultat[prog->i][prog->j]=1;}
            else {prog->Valeur_Resultat[prog->i][prog->j]=0;}
        }
    }

    for(prog->i = 1; prog->i <= prog->Nbr_Lig; prog->i++)
    {
        prog->echange=prog->Valeur1[prog->i][prog->i];

        for (prog->j = 1; prog->j <= prog->Nbr_Lig; prog->j++)
        {
            prog->Valeur1[prog->j][prog->i]=prog->Valeur1[prog->j][prog->i]/prog->echange;
            prog->Valeur_Resultat[prog->j][prog->i]=prog->Valeur_Resultat[prog->j][prog->i]/prog->echange;
        }



            for (prog->ii = 1; prog->ii <= prog->Nbr_Col; prog->ii++)
            {
                if (prog->ii != prog->i)
                {
                    prog->multiplicateur=-prog->Valeur1[prog->i][prog->ii];

                    for(prog->k = 1; prog->k<=prog->Nbr_Col;prog->k++)
                    {
                        prog->Valeur1[prog->k][prog->ii] += prog->Valeur1[prog->k][prog->i]*prog->multiplicateur;
                        prog->Valeur_Resultat[prog->k][prog->ii] += prog->Valeur_Resultat[prog->k][prog->i]*prog->multiplicateur;
                    }

                }
            }
        }}

    if (prog->deter != 0)
    {for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {for(prog->j=1; prog->j<=prog->Nbr_Col;prog->j++)
    {
        prog->Text = g_strdup_printf("%.2f", prog->Valeur_Resultat[prog->j][prog->i]);
        prog->pLabel = gtk_label_new(prog->Text);
        gtk_table_attach(GTK_TABLE(prog->pTable_Result), prog->pLabel, prog->j-1, prog->j,prog->i-1,prog->i,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        g_free(prog->Text);
    }}}

    /* Création d'une box contenant 2 boutons */

    prog->pHBox=gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création des boutons */

    prog->Button = gtk_button_new_with_label("Enregistrer dans un fichier .txt"); //Permet d'appeler la fonction qui enregistre dans un fichier
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Boite_dialogue_fichier_addition_soustraction),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Retourner au menu principal"); // Appelle la fonction permettant de revenir au menu principal
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter"); // Affiche une boite de dialogue permettant de quitter l'application */
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowResultat);

}

/* Fonction appelée depuis le menu principal */

void Taille_Matrice_Systeme(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data; /*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création d'une fenetre */

    prog->pWindowTaille = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowTaille), "Taille de la matrice");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowTaille), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowTaille), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box contenant les differents elements */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowTaille), prog->pVBox);

    /* Création des zones de textes et des textes et insertion dans la box */

    prog->Nombre_Colonne = gtk_label_new("Entrer le nombre de colonnes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Colonne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Colonne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Colonne, TRUE, FALSE, 0);


    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de lignes de la matrice");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Nombre_Ligne = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Nombre_Ligne, TRUE, FALSE, 0);

    prog->Nombre_Ligne = gtk_label_new("Entrer le nombre de coordonnees du vecteur");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Nombre_Ligne, TRUE, FALSE, 0);

    prog->Entry_Dim = gtk_spin_button_new_with_range(1,300,1);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Entry_Dim, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Ok!");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Saisir_Matrice_Systeme),prog);

    gtk_widget_show_all(prog->pWindowTaille);
}

/* Fonction appelée lors du clic sur "Ok!" de la fonction précédente */

void Saisir_Matrice_Systeme(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* On récupére les valeurs */

    prog->Nbr_Col=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Colonne));
    prog->Nbr_Lig=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Nombre_Ligne));
    prog->Dim=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prog->Entry_Dim));

    /* Création de la fenetre */

    prog->pWindowDonnees = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowDonnees), "Saisie des donnees");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowDonnees), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowDonnees), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowDonnees), prog->pVBox);

    prog->pHBox = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création de la table grâce aux valeurs récupérées */

    prog->pTable1=gtk_table_new(prog->Nbr_Lig,prog->Nbr_Col, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->pTable1, TRUE, FALSE, 0);

    prog->pLabel=gtk_label_new("*");
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->pLabel, TRUE, FALSE, 0);

    prog->pBox = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->pBox, TRUE, FALSE, 0);

    prog->pTable_Result = gtk_table_new(prog->Nbr_Lig,1, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->pTable_Result, TRUE, FALSE, 0);

    for (prog->l=1;prog->l<=prog->Nbr_Lig;prog->l++)
    {
        prog->Text = g_strdup_printf("coeff%d \n", prog->l);
        prog->pLabel = gtk_label_new(prog->Text);
        g_free(prog->Text);
        gtk_box_pack_start(GTK_BOX(prog->pBox), prog->pLabel, TRUE, FALSE, 0);
    }

    prog->pTable2=gtk_table_new(prog->Nbr_Lig,1, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->pTable2, TRUE, FALSE, 0);

    /* Utilisation de 2 boucles for pour créer le bon nombre de cases */

    for(prog->i=1; prog->i<=prog->Nbr_Col;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Lig; prog->j++)
        {
            prog->Case1[prog->i][prog->j]= gtk_spin_button_new_with_range(-300,300,0.00000001);
            gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
            gtk_table_attach(GTK_TABLE(prog->pTable1), prog->Case1[prog->i][prog->j],prog->i-1, prog->i, prog->j-1, prog->j,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        }
    }
    for(prog->i=1; prog->i<=prog->Dim;prog->i++)
    {
        prog->Case2[1][prog->i]= gtk_spin_button_new_with_range(-300,300,0.00000001);
        gtk_spin_button_set_value(prog->Case1[prog->i][prog->j], 0);
        gtk_table_attach(GTK_TABLE(prog->pTable2), prog->Case2[1][prog->i],0, 1, prog->i-1, prog->i,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
    }

    /* Création du bouton appelant la fonction permettant de trouver les solutions si elles existent et de les afficher */

    prog->Button = gtk_button_new_with_label("Calculer!");
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Calcul_Systeme), prog);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowDonnees);
}

/* Fonction appelée lors du clic sur "Calculer!" de la fonction précédente */

void Calcul_Systeme(GtkWidget *widget, gpointer data)
{
    Structure *prog=(Structure *)data;/*Ligne qui permet de réutiliser toute les données de la structure principale */

    /* Création de la fenetre */

    prog->pWindowResultat = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(prog->pWindowResultat), "Resultat");
    gtk_window_set_default_size(GTK_WINDOW(prog->pWindowResultat), 320, 200);
    g_signal_connect(G_OBJECT(prog->pWindowResultat), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Création de la box */

    prog->pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(prog->pWindowResultat), prog->pVBox);

    prog->pTable_Result = gtk_table_new(prog->Nbr_Lig,1, TRUE);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pTable_Result, TRUE, FALSE, 0);

    /* On utilise la méthode du pivot de Gauss pour trouver le déterminant. */

    prog->deter=1;

    for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {

            prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));


        }
    }

    for(prog->i = 1; prog->i <= prog->Nbr_Lig; prog->i++) // Recherche du plus grand terme de la colonne i en valeur absolue.
    {
        prog-> max = 0;

        prog->k = prog->i;
        for (prog->j = prog->i; prog->j <= prog->Nbr_Col; prog->j++)
        {
            if (fabs(prog->Valeur1[prog->i][prog->j]) > prog->max)
            {
                prog-> max = fabs(prog->Valeur1[prog->i][prog->j]);
                 prog->k = prog->j;
            }
        }

        if (prog->k != prog->i) // On échange les lignes pour que l'élément le plus grand (le pivot) soit sur la diagonale
        {
            for(prog->j=1;prog->j<=prog->Nbr_Col;prog->j++)
            {prog->echange = prog->Valeur1[prog->j][prog->i];
            prog->Valeur1[prog->j][prog->i] = prog->Valeur1[prog->j][prog->k];
            prog->Valeur1[prog->j][prog->k] = prog->echange;}
            prog->deter *= -1; // Échange de lignes : le déterminant est changé en son opposé

        }

        /* on ajoute à chaque ligne un multiple de la ligne pivot pour annuler les termes sous le pivot, ce qui ne modifie pas le déterminant */

        for (prog->j = prog->i+1; prog->j <= prog->Nbr_Col; prog->j++) //
        {
            prog->multiplicateur = -prog->Valeur1[prog->i][prog->j]/prog->Valeur1[prog->i][prog->i];
            for (prog->ii = prog->i; prog->ii <= prog->Nbr_Col; prog->ii++)
            {
                prog->Valeur1[prog->ii][prog->j] += prog->Valeur1[prog->ii][prog->i]*prog->multiplicateur;
            }

        }

        /* La matrice est triangulaire. Son déterminant est le produit des termes de la diagonale */

        prog->deter *= prog->Valeur1[prog->i][prog->i];
    }

    if (prog->deter==0){prog->pLabel = gtk_label_new("Il n'y a pas de solutions a ce systeme");
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pLabel, TRUE, FALSE, 0);}

    /* On utilise la méthode de l'élimination de Jordan pour trouver les solutions. */
    else
    {for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        prog->Valeur2[1][prog->i]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case2[1][prog->i]));
        for(prog->j=1; prog->j<=prog->Nbr_Col; prog->j++)
        {
            prog->Valeur1[prog->i][prog->j]=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(prog->Case1[prog->i][prog->j]));
        }
    }

    for(prog->i = 1; prog->i <= prog->Nbr_Lig; prog->i++)
    {
        prog->echange=prog->Valeur1[prog->i][prog->i];

        for (prog->j = 1; prog->j <= prog->Nbr_Lig; prog->j++)
        {
            prog->Valeur1[prog->j][prog->i]=prog->Valeur1[prog->j][prog->i]/prog->echange;

        }
            prog->Valeur2[1][prog->i]=prog->Valeur2[1][prog->i]/prog->echange;


            for (prog->ii = 1; prog->ii <= prog->Nbr_Col; prog->ii++)
            {
                if (prog->ii != prog->i)
                {
                    prog->multiplicateur=-prog->Valeur1[prog->i][prog->ii];

                    for(prog->k = 1; prog->k<=prog->Nbr_Col;prog->k++)
                    {
                        prog->Valeur1[prog->k][prog->ii] += prog->Valeur1[prog->k][prog->i]*prog->multiplicateur;
                    }
                prog->Valeur2[1][prog->ii] += prog->Valeur2[1][prog->i]*prog->multiplicateur;
                }
            }
        }}
    if (prog->deter != 0)
    {for(prog->i=1; prog->i<=prog->Nbr_Lig;prog->i++)
    {
        prog->Text = g_strdup_printf("%.2f\n", prog->Valeur2[1][prog->i]);
        prog->pLabel = gtk_label_new(prog->Text);
        gtk_table_attach(GTK_TABLE(prog->pTable_Result), prog->pLabel, 0, 1,prog->i-1,prog->i,GTK_EXPAND | GTK_FILL, GTK_EXPAND| GTK_FILL, 0, 0);
        g_free(prog->Text);
    }}

    /* Création d'une box contenant 2 boutons */

    prog->pHBox=gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(prog->pVBox), prog->pHBox, TRUE, FALSE, 0);

    /* Création des boutons */

    prog->Button = gtk_button_new_with_label("Retourner au menu principal"); // Appelle la fonction permettant de revenir au menu principal
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(Retour),prog);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    prog->Button = gtk_button_new_with_label("Quitter"); // Affiche une boite de dialogue permettant de quitter l'application */
    g_signal_connect(G_OBJECT(prog->Button), "clicked", G_CALLBACK(OnQuitter),(GtkWidget*) prog->pWindowResultat);
    gtk_box_pack_start(GTK_BOX(prog->pHBox), prog->Button, TRUE, FALSE, 0);

    gtk_widget_show_all(prog->pWindowResultat);
}
