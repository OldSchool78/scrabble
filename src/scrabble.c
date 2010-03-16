#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[7]);


int main(void)
{
    // Get input words from both players
	char word1[7], word2[7];

    printf("Player 1 : ");
    scanf ("%s", word1);

    
    printf("Player 2: ");
    scanf ("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    

    // Print the winner
    if (score1 > score2)
    {
		printf("Player 1 wins. Score: %d", score1);
	}
	else if (score2 > score1)
	{
		printf("Player 2 wins.Score: %d", score2);
	}
    else
    {
        printf("It's a tie!\n");
    }
	
	printf("\n");
	return(0);  
}


// Compute and return score for string
int compute_score(char word[7])
{
    int score = 0;
    size_t i;

    for (i = 0; i < strlen(word); i++)
    {
        char c = word[i];
        int index = toupper(c) - 'A';
        score += POINTS[index];
    }

    return score;
}

