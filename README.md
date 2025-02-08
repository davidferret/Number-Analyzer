# Number Analyzer

This is a project that processes a set of integers to determine useful statistical insights, including the largest and smallest values, the median, and the average. It's designed to help you quickly analyze a dataset and extract key numerical trends.

The way I programmed this project was by implementing a system that takes in space-separated integers, sorts them, and identifies the highest and lowest numbers. Then, it calculates the median by selecting the middle value or averaging the two middle numbers when applicable. It also computes the arithmetic mean, giving you a clear measure of the dataset’s central tendency. I included an interactive feature that allows you to repeat the calculations with new data, making it more flexible and user-friendly.

I built this project because I wanted a simple way to analyze numbers without needing a spreadsheet or a calculator. It was a good challenge to implement sorting logic and statistical functions while keeping the input and output intuitive. I hope that this helps you get quick insights from numerical data in an easy way.

## Example Output
```
--- Number Analyzer ---
Enter the number of integers you want to input: 5
Enter 5 integers separated by spaces: 10 20 30 40 50
The largest number is 50
The smallest number is 10
The median is 30.00
The average is 30.00
Results saved to 'number_analysis.txt'.

Would you like to analyze another set of numbers? (y/n): y
Enter the number of integers you want to input: 3
Enter 3 integers separated by spaces: 9 3 6
The largest number is 9
The smallest number is 3
The median is 6.00
The average is 6.00
Results saved to 'number_analysis.txt'.

Would you like to analyze another set of numbers? (y/n): n
Thank you for using the number analyzer!

```
