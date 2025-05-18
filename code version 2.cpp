#include <iostream>
#include <random>
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
         << "Your Password will be " << total << " character long." << endl;
    random_device rd;
    mt19937 gen(rd());
    for (int a = 0; a < bi; a++)
    {

        uniform_int_distribution<> dis(0, 25);
        output[a] = big[dis(gen)];
    }
    for (int a = bi - 1; a < bi + sm - 1; a++)
    {
        uniform_int_distribution<> dis(0, 25);
        output[a] = small[dis(gen)];
    }
    for (int a = sm + bi - 1; a < +nu + bi + sm - 1; a++)
    {
        uniform_int_distribution<> dis(0, 9);
        output[a] = num[dis(gen)];
    }
    for (int a = sm + nu + bi - 1; a < nu + sp + bi + sm - 1; a++)
    {
        uniform_int_distribution<> dis(0, 31);
        output[a] = special[dis(gen)];
    }
    cout << "Your Password is: ";
    random_shuffle(output, output + total);
    for (int a = 0; a < total; a++)
    {
        cout << output[a];
    }
}
