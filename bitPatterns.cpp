// Mark Abramov
// A C++ program that interprets 10-bit patterns as unsigned maginited, signed magnitude, One's Complement, and Two's Complement.


#include <iostream>
#include <string>
using namespace std;

// Determines whether a binary pattern is positive or negative
string findSign(string num) {
  return (num[0] == '0') ? "+" : "-";
}

// Finds the unsigned decimal value of the bit pattern (no + or - symbol)
string unsignedDecimal(string binary) {
  int decimal = 0, base = 1, temp = stoi(binary);
  while (temp) {
    int lastDigit = temp % 10;
    temp /= 10;
    decimal += (lastDigit * base);
    base *= 2;
  }
  return to_string(decimal);
}

// Finds the signed magnitude decimal value of the bit pattern (with a + or - symbol)
string signedDecimal(string binary) {
  return findSign(binary) + unsignedDecimal(binary.substr(1));
}

// Finds the One's Complement decimal value of the bit pattern (with a + or - symbol)
string onesComplement(string binary){
  string sign = findSign(binary);
  if (sign == "+") return signedDecimal(binary);
  string ones = "";
  for (int i = 0; i < 10; i++){
    ones += (binary[i] == '0') ? '1': '0';
  }
  return sign + unsignedDecimal(ones.substr(1));
}

// Finds the Two's Complement decimal value of the bit pattern (with a + or - symbol)
string twosComplement(string binary){
  string sign = findSign(binary);
  if (sign == "+") return signedDecimal(binary);
  string twos = onesComplement(binary);
  int value = stoi(twos.substr(1)) + 1;
  return sign + to_string(value);
}

// Driver program that takes in 10-bit pattern as input
int main(){
  cout << "Binary: ";
  string input;
  cin >> input;
  cout << "Unsigned Decimal: " << unsignedDecimal(input) << endl;
  cout << "Signed Decimal: " << signedDecimal(input) << endl;
  cout << "One's Complement: " << onesComplement(input) <<endl;
  cout << "Two's Complement: " << twosComplement(input) << endl;

  return 0;
}
