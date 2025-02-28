Test Case 1 :
The usual case where people put in normal values.

Input: $ ./main 10
1,2
3,5

Output: 10 @ 1 = 20
Remainder: 0
Value: 20

Test Case 2:
Maybe someone forgot to put in a valuie or is confused on how it works.
$ ./main
Usage: C:\351Proj\Proj1\main <rod_length>

Test Case 3
What if a user inputs an invalid format?
$ ./main 20
Enter segment data as <length>, <value>

Remaining Rod: 20
Value: 0

Test Case 4:
$ ./main 20
To make sure there are actually options that are more than 0
Enter segment data as <length>, <value>
0,2
Invalid segment data. Ensure length > 0 and value >= 0.

Test Case 5:
What if the user is trying to input a negative value.
$ ./main 20
-1.4
Invalid format

Test case 6:
This is a bigger one that had a few options on what to pick.
$ ./main 47
Enter segment data as <length>, <value>
2,3
3,5
5,9

9 @ 5 = 81
1 @ 2 = 3
Remainder: 0
Value: 84
