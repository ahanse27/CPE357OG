

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
                char* indVarCopy = strdup(indVar);                                              /* makes a copy of the variable */
                char *result = indVarCopy+1;                                                    /* removes first " */               
                result[strlen(result)-1] = '\0';                                                /* removes last " */
                if(x == 51){
                    char *finSubEntry = result;
                    finSubEntry[strlen(finSubEntry)-1] = '\0';                                   /* removes final quote from last subEntry*/
                    varArray[x] = finSubEntry;
                    x++;
                }
                varArray[x] =result;
                x++;
            }
            x = 0;
            for(k = 0; k < NUMHEADER; k++){                                                      /* There are 52 sub-entries for each entry read */
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

int getNumEntries(){
    FILE *demoFile = fopen("small.csv", "r");  
    char c;
    int count;
    if(demoFile == NULL){
        perror("ERROR: ");
        exit(-1);
    }
    printf("file opened successfully\n");
    
    for (c = getc(demoFile); c != EOF; c = getc(demoFile)){
        if (c == '\n'){
            count = count + 1;
        }
    }
    int finCount = count -1;
    printf("Number of entries in file is %d\n", finCount);
    fclose(demoFile);
    return finCount;
}

struct Entry *createEntry(int finCount){
    printf("Entered createEntry \n");
    FILE *demoFile = fopen("small.csv", "r"); 
    struct Entry *entryBuffer = calloc(finCount, sizeof(struct Entry));
    if(!entryBuffer){
        perror("ERROR: calloc failed");
        exit(-1);
    }
    char* line = NULL;
    char *indVar = NULL;
    char *delim = ",";
    int lineCount = 0;
    int x = 0;
    int i = 0;
    size_t read = 0;
    size_t len = 0;

    
    while((read = getline(&line, &len, demoFile) != -1)){                   /* read until the end of the file */
        if(lineCount == 0){
            printf("header line has been skipped \n");     // need to skip header line
        }
        if(lineCount > 0){
            while((indVar = strsep(&line, delim)) != NULL){
                char* indVarCopy = strdup(indVar);                                              /* makes a copy of the variable */
                char *result = indVarCopy+1;                                                    /* removes first " */               
                result[strlen(result)-1] = '\0';                                                /* removes last " */

                //printf("%s \n", result);
                int index = lineCount - 1;                                                      /* gives the correct index of the array */
                if(x == 0){
                    entryBuffer[index].county = result;
                    printf("%s \n", entryBuffer[index].county);
                }
                if(x == 1){
                    entryBuffer[index].state = result;
                    printf("%s \n", entryBuffer[index].state);
                }
                if(x == 5){
                    entryBuffer[index].eduBach = atof(result);
                    printf("%f \n", entryBuffer[index].eduBach);
                }
                if(x == 6){
                    entryBuffer[index].eduHigh = atof(result);
                    printf("%f \n", entryBuffer[index].eduHigh);
                }
                if(x == 11){
                    entryBuffer[index].ethniAmerInd = atof(result);
                    printf("%f\n", entryBuffer[index].ethniAmerInd);
                }
                if(x == 12){
                    entryBuffer[index].ethniAsian = atof(result);
                    printf("%f\n", entryBuffer[index].ethniAsian);
                }
                if(x == 13){
                    entryBuffer[index].ethniBlack = atof(result);
                    printf("%f\n", entryBuffer[index].ethniBlack);
                }
                if(x == 14){
                    entryBuffer[index].ethniHisp = atof(result);
                    printf("%f\n", entryBuffer[index].ethniHisp);
                }
                if(x == 15){
                    entryBuffer[index].ethniPacif = atof(result);
                    printf("%f\n", entryBuffer[index].ethniPacif);
                }
                if(x == 16){
                    entryBuffer[index].ethniTwoorMore = atof(result);
                    printf("%f\n", entryBuffer[index].ethniTwoorMore);
                }
                if(x == 17){
                    entryBuffer[index].ethniWhite = atof(result);
                    printf("%f\n", entryBuffer[index].ethniWhite);
                }
                if(x == 18){
                    entryBuffer[index].ethniWhiteNoHisp= atof(result);
                    printf("%f\n", entryBuffer[index].ethniWhiteNoHisp);
                }
                if(x == 25){
                    entryBuffer[index].incomeMedHouse = atoi(result);
                    printf("%f\n", entryBuffer[index].incomeMedHouse);
                }
                if(x == 26){
                    entryBuffer[index].incomePerCap = atoi(result);
                    printf("%f\n", entryBuffer[index].incomePerCap);
                }
                if(x == 27){
                    entryBuffer[index].incomePerPerson = atof(result);
                    printf("%f\n", entryBuffer[index].incomePerPerson);
                }
                if(x == 38){
                    entryBuffer[index].pop2014 = atoi(result);
                    printf("%f\n", entryBuffer[index].pop2014);
                }
                x++;
            }
            x = 0;       /* reset x value for next entry*/                               
        }
        lineCount++;
        printf("\n");
    }

    free(line);
    fclose(demoFile);

    return entryBuffer;
}

int main(){         //need to add argv and argc args and then validate commandline args
    

    int finCount = getNumEntries();                                                 /* get number of entries that will be in entryArray */

    struct Entry* entryArray = calloc(finCount, sizeof(struct Entry));              /* allocate memory for entry array */
    if(!entryArray){
        perror("ERROR: calloc failed");
        exit(-1);
    }
    entryArray = createEntry(finCount);
    
    printf("%s\n", entryArray[0].county);
    printf("%s\n", entryArray[1].county);
    printf("%s\n", entryArray[2].county);
    printf("%s\n", entryArray[3].county);


    return 0;
}
