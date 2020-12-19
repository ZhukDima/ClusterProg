#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

    void setStartDir(const QString &dir);

    void setActualChoosenFiles(const QStringList &files);

private slots:
    void on_SettingsDialog_rejected();

    void on_chooseFilesButton_clicked();

    void on_saveSettingsButton_clicked();

signals:
    void sendChoosenFiles(const QStringList &files);

private:
    Ui::SettingsDialog *ui;
    QString startDir;
    QStringList choosenFiles;
};

#endif // SETTINGSDIALOG_H
