#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
//#include "history.h"

int main(){
  char userInput[25];
  char *tokens[10];//char array to store the user input
  printf("Welcome!\n");
  while(1){
    printf("Please enter something you wish to tokenize.\n");
    printf(">"); //display that the is ready for input
    fgets(userInput,sizeof(userInput),stdin);
    printf("%s", userInput);
    break;
  }
  printf("out of loop");
}
