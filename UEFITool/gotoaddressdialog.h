/* gotoaddressdialog.h

  Copyright (c) 2018, Nikolaj Schlej. All rights reserved.
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

  */

#ifndef GOTOADDRESSDIALOG_H
#define GOTOADDRESSDIALOG_H

#include <QObject>
#include <QDialog>
#include "ui_gotoaddressdialog.h"
class GoToAddressDialog : public QDialog
{
    Q_OBJECT

public:
    GoToAddressDialog(QWidget* parent = NULL) :
        QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint),
        ui(new Ui::GoToAddressDialog) {
        ui->setupUi(this);
    }

    ~GoToAddressDialog() { delete ui; }

    Ui::GoToAddressDialog* ui;
};

#endif // GOTOADDRESSDIALOG_H
