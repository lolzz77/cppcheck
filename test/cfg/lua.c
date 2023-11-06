#include <stdio.h>
#include <pthread.h>

// Test library configuration for lua.cfg
//
// Usage:
// $ cppcheck --check-library --library=lua --enable=style,information --inconclusive --error-exitcode=1 --disable=missingInclude --inline-suppr test/cfg/lua.c
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#include <lua.h>
#include <stdio.h>

void validCode(lua_State *L)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    int a = lua_gettop(L);
    printf("%d", a);
    lua_pushnil(L);
    lua_pop(L, 1);
}

void ignoredReturnValue(lua_State *L)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // cppcheck-suppress ignoredReturnValue
    lua_tonumber(L, 1);
    // cppcheck-suppress ignoredReturnValue
    lua_tostring(L, 1);
    // cppcheck-suppress ignoredReturnValue
    lua_isboolean(L, 1);
    // cppcheck-suppress ignoredReturnValue
    lua_isnil(L, 1);
}
