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

#include "txtreport.h"

#include "erroritem.h"

#include <QDir>
#include <QFile>
#include <QList>
#include <QtGlobal>

TxtReport::TxtReport(const QString &filename) :
    Report(filename)
{}

bool TxtReport::create()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    if (Report::create()) {
        mTxtWriter.setDevice(Report::getFile());
        return true;
    }
    return false;
}

void TxtReport::writeHeader()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // No header for txt report
}

void TxtReport::writeFooter()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    // No footer for txt report
}

void TxtReport::writeError(const ErrorItem &error)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    /*
       Error example from the core program in text
       [gui/test.cpp:23] -> [gui/test.cpp:14]: (error) Mismatching allocation and deallocation: k
     */

    QString line;

    for (int i = 0; i < error.errorPath.size(); i++) {
        const QString file = QDir::toNativeSeparators(error.errorPath[i].file);
        line += QString("[%1:%2]").arg(file).arg(error.errorPath[i].line);
        if (i < error.errorPath.size() - 1) {
            line += " -> ";
        }

        if (i == error.errorPath.size() - 1) {
            line += ": ";
        }
    }
    QString temp = "(%1";
    if (error.inconclusive) {
        temp += ", ";
        temp += tr("inconclusive");
    }
    temp += ") ";
    line += temp.arg(GuiSeverity::toString(error.severity));
    line += error.summary;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    mTxtWriter << line << Qt::endl;
#else
    mTxtWriter << line << endl;
#endif
}
