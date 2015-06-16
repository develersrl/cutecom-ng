/**
 * \file
 * <!--
 * Copyright 2015 Develer S.r.l. (http://www.develer.com/)
 * -->
 *
 * \brief Serial port connection and settings dialog
 *
 * \author Aurelien Rainone <aurelien@develer.org>
 */

#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectDialog;
}



/**
 * @brief The ConnectDialog class
 */
class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = 0);
    ~ConnectDialog();

    void accept();

private:
    Ui::ConnectDialog *ui;


    /**
     * @brief Represent the default serial port settings
     *
     * Has the following keys :
     *  - "device"
     *  - "baud_rate"
     *  - "data_bits"
     *  - "stop_bits"
     *  - "parity"
     *  - "flow_control"
     * All values are QStrings
     */

    QHash<QString, QString> defaultValues;

private:
    /**
     * fill connection settings combo boxes
     */
    void fillSettingsLists();

    /**
     * preselect serial port connection settings
     */
    void preselectPortSettings(const QHash<QString, QString>& settings);


signals:
    /**
     * signal emitted 'open device' button has been clicked
     */
    void openDeviceClicked(const QHash<QString, QString>& config);
};

#endif // CONNECTDIALOG_H