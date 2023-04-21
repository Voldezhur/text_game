#include <iostream>
#include <string>
#include <time.h>

double A = time(nullptr);

unsigned int fonNeyman(unsigned int x){
    if(x < 8){
        // get the number from which to get the random value
        std::string B = std::to_string(A*A);
        std::string num = "";

        // index to start building randomized value from
        int n = 10;
        

        // build randomized value with numbers taken from the middle of the original number (from 5th to (x-1)th)
        for(int i = n; i <= n + x - 1; i++){
            // check if value starts with 0 and if it does replace 0  with 1
            if(i == n && B[i] == '0'){
                num += '1';
            }

            else{
                num += B[i];
            }
        }


        // replace A with B for different results, checking if the first number is 0 and replacing it with 1 in that case
        if(B[4] == '0'){
            B[4] = '1';
        }

        A = stod(B.substr(4, 11));
    

        // return final randomized value
        return stoi(num);
    }


    else{
        std::cout << "x must be less than 8";
    }
    
    return 0;
}