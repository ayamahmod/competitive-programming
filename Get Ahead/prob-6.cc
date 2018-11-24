// We look at car license plates and try to find a word from the dictionary
// that includes all the letters from the licence plate.
// The shorter the word, the better. The licence plates start with
// two or three letters, then they are followed by 5 characters,
// from which at most 2 are letters, the rest are digits.
// Write code that will find the shortest words for 1000 licence plates.
// You are given a dictionary. e.g. for the licence plate "RT 123SO" the s
// hortest word would be "SORT", for "RC 10014": "CAR".
//
// A few things to clarify:
// - Keep duplicate letters
// - Ordering is irrelevant
// - Case is irrelevant
// - The dictionary is sorted lexicographically
// - The dictionary contains about 4 million entries
//
// Test Cases
// For the licence plate "RT 123SO" the shortest word would be "SORT"
// For "RC 10014", the shortest word is "CAR".

bool comp(const string& s1, const string& s2) {
  return s1.size() < s2.size();
}

string allLettersWord(const string& license, vector<string>& dict) {
  string chars = "";
  for(int i = 0; i < license.size(); ++i) {
    if(license[i] >= "A" && license[i] <= "Z")
      chars += license[i]+32;
  }
  sort(chars.begin(), chars.end());
  sort(dict.begin(), dict.end(), comp);
  for(int i = 0; i < dict.size(); ++i) {
    if(dict[i].size() < chars.size()) continue;
    sortedWord = dict[i];
    sort(sortedWord.begin(), sortedWord.end());
    int j = 0, k = 0;
    do {
      if(sortedWord[j] > chars[k]) break;
      if(sortedDict[j] == chars[k]) ++k;
      ++j;
    } while(j < sortedWord.size() && k < chars.size());
    if(k == chars.size()) return dict[i];
  }
}

// Time complexity: O(nlogn)
// Space complexity: O(n) sort in place or not?
