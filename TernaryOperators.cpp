#include <iostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

int main() {
  // If clauses
  if (s_Level > 5)
    s_Speed = 10;
  else
    s_Speed = 5;

  // The same with a TernaryOperator
  s_Speed = s_Level > 5 ? 10 : 5;

  // if clause is slower than ternaryOperator
  std::string otherRank;
  if (s_Speed > 10)
    otherRank = "Master";  // this creates an a temparry string and copy that
                           // into otherRank variable
  else
    otherRank = "Beginner";  // this creates an a temparry string and copy that
                             // into otherRank variable

  std::string rank =
      s_Level > 10 ? "Master" : "Beginner";  // This doesn't create intermediate
                                             // string (optimization)

  std::cin.get();
}