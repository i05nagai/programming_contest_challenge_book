#include "chap2/greedy_best_cow_line.h"
#include <iostream>

std::string greedy_best_cow_line(std::string word)
{
    unsigned int start = 0;
    unsigned int end = word.size() - 1;
    std::string answer = "";
    bool useFront = false;

    for (int i = 0; i < word.size(); ++i) {
        // compare word with inversed word by disctionary order
        for (int j = 0; j < (end - start); ++j) {
            // front
            if (word[start + j] < word[end - j]) {
                useFront = true;
                break;
            // back
            } else if (word[start + j] > word[end - j]) {
                useFront = false;
                break;
            }
        }

        if (useFront) {
            answer += word[start];
            start++;
        // if word and inversed word is same order, we take the last char.
        } else {
            answer += word[end];
            end--;
        }
    }

    return answer;
}
