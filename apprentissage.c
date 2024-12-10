#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_JOUEURS 999

void afficherAnimaux();
void afficherMaison();
void afficherTravail();
void afficherLoisirs();
void jouerMotsCategorie(int joueurIndex, int categorie);


typedef struct {
    char identifiant[50];
    char motdepasse[100];
    char pseudo[50];
    int score;
} Joueur;

Joueur joueurs[MAX_JOUEURS];
int nbJoueurs = 0;
int choix;

char pseudoPrecedent[50];

void fonctionConnect();

void sauvegarderJoueurs() {
    FILE *fichier = fopen("joueurs.txt", "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nbJoueurs; ++i) {
        fprintf(fichier, "%s %s %s %d\n", joueurs[i].identifiant, joueurs[i].motdepasse, joueurs[i].pseudo, joueurs[i].score);
    }

    fclose(fichier);
}

void chargerJoueurs() {
    FILE *fichier = fopen("joueurs.txt", "r");
    if (fichier == NULL) {
        return;
    }

    nbJoueurs = 0;

    while (fscanf(fichier, "%s %s %s %d", joueurs[nbJoueurs].identifiant, joueurs[nbJoueurs].motdepasse, joueurs[nbJoueurs].pseudo, &joueurs[nbJoueurs].score) == 4) {
        nbJoueurs++;
        if (nbJoueurs >= MAX_JOUEURS) {
            break;
        }
    }

    fclose(fichier);
}


int comparaisonScores(const void *a, const void *b) {
    return ((Joueur *)b)->score - ((Joueur *)a)->score;
}

void trierJoueurs() {
    qsort(joueurs, nbJoueurs, sizeof(Joueur), comparaisonScores);
}

void afficherClassement() {
    printf("\nClassement :\n");
    for (int i = 0; i < nbJoueurs; ++i) {
        printf("%d. %s - Score : %d points\n", i + 1, joueurs[i].pseudo, joueurs[i].score);
    }

    if (nbJoueurs > 1) {
        printf("Joueur précédent : %s\n", pseudoPrecedent);
    }
}

void jouerMotAleatoire(int joueurIndex) {
    int choixCategorie;

    printf("Choisissez une catégorie :\n");
    printf("1. Animaux\n");
    printf("2. Maison\n");
    printf("3. Travail\n");
    printf("4. Loisirs\n");

    scanf("%d", &choixCategorie);

    switch (choixCategorie) {
        case 1:
            jouerMotsCategorie(joueurIndex, 1);
            break;
        case 2:
            jouerMotsCategorie(joueurIndex, 2);
            break;
        case 3:
            jouerMotsCategorie(joueurIndex, 3);
            break;
        case 4:
            jouerMotsCategorie(joueurIndex, 4);
            break;
        default:
            printf("Catégorie non valide.\n");
            return;
    }
}

void melangerMots(char **nomsFrancais, char **nomsAnglais, int taille) {
    for (int i = 0; i < taille; i++) {
        int j = rand() % taille;

        char *tempFrancais = nomsFrancais[i];
        nomsFrancais[i] = nomsFrancais[j];
        nomsFrancais[j] = tempFrancais;

        char *tempAnglais = nomsAnglais[i];
        nomsAnglais[i] = nomsAnglais[j];
        nomsAnglais[j] = tempAnglais;
    }
}


void jouerMotsCategorie(int joueurIndex, int categorie) {
    char *nomsFrancais[31];
    char *nomsAnglais[31];
    int i;

switch (categorie) {
        case 1:  // Animaux
    nomsFrancais[0] = "chien"; nomsAnglais[0] = "dog";
    nomsFrancais[1] = "chat"; nomsAnglais[1] = "cat";
    nomsFrancais[2] = "oiseau"; nomsAnglais[2] = "bird";
    nomsFrancais[3] = "poisson"; nomsAnglais[3] = "fish";
    nomsFrancais[4] = "éléphant"; nomsAnglais[4] = "elephant";
    nomsFrancais[5] = "tigre"; nomsAnglais[5] = "tiger";
    nomsFrancais[6] = "souris"; nomsAnglais[6] = "mouse";
    nomsFrancais[7] = "serpent"; nomsAnglais[7] = "snake";
    nomsFrancais[8] = "cheval"; nomsAnglais[8] = "horse";
    nomsFrancais[9] = "papillon"; nomsAnglais[9] = "butterfly";
    nomsFrancais[10] = "vache"; nomsAnglais[10] = "cow";
    nomsFrancais[11] = "poulet"; nomsAnglais[11] = "chicken";
    nomsFrancais[12] = "cochon"; nomsAnglais[12] = "pig";
    nomsFrancais[13] = "canard"; nomsAnglais[13] = "duck";
    nomsFrancais[14] = "chevre"; nomsAnglais[14] = "goat";
    nomsFrancais[15] = "lapin"; nomsAnglais[15] = "rabbit";
    nomsFrancais[16] = "ours"; nomsAnglais[16] = "bear";
    nomsFrancais[17] = "loup"; nomsAnglais[17] = "wolf";
    nomsFrancais[18] = "pengouin"; nomsAnglais[18] = "penguin";
    nomsFrancais[19] = "girafe"; nomsAnglais[19] = "giraffe";
    nomsFrancais[20] = "koala"; nomsAnglais[20] = "koala";
    nomsFrancais[21] = "hippopotame"; nomsAnglais[21] = "hippopotamus";
    nomsFrancais[22] = "écureuil"; nomsAnglais[22] = "squirrel";
    nomsFrancais[23] = "lion"; nomsAnglais[23] = "lion";
    nomsFrancais[24] = "tortue"; nomsAnglais[24] = "turtle";
    nomsFrancais[25] = "abeille"; nomsAnglais[25] = "bee";
    nomsFrancais[26] = "panda"; nomsAnglais[26] = "panda";
    nomsFrancais[27] = "renard"; nomsAnglais[27] = "fox";
    nomsFrancais[28] = "crocodile"; nomsAnglais[28] = "crocodile";
    nomsFrancais[29] = "léopard"; nomsAnglais[29] = "leopard";
    break;
        case 2:  // Maison
    nomsFrancais[0] = "maison"; nomsAnglais[0] = "house";
    nomsFrancais[1] = "chambre"; nomsAnglais[1] = "bedroom";
    nomsFrancais[2] = "cuisine"; nomsAnglais[2] = "kitchen";
    nomsFrancais[3] = "salle de bain"; nomsAnglais[3] = "bathroom";
    nomsFrancais[4] = "salon"; nomsAnglais[4] = "living room";
    nomsFrancais[5] = "fenêtre"; nomsAnglais[5] = "window";
    nomsFrancais[6] = "porte"; nomsAnglais[6] = "door";
    nomsFrancais[7] = "lit"; nomsAnglais[7] = "bed";
    nomsFrancais[8] = "table"; nomsAnglais[8] = "table";
    nomsFrancais[9] = "chaise"; nomsAnglais[9] = "chair";
    nomsFrancais[10] = "bureau"; nomsAnglais[10] = "desk";
    nomsFrancais[11] = "tapis"; nomsAnglais[11] = "carpet";
    nomsFrancais[12] = "rideau"; nomsAnglais[12] = "curtain";
    nomsFrancais[13] = "étagère"; nomsAnglais[13] = "shelf";
    nomsFrancais[14] = "lampe"; nomsAnglais[14] = "lamp";
    nomsFrancais[15] = "miroir"; nomsAnglais[15] = "mirror";
    nomsFrancais[16] = "clé"; nomsAnglais[16] = "key";
    nomsFrancais[17] = "télévision"; nomsAnglais[17] = "television";
    nomsFrancais[18] = "escalier"; nomsAnglais[18] = "stairs";
    nomsFrancais[19] = "ordinateur"; nomsAnglais[19] = "computer";
    nomsFrancais[20] = "sac"; nomsAnglais[20] = "bag";
    nomsFrancais[21] = "fenêtre"; nomsAnglais[21] = "window";
    nomsFrancais[22] = "toit"; nomsAnglais[22] = "roof";
    nomsFrancais[23] = "garage"; nomsAnglais[23] = "garage";
    nomsFrancais[24] = "horloge"; nomsAnglais[24] = "clock";
    nomsFrancais[25] = "plante"; nomsAnglais[25] = "plant";
    nomsFrancais[26] = "armoire"; nomsAnglais[26] = "wardrobe";
    nomsFrancais[27] = "rideau"; nomsAnglais[27] = "curtain";
    nomsFrancais[28] = "clé"; nomsAnglais[28] = "key";
    nomsFrancais[29] = "chapeau"; nomsAnglais[29] = "hat";
    break;
        case 3:  // Travail
    nomsFrancais[0] = "bureau"; nomsAnglais[0] = "office";
    nomsFrancais[1] = "ordinateur"; nomsAnglais[1] = "computer";
    nomsFrancais[2] = "réunion"; nomsAnglais[2] = "meeting";
    nomsFrancais[3] = "projet"; nomsAnglais[3] = "project";
    nomsFrancais[4] = "client"; nomsAnglais[4] = "client";
    nomsFrancais[5] = "collègue"; nomsAnglais[5] = "colleague";
    nomsFrancais[6] = "travailleur"; nomsAnglais[6] = "worker";
    nomsFrancais[7] = "récompense"; nomsAnglais[7] = "reward";
    nomsFrancais[8] = "présentation"; nomsAnglais[8] = "presentation";
    nomsFrancais[9] = "salaire"; nomsAnglais[9] = "salary";
    nomsFrancais[10] = "manager"; nomsAnglais[10] = "manager";
    nomsFrancais[11] = "projet"; nomsAnglais[11] = "project";
    nomsFrancais[12] = "client"; nomsAnglais[12] = "client";
    nomsFrancais[13] = "équipe"; nomsAnglais[13] = "team";
    nomsFrancais[14] = "tâche"; nomsAnglais[14] = "task";
    nomsFrancais[15] = "présentation"; nomsAnglais[15] = "presentation";
    nomsFrancais[16] = "bureau"; nomsAnglais[16] = "desk";
    nomsFrancais[17] = "ordinateur"; nomsAnglais[17] = "computer";
    nomsFrancais[18] = "collaboration"; nomsAnglais[18] = "collaboration";
    nomsFrancais[19] = "chef"; nomsAnglais[19] = "boss";
    nomsFrancais[20] = "salaire"; nomsAnglais[20] = "salary";
    nomsFrancais[21] = "promotion"; nomsAnglais[21] = "promotion";
    nomsFrancais[22] = "congé"; nomsAnglais[22] = "vacation";
    nomsFrancais[23] = "réunion"; nomsAnglais[23] = "meeting";
    nomsFrancais[24] = "email"; nomsAnglais[24] = "email";
    nomsFrancais[25] = "mission"; nomsAnglais[25] = "mission";
    nomsFrancais[26] = "entretien"; nomsAnglais[26] = "interview";
    nomsFrancais[27] = "projet"; nomsAnglais[27] = "project";
    nomsFrancais[28] = "travailleur"; nomsAnglais[28] = "worker";
    nomsFrancais[29] = "présentation"; nomsAnglais[29] = "presentation";
    break;
        case 4:  // Loisirs
    nomsFrancais[0] = "lecture"; nomsAnglais[0] = "reading";
    nomsFrancais[1] = "cinéma"; nomsAnglais[1] = "cinema";
    nomsFrancais[2] = "musique"; nomsAnglais[2] = "music";
    nomsFrancais[3] = "voyage"; nomsAnglais[3] = "travel";
    nomsFrancais[4] = "sport"; nomsAnglais[4] = "sport";
    nomsFrancais[5] = "peinture"; nomsAnglais[5] = "painting";
    nomsFrancais[6] = "jardinage"; nomsAnglais[6] = "gardening";
    nomsFrancais[7] = "cuisine"; nomsAnglais[7] = "cooking";
    nomsFrancais[8] = "lecture"; nomsAnglais[8] = "reading";
    nomsFrancais[9] = "photographie"; nomsAnglais[9] = "photography";
    nomsFrancais[10] = "théâtre"; nomsAnglais[10] = "theater";
    nomsFrancais[11] = "danse"; nomsAnglais[11] = "dance";
    nomsFrancais[12] = "concert"; nomsAnglais[12] = "concert";
    nomsFrancais[13] = "bricolage"; nomsAnglais[13] = "DIY";
    nomsFrancais[14] = "puzzle"; nomsAnglais[14] = "puzzle";
    nomsFrancais[15] = "plage"; nomsAnglais[15] = "beach";
    nomsFrancais[16] = "camping"; nomsAnglais[16] = "camping";
    nomsFrancais[17] = "vélo"; nomsAnglais[17] = "cycling";
    nomsFrancais[18] = "pêche"; nomsAnglais[18] = "fishing";
    nomsFrancais[19] = "yoga"; nomsAnglais[19] = "yoga";
    nomsFrancais[20] = "escalade"; nomsAnglais[20] = "climbing";
    nomsFrancais[21] = "photographie"; nomsAnglais[21] = "photography";
    nomsFrancais[22] = "karaoké"; nomsAnglais[22] = "karaoke";
    nomsFrancais[23] = "chasse"; nomsAnglais[23] = "hunting";
    nomsFrancais[24] = "jouer"; nomsAnglais[24] = "gaming";
    nomsFrancais[25] = "peinture"; nomsAnglais[25] = "painting";
    nomsFrancais[26] = "lire"; nomsAnglais[26] = "reading";
    nomsFrancais[27] = "voyage"; nomsAnglais[27] = "travel";
    nomsFrancais[28] = "natation"; nomsAnglais[28] = "swimming";
    nomsFrancais[29] = "cuisine"; nomsAnglais[29] = "cooking";
    break;
        default:
            printf("Catégorie non valide.\n");
            return;
    }
        melangerMots(nomsFrancais, nomsAnglais, 30);

    for (i = 0; i < 5; i++) {
        printf("Mot en français : %s\n", nomsFrancais[i]);

        char reponse[50];
        printf("Traduisez le mot en anglais : ");
        scanf(" %[^\n]", reponse);

        if (strcmp(reponse, nomsAnglais[i]) == 0) {
            printf("Correct ! +10 points\n");
            joueurs[joueurIndex].score += 10;
        } else {
            printf("Incorrect. Aucun point.\n");
        }
    }

    printf("Fin du mode Association de mots. Vous avez obtenu %d points.\n", joueurs[joueurIndex].score);
    trierJoueurs();
    afficherClassement();
}

void vraiFaux(int joueurIndex) {
    int score = 0;

    printf("Vrai/Faux - Indiquez si les phrases suivantes sont vraies ou fausses :\n");

    char *phrasesAnglaises[] = {"The moon is made of cheese.", "Fish can climb trees.", "Insects have six legs.", "Chocolate comes from cactus.", "Penguins can fly.", "Mount Everest is the tallest mountain on Earth.", "Cats and dogs are the same species.", "The speed of light is faster than the speed of sound.", "Humans only use 10% of their brains.", "Spiders are insects." };

    int reponsesAttendues[] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0};


    for (int i = 0; i < 5; ++i) {
        printf("%d. %s\n", i + 1, phrasesAnglaises[i]);

        int reponseUtilisateur;
        printf("Vrai (1) / Faux (0) : ");
        scanf("%d", &reponseUtilisateur);

        if (reponseUtilisateur == reponsesAttendues[i]) {
            printf("Correct ! +10 points\n");
            score += 10;
        } else {
            printf("Incorrect. Aucun point.\n");
        }
    }

    joueurs[joueurIndex].score += score;
    printf("Fin du mode Vrai/Faux. Vous avez obtenu %d points.\n", score);
    trierJoueurs();
    afficherClassement();
}

void traduirePhrases(int joueurIndex) {
    for (int i = 0; i < 5; ++i) {
        int indicePhrase = rand() % 5;

        char *phrasesFrancaises[] = { "Le soleil se lève à l'est.","Les chats peuvent voler.","La programmation est amusante.", "L'eau bout à 100 degrés Celsius.","Paris est la capitale de l'Angleterre."};

        char *phrasesAnglaises[] = {"The sun rises in the east.", "Cats can fly.", "Programming is fun.", "Water boils at 100 degrees Celsius.", "Paris is the capital of England."};

        char reponse[100];
        printf("Traduisez la phrase suivante en anglais : \"%s\"\n", phrasesFrancaises[indicePhrase]);
        scanf(" %[^\n]", reponse);

        if (strcmp(reponse, phrasesAnglaises[indicePhrase]) == 0) {
            printf("Correct ! +20 points\n");
            joueurs[joueurIndex].score += 20;
        } else {
            printf("Incorrect. -10 points\n");
            joueurs[joueurIndex].score -= 10;
        }
    }
    trierJoueurs();
    afficherClassement();
}

char *phrases[] = {
    "The ......... is a domestic animal that meows.",
    "The ......... is a motorized means of transportation.",
    "The ......... is a hot drink often consumed in the morning.",
    "The ......... is a stringed musical instrument.",
    "The ......... is a yellow and curved fruit.",
    "The ......... is a planet in the solar system.",
    "The ......... is a language spoken in Spain.",
    "The ......... is an insect that produces honey.",
    "The ......... is a season when it is cold.",
    "The ......... is a color between blue and green."
};

char *motsPossibles[][3] = {
    {"dog", "cat", "bird"},
    {"plane", "computer", "car"},
    {"tea", "coffee", "juice"},
    {"piano", "guitar", "violin"},
    {"banana", "apple", "strawberry"},
    {"Earth", "Mars", "Venus"},
    {"French", "Spanish", "German"},
    {"bee", "butterfly", "mosquito"},
    {"winter", "summer", "autumn"},
    {"green", "red", "yellow"}
};

void completerPhrases(int joueurIndex) {
    srand(time(NULL));

    for (int i = 0; i < 5; ++i) {
        int indicePhrase = rand() % 10;

        int indiceMotManquant = rand() % 3;

        printf("Complete the sentence:\n%s\n", phrases[indicePhrase]);

        for (int j = 0; j < 3; ++j) {
            printf("%d. %s\n", j + 1, motsPossibles[indicePhrase][j]);
        }

        int choixUtilisateur;
        printf("Your choice (1, 2, or 3): ");
        scanf("%d", &choixUtilisateur);

        while(getchar() != '\n');

        if (choixUtilisateur == indiceMotManquant + 1) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is: %s\n", motsPossibles[indicePhrase][indiceMotManquant]);
        }
    }
    trierJoueurs();
    afficherClassement();
}

void choisirModeJeu(int joueurIndex) {
    printf("Choisissez le mode de jeu :\n");
    printf("1: Association de mots\n");
    printf("2: Vrai ou faux\n");
    printf("3: Traduction des phrases\n");
    printf("4: Compléter les phrases à trou\n");

    scanf("%d", &choix);

    switch (choix) {
        case 1:
            jouerMotAleatoire (joueurIndex);
            break;
        case 2:
            vraiFaux(joueurIndex);
            break;
        case 3:
            traduirePhrases(joueurIndex);
            break;
        case 4:
            completerPhrases(joueurIndex);
            break;

        default:
            printf("Mode de jeu non valide.\n");
            break;
    }
}

int sessionJoueur = -1;

void fonctionFormulaire() {
    if (nbJoueurs < MAX_JOUEURS) {
        printf("Entrez un Identifiant : ");
        scanf("%s", joueurs[nbJoueurs].identifiant);

        bool identifiantExiste = false;
        for (int i = 0; i < nbJoueurs; ++i) {
            if (strcmp(joueurs[nbJoueurs].identifiant, joueurs[i].identifiant) == 0) {
                identifiantExiste = true;
                break;
            }
        }

        if (identifiantExiste) {
            printf("Cet identifiant est déjà utilisé. Veuillez choisir un autre identifiant.\n");
            return;
        }

        printf("Entrez un Mot de passe : ");
        scanf("%s", joueurs[nbJoueurs].motdepasse);

        printf("Entrez un Pseudonyme : ");
        scanf("%s", joueurs[nbJoueurs].pseudo);

        strcpy(pseudoPrecedent, joueurs[nbJoueurs].pseudo);

        printf("Inscription réussie.\n");
        nbJoueurs++;

        sauvegarderJoueurs();
    } else {
        printf("Nombre maximal de joueurs atteint.\n");
    }
}

void fonctionConnect() {
    chargerJoueurs();

    char identifiant[50];
    char motdepasse[100];

    printf("Identifiant : ");
    scanf("%s", identifiant);

    printf("Mot de passe : ");
    scanf("%s", motdepasse);

    int joueurTrouve = -1;
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(identifiant, joueurs[i].identifiant) == 0 && strcmp(motdepasse, joueurs[i].motdepasse) == 0) {
            joueurTrouve = i;
            break;
        }
    }

    if (joueurTrouve != -1) {
        printf("Connexion réussie.\n");

        sessionJoueur = joueurTrouve;

        choisirModeJeu(joueurTrouve);
    } else {
        printf("Identifiant ou mot de passe incorrect.\n");
    }

    sauvegarderJoueurs();
}

void fonctionConnection() {
    printf("(1): Se connecter\n(2): S'inscrire\n");
    scanf("%d", &choix);

    if (choix == 1 || choix == 2) {
        if (choix == 1) {
            fonctionConnect();
        } else {
            fonctionFormulaire();
        }
    } else {
        printf("Choix non valide.\n");
    }
}

int main() {
    srand(time(NULL));
    printf("Bienvenue dans le jeu\n");

    chargerJoueurs();
    fonctionConnection();

    return 0;
}
