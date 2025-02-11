/* Given a string array words, return an array of all characters
that show up in all strings within the words (including duplicates).
You may return the answer in any order.

 Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.


Here’s a C solution for the problem. It uses frequency counting to determine the common characters among all words.

Approach:
Maintain an array min_freq[26] to store the minimum frequency of each letter across all words.
Initialize min_freq with the frequency of the first word.
Iterate through the remaining words and update min_freq with the minimum count of each letter.
Construct the output based on min_freq.
*/

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

void commonChars(char *words[], int wordsSize) {
    int min_freq[ALPHABET_SIZE]; // Store minimum frequency of each character
    int temp_freq[ALPHABET_SIZE]; // Temporary frequency array
    
    // Initialize min_freq with frequency of characters in the first word
    memset(min_freq, 0, sizeof(min_freq));
    for (int i = 0; words[0][i] != '\0'; i++) {
        min_freq[words[0][i] - 'a']++;
    }

    // Iterate over remaining words
    for (int i = 1; i < wordsSize; i++) {
        memset(temp_freq, 0, sizeof(temp_freq));
        
        // Count character frequency for the current word
        for (int j = 0; words[i][j] != '\0'; j++) {
            temp_freq[words[i][j] - 'a']++;
        }

        // Update min_freq to store the minimum count
        for (int k = 0; k < ALPHABET_SIZE; k++) {
            if (min_freq[k] > temp_freq[k]) {
                min_freq[k] = temp_freq[k];
            }
        }
    }

    // Print the output based on min_freq
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        while (min_freq[i] > 0) {
            printf("%c ", i + 'a');
            min_freq[i]--;
        }
    }
    printf("\n");
}

// Driver Code
int main() {
    char *words1[] = {"bella", "label", "roller"};
    int size1 = sizeof(words1) / sizeof(words1[0]);
    commonChars(words1, size1); // Output: e l l

    char *words2[] = {"cool", "lock", "cook"};
    int size2 = sizeof(words2) / sizeof(words2[0]);
    commonChars(words2, size2); // Output: c o

    return 0;
}
/*Explanation:
The min_freq array keeps track of the minimum occurrence of each letter across all words.
temp_freq temporarily stores the frequency of letters for the current word.
The min_freq array is updated by taking the minimum count across all words.
Finally, the result is printed based on the characters that appear in all words.
Complexity:
Time Complexity: 
𝑂(𝑁×𝑀)
O(N×M), where 𝑁 N is the number of words and 
𝑀 M is the average length of each word.
Space Complexity: 𝑂(1)
O(1) (since we use fixed-size arrays).*/
