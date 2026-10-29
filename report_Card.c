#include <stdio.h>
int MAX_SIZE = 1000;

int sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    return s;
}

float average(int arr[], int n)
{
    float s = 0.0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    return (s / n);
}
int min(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (res > arr[i])
        {
            res = arr[i];
        }
    }
    return res;
}
// max2
int max(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (res < arr[i])
        {
            res = arr[i];
        }
    }
    return res;
}

char gradeOf(int score) // when called assigns a grade to the different values
{
    if (score >= 90)
        return 'A';
    else if (score >= 80)
        return 'B';
    else if (score >= 70)
        return 'C';
    else if (score >= 60)
        return 'D';
    else
        return 'F';
}

void printScoresandGrades(int scores[], int n) // print the final grades of the students submitted
{
    printf("\n---Individual Report---\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d: %d -> %c\n", (i + 1), scores[i], gradeOf(scores[i]));
    }
}

int average_return(int scores[], int n, float threshold)
{
    // int target = scores;
    int tmp = 0;
    // float class_average = average(scores,n);
    // printf("The class average is %d.\n",class_average);

    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= threshold)
        {
            tmp = tmp + 1;
        }
    }
    return tmp;
}

void printHistogram(int scores[], int n)
{
    int counts[5] = {0};

    for (int i = 0; i < n; i++)
    {
        char g = gradeOf(scores[i]);
        if (g == 'A')
            counts[0]++;
        else if (g == 'B')
            counts[1]++;
        else if (g == 'C')
            counts[2]++;
        else if (g == 'D')
            counts[3]++;
        else
            counts[4]++;
    }

    /*print five rows*/
    printf("\n---Grade Histogram---\n");
    char grades[5] = {'A', 'B', 'C', 'D', 'F'};
    for (int i = 0; i < 5; i++)
    {
        printf("%c: ", grades[i]);
        for (int j = 0; j < counts[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    // --- REPORT CARD----//
    // Determine the number of students
    int size, num;
    int score[MAX_SIZE];
    int array[MAX_SIZE];
    // Prompt user for number quantity in the array
    printf("How many students?: ");
    scanf("%d", &size);

    // S2 Guesser && S4 P04

    // s04 p04
    int i;

    for (i = 0; i < size; i++)
    {
        // if(score[i] > 0 || score[i] < 100)
        do
        {
            printf("Enter score for student %d (0 - 100): ", (i + 1));
            scanf("%d", &score[i]);

            if (score[i] < 0 || score[i] > 100)
            {
                printf("Invalid nmber !!!!!!, try again(0-100): \n");
            }

        } while (score[i] < 0 || score[i] > 100);
    }

    printScoresandGrades(score, size);

    // Class Report
    printf("\nClass Size : %d\n");
    printf("Sum : %d\n", sum(score, size));
    float avg = average(score, size);

    printf("Average : %.2f\n", avg);
    printf("Highest : %d\n", max(score, size));
    printf("Lowest : %d\n", min(score, size));
    printf("At or above average: %d student(s)\n", average_return(score, size, avg));

    printHistogram(score, size);

    // sum average min/max

    // Student grade (s04 p04)

    //  s04 & p04

    // Read each student's score
    // Print each students grade
    // Print class average
    //  count how many students scored at or above average
    // Print a tiny grade histogram

    return 0;
}