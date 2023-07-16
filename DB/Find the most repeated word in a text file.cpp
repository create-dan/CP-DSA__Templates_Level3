#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> &p1, pair<string, int> &p2)
{
    return p1.second > p2.second;
}

vector<pair<string, int>> mostFreqElements(string filename)
{

    // jo file open karni hai
    ifstream file(filename);

    string line;

    map<string, int> wordFreq;

    // read the file line by line
    while (getline(file, line))
    {
        stringstream ss(line);
        string word;

        // tokenize the line into words
        while (ss >> word)
        {
            wordFreq[word]++;
        }
    }

    // putting map data into vector
    vector<pair<string, int>> ans(wordFreq.begin(), wordFreq.end());
    sort(ans.begin(), ans.end(), cmp);

    return ans;
}

int main()
{

    string filename = "example.txt";

    // {"first",10}
    // {"second",20}
    // {"third",30}

    vector<pair<string, int>> v = mostFreqElements(filename);

    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}

// The code snippet you provided reads a file line by line and tokenizes each line into words.It then updates the frequency count of each word using a `wordFreq` map.

// Here's a detailed explanation of the code:

// 1. `while (getline(file, line))`: This loop reads the file line by line until the end of the file. It uses the `getline()` function to read each line and store it in the `line` variable.

// 2. `stringstream ss(line)`: This creates a stringstream object `ss` and initializes it with the current line. The stringstream allows us to extract individual words from the line.

// 3. `string word`: This variable will store each word extracted from the line.

// 4. `while (ss >> word)`: This inner loop extracts words from the stringstream `ss` one by one until there are no more words left. It uses the `>>` operator to extract each word and store it in the `word` variable.

// 5. Inside the inner loop, you can perform any necessary preprocessing or cleaning on the word, such as removing punctuation or converting it to lowercase, depending on your requirements.

// 6. `wordFreq[word]++`: This line updates the frequency count of the current word in the `wordFreq` map. If the word is not already present in the map, it is added with a frequency count of 1. If the word is already present, its frequency count is incremented by 1.

// The important file management function used in this code is `getline()`, which reads a line from the input file. It takes two parameters: the file object (`file`) and a string variable (`line`) where the read line will be stored. `getline()` returns a boolean value indicating whether the read operation was successful or not (true if successful, false otherwise). By using this function in a `while` loop, you can read the file line by line until the end.

// Overall, this code snippet demonstrates a simple approach to read a file, tokenize it into words, and count the frequency of each word using a map data structure.