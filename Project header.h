#ifndef Project header_h
#define Project header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ProcessSpamPhish(){
  //Inputing lines from Phishing.data into its own array
  FILE * fPtr;
  fPtr = fopen("phishing.rtf", "r");
  char line[150];
  char fishing[80][25] = {""};
  int j = 0;
  while (fscanf(fPtr,"%s", line) != EOF){ //loop that adds lines from txt to array
    strcpy(fishing[j], line);
    j++;
  }
  fclose(fPtr);
  //*****************************************************
  //Inputing lines from spam.data into its own array
  FILE * newPtr;
  newPtr = fopen("spam.rtf", "r");
  char newLine[150];
  char spam[80][25] = {""};
  int w = 0;
  while (fscanf(newPtr, "%s", newLine) != EOF){//loop that adds lines from txt to array
    strcpy(spam[w], newLine);
    w++;
  }
  fclose(newPtr);

  //*************  putting email into its own array
  FILE * email;
  email = fopen("myemail.rtf", "r");
  char word[25];
  char emailCtx[250][30] = {""};
  int y = 0;
  while (fscanf(email, "%s", word) != EOF){//loop that adds lines from txt to array
    strcpy(emailCtx[y], word);
    //Testing if letter is a punctuitaiton mark
    for(int i=0; i<30; i++){
      if(ispunct(emailCtx[y][i])){
    emailCtx[y][i] = '\0';
      }
    }
    y++;
  }
  fclose(email);
  int totalSpam = 0;
  int totalFish = 0;
  char fSpam[40][25] = {""};
  char fFish[40][25] = {""};
  int fcnt = 0;
  int scnt = 0;
  for(int i= 0; i<250; i++){
    for(int j=0; j<80; j++){
      //below checks for spam word
      if (strcasecmp(emailCtx[i], spam[j]) == 0){
    strcpy(fSpam[scnt], spam[j]);
    strcpy(fSpam[scnt+1], spam[j+1]);
    //printf("SPAM %s : %s\n", fSpam[scnt+1], fSpam[scnt]);
    totalSpam += atoi(spam[j+1]);
    scnt+=2;
      }//below Checks for Fish word
      else if(strcasecmp(emailCtx[i], fishing[j]) == 0){
    strcpy(fFish[fcnt], fishing[j]);
    strcpy(fFish[fcnt+1], fishing[j+1]);
    //printf("FISH %s : %s\n", fFish[fcnt+1], fFish[fcnt]);
    totalFish += atoi(fishing[j+1]);
    fcnt+=2;
      }
    }
  }

  printf("\nSPAM Report - %d\n", totalSpam);
  printf("The following words or phrases were detected:\n");
  for (int i = 0; i < 40; i+=2){
    if(!(strcmp(fSpam[i], "\0") == 0)){
      printf("%s - %s points\n", fSpam[i], fSpam[i+1]);
    }
  }

  printf("\nPhishing Report - %d", totalFish);
  printf("\nThe following words or phrases were detected:\n");
  for(int i=0; i<40; i+=2){
    if(!(strcmp(fFish[i], "\0") == 0))
      printf("%s - %s points\n", fFish[i], fFish[i+1]);
  }
}//end of function

void ProcessSpellCheck(){
  FILE * dict;
  char temp[20];
  FILE * email;
  email = fopen("myemail.rtf", "r");
  char word[25];
  char emailCtx[250][30] = {""};
  int y = 0;
  while (fscanf(email, "%s", word) != EOF){//loop that adds lines from txt to array
    strcpy(emailCtx[y], word);
    //Testing if letter is a punctuitaiton mark
    for(int i=0; i<30; i++){
      if(ispunct(emailCtx[y][i])){
    emailCtx[y][i] = '\0';
      }
    }
    y++;
  }
  char notspelled[250][30];
  int mcnt = 0;
  for(int i=0; i<250; i++){
    dict = fopen("dictionary.rtf", "r");
    //printf("%s\n", emailCtx[i]);
    int count = 0;
    while(fscanf(dict, "%s", temp) != EOF){
      //printf("Hey");
      if(strcasecmp(emailCtx[i], temp) == 0){
    //printf("%s\n", emailCtx[i]);
    count+=1;
      }
    }
    if(!(strcmp(emailCtx[i], "\0") == 0)){
    if(count == 0){
      strcpy(notspelled[mcnt], emailCtx[i]);
      printf("%s, ", notspelled[mcnt]);
      //printf("%d", count);
      mcnt+=1;
    }
    }
    fclose(dict);
  }
}
#endif
