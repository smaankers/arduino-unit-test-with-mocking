//---

#include <gtest/gtest.h>

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest (&(argc), (argv));

  if (RUN_ALL_TESTS() > 0)
  {
    return 1;
  }

  return 0;
}


