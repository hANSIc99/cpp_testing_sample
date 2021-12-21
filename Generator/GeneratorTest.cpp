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
  int nCalcNoElements = 0;
  std::stringstream buffer;

  Generator::generate(buffer, NumberOfElements);

  std::string s_no;

  while(std::getline(buffer, s_no, ' ')) {
    nCalcNoElements++;
  }

  EXPECT_EQ(nCalcNoElements, NumberOfElements);
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
  
  std::vector<int> vNumbersRef(NumberOfElements); // Input vector
  std::iota(vNumbersRef.begin(), vNumbersRef.end(), 1); // Populate vector
  
  // Calculate reference checksum
  for(const int n : vNumbersRef){
    nChecksum_in += n;
  }

  std::stringstream buffer;

  Generator::generate(buffer, NumberOfElements);


  std::vector<int> vNumbersGen; // Output vector
  std::string s_no;

  // Read the buffer back to the output vector
  while(std::getline(buffer, s_no, ' ')) {
    vNumbersGen.push_back(std::stoi(s_no));
  }

  // Calculate output checksum
    for(const int n : vNumbersGen){
    nChecksum_out += n;
  }

  EXPECT_EQ(nChecksum_in, nChecksum_out);
}