#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
    char big[26] = {'X', 'K', 'C', 'H', 'G', 'P', 'E', 'S', 'Y', 'D', 'A', 'W', 'Q', 'O', 'R', 'M', 'L', 'U', 'V', 'F', 'Z', 'B', 'T', 'J', 'I', 'N'};
    char small[26] = {'j', 'e', 'u', 'c', 'i', 'b', 'x', 'g', 'h', 'p', 'a', 'r', 'm', 'o', 'n', 's', 'v', 'd', 'y', 'f', 'q', 'l', 'k', 't', 'z', 'w'};
    char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char special[32] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', ':', ';', '"', '\'', '<', '>', '?', '/', '\\', '~'};
    int bi, sm, nu, sp;
    cout << "Please enter total capital letter you want: ";
    cin >> bi;
    cout << "Please enter total small letter you want: ";
    cin >> sm;
    cout << "Please enter total number you want: ";
    cin >> nu;
    cout << "Please enter total special character you want: ";
    cin >> sp;
    int total = bi + sm + nu + sp;
    char output[total];
    cout << endl
         << "Your Password will be " << total << " character long." << endl
         << "Please wait " << total << " seconds...." << endl;
    for (int a = 0; a < bi; a++)
    {
        int min = 0;
        int max = 25;
        srand(time(0));
        int random = rand() % (max - min + 1) + min;
        output[a] = big[random];
        sleep(1);
    }
    for (int a = bi - 1; a < bi + sm - 1; a++)
    {
        int min = 0;
        int max = 25;
        srand(time(0));
        int random = rand() % (max - min + 1) + min;
        output[a] = small[random];
        sleep(1);
    }
    for (int a = sm + bi - 1; a < +nu + bi + sm - 1; a++)
    {
        int min = 0;
        int max = 9;
        srand(time(0));
        int random = rand() % (max - min + 1) + min;
        output[a] = num[random];
        sleep(1);
    }
    for (int a = sm + nu + bi - 1; a < nu + sp + bi + sm - 1; a++)
    {
        int min = 0;
        int max = 31;
        srand(time(0));
        int random = rand() % (max - min + 1) + min;
        output[a] = special[random];
        sleep(1);
    }
    cout << "Your Password is: ";
    random_shuffle(output, output + total);
    for (int a = 0; a < total; a++)
    {
        cout << output[a];
    }
}
