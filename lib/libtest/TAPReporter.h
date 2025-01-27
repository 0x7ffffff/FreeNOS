/*
 * Copyright (C) 2015 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIBTEST_TAPREPORTER_H
#define __LIBTEST_TAPREPORTER_H

#include "TestReporter.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libtest
 * @{
 */

/**
 * Output TestResults in TAP format to stdout.
 *
 * @see https://testanything.org/tap-specification.html
 */
class TAPReporter : public TestReporter {
public:

    /**
     * Constructor.
     */
    TAPReporter(int argc, char **argv);

    /**
     * Report start of testing.
     */
    virtual void reportBegin(List<TestInstance *> &tests);

    /**
     * Report start of a test.
     */
    virtual void reportBefore(TestInstance &test);

    /**
     * Report finish of a test.
     */
    virtual void reportAfter(TestInstance &test, TestResult &result);

    /**
     * Report completion of all tests.
     */
    virtual void reportFinish(List<TestInstance *> &tests);

private:

    /** Test counter. */
    uint m_count;
};

/**
 * @}
 * @}
 */

#endif /* __LIBTEST_TAPREPORTER_H */
