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

#include "filelist.h"

#include "pathmatch.h"

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include <QDir>
#include <Qt>

QStringList FileList::getDefaultFilters()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    QStringList extensions;
    extensions << "*.cpp" << "*.cxx" << "*.cc" << "*.c" << "*.c++" << "*.txx" << "*.tpp" << "*.ipp" << "*.ixx";
    return extensions;
}

bool FileList::filterMatches(const QFileInfo &inf)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    if (inf.isFile()) {
        const QStringList filters = FileList::getDefaultFilters();
        QString ext("*.");
        ext += inf.suffix();
        if (filters.contains(ext, Qt::CaseInsensitive))
            return true;
    }
    return false;
}

void FileList::addFile(const QString &filepath)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    QFileInfo inf(filepath);
    if (filterMatches(inf))
        mFileList << inf;
}

void FileList::addDirectory(const QString &directory, bool recursive)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    QDir dir(directory);
    dir.setSorting(QDir::Name);
    const QStringList filters = FileList::getDefaultFilters();
    const QStringList origNameFilters = dir.nameFilters();
    dir.setNameFilters(filters);
    if (!recursive) {
        dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
        QFileInfoList items = dir.entryInfoList();
        mFileList += items;
    } else {
        dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
        QFileInfoList items = dir.entryInfoList();
        mFileList += items;

        dir.setNameFilters(origNameFilters);
        dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
        for (const QFileInfo& item : dir.entryInfoList()) {
            const QString path = item.canonicalFilePath();
            addDirectory(path, recursive);
        }
    }
}

void FileList::addPathList(const QStringList &paths)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    for (const QString& path : paths) {
        QFileInfo inf(path);
        if (inf.isFile())
            addFile(path);
        else
            addDirectory(path, true);
    }
}

QStringList FileList::getFileList() const
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    if (mExcludedPaths.empty()) {
        QStringList names;
        for (const QFileInfo& item : mFileList) {
            QString name = QDir::fromNativeSeparators(item.filePath());
            names << name;
        }
        return names;
    }
    return applyExcludeList();
}

void FileList::addExcludeList(const QStringList &paths)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    mExcludedPaths = paths;
}

static std::vector<std::string> toStdStringList(const QStringList &stringList)
{
    std::vector<std::string> ret;
    std::transform(stringList.cbegin(), stringList.cend(), std::back_inserter(ret), [](const QString& s) {
        return s.toStdString();
    });
    return ret;
}

QStringList FileList::applyExcludeList() const
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
#ifdef _WIN32
    const PathMatch pathMatch(toStdStringList(mExcludedPaths), true);
#else
    const PathMatch pathMatch(toStdStringList(mExcludedPaths), false);
#endif

    QStringList paths;
    for (const QFileInfo& item : mFileList) {
        if (pathMatch.match(QDir::fromNativeSeparators(item.filePath()).toStdString()))
            continue;
        QString canonical = QDir::fromNativeSeparators(item.canonicalFilePath());
        if (!pathMatch.match(canonical.toStdString()))
            paths << canonical;
    }
    return paths;
}
