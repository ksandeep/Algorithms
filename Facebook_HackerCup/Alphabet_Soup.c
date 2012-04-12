/* fscanf example */

// HACKERCUP : 9 characters
#include <stdio.h>
#include <string.h>
#define MAX 1010

const char search_key[] = "HACKERCUP";


int main ()
{
  int i, j, k, T, min, len;
  char c;
  len = strlen(search_key);
  FILE *pFile, *oFile;
  char str[MAX];
  int* attendance = (int*) malloc (len * sizeof(int));
  
  pFile = fopen ("alphabet_soup.txt","r");               //input_small               input_large
  if (pFile == NULL){
            printf("\n Error in opening file!!");
            return 1;
  }
  oFile = fopen ("alphabet_soup_result.txt","w");               //soup_small               alphabet_soup
  if (oFile == NULL){
            printf("\n Error in opening file!!");
            return 1;
  }
  
  fscanf (pFile, "%d", &T);
  fgets(str, sizeof str, pFile);
  
  
  
  //printf ("I have read: %d \n",T);
  for (i = 1; i <= T; i++)
  {
      if (fgets(str, sizeof str, pFile) == NULL ){
         printf ("\n Error in reading string!!");
      }      
      j = 0;
      //fscanf(pFile, "%c", &c);
      //printf("%s", str);
      
      for (k=0; k < len; k++)
      attendance[k] = 0;
      
      while(str[j] != '\0')
      {
                   for (k = 0; k < len; k++)
                   {
                       if (str[j] == search_key[k])
                          attendance[k]++;
                   }
                   //printf("%c", str[j]);
                   j++;
      }
      min = attendance[0];
      for (k=0; k < len; k++)
      {
          if ((k == 2) || (k == 6))
             attendance[k] /= 2;
          //printf("\n Character %c appears %d times.",search_key[k], attendance[k]);
          if(attendance[k] < min)
                           min = attendance[k];
      }
      printf("Case #%d: %d\n", i, min);
      fprintf(oFile, "Case #%d: %d\n", i, min);
      
      
      //printf("%s", str);
      //fputs(str, stdout);
                     
           
  }
  
  fclose (pFile);
  fclose (oFile);
 
  getchar();
  return 0;
}
