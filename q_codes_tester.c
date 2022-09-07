#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	FILE *fp = fopen("q_codes_list.csv", "r");
	char* question;
	char* qCode;
	int i;
	int numQuestions = 10;
	char answer[4];	

	if (fp != NULL)
	{
		for (i = 0; i < numQuestions; i++)
		{
			char line[100];
			fgets(line, sizeof line, fp);	

			//splits qcodes and questions and saves them into separate variables
			question = strtok(line, ",");
			qCode = strtok(NULL, ",");
			printf("Question = %s\n\n", question);
			scanf("%3s", answer);
			printf("%s", answer);
	
			//clear input buffer
			int dummy;
			while ((dummy = getchar()) != '\n' && dummy != EOF) { }	
			
			if (checkAnswer() == 0)
			{
				printf("Correct! The answer was %s.", answer);		
			{
		}	
	
	fclose(fp);
	}
	else
	{
		perror("q_codes_list.csv");
	}
}

int checkAnswer(char* qCode, char* answer)
{

}


//TODO: IMPLEMENT RANDOMNESS, COMPARE QUESTION WITH ANSWER, POINTS SYSTEM, ASK HOW MANY QUESTIONS FIRST
