#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int str_to_int(std::string str) {
    std::string numsStr[10] = { "zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i < 10; i++) {
        if (str == numsStr[i]) {
            return i;
        }
    }
    return -1;
}

void reverse_str(std::string& str) {
    std::reverse(str.begin(), str.end());
}

int find_first_number(std::string str) {
    std::string numsStr[10] = { "zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 1; i < str.length() + 1; i++) {
        std::string newStr = str.substr(0, i);
        if (isdigit(newStr[i - 1])) {
            return newStr[i - 1] - '0';
        }
        for (int j = 0; j < 10; j++) {
            if (newStr.find(numsStr[j]) != std::string::npos) {
                return str_to_int(numsStr[j]);
            }
        }
    }
    return -1;
}

int find_last_number(std::string str) {
    std::string numsStr[10] = { "orez", "eno", "owt", "eerht", "ruof", "evif", "xis", "neves", "thgie", "enin" };
    reverse_str(str);
    for (int i = 1; i < str.length() + 1; i++) {
        std::string newStr = str.substr(0, i);
        if (isdigit(newStr[i - 1])) {
            return newStr[i - 1] - '0';
        }
        for (int j = 0; j < 10; j++) {
            if (newStr.find(numsStr[j]) != std::string::npos) {
                std::string check = numsStr[j];
                reverse_str(check);
                return str_to_int(check);
            }
        }
    }
    return -1;
}

int main()
{
    std::ifstream fptr("input.txt");
    if (!fptr) {
        std::cout << "Nie mozna odczytac pliku";
        return 1;
    }
    
    std::string myString;
    int counter = 1;
    int sum_numbers = 0;
    int firstNumber = 0;
    int lastNumber = 0;

    while (std::getline(fptr, myString)) {
        std::string str_number;
        firstNumber = find_first_number(myString);
        lastNumber = find_last_number(myString);
        str_number = std::to_string(firstNumber) + std::to_string(lastNumber);
        sum_numbers += std::stoi(str_number);
        std::cout << counter << ". " << firstNumber << lastNumber << "\n";
        counter++;
    }

    std::cout << "Sum of numbers: " << sum_numbers;
    fptr.close();

    return 0;
}
