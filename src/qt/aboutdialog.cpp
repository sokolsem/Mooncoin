// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include "clientmodel.h"
#include "clientversion.h"

// Copyright year (2009-this)
// Todo: update this when changing our copyright comments in the source
const int ABOUTDIALOG_COPYRIGHT_YEAR = 2014;

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    // Set current copyright year
    ui->copyrightLabel->setText(tr("Copyright") + QString(" &copy; 2011-2021 ") + tr("The WEA developer") + QString("<br>") + tr("Copyright") + QString(" &copy; ") + tr("2011-2013 The Litecoin developers") + QString("<br>") + tr("Copyright") + QString(" &copy; ") + tr("2013 Team Mooncoin").arg(ABOUTDIALOG_COPYRIGHT_YEAR) + QString("<br>") + tr("February, 2021. Compiled from https://github.com/sokolsem/perspectivecoin") + QString("<br>") + tr("based on https://github.com/mooncoin-project/mooncoin-landann ") + QString("<br>") + tr("by sites"));
}

void AboutDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion());
    }
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    close();
}
