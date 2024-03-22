/**------------------------------------------
    Program 3: Typing Tutor

    Course: CS 141, Fall 2022.
    System: Linux x86_64 and G++
    Author: Ayush Patel, Starter Code provied by :George Maratos and David Hayes
 ---------------------------------------------**/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
using namespace std;

const int NMISP = 5;
const int RNG_RANGE = 100;

void
display_header(const int ndict, const int nmiss)
{ //this functions displays the header for the typing tutor, where ndict is the total number of words in the dictionary, and nmiss is the total number of words mispelled
  cout << "*** Typing Tutor" << endl;
  cout << "There are " << ndict << " words in the dictionary." << endl;
  cout << "There are " << nmiss << " commonly misspelled words." << endl;
    /* TODO: Print out the header, you can see an example of it
    in the write-up. Refer to Section "At Program Start".

    Parameters:
        int ndict -> the number of words in the full dictionary
        int nmiss -> the number of word pairs in the misspelled
                     dataset.
    */
}

void
display_menu_options()
{
    /* This function prints out all the menu options, it is
    given to you as part of the starter code. If you change
    it,  you run the  risk of failing  an early test of the
    autograder.*/

    cout << endl << "*** Select a menu option:" << endl
         << "1. Spell commonly misspelled words" << endl
         << "2. Type random words from the full dictionary" << endl
         << "3. Display some words from one of the lists" << endl
         << "4. Use binary search to lookup a word in the dictionary" << endl
         << "5. Exit the program." << endl
         << "Your choice: ";
}

vector<int>
randn(const int n, const int max)
{ // this function prints out the random words from the file, using rand and modulo of the max number plus one, and you use a vector to push back the random number
  vector<int> temp;
  
  // srand(n);
  int randomn = 0;
  for (int i = 0; i < n; i++) {
    randomn = rand() % (max+1);
    temp.push_back(randomn);
  }
  return temp;
    /*  TODO: Create and return a vector that has n random numbers drawn
    from  between 0 and the value of the parameter max. This function is
    relevant to many sections, and is needed any time random numbers are
    needed. Check the example file rng.cc for hints.

    Parameters:
        int n -> the number of random numbers to generate
        int max -> the maximum random number, random numbers are drawn
                    from between [0, max]

    Returns:
        a vector that contains n random numbers between [0, max]
    */

    // placeholder statements so code compiles you can delete these
    // return temp;
}

ifstream
open(const string& src_file)
{
    ifstream src{src_file};
    if (!src.is_open()) {
        cout << "Could not find file " << src_file << "." << endl;
        exit(1);
    }
    return src;
}

void
extract_dict(vector<string>& dst, const string& src_file)
{ // this function opens the file and uses a vector to push the strings from the file
  
  ifstream r = open(src_file);
  string str;
  while (getline(r, str)) {
    dst.push_back(str);
    }
    
    /* TODO: Read the data from the file, the file name is src_file,
    and store each line in the vector dst.

    Parameters:
        dst -> an empty vector (of strings), passed by reference,
               that  you  will  store  every line  of the file in
               (each line is one element in the file).

        src_file -> a string, passed by reference, that you are not
                    allowed to change  (const),  that is simply the
                    name of the file.
    Hints:
        Use the function (defined in this file) called open.
    */
}

void
extract_misspelled(vector<string>& misspelled, vector<string>& correct,
                    const string& src_file)
{ // this function extracts the mispelled words into a vector from the file given, using clear resets the words in the file as it is going in order
  
  ifstream r = open(src_file);
  string str;
  string vectoradd;
  while (getline(r, str)) {
    for (int i = 0; i < str.size(); i++) {
      if (str.at(i) == ' ') {
        misspelled.push_back(vectoradd);
        vectoradd.clear();
        }
      else {
        vectoradd.push_back(str.at(i));
        }
    }
    correct.push_back(vectoradd);
    vectoradd.clear();
    }
  
        
    
  
    /* TODO: Extract the word pairs (misspelled, correct) from the file
    and store them in their respective vectors.

    Parameters:
        misspelled -> an  empty vector (strings),  passed by reference,
                      that you will store the misspelled words in.

        correct -> an empty vector (strings), passed by reference, that
                   you will store the correct version of the words in.

        src_file -> a string, passed by reference, that you are not
                    allowed to change  (const),  that is simply the
                    name of the file.
    Hints:
        This function is very similar to extract_dict. Instead of simply
        storing the contents of the whole line as an element in dst, you
        have to process  the line into a misspelled word and the correct
        version. Each of those will be stored into separate vectors.  So
        you  should have  misspelled[i]  =  the ith misspelled  word and
        correct[i] = the ith correct word.
    */
}

void
display_elems(const vector<string>& src, const vector<int>& positions)
{ // this function displays the elements by accessing the positions of the string
   for (int i = 0; i < 5; i++) {
     if (i != 5-1) {
       cout << src.at(positions.at(i)) << " ";
     }
     else {
       cout << src.at(positions.at(i));
       }
     }
    /* TODO: With the vector of indices (position), print out the elements
    in the vector src only at those indices,  with a space between each of
    the elements.  Don't print a space after the last element. See Section
    "Menu Option 1: Spelling Misspelled"

    Parameters:
        src -> a vector (strings), passed by reference, that is not
               allowed to be modified (const), which holds the data
               that is to be printed

        positions -> a vector (int), passed by reference, that is not
                     allowed to be modified (const),  which holds the
                     indices for elements in src to print.
    */
}

void
extract_spelling_answers(vector<string>& dst, const vector<string>& correct,
                            const vector<int> positions)
{ // this function has the correct words spelled in the correct vector
  for (int i = 0; i < 5; i++) {
       dst.push_back(correct.at(positions.at(i)));
     }
     
    /* TODO: Copy the elements at the indices, in the positions vector,
    from the correct vector, into the vector dst. See Section "Menu Op-
    tion 1: Spelling Misspelled".

    Parameters:
        dst -> an empty vector (of strings), passed by reference, that
               you will copy the specific elements from correct into.

        correct -> a vector (strings), passed by reference, that is not
                   allowed to be modified (const), which holds the data
                   that is to be copied over to dst

        positions -> a vector (int), passed by reference, that is not
                     allowed to be modified (const),  which holds the
                     indices of the elements in correct to copy over

    Hints:
        This is very similar to display_elems, except you are not printing
        out the elements but instead copying them over to dst.
    */
}

void
extract_spelling_mistakes(vector<string>& dst, const string& to_grade,
                const vector<string>& correct)
{ // this function extracts the mistakes the user makes, using the string stream function and a vector to extract the to grade string, and then using a for loop to add the word spelled correctly into a vector
  vector<string> extract; // extract to_grade into each word
  string str;
  istringstream ss(to_grade);
  while (getline(ss, str, ' ')) {
    extract.push_back(str);
  }
  for (int i = 0; i < 5; i++) {
    if (extract.at(i) != correct.at(i)) {
      dst.push_back(extract.at(i) + " -> " + correct.at(i));
      // cout << extract.at(i) << "->" << correct.at(i) << endl;
    }
  }
  
  
    /* TODO: Populate the vector dst with all the spelling errors in the
    user's answer (to_grade).  See Section "Menu Option 1: Spelling Mis-
    spelled"

    Parameters:
        dst -> an empty vector (of strings), passed by reference, that you
        will fill with strings that represent spelling errors  (mispelling
        -> correct spelling) (see Hints)

        to_grade -> a string, passed  by reference,  that is not allowed to
                    be modified (const) that holds the user's typed answer.

        correct -> a vector (strings), passed by reference, that is not
                   allowed to be modified (const), which holds the correct
                   answers. (one vector element -> one word)

    Hints:
        First you need to extract the answer, the user gave, for each word.
        Once you have those, you can compare it with the associated correct
        answer  (answer ?= correct[i] for the ith word).  You then populate
        the vector dst with a string that described the error. For example,
        if the word is  "hello" and  the user types  "jello" then the error
        will be "jello -> hello".
    */
}

void
report_misspell_mistakes(const vector<string>& mistakes,
                            const int num_words)
{ // this function reports the mispelled words that the user inputted, and counter is how many times the user makes an error, and calculated the correct and not correct words depending on how many right or wrong the user got
  int counter = 0;
  int correctcounter = 0; 
  if (mistakes.size() != 0) {
    cout << "Misspelled words: " << endl;
  }
  for (int i = 0; i < mistakes.size(); i++) {
    // cout << "Misspelled words: " << endl;
    cout << "    " << mistakes.at(i) << endl;
    counter = counter + 1;
  }
  if (counter == 0) {
    cout << "No misspelled words!" << endl;
  }
  correctcounter = 5 - counter;
  int win = correctcounter*3;
  int lose = counter*6;
  cout << win << " points: " << correctcounter << " spelled correctly x 3 points for each." << endl;
  cout << lose << " point penalty: " << counter << " spelled incorrectly x -6 points for each." << endl;
  cout << "Score: " << win - lose << endl;
    /*  TODO: Print out the spelling mistakes to the user. Following
    the format from the write-up. See Section "Menu Option 1: Spell-
    ing Misspelled".

    Parameters:
        mistakes -> a vector (strings), passed by reference, that is
                    not allowed  to be modified  (const),  and holds
                    the messages about  misspellings that we want to
                    report to the user.

        num_words -> an integer, that is not allowed to be modified
                     (const),  which is  the total number  of words
                     being tested
    */
}

void
evaluate_user_misspells(const vector<string>& src, const vector<int>& positions)
{ // this function calls the previous functions to output the mistakes the user makes
  string input;
  getline(cin, input);

  vector<string> mistakes;
  vector<string> answers;
  // int total;

  extract_spelling_answers(answers, src, positions);

  extract_spelling_mistakes(mistakes, input, answers);

  report_misspell_mistakes(mistakes, answers.size());
  
    /*TODO: Read the users input for the typing test, and report
    back their performance. See Section "Menu Option 1: Spelling
    Misspelled".

    Parameters:
        src -> a vector (strings), passed by reference, that is not
               allowed to be modified (const), which holds the data
               that the user is being tested on.

        positions -> a vector (int), passed by reference, that is not
                     allowed to be modified (const),  which holds the
                     indices of the elements in correct to copy over

    Hints:
        Using getline to read in  the entire sequence might be a
        good idea. This function  should be easier to  write, if
        you have already completed the functions for calculating
        and  reporting  spelling mistakes.  Call those functions
        instead of duplicating the work.
    */
}

void
misspelled(const vector<string>& mspelled, const vector<string>& correct)
{ // this function is the menu option 1, data is all of the words that the program shows to the user to type, calling the random, display elems, and the user misspells function to have menu option 1 work
  
  vector<int> randomnum = randn(5, mspelled.size()-1);
  cout << endl;
  cout << "*** Using commonly misspelled words." << endl; 
  vector <string> src;
  // vector<int> indices;
  vector<string> data;
  for (int i = 0; i < correct.size(); i++) {
    data.push_back(correct.at(i));
  }
  for (int i = 0; i < mspelled.size(); i++) {
    data.push_back(mspelled.at(i));
  }
  display_elems(mspelled, randomnum);
  cout << endl;
  cout << "Type the words above with the correct spelling: " << endl;
  evaluate_user_misspells(data, randomnum);
    /*  TODO: Print out the starting message for option 1, display 5 random
    words from the dictionary, finally evaluate the user's input. See "Menu
    Option 1: Spelling Misspelled".

    Parameters:
        mspelled -> a vector (string) where each element is one
                    mispelled word from the data set

        correct -> a vector (string) where each element is a
                   correctly spelled word from the data set

    Hints:
        Do not try to write this function first.  The role of this function
        is to simply drive the whole procedure for menu option 1, it should
        be calling helper functions to handle the details of the sub tasks.
        Use randn, display_elems, and evaluate_user_misspells.
    */
}

void
full_dict(const vector<string>& dict)
{ // this function shows the menu option 2 where the words are from the dictionary
  cout << endl;
  cout << "*** Using full dictionary." << endl;
  vector<int> guess = randn(5, dict.size()-1);
  display_elems(dict, guess);
  cout << endl;
  cout << "Correctly type the words above: " << endl;
  evaluate_user_misspells(dict, guess);
    /* TODO: Print out starting message for menu option 2, display five random
    words from the full dictionary, then evaluate the user's input. See Section
    "Menu Option 2: Typing From Dictionary"

    Parameters:
        dict -> a vector (string), passed by reference, where
                each element is one word from the full
                dictionary.

    Hints:
        Do not start by writing this function. It's role is to simply drive
        the whole procedure for menu option 2,  it should be calling helper
        functions to  handle the details  of the task.  You should be using
        randn, display_elems, and evaluate_user_misspells.
    */
}

void
display_words_prompt()
{
    // This displays the data set choices for menu option 3
    cout << endl << "*** Displaying word list entries." << endl
         << "Which words do you want to display?" << endl
         << "A. Dictionary of all words" << endl
         << "B. Commonly misspelled words (wrongly spelled)" << endl
         << "C. Commonly misspelled words (correctly spelled)" << endl
         << "Your choice: ";
}

void
print_range(const vector<string>& data)
{ // this function gets input from the user of two numbers for the range of words from the file, and if the range total is negative, the range is going the wrong way, and the range numbers have to be within the file size, output error message if the inputs are invalid
  
  int range1;
  int range2;
  cin >> range1;
  cin >> range2;
  if (range2-range1 > 0 && range1 <= data.size() && range2 <= data.size() ) {
    
    for (int i = range1; i <= range2; i++) {
      cout << i << ". " << data.at(i) << endl;
    }
    }
  else {
    cout << "The end index must come after the start, and the indices must be in range." << endl;
  }
  
  
    /* TODO:  Display the starting  message for menu option 3,  read the
    users chosen range, verify that the indices are in range, then print
    out the  words in the index range.  See Section "Menu Option 3: Word
    Range"

    Parameters:
        data -> a vector (string),  passed by reference, that cannot be
                modified (const), which holds the all the data (and the
                user will print some of it in a range)

        Hints:
            You can determine the range of the data by checking the size
            of the vector. You need to make sure the  range is valid for
            the given dataset  (think about what  values  the user could
            give that would be invalid). Check the write-up to make sure
            you are printing the data in the expected format.
    */
}

void
display_in_range(const vector<string>& dict, const vector<string>& mspelled,
                const vector<string>& correct)
{ // this function is for menu option 3, reads user input of a letter between a, b, and c, and depending on the choice, the user gets the words on the certain file from the option 
  display_words_prompt();
  char userInput;
  cin >> userInput;
  if (userInput == 'A' || userInput == 'a') {
    cout << "*** Enter the start and end indices between 0 and " << dict.size()-1 << ": ";
    print_range(dict);
  }
  else if (userInput == 'B' || userInput == 'b') {
    cout << "*** Enter the start and end indices between 0 and " << mspelled.size()-1 << ": ";
    print_range(mspelled);
  }
  else if (userInput == 'C' || userInput == 'c') {
    cout << "*** Enter the start and end indices between 0 and " << correct.size()-1 << ": ";
    print_range(correct);
  }
    /* TODO: Display the initial messages for menu option 3, read in
    the user's choice of dataset, and display the data in range. See
    Section "Menu Option 3: Word Range"

    Parameters:
        dict -> a vector (string),  passed by reference, that cannot be
                modified (const), which holds the all the data from the
                full dictionary

        mspelled -> a vector (string), passed by reference, that cannot
                    be modified (const),  which holds the all the miss-
                    pelled words

        correct -> a vector (string), passed by reference, that cannot
                   be modified (const),  which holds the all the words
                   with correct spelling

    Hints:
        First write  the function print_range, which will print data in a
        range (in general). This function should call print_range, but it
        will read in the user's  choice of data set and  call print_range
        with the user's choice.
    */

}

void
bsearch(const vector<string>& data)
{ // this function does the bonary search for menu option 4, where mid is the middle number of each iteration, and left and right depends on whether the word is close to the middle word or not, the counter was for the number in steps of the word, and if counter is 10 or more, the output is one less space
  string binaryinput;
  cout << "*** Enter word to search: ";
  cin >> binaryinput;
  bool found;
  int counter = 0;
  int mid = 0;
  int left = 0;
  int right = data.size()-1;
  while (left <= right) {
    // mid = left + right + 1;
    mid = (left+right+1) / 2;
    if (binaryinput > data[mid]) {
      left = mid + 1;
      counter = counter +1;
      if (counter >= 10) {
        cout << "   " << counter << ". Comparing to: " << data[mid] << endl;
      }
      else {
      cout << "    " << counter << ". Comparing to: " << data[mid] << endl;
        }
    }
    else if (binaryinput < data[mid]) {
      right = mid - 1;
      counter = counter + 1;
      if (counter >= 10) {
        cout << "   " << counter << ". Comparing to: " << data[mid] << endl;
      }
      else {
      cout << "    " << counter << ". Comparing to: " << data[mid] << endl;
        }
    }
    else {
      if (counter >= 10) {
        cout << "   " << counter+1 << ". Comparing to: " << data[mid] << endl;
      }
      else {
      cout << "    " << counter+1 << ". Comparing to: " << data[mid] << endl;
        }
      // cout << "    " << counter+1 << ". Comparing to: " << data[mid] << endl;
      found = true;
      break;
    }
  }
  if (found) {
    cout << binaryinput << " was found." << endl;
  }
  else {
    cout << binaryinput << " was NOT found." << endl;
  }
  

    
    /* TODO:  Read in the word to search for, from the user, and run the
    Binary Search Algorithm to search for the word. At every step of the
    algorithm,  print out the current word,  that is being compared with
    the target.

    Parameters:
        data -> a vector (string),  passed by reference, that cannot be
                modified (const), which holds the all the data from the
                full dictionary
    Hints:
        See our sample code to learn how the binary search algorithm works.
        Remember to  output the text in the same  format as you  see in the
        write-up.
    */

}

void
extract_all_data(vector<string>& dict, vector<string>& mspelled,
                    vector<string>& correct)
{
    extract_dict(dict, "dictionary.txt");
    extract_misspelled(mspelled, correct, "misspelled_words.txt");
}

int
main()
{
    srand(1);
    vector<string> dict, mspelled, correct;
    extract_all_data(dict, mspelled, correct);
    display_header(dict.size(), correct.size());
    unsigned int choice;
    do {
        display_menu_options();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            misspelled(mspelled, correct);
            break;
        case 2:
            full_dict(dict);
            break;
        case 3:
            display_in_range(dict, mspelled, correct);
            break;
        case 4:
            bsearch(dict);
            break;
        case 5:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "No menu option " << choice << ". "
                 << "Please try again." << endl;
        }
    } while ((choice != 5) && !cin.eof());

    return 0;
}