#include "schemeValidator.h"

int schemeValidator(char scheme[]) {
  int result = -1;
  if (isAlpha(scheme[1])) {
    for(int i = 2; scheme[i] != '\0'; i++) {
      if (isAlpha(scheme[i]) == true) result = 0;
      else if (isDigit(scheme[i]) == true) result = 0;
      else if (isSpecial(scheme[i]) == true) result = 0;
    }
  }
  if ('A' < scheme[0] && scheme[0] < 'Z') {
    result = 1;
  }
  return result;
}

bool isAlpha(char c) {
  return 'a' < c && c < 'z';
}

bool isSpecial(char c) {
  bool result = true;
  if (c == '+') result = false;
  else if (c == '-') result = false;
  return result;
}

bool isDigit(char c) {
  if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){return true;}
  return false;
  //return (0 < c && c < 9);
}


