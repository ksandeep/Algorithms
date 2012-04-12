#include <stdio.h>
#include <string.h>
#define MAX 1010
#define debug 0

int is_font_valid(int font, int W, int H, char *str)
{
     int i, j, no_of_words;
     
     // Find the total no of words in str
     no_of_words = 1;
     for (i=0; i < strlen(str); i++)
         if (str[i] == ' ')
            no_of_words++;    
     
     // Declare 2 arrays, to store word sizes and fitting information
     int * word_fitting = (int*) malloc (no_of_words * sizeof(int));
     int * word_sizes = (int*) malloc (no_of_words * sizeof(int));
     
     // Initialize the two arrays
     for (i=0; i < no_of_words; i++)
     {
         word_sizes[i] = 0;
         word_fitting[i] = 0;
     }     
     
     // Count the word sizes and fill the array word_sizes
     j=0;
     for (i=0; i < strlen(str); i++)
     {
         if (str[i] == ' ')
            j++;
         else 
              word_sizes[j]++;
     }
     
     if (debug){
         printf("\n The no of words in \"%s\" is = %d", str, no_of_words);
         
        
         for (i=0; i < no_of_words; i++)
         {
             printf("\n Word %d 's size = %d", i+1, word_sizes[i]);
         }
     }
     
     int avail_lines = H / font;
     int current_line = 0;
     int current_word = 0;
     int spaces_first_word = 0;        // This is set to zero for the first word being fitted in a line
     int avail_width_current_line = W;
     
     while ((current_line < avail_lines) && (current_word < no_of_words))
     {
           if (word_sizes[current_word] > W)
              return 0;            // A word cannot fit in the line, font size invalid
           
           if ( (font*(spaces_first_word + word_sizes[current_word])) <= avail_width_current_line)
           {
                // current word can be fitted
                // do a fitting
                if (debug)
                {
                          printf("\n avail_width_current_line  = %d", avail_width_current_line);
                          printf("\n to be deducted  = %d", font*(spaces_first_word + word_sizes[current_word]));
                          printf("\n current word  = %d", current_word);
                          printf("\n current line  = %d", current_line);
                }
                
                word_fitting[current_word] = 1;
                avail_width_current_line = avail_width_current_line - (font*(spaces_first_word + word_sizes[current_word]));
                current_word++;
                // if this was the first word in the line, the next word and onwards will need a space
                if (spaces_first_word == 0)
                   spaces_first_word = 1;
                
           }
           else
           {
               // move to next line
               current_line++;
               avail_width_current_line = W;
               spaces_first_word = 0;
           }
     }
     
     if (debug){
                
         for (i = 0; i < no_of_words; i++)
             printf("\n word_fitting[%d] = %d", i, word_fitting[i]);
             
         printf("\n current line  = %d", current_line);
     }        
     if (current_line == avail_lines)
     {
        // all lines were used
        // the font size is invalid
        return 0;
     }
     else if (current_word == no_of_words)
     {
          // all words were fitted
          // the font size is valid
          return 1;
     }
     printf("\n Should not reach here !!!");
}

int main()
{
    int T, W, H, i, font = 3;
    char str[MAX];
    FILE *pFile, *oFile;
    
    pFile = fopen ("billboards.txt","r");               //input_small               input_large
    if (pFile == NULL){
       printf("\n Error in opening file!!");
       getchar();
       return 1;
    }
    
    oFile = fopen ("billboards_result.txt","w");               //input_small               input_large
    if (oFile == NULL){
       printf("\n Error in opening file!!");
       getchar();
       return 1;
    }
    
    fscanf (pFile, "%d", &T);
    //fscanf (pFile, "\n");
    //printf("T = %d\n", T);
    
    for (i = 1; i <= T; i++)
    {
        fscanf (pFile, "%d", &W);
        fscanf (pFile, "%d\n", &H);
        fgets(str, sizeof str, pFile);
        if (i != T)
           str[strlen(str)-1] = '\0';
        
        
        /*       
        printf("\nW = %d\n", W);
        printf("\nH = %d\n", H); 
        printf("\nstr = %s, %d", str, strlen(str));
        */

        
        font = 1;
        while (is_font_valid(font, W, H, str) == 1)
              font++;

        printf("Case #%d: %d\n", i, font-1);
        fprintf(oFile, "Case #%d: %d\n", i, font-1);

    }    
    fclose (pFile);
    fclose (oFile);
    //getchar();
    getchar();
    return 0;
}
