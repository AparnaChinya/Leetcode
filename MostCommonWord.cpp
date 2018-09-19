/*
819. Most Common Word
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.
Example:
Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.
 
Note:
	• 1 <= paragraph.length <= 1000.
	• 1 <= banned.length <= 100.
	• 1 <= banned[i].length <= 10.
	• The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
	• paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
	• Different words in paragraph are always separated by a space.
	• There are no hyphens or hyphenated words.
	• Words only consist of letters, never apostrophes or other punctuation symbols.

From <https://leetcode.com/problems/most-common-word/description/>
*/
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> mostOccurredWords;

        for(auto &ch : paragraph) {
            if(isalpha(ch)) {
                ch = tolower(ch);
            }
        }

        stringstream s(paragraph);
        //cout << paragraph;
        string line = "";
        while(getline(s,line,' ')) {
            for(auto &ch : line) {
                if(!isalpha(ch)) {
                    ch = ' ';
                }
            }
            line = (line[line.size()-1] == ' ') ? line.substr(0,line.size()-1) : line;
            if(find(banned.begin(),banned.end(),line) == banned.end() && line != " " && line != "\0") {
                //cout << line << endl;
                mostOccurredWords[line]++;
            }
        }
        string result = "";
        int max = INT_MIN;
        for(auto item : mostOccurredWords) {
            cout << item.first << " " << item.second << endl;
            if(max < item.second) {
                max = item.second;
                result = item.first;
            }
        }
        return (result[result.size()-1] == ' ') ? result.substr(0,result.size()-1) : result;
    }
};

