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

#include "platforms.h"

Platforms::Platforms(QObject *parent)
    : QObject(parent)
{
    init();
}

void Platforms::add(const QString &title, Platform::Type platform)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    PlatformData plat;
    plat.mTitle = title;
    plat.mType = platform;
    plat.mActMainWindow = nullptr;
    mPlatforms << plat;
}

void Platforms::init()
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    add(tr("Native"), Platform::Type::Native);
    add(tr("Unix 32-bit"), Platform::Type::Unix32);
    add(tr("Unix 64-bit"), Platform::Type::Unix64);
    add(tr("Windows 32-bit ANSI"), Platform::Type::Win32A);
    add(tr("Windows 32-bit Unicode"), Platform::Type::Win32W);
    add(tr("Windows 64-bit"), Platform::Type::Win64);
}

int Platforms::getCount() const
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    return mPlatforms.count();
}

PlatformData& Platforms::get(Platform::Type platform)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    QList<PlatformData>::iterator iter = mPlatforms.begin();
    while (iter != mPlatforms.end()) {
        if (iter->mType == platform) {
            return *iter;
        }
        ++iter;
    }
    return mPlatforms.first();
}
