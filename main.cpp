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

    cout << "\n\nPlacements? (y): ";
    cin >> placements;
    cout << "Matches played: ";
	cin >> matches;
    cout << "Score: ";
	cin >> score;
    cout << "Average rating? (y): ";
    cin >> temp;		
		if (temp == 'y') {
			cout << "Average rating opponents: ";
			cin >> averageOpponent;
		} else {
            cout << "Total sum all ratings played against: ";
			cin >> sumRatingAllOpponents;
            averageOpponent = sumRatingAllOpponents / matches;
		}		
		
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
		cout << "\nAverage opponent is " << averageOpponent << endl;
		cout << "\nYour new rating is " << newRating(multiplier, ownRating, averageOpponent, matches, score) << endl;
	}
}
