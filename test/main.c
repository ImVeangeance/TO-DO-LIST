#define CTEST_MAIN

#include <ctest.h>
#include "function.h"
#include <stdbool.h>

CTEST(DeleteTest, Check)
{
	delka=0;
	bool result = Delete(database, buffile, delka);
	ASSERT_FALSE(result);
}
