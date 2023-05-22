#include <stdlib.h>
#include <string.h>

#include <lib/quizz_data.h>

#include <ctest.h>

CTEST(replace_with_underline, replace)
{
    char realresult[100] = "simple str";
    *realresult = replace_with_underline(realresult);
    ASSERT_STR("simple_str", realresult);
}

CTEST(replace_with_spaces, replace)
{
    char realresult[100] = "simple_str";
    *realresult = replace_with_spaces(realresult);
    ASSERT_STR("simple str", realresult);
}
