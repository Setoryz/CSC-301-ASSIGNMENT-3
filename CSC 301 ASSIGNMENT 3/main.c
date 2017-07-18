/* PROGRAM TO CALCULATE THE NUMBER OF YEARS BEYOND 2000 */
/* CSC 301 -> STRUCTURED PROGRAMMING */
/* NAME -> ODUKOYA SEYITAN VICTOR */
/* MATRIC NUMBER -> 20141622 */

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *monthInWords(int num)
{
	switch (num)
	{
	case 1:
		return "January";
		break;
	case 2:
		return "Febraury";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;
	}
}

void printAnimate(char *textToAnimate)
{
	int i = 0;
	int j = strlen(textToAnimate);
	for (i = 0; i < j; i++)
	{
		putchar(textToAnimate[i]);
		fflush(stdout);
		Sleep(20);
	}
}

int main()
{
	printf("******************************************************************************************************************************************************");
	printAnimate("******************************************************************************************************************************************************");
	printAnimate("*\t\t\t\t|\tPROGRAM TO CALCULATE NUMBER OF DAYS BEYOND 2000 AND INPUT\t|\t\t\t\t\t     *");
	printAnimate("*\t\t\t\t|\t\t CSC 301 ASSIGNMENT (STRUCTURED PROGRAMMING) \t\t|\t\t\t\t\t     *");
	printAnimate("*\t\t\t\t|\t\t STUDENT'S NAME  : ODUKOYA SEYITAN VICTOR \t\t|\t\t\t\t\t     *");
	printAnimate("*\t\t\t\t|\t\t MATRIC NUMBER   : 20141622 \t\t\t\t|\t\t\t\t\t     *");
	printAnimate("*\t\t\t\t|\t\t LECTURER'S NAME : MRS C.0.TINUBU \t\t\t|\t\t\t\t\t     *");
	printAnimate("******************************************************************************************************************************************************");
	printf("******************************************************************************************************************************************************");

	int mm = 0, dd = 0, yy = 0;
	int i;
	do
	{
		printAnimate("******|\tEnter the date in the format MM-DD-YY : ");
		scanf("%d-%d-%d", &mm, &dd, &yy);
		i = 1;
		if (dd < 1 || dd > 31)
		{
			printAnimate("******|\tThe date you entered is incorrect, Kindly re-enter the date \n");
			i = 0;
		}
		if (mm < 1 || mm > 12)
		{
			printAnimate("******|\tThe month you entered is incorrect, Kindly re-enter the month \n");
			i = 0;
		}
		if (yy < 2000 || yy > 2017)
		{
			printAnimate("******|\tThe year should be between 2000 and 2017 and should be in the format 20** \n");
			i = 0;
		}
	} while (i == 0);

	// to calculate the numbers of days beyond 2000
	int daysInCurrentYear; //days in the current year
	daysInCurrentYear = (int)(30.42 * (mm - 1)) + dd;
	if (mm == 2) //February
		--daysInCurrentYear;
	if (mm > 2 && mm < 8) //March - July
		++daysInCurrentYear;
	if (yy % 4 == 0 && mm > 2) //leap year
		++daysInCurrentYear;

	int yearsInterval = (yy - 2000) - 1;
	int noOfLeapYears = yearsInterval / 4;
	int remainderYears = (yearsInterval % 4);
	int daysBeforeCurrentYear = (noOfLeapYears * 1461) + (remainderYears * 365);
	int totalNoOfDays = daysBeforeCurrentYear + daysInCurrentYear;
	char *textToPrint[150];
	sprintf( textToPrint, "******|\t The number of days between January 1, 2000 and %s %d, %d is %d \n", monthInWords(mm), dd, yy, totalNoOfDays);
	printAnimate(textToPrint);

	return 0;
}
