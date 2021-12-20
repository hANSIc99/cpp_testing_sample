#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include <numeric>

#include "Generator.h"


TEST(GeneratorTest, ReferenceCheck){

  const int NumberOfElements = 10;
  std::stringstream buffer;
  

  EXPECT_EQ(
    std::addressof(buffer),
    std::addressof(Generator::generate(buffer, NumberOfElements))
    );
}

TEST(GeneratorTest, NumberOfElements){

  const int NumberOfElements = 50;
  std::stringstream buffer;

  Generator::generate(buffer, NumberOfElements);
  // Output vektor
  std::vector<std::string> vNumbers;
  std::string s_no;
  while(std::getline(buffer, s_no, ' ')) {
    vNumbers.push_back(s_no);
  }

  EXPECT_EQ(vNumbers.size(), NumberOfElements);
}

TEST(GeneratorTest, Shuffle){

  const int NumberOfElements = 50;

  std::stringstream buffer_A;
  std::stringstream buffer_B;

  Generator::generate(buffer_A, NumberOfElements);
  Generator::generate(buffer_B, NumberOfElements);

  EXPECT_NE(buffer_A.str(), buffer_B.str());
}


TEST(GeneratorTest, CheckSum){

  const int NumberOfElements = 50;
  int nChecksum_in = 0;
  int nChecksum_out = 0;
  // Input vector
  std::vector<int> vNumbersRef(NumberOfElements);
  std::iota(vNumbersRef.begin(), vNumbersRef.end(), 1);
  
  // Calculate reference checksum
  for(const int n : vNumbersRef){
    nChecksum_in += n;
  }

  std::stringstream buffer;

  Generator::generate(buffer, NumberOfElements);

  // Output vektor
  std::vector<int> vNumbersGen;
  std::string s_no;
  while(std::getline(buffer, s_no, ' ')) {
    vNumbersGen.push_back(std::stoi(s_no));
  }

  // Calculate output checksum
    for(const int n : vNumbersGen){
    nChecksum_out += n;
  }

  EXPECT_EQ(nChecksum_in, nChecksum_out);
}