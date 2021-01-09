#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setIdxCurUser(const qint32 &index);
    qint32 &getIdxCurUser() const;

private:
    Ui::MainWindow *ui;
    qint32 idxCurUser = -1;
};

#endif // MAINWINDOW_H
