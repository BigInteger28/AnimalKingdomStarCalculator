package main

import (
	"fmt"
)

func newRating(multiplier, ownRating, averageOpponent, matches, score float64) float64 {
	mid := matches / ((averageOpponent / ownRating) * 2)
	if mid > matches*0.7 {
		mid = matches * 0.7
	}
	abovemid := score - mid
	return ownRating + (abovemid * multiplier)
}

func main() {
	for {
		var multiplier, ownRating, sumRatingAllOpponents, matches, score, averageOpponent float64
		var placements, temp string

		fmt.Println("\n\nPlacements? (y): ")
		fmt.Scanln(&placements)
		fmt.Println("Matches played: ")
		fmt.Scanln(&matches)
		fmt.Println("Score: ")
		fmt.Scanln(&score)
		fmt.Println("Average rating? (y): ")
		fmt.Scanln(&temp)
		if temp == "y" {
			fmt.Println("Average rating opponents: ")
			fmt.Scanln(&averageOpponent)
		} else {
			fmt.Println("Total sum all ratings played against: ")
			fmt.Scanln(&sumRatingAllOpponents)
			averageOpponent = sumRatingAllOpponents / matches
		}
		fmt.Println("Multiplier: ")
		fmt.Scanln(&multiplier)

		if placements == "y" {
			ownRating = averageOpponent
		} else {
			fmt.Println("Your own rating: ")
			fmt.Scanln(&ownRating)
		}
		fmt.Println("\nAverage opponent is", averageOpponent)
		fmt.Println("\nYour new rating is", newRating(multiplier, ownRating, averageOpponent, matches, score))
	}
}
