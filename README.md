# Max-Feq-words-Sorting
Max-Feq-words-Sorting

# High level algorithm:
1) Open document
2) Read words and add them to Single linked list. (avoid using Double LL to get rid of extra overhead)
3) If the word already exists in teh list, increment the count of frequency.
4) Sort the list on the basis of frequency of usage.
5) Print the list.

# Complexity:
As we are using the sorting algorithm, I have used Insertion sort.
Time complexcity : O(n*n)
Space complexity : O(m) : m represents the number of unique word (structure consist of word & count).
