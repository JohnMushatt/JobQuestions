//
// Created by john on 12/1/19.
//

#include "TextParser.h"

TextParser::TextParser(string filename) {
    cout << "Opening file..." << endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Filename does not exist");
    }
    string current_word;
    while (file >> current_word) {

        /**
         * We are going to remove any ':' and '.' characters from words for the purpose of this question
         */
        int punc_check =  current_word.find('.') + current_word.find(':');
        if(punc_check >= 0) {
            current_word = current_word.substr(0,current_word.size()-1);
        }
        /**
         * If we don't find the word in the hash map, add it with a frequency of 0
         */
        if (this->frequencies.count(current_word)==0) {
            //Make a pair
            std::pair<string, int> p(current_word, 1);
            //Insert pair into map
            this->frequencies.insert(p);
        } else {
            /**
             * Insert or replace the new [word : frequency] pair with updated frequency
             */
            this->frequencies.insert_or_assign(current_word, this->frequencies.at(current_word) + 1);
        }
    }
    /**
     * Construct an iterator to loop through the hash map
     */
    std::unordered_map<string,int>::iterator it = this->frequencies.begin();
    //Max frequency
    std::pair<string,int> max("",0);
    //Iterator over the hash map
    while(it!=this->frequencies.end()) {
        if(it->second>=max.second) {
            max.first = it->first;
            max.second = it->second;
        }
        it++;
    }

    cout<<"Most frequent word: \"" << max.first << "\". It's frequency was: " << max.second<<endl;

}