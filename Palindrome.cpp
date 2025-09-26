/* Name: Aahana Sapra
   Date: 9/11/2025
   Description: This program will read in a series of characters
   and remove all spaces and punctuation so there are only letters
   and numbers left. Then, the program will determine if the string
   of characters is a palindrome.
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  // read in user input
  char userInput[80];
  cin.get(userInput, 80);

  /* prints number of char
     cout << "Length (null-terminated): " << strlen(userInput) << endl;
     prints 80
     cout << "Length (fixed-size): " << sizeof(userInput) << endl;
  */
  
  // remove spaces and punctuation
  char modifiedInput[80];
  int indexModified = 0;
  for (int i = 0; i < strlen(userInput); i++) {
    if (isalnum(userInput[i])) {
      modifiedInput[indexModified] = userInput[i];
      // change letters to lower case
      if (isalpha(modifiedInput[indexModified])) {
	modifiedInput[indexModified] = tolower(modifiedInput[indexModified]);
      }
      indexModified++;
    }
  }
  modifiedInput[indexModified] = '\0';

  // reverse input and store in another array
  char reverseInput[80];
  int indexReverse = 0;
  for (int i = strlen(modifiedInput) - 1; i >= 0; i--) { // last index = length - 1
    reverseInput[indexReverse] = modifiedInput[i];
    indexReverse++;
  }
  reverseInput[indexReverse] = '\0';

  // check if input is a palindrome and print results
  if (strcmp(modifiedInput, reverseInput) == 0) {
    cout << "Palindrome" <<  endl;
  } else {
    cout << "Not a palindrome." << endl;
  }
  
  return 0;
}
