/************************chadhaAnishaA3Main.c**************
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
gcc -std=c99 -Wall chadhaAnishaA3Main.c main.c
Running: ./a.out
OR
gcc -std=c99 -Wall chadhaAnishaA3Main.c main.c -o assn3
Running the Program: ./assn3
*********************************************************/

#include "givenA3.h"

int main (int argc, char * argv[]) {

int country [COUNTRIES][MEDALCAT];

int totalAllCountries [COUNTRIES];

int indexMedal = 0;

int whichMedal;

int indexOfCountries [COUNTRIES];

int minOrMax = 0;

int choice;

int i =0;

int x = 0;

int y = 0;

int z = 0;

int a = 0;

int b = 0;

int totalAllMedals[MEDALCAT];

char countryName [MAX_LENGTH_CNAME];

char countryNames [COUNTRIES][MAX_LENGTH_CNAME];


    do {
        printf ("\nHere is the menu \n\n");
        printf ("1. Display all country names read from file and the total number of medals won by each\n");
        printf ("2.    Function 2 - Find total number of medals won by each country\n");
        printf ("3.    Function 3 - Finds total number of medals in each category (Gold, Silver, Bronze)\n");
        printf ("4.    Function 4 – Display horizontal histogram\n");
        printf ("5.    Function 5 – Search for a country and return the total number of medals won by it\n");
        printf ("6.    Function 6 – Rank and display top three countries in order of total medals won\n");
        printf ("7.    Function 7 – Rank and display top three countries in order of total gold medals won\n");
        printf ("8.    Function 8 – Find and display all countries that won no X medals, given X as either Gold, Silver or Bronze\n");
        printf ("9.    Function 9 – Find and display all countries that won ONLY X medals, given X as either Gold, Silver or Bronze\n");
        printf ("10.   Function 10 – Find and display name of the country that has minimum or maximum length among all countries read in option 1\n");

        printf ("11.    Exit \n");

        printf ("Enter your choice: ");
        scanf ("%d", &choice);

        switch (choice) {
            case 1:

                readFromFile(argv[1], country, countryNames);

            break;

            case 2:

                findTotalPerCountry (country, totalAllCountries);
                    for (i = 0; i < COUNTRIES; i++){
                       printf("Country %s = %d\n", countryNames[i], totalAllCountries[i]);
                    }
            break;

            case 3:

                x = findTotalPerMedal (country, totalAllMedals , &whichMedal);
                printf("In findTotalPerMedal \n");
                printf("Medal = Gold, Total = %d\n",totalAllMedals[0]);
                printf("Medal = Silver, Total = %d\n", totalAllMedals[1]);
                printf("Medal = Bronze, Total = %d\n",totalAllMedals[2]);
                printf("Maximum number of medals = %d in category (Bronze)\n", x);

            break;

            case 4:

                printf("Printing Histogram\n");
                printf("In hHistogram\n\n");
                hHistogram(countryNames,totalAllCountries);

            break;

            case 5:

                printf("Searching for which country? ");
                scanf("%s", countryName);
                y = searchCountry (countryName, countryNames , totalAllCountries);
                printf("In searchCountry \n");

                 if ( y == -1){
                    printf("Country name not found in this database \n");
                }

                else {
                    printf("Found it - %s has a total of %d medals", countryName, y);

                }

            break;

            case 6:

                printf("Rank top three based on total number of medals \n");
                rankTopThreeByTotal(totalAllCountries, countryNames );

            break;

            case 7:

                printf ("Rank top three based on Gold Medals \n");
                rankTopThreeByMedal(country, countryNames);

            break;

            case 8:

                printf("Which medal do you want to look for - type 0 for Gold, 1 for Silver, 2 for Bronze? ");
                scanf("%d", &indexMedal);

                z = findAllWithNoXMedals( country , indexMedal, indexOfCountries);
                printf("Number of countries with no bronze medals = %d \n", z );

                for (i = 0; i < z ; i++){
                    printf("%s \n" ,countryNames[indexOfCountries[i]]);
                }

            break;

            case 9:

            printf("Which medal do you want to look for - type 0 for Gold, 1 for Silver, 2 for Bronze? ");
            scanf("%d", &indexMedal);

            a = findAllWithOnlyXMedals(country, indexMedal, indexOfCountries);
            printf("%d \n", a);

            for (i = 0; i < a ; i++) {
                printf("%s \n" ,countryNames[indexOfCountries[i]]);
            }

            break;

            case 10:

            printf("Do you want min (enter 1) or max (enter 2)?: ");
            scanf("%d", &minOrMax);

            b = findCountryIndexWithMinOrMaxLength(minOrMax,countryNames);

            if (b == 1) {
                printf("The country name with minimum length = %s", countryNames[b]);
            }

            else {
                printf("The country name with maximum length = %s", countryNames[b]);
            }

            break;

            default: printf("That is an invalid choice\n");

        }

    } while (choice != 11);


   return 0;
}


