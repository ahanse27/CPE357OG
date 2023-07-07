#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.h"
#define NUMHEADER   52





void displayCounty(){

    FILE *demoFile = fopen("small.csv", "r");
    char *line = NULL;
    char *indVar = NULL;
    char *indHeader = NULL;
    char *varArray[10000];
    char *headerArray[10000];
    char *delim = ",";
    char *ewa = "Ethnicities.White Alon"; 
    char * nholFix = "not Hispanic or Latino";
    char * ewaFix = "Ethnicities.White Alone not Hispanic or Latino";
    size_t len = 0;
    size_t read = 0;
    int lineCount = 0;
    int x = 0;
    int k = 0;

    if(demoFile == NULL){
        fprintf(stderr, "Unable to open file!");
        exit(1);
    }

    while((read = getline(&line, &len, demoFile) != -1)){
        if(lineCount == 0){                                                                     /* the first line of the file is the headers */
            while((indHeader = strsep(&line, delim)) != NULL){                                  /* while loop creates an array for the headers */
                char* headerCopy = strdup(indHeader);                                           /* makes a copy of the header */
                char *result = headerCopy+1;                                                    /* removes first " */               
                result[strlen(result)-1] = '\0';                                                /* removes last " */
                if(strcmp(result, ewa) == 0){                                                   /* fixes a mistake in the file */
                    result = ewaFix;
                    headerArray[x] = result;
                    x++;
                }
                else if(strcmp(result, nholFix) == 0){                                          /* fixes a mistake in the file */
                    result = NULL;
                }
                else{
                    if(x == 51){
                        char *finSubEntry = result;
                        finSubEntry[strlen(finSubEntry)-1] = '\0';                              /* removes final quote from last subEntry*/
                        headerArray[x] = finSubEntry;
                        x++;
                    }
                    headerArray[x] = result;
                    x++;
                }
            }
            x = 0;
        }
        if(lineCount > 0){
            while((indVar = strsep(&line, delim)) != NULL){
                char* indVarCopy = strdup(indVar);                                              /* makes a copy of the variabler */
                char *result = indVarCopy+1;                                                    /* removes first " */               
                result[strlen(result)-1] = '\0';                                                /* removes last " */
                if(x == 51){
                    char *finSubEntry = result;
                    finSubEntry[strlen(finSubEntry)-1] = '\0';                              /* removes final quote from last subEntry*/
                    varArray[x] = finSubEntry;
                    x++;
                }
                varArray[x] =result;
                x++;
            }
            x = 0;
            for(k = 0; k < 52; k++){                                                            /* There are 52 sub-entries for each entry read */
                printf("%s: ", headerArray[k]);
                printf("%s \n", varArray[k]);
            }
        }
        lineCount++;
        printf(" \n");
    }

    //tidy up
    free(line);
    fclose(demoFile);
}


int main(){
    
    displayCounty();

    return 0;
}
