#include "unity.h"
#include "state.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_whenStateIsRed_thenNextStateIsGreen(void)
{
    STATE next;

	next = StateGetNext(STATE_RED);

    TEST_ASSERT_EQUAL(STATE_GREEN, next);
}

void test_whenStateIsGreen_thenNextStateIsBlue(void)
{
    STATE next;

    next = StateGetNext(STATE_GREEN);

    TEST_ASSERT_EQUAL(STATE_BLUE, next);
}

void test_whenStateIsBlue_thenNextStateIsRed(void)
{
    STATE next;

    next = StateGetNext(STATE_BLUE);

    TEST_ASSERT_EQUAL(STATE_RED, next);
}
