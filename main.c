#include <stdio.h>

float newRating(float multiplier, float ownRating, float averageOpponent, float matches, float score)
{
	float mid = matches / ((averageOpponent / ownRating) * 2);
	if (mid > matches * 0.7) mid = matches * 0.7;
	float abovemid = score - mid;
	return ownRating + (abovemid * multiplier);
}

int main()
{
	while (1 != 2)
    {
		float multiplier;
		float ownRating;
		float sumRatingAllOpponents;
		float matches;
		float score;
		float averageOpponent;
		float highestRatingInList; //Voorlopig is dit Amon
		char placements;
		char human;
		
        printf("Placements? (y): ");
        scanf(" %c", &placements);
        printf("Total sum all ratings played against: ");
        scanf("%f", &sumRatingAllOpponents);
		printf("Matches played: ");
		scanf("%f", &matches);
		printf("Score: ");
		scanf("%f", &score);
		if (placements == 'y') {			
            multiplier = 8;
            ownRating = (sumRatingAllOpponents / matches);			
		}
		else {
			printf("Multiplier: ");
			scanf("%f", &multiplier);
            printf("Your own rating: ");
            scanf("%f", &ownRating);
		}
        averageOpponent = sumRatingAllOpponents / matches;
		printf("\nAverage opponent is %.1f", averageOpponent);
		printf("\nYour new rating is %.1f", newRating(multiplier, ownRating, averageOpponent, matches, score));
		printf("\n\n");
	}
}
