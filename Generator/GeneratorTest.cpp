#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "Generator.h"

TEST(GeneratorTest, NumberOfElements){

  std::stringstream buffer;

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(1, 6);
  Generator::generate(buffer, 5);

  // Just to view the data during debugging
  std::string sData; 
  std::getline(buffer, sData);


  // Output vektor
  std::vector<std::string> vNumbers;
  std::string s_no;
  while(std::getline(buffer, s_no, ' ')) {
    vNumbers.push_back(s_no);
  }

  EXPECT_EQ(vNumbers.size(), 1);
}