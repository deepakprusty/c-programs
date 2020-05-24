

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <ctype.h>

unsigned long days=0;
//stores the days elapsed since 01.01.1899
void display(int n)
//contains the number of days to display
{
	int i, column, k, flag=0, j;
	printf("Sun   Mon   Tues  Wed   Thur  Fri  Sat
");
	for(i=1; i<=n; i++)
	{
	k=days%7;//remainder gives the starting day of each month
	if(flag==0)
	{
	for(j=1; j<=k; j++)//controls tabs of first week
	printf("	");
	flag=1;//ensures that block is only executed once
	column=k;
	}
	printf("%d	", i);
	column++;
	if(column%7==0)//prints new line at the end of each week
	printf("
");
	}
	printf("
				Press any key to continue

");
	getch();
}

void calculate(int year)
//function calculates no. of days elapsed since 1899
{
	int i, month;
	for(i=1899; i<year; i++)
        //1899 chosen because Jan 1, 1899 is a Sunday
	{
	if((i%400==0)?1:((i%100==0)?0:((i%4==0)?1:0)))

/*This is because a leap year does not strictly fall on	every
fourth year.  If a year is divisible by 4, then it is a leap
year, but if that year is divisible by 100, then it is
not a leap year.  However, if the year is also divisible by
400, then it is a leap year.  Eg: 1900 is not a leap year*/

	days+=366;
	else
	days+=365;
	}
	for(month=1; month<=12; month++)
	{
	printf("


		");
	switch(month)
        /*switch case used to display each month and
	increment no. of days*/
	{
	case 1: printf(" JANUARAY %d

", year);
	display(31);
	days+=31;
	break;
	case 2: printf(" FEBURARY %d

", year);
	if((year%400==0)?1:((year%100==0)?0:((year%4==0)?1:0)))
	{
	display(29);
	days+=29;
	}
	else
	{
	display(28);
	days+=28;
	}
	break;
	case 3: printf(" MARCH %d

", year);
	display(31);
	days+=31;
	break;
	case 4: printf(" APRIL %d

", year);
	display(30);
	days+=30;
	break;
	case 5: printf(" MAY %d

", year);
	display(31);
	days+=31;
	break;
	case 6: printf(" JUNE %d

", year);
	display(30);
	days+=30;
	break;
	case 7: printf(" JULY %d

", year);
	display(31);
	days+=31;
	break;
	case 8: printf(" AUGUST %d

", year);
	display(31);
	days+=31;
	break;
	case 9: printf(" SEPTEMBER %d

", year);
	display(30);
	days+=30;
	break;
	case 10: printf(" OCTOBER %d

", year);
	display(31);
	days+=31;
	break;
	case 11: printf(" NOVEMBER %d

", year);
	display(30);
	days+=30;
	break;
	case 12: printf(" DECEMBER %d

", year);
	display(31);
	days+=31;
	break;
	}
	}
}

void main()
{
	char ch[10];
	int i, year, choice;
	do
	{
	clrscr();
	days=0;
	printf("Enter the year in 'yyyy' format:
");
	scanf("%s", ch);//stores input first as a string
	for(i=0; i<strlen(ch); i++)
	if(ch[i]<'0' || ch[i]>'9')//checks for invalid inputs
	{
	printf("

Invalid Year!");
	printf("

END OF PROGRAM");
	getch();
	exit(0);
	}
	year = atoi(ch);
        //converts the year from string to integer datatype
	clrscr();
	printf("

		Calender for Year %d", year);
	printf("******************");
	calculate(year);
        //calls function to calculate no. of days elapsed
	
        printf("*******************");
	printf("

Press 1 to continue, 2 to exit
");
	scanf("%d", &choice);
	}while(choice==1);
	clrscr();
	printf("

END OF PROGRAM");
	getch();
}
