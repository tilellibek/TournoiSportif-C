#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TEAMS 20
#define MAX_TEAM_NAME 50

int main() {
int ks, sk;
pid_t pid[10];
char win1[10];
char win2[10];
int l1,l2,l3;
int round1[6];
int round2[6];
int round3[6];



printf("\nVeuillez patienter...\n");  //écrire le message d’attente
printf("match 1 est  entrain de joué...\n");
    
    sleep(7); 
    
    
printf("\nVeuillez patienter..\n");  
printf("Le match 2 est en train d'être joué...\n");
    
sleep(6);  // Pause l'exécution pendant 5 secondes



printf("\nVeuillez patienter...\n"); 
printf("la finale est entrain de jouée... \n");
    
    sleep(5);

printf("\n le programme est fini veuillez voir le fichier de sortie ");
    
int match_count = 0;


    char teamNames[MAX_TEAMS][MAX_TEAM_NAME];
    int numTeams = 0;
    char teamA[MAX_TEAM_NAME], teamB[MAX_TEAM_NAME];
    int teamAScore1, teamBScore1, teamAScore2, teamBScore2, teamAScore3, teamBScore3;
    int i, j, k,l;
// Ouvrir le fichier d'entrée et lire tous les noms des équipes.
    FILE* inputFile = fopen("teams.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    while (fgets(teamNames[numTeams], MAX_TEAM_NAME, inputFile) != NULL) {
       // Supprimer le caractère de nouvelle ligne à la fin de la chaîne de caractères.
        teamNames[numTeams][strcspn(teamNames[numTeams], "\n")] = '\0';
        numTeams++;
    }
    fclose(inputFile);

    // Initialiser le générateur de nombres aléatoires.
    srand(time(NULL));

pid[match_count] = fork();

if(pid[match_count]==0)
{
// Sélectionner deux équipes au hasard pour le match 1.
    i = rand() % numTeams;
    j = rand() % numTeams;

    while (j == i) {
        j = rand() % numTeams;
    }
    strcpy(teamA, teamNames[i]);
    strcpy(teamB, teamNames[j]);
     sk = i; ks = j;
   // Simuler le match 1.
    
    teamAScore1 = rand() % 6;
    teamBScore1 = rand() % 6;
    printf("%s %d - %d %s\n", teamA, teamAScore1, teamBScore1, teamB);




	if(teamAScore1>teamBScore1)
	{
		strcpy(win1,teamA);
	}
	else
	{
		strcpy(win1,teamB);
		
	}
	
	printf("\nThe Winner of Match 1 is %s", win1);
	printf("\n");

}

 match_count++;
 
 pid[match_count] = fork();

if(pid[match_count]==0)
{

    // Sélectionner deux équipes au hasard pour le match 2.
    k = rand() % numTeams;
    while (1) {
        k = rand() % numTeams;
        if(k != i && k != j)
        {
        	break;
		}
    }
    strcpy(teamA, teamNames[k]);

    l = rand() % numTeams;
    while (1) {
        l = rand() % numTeams;
        if(l!=k && l!= sk && l!= ks){
        	break;
		}
    }
    strcpy(teamB, teamNames[l]);

    // simuler match 2 
    teamAScore2 = rand() % 6;
    teamBScore2 = rand() % 6;
     printf("%s %d - %d %s\n", teamA, teamAScore2, teamBScore2, teamB);


	if(teamAScore2>teamBScore2)
	{
		strcpy(win2,teamA);
	}
	else
	{
		strcpy(win2,teamB);
		
	}
	
 printf("\nThe Winner of Match 2 is : %s", win2);

printf("\n");

}
  // Sleep pour 5 s

match_count++;
pid[match_count] = fork();

if(pid[match_count]==0)
{
}

    //sélectionne deux équipes pour le match final
   if (teamAScore1 + teamAScore2 > teamBScore1 + teamBScore2) {
        strcpy(teamA, win1);
    } else if (teamAScore1 + teamAScore2 < teamBScore1 + teamBScore2) {
        strcpy(teamA, win2);
    } else {
       
        i = rand() % numTeams;
        j = rand() % numTeams;
        while (j == i) {
           j = rand() % numTeams;
       }
        strcpy(teamA, win1);
        strcpy(teamB, win2);
    }

    // simuler le match de la finale 
    

teamAScore3 = rand() % 6;
teamBScore3 = rand() % 6;
printf("%s %d - %d %s\n", win1, teamAScore3, teamBScore3, win2);
// ouvrir output
FILE* outputFile = fopen("output.txt", "w");
if (outputFile == NULL) {
    printf("Error opening output file\n");
    return 1;
}
//écrire les statistiques des matchs dans le fichier de sortie
fprintf(outputFile, "Match 1:");

fprintf(outputFile, "\nRound 1: \n%s %s %d %s %s %s %d", teamNames[i], " gets ", rand() % 6, " points and ",teamNames[j] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 2: \n%s %s %d %s %s %s %d", teamNames[i], " gets ", rand() % 6, " points and ",teamNames[j] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 3: \n%s %s %d %s %s %s %d", teamNames[i], " gets ", rand() % 6, " points and ",teamNames[j] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 4: \n%s %s %d %s %s %s %d", teamNames[i], " gets ", rand() % 6, " points and ",teamNames[j] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 5: \n%s %s %d %s %s %s %d", teamNames[i], " gets ", rand() % 6, " points and ",teamNames[j] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 6: \n%s %s %d %s %s %s %d", teamNames[i], " gets ", rand() % 6, " points and ",teamNames[j] , " gets ", rand() % 5);
fprintf(outputFile, "\nFinal Round: \n %s %d - %d %s", teamNames[i], teamAScore1, teamBScore1, teamNames[j]);

fprintf(outputFile, "\n\nMatch 2:");


fprintf(outputFile, "\nRound 1: \n%s %s %d %s %s %s %d", teamNames[k], " gets ", rand() % 6, " points and ",teamNames[l] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 2: \n%s %s %d %s %s %s %d", teamNames[k], " gets ", rand() % 6, " points and ",teamNames[l] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 3: \n%s %s %d %s %s %s %d", teamNames[k], " gets ", rand() % 6, " points and ",teamNames[l] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 4: \n%s %s %d %s %s %s %d", teamNames[k], " gets ", rand() % 6, " points and ",teamNames[l] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 5: \n%s %s %d %s %s %s %d", teamNames[k], " gets ", rand() % 6, " points and ",teamNames[l] , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 6: \n%s %s %d %s %s %s %d", teamNames[k], " gets ", rand() % 6, " points and ",teamNames[l] , " gets ", rand() % 5);
fprintf(outputFile, "\nFinal Round:\n %s %d - %d  %s", teamNames[k], teamAScore2, teamBScore2, teamNames[l]);

fprintf(outputFile, "\n\nFinal Match:");


fprintf(outputFile, "\nRound 1: \n%s %s %d %s %s %s %d", win1, " gets ", rand() % 6, " points and ",win2 , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 2: \n%s %s %d %s %s %s %d", win1, " gets ", rand() % 6, " points and ",win2 , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 3: \n%s %s %d %s %s %s %d", win1, " gets ", rand() % 6, " points and ",win2 , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 4: \n%s %s %d %s %s %s %d", win1, " gets ", rand() % 6, " points and ",win2 , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 5: \n%s %s %d %s %s %s %d", win1, " gets ", rand() % 6, " points and ",win2 , " gets ", rand() % 5);
fprintf(outputFile, "\nRound 6: \n%s %s %d %s %s %s %d", win1, " gets ", rand() % 6, " points and ",win2 , " gets ", rand() % 5);
fprintf(outputFile, "\nFinal Round:\n %s %d - %d %s", win1, teamAScore3, teamBScore3, win2);


if(teamAScore3>teamBScore3)
fprintf(outputFile, "\n\nL'équipe gagnante est donc: %s", win1);

else
fprintf(outputFile, "\n\nL'équipe gagnante est donc: %s", win2);



// fermer le fichier de sortie 
fclose(outputFile);



return 0;

}
