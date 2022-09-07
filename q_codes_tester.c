#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int checkAnswer(char* qCode, char* answer)
{
	int i = 0;
	char chr;
	char upperAnswer[4];

    while (answer[i]) { 
        chr = answer[i]; 
		chr = toupper(chr);	
		strncat(upperAnswer, &chr, 1);
        i++; 
    } 

	if (strcmp(qCode, upperAnswer) == 0)
	{
		return 0;
		
	}
	else
	{
		return 1;
	}
}

void main()
{
	FILE *fp = fopen("q_codes_list.csv", "r");
	char* question;
	char* qCode;
	int i;
	int numQuestions = 10;
	char answer[4];	
	char points;	
	int dummy;

	system("clear");
	
	if (fp != NULL)
	{
		printf("How many questions would you like? (max 42)\n\n"); 
		scanf("%d", &numQuestions);

		//clear input buffer
		while ((dummy = getchar()) != '\n' && dummy != EOF) { }	

		system("clear");

		for (i = 0; i < numQuestions; i++)
		{
			char line[100];
			fgets(line, sizeof line, fp);	

			//splits qcodes and questions and saves them into separate variables
			question = strtok(line, ",");
			qCode = strtok(NULL, ",");

			//removes newline
			qCode[strcspn(qCode, "\n")] = 0;

			printf("[Question %d] What is the code for: '%s'\n\n", i + 1, question);
			scanf(" %3s", answer);
	
			//clear input buffer
			while ((dummy = getchar()) != '\n' && dummy != EOF) { }	
			
			if (checkAnswer(qCode, answer) == 0)
			{
				system("clear");
				printf("Correct! The answer was: %s.\n\n", qCode);		
				points++;
				sleep(2);
			}
			else 
			{
				system("clear");
				printf("WRONG. The correct answer was %s.\n\n", qCode);
				sleep(2);
			}
			system("clear");
		}		
		fclose(fp);	
	}
	else
	{
		perror("q_codes_list.csv");
	}
	
	printf("In total, you scored %d/%d.\n\n", points, numQuestions);
}


//TODO: IMPLEMENT RANDOMNESS
