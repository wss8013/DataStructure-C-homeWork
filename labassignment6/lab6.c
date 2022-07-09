// Shasha Wang
// wang.shas@northeastern.edu

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to encrypt the data*/
void encrypt(char text[], int key)
{
  int i = 0;
  for(i = 0; i < strlen(text); i++){
    // deal with upper case 
    if(isupper(text[i])){
      text[i] = (text[i] - 'A' + key) % 26 + 'A';

    }
    
    //deal with lower case 
    if(islower(text[i])){
      text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
  }
}

/*function to decrypt the data*/
void decrypt(char text[],int key)
{
  int i = 0;
  for(i = 0; i < strlen(text); i++) {
    if(isupper(text[i])){
      char temp = text[i] - key;
      if(temp < 'A') {
	text[i] = (temp + 'Z' - 'A' + 1);
      }else {
	text[i] = temp;
      }
      
    }

    if(islower(text[i])){
      char temp = text[i] - key;
      if(temp < 'a'){
	text[i] = (temp + 'z' - 'a' + 1);
      }else {
	text[i] = temp;
      }
      
    }
  }
    
}


/*----------- Main program---------------*/
int main()
{
    char text[20] ;
    int keyvalue=3;
    /*Input string */
    printf("Enter the message:  ");
    scanf("%s",text);
    printf("text input   = %s\n",text);
    
    /*call function to encrypt the data*/
    encrypt(text,keyvalue);
    printf("Encrypted value = %s\n",text);
    
    /*call function to decrypt the data*/
    decrypt(text,keyvalue);
    printf("Decrypted value = %s\n",text);
    
    return 0;
}
