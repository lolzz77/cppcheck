#include <stdio.h>
#include <pthread.h>
/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2023 Cppcheck team.
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


#include "analyzerinfo.h"
#include "fixture.h"

#include <sstream>

class TestAnalyzerInformation : public TestFixture, private AnalyzerInformation {
public:
    TestAnalyzerInformation() : TestFixture("TestAnalyzerInformation") {}

private:

    void run() override {
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
        TEST_CASE(getAnalyzerInfoFile);
    }

    void getAnalyzerInfoFile() const {
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
        constexpr char filesTxt[] = "file1.a4::file1.c\n";
        std::istringstream f1(filesTxt);
        ASSERT_EQUALS("file1.a4", getAnalyzerInfoFileFromFilesTxt(f1, "file1.c", ""));
        std::istringstream f2(filesTxt);
        ASSERT_EQUALS("file1.a4", getAnalyzerInfoFileFromFilesTxt(f2, "./file1.c", ""));
        ASSERT_EQUALS("builddir/file1.c.analyzerinfo", AnalyzerInformation::getAnalyzerInfoFile("builddir", "file1.c", ""));
        ASSERT_EQUALS("builddir/file1.c.analyzerinfo", AnalyzerInformation::getAnalyzerInfoFile("builddir", "some/path/file1.c", ""));
    }
};

REGISTER_TEST(TestAnalyzerInformation)
