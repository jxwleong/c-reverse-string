#include "ReverseString.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int  getStringLength(char * str)
{
  int   i    = 0 ;
  if(str== 0 || str[i] =='\0')
  {
    return 0;
  }
  //if(isalpha(str[i]) || isdigit(str[i]))// if use str (pointer) it store address so cant compare bcz isaplha(int)
  //{
    while(str[i] !=0 && str !='\0')
    {
      i++;
    }
    return i;
  //}
}

// Method 1 (move pointer to last character and store in backwards)
//Can't reverse more than 3 numbers & can't reverse two strings
char  *ReverseString(char *str)                  //return string so need * for function name.
 {
   static char *Rev_storage ;

   int   i    = 0 ;
   int   k    = 0 ;

   if(str== 0 || str[i] =='\0')
   {
     return "NULL or empty string detected.";
   }

   //if(isalpha(str[i]) || isdigit(str[i]))
      //if use str (pointer) it store address so cant compare bcz isaplha(int)
   //{
	   else{
		   int j = getStringLength(str);


     while (i<j)                // skip while not complete when using numbers
     {
      ++str;                           // Move the pointers until '\0'(end of string)
      i++;                             // I increment to check the conditions
     }


		str--;                           // pointer decrement to move 1 step back from '\0'


    for (k=i;k>0;k--)
    {
        //Rev_storage = str;              // 1) store last character of the string to a new array
        Rev_storage = &(str[k]);         // 2) 1 and 2 also works return the whole address
        ++Rev_storage;                  // 2 is return the whole address while 1 byte by byte.
    }
    //str = Rev_storage;                  // overwrite the input string memory but will affect when try to
    return    Rev_storage;
	   }              // Didn't solve the overwriting issue when call function two times
}
  //}



// Method 2 (character swapping) should be working but rake aborted??
/*
char  *ReverseString(char *str)       //return string so need * for function name.
 {
   char *first_char  = str;
   char temp;
   char *last_char    = first_char +  getStringLength(str) -1;  // minus the '\0'

   if(str== 0 || str[0] =='\0')
   {
     return "NULL or empty string detected.";
   }
   else
   {
     while(last_char>first_char)        //Example       (first_char & last_char swap)
     {                                  // ABCD- last_char then replace by temp (first_char)
      temp= *first_char;                 // |
      *first_char = *last_char;         // first_char then replace by last_char
      *last_char  = temp;               // After swap1
      first_char++;                     //DBCA
      last_char--;                      // ||
                                        // 1L       1= first_char,L= last_char
                                        // After swap2
                                        //DCBA      Complete!!
                                        // The process continue until last_char < first_char

     }


    //free(Rev_storage);
    return  str;
   }

 }
*/
