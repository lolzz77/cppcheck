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

#include "fileviewdialog.h"

#include <QByteArray>
#include <QDialogButtonBox>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QTextEdit>

#include "ui_fileview.h"

FileViewDialog::FileViewDialog(const QString &file,
                               const QString &title,
                               QWidget *parent)
    : QDialog(parent)
    , mUI(new Ui::Fileview)
{
    mUI->setupUi(this);


    setWindowTitle(title);
    connect(mUI->mButtons, SIGNAL(accepted()), this, SLOT(accept()));
    loadTextFile(file, mUI->mText);
}

FileViewDialog::~FileViewDialog()
{
    delete mUI;
}

void FileViewDialog::loadTextFile(const QString &filename, QTextEdit *edit)
{
	printf("MEE %s\r\n", __FILE__);
	printf(" \x1b[33m \t %s:%d \x1b[0m \r\n", __FUNCTION__, __LINE__);
	printf("\t Thread ID: %lu\r\n\n", pthread_self());
    QFile file(filename);
    if (!file.exists()) {
        QString msg(tr("Could not find the file: %1"));
        msg = msg.arg(filename);

        QMessageBox msgbox(QMessageBox::Critical,
                           tr("Cppcheck"),
                           msg,
                           QMessageBox::Ok,
                           this);
        msgbox.exec();
        return;
    }

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.isReadable()) {
        QString msg(tr("Could not read the file: %1"));
        msg = msg.arg(filename);

        QMessageBox msgbox(QMessageBox::Critical,
                           tr("Cppcheck"),
                           msg,
                           QMessageBox::Ok,
                           this);
        msgbox.exec();
        return;
    }
    QByteArray filedata = file.readAll();
    file.close();

    edit->setPlainText(filedata);
}
