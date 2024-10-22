#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if( c == ' ' || c == '\t'){
    return 1;
  }else{
    return 0;
  }
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if (c != ' ' && c != '\t' && c != '\0') {
    return 1;  // Return true if c is a non-whitespace, non-null character
  } else {
    return 0;  // Return false for space, tab, or null terminator
  }
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  if (str == NULL || *str == '\0') {
    return NULL;  // Return NULL if string is empty
  }

  // This takes care of any input that starts with spaces or tabs
  while (*str != '\0' && space_char(*str)) {
    str++;
  }

  // If we reach the end of the string, return NULL (no token found)
  if (*str == '\0') {
    return NULL;
  }
  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
// Iterate through the token until we find a space, tab, or null terminator
while (*token != '\0' && !space_char(*token)) {
  token++;
 }
return token;
}
/* Counts the number of tokens in the string argument. */
int count_tokens(char *s){
    int count = 0;
    char *token = token_start(str);

    while (token != NULL) {
      count++;
      token = token_start(token_terminator(token));
    }

    return count;
  }

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){

  // allocatinig memory for the length of the character and adding one for the teminator
  char *newStr = (char *)malloc(len + 1);
 strncpy(newStr, inStr, len);
  newStr[len] = '\0';

  return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
int token_count = count_tokens(str);
char **token_vector = malloc(sizeof(char*) * (token_count + 1));
for (int i = 0; i < token_count; i++) {
  char *start  = token_start(str);
  char *end = token_terminator(str);
  int length = end - str;
  token_vector[i] = copy_str(start, length);
  start = token_start(end+1);
 }
return token_vector;
}
/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
  while (tokens[i] != NULL) {
    printf("%s\n", tokens[i]);
  }
}
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  char **p = tokens;
  while (*p != NULL) {
    free(*p);
    p++;
  }
  free(tokens);
}
#endif
