#include <stdio.h>

int main(void)
{
    int score;
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            int character;
            if (feof(stdin)) {
                return 0;
            }
            printf("Please enter a whole number.\n");
            while ((character = getchar()) != '\n' && character != EOF) {
            }
            continue;
        }
        if (score == 1) {
            break;
        }
        if (score < 0) {
            printf("Invalid score. The score cannot be negative.\n");
            continue;
        }
        printf("Possible combinations of scoring plays if a team's score is %d:\n",
               score);

        int foundCombination = 0;

        for (int tdTwoPoint = 0; tdTwoPoint <= score / 8; tdTwoPoint++) {
            int pointsLeftAfter8 = score - tdTwoPoint * 8;

            for (int tdFieldGoal = 0; tdFieldGoal <= pointsLeftAfter8 / 7;
                 tdFieldGoal++) {
                int pointsLeftAfter7 = pointsLeftAfter8 - tdFieldGoal * 7;

                for (int touchdown = 0; touchdown <= pointsLeftAfter7 / 6;
                     touchdown++) {
                    int pointsLeftAfter6 = pointsLeftAfter7 - touchdown * 6;

                    for (int fieldGoal = 0; fieldGoal <= pointsLeftAfter6 / 3;
                         fieldGoal++) {
                        int pointsLeft = pointsLeftAfter6 - fieldGoal * 3;

                        if (pointsLeft % 2 == 0) {
                            int safety = pointsLeft / 2;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, "
                                   "%d 3pt FG, %d Safety\n",
                                   tdTwoPoint, tdFieldGoal, touchdown,
                                   fieldGoal, safety);
                            foundCombination = 1;
                        }
                    }
                }
            }
        }
        if (foundCombination == 0) {
            printf("No scoring-play combinations produce a score of %d.\n", score);
        }
    }
    return 0;
}
