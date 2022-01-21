#include <iostream>

using namespace std;

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
		float highestRatingInList;
		char placements;
		char human;
		char temp;

		cout << "\nPlacements? (y): ";
		cin >> placements;
		cout << "Total sum all ratings played against: ";
		cin >> temp;
		if (temp == '.') {
			cout << "Average rating opponents: ";
			cin >> averageOpponent;
		} else {
			sumRatingAllOpponents = float(temp);
		}
		cout << "Matches played: ";
		cin >> matches;
		cout << "Score: ";
		cin >> score;
		if (placements == 'y') {
      		multiplier = 8;
      		ownRating = (sumRatingAllOpponents / matches);
		}
		else {
			cout << "Multiplier: ";
			cin >> multiplier;
      		cout << "Your own rating: ";
      		cin >> ownRating;
		}
		if (temp != '.') { averageOpponent = sumRatingAllOpponents / matches; }
		cout << "\nAverage opponent is ", averageOpponent;
		cout << "\nYour new rating is ", newRating(multiplier, ownRating, averageOpponent, matches, score);
	}
}
