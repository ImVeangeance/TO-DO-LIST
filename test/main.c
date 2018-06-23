#define CTEST_MAIN

#include <ctest.h>
#include "function.h"
#include <stdbool.h>

FILE *database; 
FILE *buffile;


CTEST(Del,ForOneNoteDatabase)
{
	int a=1;
	Delete(a);
	if (buffile==NULL)
	{
		ASSERT_TRUE(1);
	}
}

CTEST(Del,ForOneNoteBuffile)
{
	int a=1;
	Delete(a);
	if (database==NULL)
	{
		ASSERT_TRUE(1);
	}
}
//
CTEST(Del,ForOneNoteDatabaseBad)
{
	bool b=1;
	int a=1;
	Delete(a);
	if (database==NULL)
	{
		ASSERT_FALSE(b);
	}
	else
		ASSERT_TRUE(b);
}

CTEST(Del,ForOneNoteBuffileBad)
{
	bool b=1;
	int a=1;
	Delete(a);
	if (buffile==NULL)
	{
		ASSERT_FALSE(b);
	}
	else
		ASSERT_TRUE(b);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
