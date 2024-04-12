/************************chadhaAnishaA3.c**************
Student Name: Anisha Chadha  Email Id: achadh02@uoguelph.ca
Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity.
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any
and all material
that I have used, whether directly quoted or paraphrased. Furthermore,
I certify that this assignment was prepared by me specifically for this
course.
********************************************************/


/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall chadhaAnishaA3.c main.c
Running: ./a.out
OR
gcc -std=c99 -Wall chadhaAnishaA3.c main.c -o assn3
Running the Program: ./assn3
*********************************************************/



#include "givenA3.h"


/** (1)
readFromFile: This function takes 3 parameters. The 1st parameter called fileWithMedals is a string that
stores the filename of a sequential data file. The 2nd and 3rd parameters are populated using data file
that stores the country names and medals won by each country.
In: char fileWithMedals[30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]
Out: void
Return: Nothing
***/


void readFromFile (char fileWithMedals[30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]) 
{
   int i = 0;
   int j = 0;

   FILE* inFile = NULL;                         // creating File variable

   inFile = fopen(fileWithMedals, "r");         // opening the file

   if (inFile == NULL)                          // checking if the file opened
   {
      printf("Can't open the file\n");
      country[0][0] = - 999;
   }

   else
   {
   while (!feof(inFile)){
         fscanf(inFile, "%s %d %d %d", countryNames[i], &country[i][j], &country[i][j+1], &country[i][j+2]);
         printf("Country: %s ,Gold: %d ,Silver: %d ,Bronze: %d", countryNames[i], country[i][j], country[i][j+1], country[i][j+2]);
         printf("\n");
         i++;
      }

      fclose(inFile);      // closing the file
   }
}


/** (2)
findTotalPerCountry: Finds total medals for each country and stores it in array totalAllCountries.
In: int country [COUNTRIES] [MEDALCAT], int totalAllCountries [COUNTRIES]
Out: void
Return: Nothing
***/


void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT], int totalAllCountries [COUNTRIES])
{

   for (int i = 0; i < COUNTRIES; i++)
   {
      totalAllCountries[i] =  country[i][0] + country[i][1] + country[i][2];

   }
}


/** (3)
findTotalPerMedal: Finds total number of medals in each category (Gold/Silver/Bronze) and stores them in array
totalAllMedals. Returns the maximum value in totalAllMedals. Outputs (through call-by-reference parameter) the index of the category with maximum medals – category given in parameter whichMedal
In: int country [COUNTRIES][MEDALCAT], int totalAllMedals [MEDALCAT], int * whichMedal
Out: int
Return: find max value in totalAllMedals and returns it, assigns whichMedal appropariete value (by reference)
***/


int findTotalPerMedal (int country [COUNTRIES][MEDALCAT], int totalAllMedals [MEDALCAT], int * whichMedal)
{
   int maxVal;
   maxVal = 0;
   *whichMedal = 0;
   totalAllMedals[0] = 0;
   totalAllMedals[1] = 0;
   totalAllMedals[2] = 0;


// outer loop that loops the the chosen category for each country and sums the number of medals
   for (int i = 0; i < COUNTRIES; i++)
   {

// inner loop that goes through categories of medals (gold, silver, bronze)
      for (int j = 0; j < MEDALCAT; j++)
     {

        totalAllMedals[j] = totalAllMedals[j] + country[i][j]; 

// finds the max number in the array and passes the index to whichMedal
        if (totalAllMedals[j] > maxVal)
         {
            maxVal = totalAllMedals[j];
            *whichMedal = j;
         }
      }
   }

return maxVal;
}


/** (4)
hHistogram: Displays a horizontal histogram of stars, where each star represents a medal. The total number of medals must be printed at the end of the line. For example (note that the medal counts may be
different for you).
In: char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]
Out: void
Post: printf horizontal histogram based of length of the country name and number of medals won by it.
***/


void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES])
{

   int number;


   for (int i = 0; i < COUNTRIES; i++){         // loop that prints horizontal histogram

      printf("%-10s : ", countryNames[i]);
      number  = totalMedals[i];

      if (number % 2 == 0)
      {
         for (int j = 0; j < number/2; j++)
         {
            printf("*");
         }
         printf(" (%d)\n", totalMedals[i] + (totalMedals[i] % 2) /2);
         printf("\n");
      }
      else {
         for (int j = 0; j < number/2 + 1; j++)
         {
            printf("*");
         }
         printf(" (%d)\n", totalMedals[i] + (totalMedals[i] % 2) /2);
         printf("\n");
      }
   }
}


/** (5)
searchCountry: Returns the total number of medals won by a country, given its name (countryName). If countryName
does not exist in the given list of 10 countries, it returns -1.
In: char countryName [MAX_LENGTH_CNAME], char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalAllCountries [COUNTRIES]
Out: int
Return: return the number of medals won a country that the user was searching for (else returns -1).
***/


int searchCountry (char countryName [MAX_LENGTH_CNAME], char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalAllCountries [COUNTRIES])
{
// loop that goes through through each country name in the array countryNames and compares it name given by the user using strcmp
   for (int i = 0; i < COUNTRIES; i++)
   {
      if (strcmp(countryName, countryNames[i]) == 0)
      {
         return totalAllCountries[i];

      }
   }

   return -1;
}


/** (6)
rankTopThreeByTotal: Displays the top three country names and the total medals won by each of them – the display must be in order of total medals won.
In: int totalMedals[COUNTRIES], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]
Out: void
Return: Prints the top 3 country's name and the number of medals won by it from the largest to smallest based on totalMedals and countryNames.
***/


void rankTopThreeByTotal (int totalMedals[COUNTRIES], char countryNames [COUNTRIES][MAX_LENGTH_CNAME])
{
   int maxVal1 = -1 ;
   int maxVal2 = -1;
   int maxVal3 = -1 ;
   int index1 = -1 ;
   int index2 = -1;
   int index3 = -1;
   int keepMax1 = -1;
   int keepMax2 = -1;
   int keepMax3 = -1;

// loop through the array of totalMedals to find top three countries
   for (int i = 0; i < COUNTRIES; i++)
   {
      if (totalMedals[i] > maxVal1)
      {
         maxVal3 = maxVal2;
         maxVal2 = maxVal1;
         maxVal1 = totalMedals[i];
      }
      else
      {

         if (totalMedals[i] > maxVal2)
         {
            maxVal3 = maxVal2;
            maxVal2 = totalMedals[i];
         }
         else
         {
            if (totalMedals[i] > maxVal3)
            {
               maxVal3 = totalMedals[i];
            }
         }
      }
   }

   keepMax1 = maxVal1;
   keepMax2 = maxVal2;
   keepMax3 = maxVal3;

// loop through the totalMedals array already knowing the top three values to 
// find the index of them (in order to use the index to print the country name)

   for (int j = 0; j < COUNTRIES; j++)
   {
      if (totalMedals[j] == maxVal1)
      {
         index1 = j;
         maxVal1 = -1;
      }
      else
      {
         if (totalMedals[j] == maxVal2)
         {
            index2 = j;
            maxVal2 = -1;
         }
         else
         {
            if (totalMedals[j] == maxVal3)
            {
              index3 = j;
              maxVal3 = -1;
            }
         }
      }
   }

      printf("%s (%d)\n", countryNames[index1], keepMax1);
      printf("%s (%d)\n", countryNames[index2], keepMax2);
      printf("%s (%d)\n", countryNames[index3], keepMax3);
}


/** (7)
rankTopThreeByMedal: Displays the top three country names and the total gold medals won by each of them – the display must be in order of total gold medals won.
 In: int country [COUNTRIES] [MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]
 Out: void
 Return: Prints the top 3 country's name and the number of medals won by it in gold category from the largest to smallest based on country (stores number of medals in each category) and countryNames.
***/


void rankTopThreeByMedal (int country [COUNTRIES] [MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME])
{

   int maxVal1 = -1;
   int maxVal2 = -1;
   int maxVal3 = -1;
   int index1 = -1;
   int index2 = -1;
   int index3 = -1;
   int keepMax1 = -1;
   int keepMax2 = -1;
   int keepMax3 = -1;

// loop through the array of country array (gold medal category) to find top three countries

   for (int i = 0; i < COUNTRIES; i++)
   {
      if (country[i][0] > maxVal1)
      {
         maxVal3 = maxVal2;
         maxVal2 = maxVal1;
         maxVal1 = country[i][0];
      }
      else
      {
         if (country[i][0] > maxVal2)
         {
            maxVal3 = maxVal2;
            maxVal2 = country[i][0];
         }
         else
         {
            if (country[i][0] > maxVal3)
            {
               maxVal3 = country[i][0];
            }
         }
      }
   }

   keepMax1 = maxVal1;
   keepMax2 = maxVal2;
   keepMax3 = maxVal3;

// loop through the totalMedals array already knowing the top three values to 
// find the index of them (in order to use the index to print the country name)

   for (int j = 0; j < COUNTRIES; j++)
   {
      if (country[j][0] == maxVal1)
      {
         index1 = j;
         maxVal1 = -1;
      }
      else
      {
         if (country[j][0] == maxVal2)
         {
            index2 = j;
            maxVal2 = -1;
         }
         else
         {
            if (country[j][0] == maxVal3)
            {
              index3 = j;
              maxVal3 = -1;
            }
         }
      }
   }

   printf("%s (%d)\n", countryNames[index1], keepMax1);
   printf("%s (%d)\n", countryNames[index2], keepMax2);
   printf("%s (%d)\n", countryNames[index3], keepMax3);
}


/** (8)
findAllWithNoXMedals: Returns the total number of countries with no medal of a specific category, where category = indexMedal (1 for Gold, 2 for Silver, 3 for Bronze). Stores the indices of countries that do not have indexMedal in an array called indexOfCountries.
In: int country [COUNTRIES] [MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]
Out: int
Return: find and returns number of countries that have a category with no medals of that category.
***/


int findAllWithNoXMedals (int country [COUNTRIES] [MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES])
{
   int total = 0;

// loop through the array and compare the number of medals in the given
// category to 0, if true store the index in the indexOfCountries array

    for (int j = 0; j < COUNTRIES; j++)
    {
       if (country[j][indexMedal - 1] == 0)
      {
         indexOfCountries[total] = j;
         total++;
      }
    }

   return total;
}


/** (9)
findAllWithOnlyXMedals: Returns the total number of countries that have ONLY won medals of a specific category, where
category = indexMedal (1 for Gold, 2 for Silver, 3 for Bronze). Stores the indices of such countries in an array called indexOfCountries.
In: int country [COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]
Out: int
Return: find and returns number of countries that have a category with medals only in that category.
***/


int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES])
{
   int total;
   int firstCat;
   int secondCat;

   total = 0;
   firstCat = 0;
   secondCat = 0;

   if (indexMedal == 3)
   {
      firstCat = 0;
      secondCat = 1;
   }
   else
   {
      if (indexMedal == 2)
      {
         firstCat = 0;
         secondCat = 2;
      }
      else
      {
         if (indexMedal == 1)
         {
            firstCat = 1;
            secondCat = 2;
         }
      }
   }

    for (int j = 0; j < COUNTRIES; j++)
   {
      if (country[j][indexMedal-1] != 0 && country[j][firstCat] == 0 && country[j][secondCat] == 0)
      {
         indexOfCountries[total] = j;
         total++;
      }
   }

   return total;
}


/** (10)
findCountryIndexWithMinOrMaxLength: Returns the index of the countryName that has min or max length - use 1 for min and 2 for max. You must return only one index, even if there are more than 1 countryNames with a max or min length
In: int minOrMax, char countryNames [COUNTRIES][MAX_LENGTH_CNAME]
Out: int
Return: find and returns the index of the country with min/max length based on minOrMax.
***/


int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][MAX_LENGTH_CNAME])
{
   int minLen;
   int indexMax ;
   int maxLen;
   int indexMin;

   minLen = MAX_LENGTH_CNAME;
   indexMax = 0;
   maxLen = 0;
   indexMin = 0;

   // retunrs the index of the country with the minimum length by looping the array // countryNames and comaping the length of the strings using strlen
   if (minOrMax == 1)
   {
      for (int i = 0; i < COUNTRIES; i++)
      {
         if (strlen(countryNames[i]) < minLen)
         {
            minLen = strlen(countryNames[i]);
            indexMin = i;
         }
      }

      return indexMin;
   }
   else
   {
      // retunrs the index of the country with the maximum length by looping the 
      // array countryNames and comaping the length of the strings using strlen
      for (int i = 0; i < COUNTRIES; i++)
      {
         if (strlen(countryNames[i]) > maxLen)
         {
            maxLen = strlen(countryNames[i]);
            indexMax = i;
         }
      }
   }

   return indexMax;
}
