// hack_nao.cc
// What's the output of the following program ?
// Try to determine the output by hand
// and then run the programm to see if you are correct

#include <iostream>

void Unknown(int *p, int num);
void HardToFollow(int *p, int q, int *num);

void Unknown(int *p, int num) {
  int *q;

  q = &num;
  *p = *q + 2;
  num = 7;
}

void HardToFollow(int *p, int q, int *num) {
  *p = q + *num;
  *num = q;
  num = p;
  p = &q;
  Unknown(num, *p);
}

int main() {
  int *q;
  int trouble[3];

  trouble[0] = 1;
  q = &trouble[1];
  *q = 2;
  trouble[2] = 3;

  HardToFollow(q, trouble[0], &trouble[2]);
  Unknown(&trouble[0], *q);

  std::cout << *q << " " << trouble[0] << " " << trouble[2];
}
