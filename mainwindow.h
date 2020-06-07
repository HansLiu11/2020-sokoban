#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void level_1();
    void level_2();
    void Set();
    void keyPressEvent(QKeyEvent *k);
public slots:
    void up();
    void down();
    void left();
    void right();
    void ReButton();
    void ReButton_2();
signals:
    void up_signal();
    void down_signal();
    void left_signal();
    void right_signal();
    void space_signal();

private slots:
    void on_NtButton_clicked();

    void on_backButton_clicked();

    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_StartButton_clicked();

    void on_NtButton_2_clicked();

private:
    int step,point,time,total_pt;
    Ui::MainWindow *ui;
    QPixmap img,pix;
    QLabel *lab_char,*lab,*emerald,*char_girl;
    vector < vector<QLabel*> > map;
    vector <QLabel*> box,ring;
    vector<vector<int> > m;
    bool first,mode;
    unsigned long Gx[3],Gy[3];
    vector<vector<int> > m1 = {{9,9,9,9,9,9,9,9,9},
                              {9,0,0,0,0,1,0,0,9},
                              {9,0,2,2,0,1,1,1,9},
                              {9,0,2,0,0,0,0,3,9},
                              {9,1,0,0,0,0,0,3,9},
                              {9,1,6,0,0,0,0,3,9},
                              {9,1,0,6,0,0,0,0,9},
                              {9,1,0,0,6,1,1,1,9},
                              {9,9,9,9,9,9,9,9,9}};
    vector<vector<int> > m2 = {{9,9,9,9,9,9,9,9,9},
                               {9,0,4,1,3,3,3,1,9},
                               {9,0,1,1,0,1,1,1,9},
                               {9,0,1,0,0,0,1,1,9},
                               {9,0,0,0,2,0,2,0,9},
                               {9,0,0,0,2,0,1,0,9},
                               {9,1,1,0,1,0,0,0,9},
                               {9,5,1,0,1,1,1,1,9},
                               {9,9,9,9,9,6,6,6,9}};

};

#endif // MAINWINDOW_H
