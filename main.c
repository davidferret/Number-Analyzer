#include <stdio.h>
#include <stdlib.h>

void findLargestAndSmallest(int numbers[], int size);
void calculateMedianAndAverage(int numbers[], int size);
void saveResultsToFile(int numbers[], int size);
void menu();

int main(void) {
    int size;
    char choice;

    do {
        printf("\n--- Number Analyzer ---\n");
        printf("Enter the number of integers you want to input: ");
        scanf("%d", &size);

        int *numbers = (int *)malloc(size * sizeof(int));
        if (numbers == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter %d integers separated by spaces: ", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
        }
        
        findLargestAndSmallest(numbers, size);
        calculateMedianAndAverage(numbers, size);
        saveResultsToFile(numbers, size);
        
        free(numbers);
        
        printf("\nWould you like to analyze another set of numbers? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("Thank you for using the number analyzer!\n");
    return 0;
}

void findLargestAndSmallest(int numbers[], int size) {
    int largest = numbers[0], smallest = numbers[0];
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }
    
    printf("The largest number is %d\n", largest);
    printf("The smallest number is %d\n", smallest);
}

void calculateMedianAndAverage(int numbers[], int size) {
    // Sorting the array for median calculation
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    
    double median;
    if (size % 2 == 0) {
        median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    } else {
        median = numbers[size / 2];
    }
    
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    double average = sum / size;
    
    printf("The median is %.2lf\n", median);
    printf("The average is %.2lf\n", average);
}

void saveResultsToFile(int numbers[], int size) {
    FILE *file = fopen("number_analysis.txt", "w");
    if (!file) {
        printf("Error creating results file!\n");
        return;
    }
    
    fprintf(file, "Number Analysis Results:\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fprintf(file, "\n");
    
    int largest = numbers[0], smallest = numbers[0];
    double sum = 0;
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] > largest) largest = numbers[i];
        if (numbers[i] < smallest) smallest = numbers[i];
        sum += numbers[i];
    }
    
    double average = sum / size;
    fprintf(file, "Largest number: %d\n", largest);
    fprintf(file, "Smallest number: %d\n", smallest);
    fprintf(file, "Average: %.2lf\n", average);
    
    double median;
    if (size % 2 == 0) {
        median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    } else {
        median = numbers[size / 2];
    }
    fprintf(file, "Median: %.2lf\n", median);
    
    fclose(file);
    printf("Results saved to 'number_analysis.txt'.\n");
}
