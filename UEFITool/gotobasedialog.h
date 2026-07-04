/* gotobasedialog.h

  Copyright (c) 2018, Nikolaj Schlej. All rights reserved.
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

  */

#ifndef GOTOBASEDIALOG_H
#define GOTOBASEDIALOG_H

#include <QObject>
#include <QDialog>
#include "ui_gotobasedialog.h"
class GoToBaseDialog : public QDialog
{
    Q_OBJECT

public:
    GoToBaseDialog(QWidget* parent = NULL):
        QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint),
        ui(new Ui::GoToBaseDialog) {
        ui->setupUi(this);
    }

    ~GoToBaseDialog() {delete ui;}

    Ui::GoToBaseDialog* ui;
};

#endif // GOTOBASEDIALOG_H
