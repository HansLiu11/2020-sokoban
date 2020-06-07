#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMovie>
#include <QStackedWidget>
#include <QLabel>
#include <QDebug>
#include <QtGlobal>
#include <stdlib.h>
#include <QTime>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(1000,550);
    this->setMinimumSize(1000,550);
    Set();
    ui->stackedWidget->setCurrentIndex(3);
    connect(this,SIGNAL(up_signal()),this,SLOT(up()));
    connect(this,SIGNAL(down_signal()),this,SLOT(down()));
    connect(this,SIGNAL(left_signal()),this,SLOT(left()));
    connect(this,SIGNAL(right_signal()),this,SLOT(right()));
    connect(ui->ReButton,SIGNAL(clicked(bool)),this,SLOT(ReButton()));
    connect(ui->RtButton2,SIGNAL(clicked(bool)),this,SLOT(ReButton_2()));
    connect(ui->NtButton,SIGNAL(clicked()),this,SLOT(on_NtButton_clicked()));
    connect(ui->quitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(ui->quitButton_2,SIGNAL(clicked()),qApp,SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::level_1()
{
    unsigned long c,r,k=0;
    int a=0,b=0;
    ui->LVlabel->setText("Level1");
    first =false;
    m=m1;
    for(int i=0;i<9;++i){
        c = static_cast<unsigned long> (i);
        for(int j=0;j<9;++j){
            QMovie *mov = new QMovie;
            r = static_cast<unsigned long> (j);
            map[c][r]->setGeometry(j*50,i*50,50,50);
            switch(m[c][r]){
                case 0:case 2:
                    map[c][r]->setStyleSheet("background-color:rgb(14, 168, 29)");
                break;
                case 1:
                    img.load(":/img/wall2.png");
                    map[c][r]->setPixmap(img);
                    map[c][r]->setScaledContents(true);
                break;
                case 3:
                    img.load(":/img/finish.png");
                    map[c][r]->setPixmap(img);
                    map[c][r]->setScaledContents(true);
                    map[c][r]->setStyleSheet("background-color:rgb(14, 168, 29)");
                    Gx[a]= c;Gy[b]= r;
                    a++;b++;
                break;
                case 6:
                    mov->setFileName(":/img/ring.gif");
                    map[c][r]->setMovie(mov);
                    map[c][r]->setScaledContents(true);
                    mov->start();
                    map[c][r]->setStyleSheet("background-color:rgb(14, 168, 29)");
                break;
                case 9:
                    img.load(":/img/牆壁2.png");
                    map[c][r]->setPixmap(img);
                    map[c][r]->setScaledContents(true);
                break;
            }
            if(m[c][r]==2){  
                box[k]->setGeometry(j*50,i*50,50,50);
                img.load(":/img/箱子2.png");
                box[k]->setPixmap(img);
                box[k]->setScaledContents(true);
                k++;

            }
        }
    }
    lab_char->setGeometry(50,50,50,50);
    QPixmap pix(":/img/Sonic.png");
    lab_char->setPixmap(pix);
    lab_char->setScaledContents(true);

}

void MainWindow::level_2()
{
    unsigned long c,r,k=0;
    int a=0,b=0;
    m=m2;
    ui->LVlabel->setText("Level2");
    mode = false;
    for(int i=0;i<9;++i){
        c = static_cast<unsigned long> (i);
        for(int j=0;j<9;++j){
            QMovie *mov = new QMovie;
            r = static_cast<unsigned long> (j);
            map[c][r]->setGeometry(j*50,i*50,50,50);
            switch(m[c][r]){
                case 0:case 2:
                    map[c][r]->setStyleSheet("background-color:rgb(14, 168, 29)");
                break;
                case 1:
                    img.load(":/img/wall2.png");
                    map[c][r]->setPixmap(img);
                    map[c][r]->setScaledContents(true);
                break;
                case 3:
                    img.load(":/img/finish.png");
                    map[c][r]->setPixmap(img);
                    map[c][r]->setScaledContents(true);
                    map[c][r]->setStyleSheet("background-color:rgb(14, 168, 29)");
                    Gx[a]= c;Gy[b]= r;
                    a++;b++;
                break;
                case 4:
                    map[c][r]->setStyleSheet("background-color:rgb(14, 168, 29)");
                    emerald->setGeometry(j*50,i*50+15,50,25);
                    img.load(":/img/Emerald1.png");
                    emerald->setPixmap(img);
                    emerald->setScaledContents(true);
                break;
                case 5:
                    map[c][r]->setStyleSheet("background-color:rgb(14, 168, 29)");
                    char_girl->setGeometry(j*50,i*50,50,50);
                break;
                case 6:
                    mov->setFileName(":/img/ring.gif");
                    map[c][r]->setMovie(mov);
                    map[c][r]->setScaledContents(true);
                    mov->start();
                    map[c][r]->setStyleSheet("background-color:rgb(14, 168, 29)");
                break;
                case 9:
                    img.load(":/img/牆壁2.png");
                    map[c][r]->setPixmap(img);
                    map[c][r]->setScaledContents(true);
                break;
            }
            if(m[c][r]==2){
                box[k]->setGeometry(j*50,i*50,50,50);
                img.load(":/img/箱子2.png");
                box[k]->setPixmap(img);
                box[k]->setScaledContents(true);
                k++;

            }
        }
    }
    lab_char->setGeometry(350,300,50,50);
    QPixmap pix(":/img/Sonic.png");
    lab_char->setPixmap(pix);
    lab_char->setScaledContents(true);
}

void MainWindow::Set()
{
    unsigned long c,r;

    step = 0;time = 0; total_pt = 0;
    point = 0;
    ui->count->setText("STEP "+QString::number(step));
    ui->Pointlb->setText("Ring "+QString::number(point));
    ui->count->setAlignment(Qt::AlignCenter);
    ui->Pointlb->setAlignment(Qt::AlignCenter);
    ui->LVlabel->setAlignment(Qt::AlignCenter);
    ui->LVlabel->setFrameStyle(QFrame::Box);
    QMovie *mov = new QMovie(":/img/Sonicgf.gif");
    ui->sonic_run->setMovie(mov);
    ui->sonic_run->setScaledContents(true);
    mov->start();
    map.resize(9);
    for(int j=0;j<9;++j){
      r = static_cast<unsigned long> (j);
      map[r].resize(9);
    }
    for(int i=0;i<9;++i){
        c = static_cast<unsigned long> (i);
        for(int j=0;j<9;++j){
            r = static_cast<unsigned long> (j);
            lab = new QLabel(ui->page);
            map[c][r]= lab;
        }
     }
    for (int i=0;i<3;++i) {
        QLabel *lab1=new QLabel(ui->page);
        box.push_back(lab1);
    }
    lab_char = new QLabel(ui->page);
    emerald = new QLabel(ui->page);
    char_girl = new QLabel(ui->page);
    first =false;
    mode = false;
    ui->NtButton->setVisible(false);
    ui->RtButton2->setVisible(false);
    ui->win->setVisible(false);
}

void MainWindow::keyPressEvent(QKeyEvent *k){
    unsigned long x=static_cast<unsigned long>(lab_char->x());
    unsigned long y=static_cast<unsigned long>(lab_char->y());
    if(k->key()== Qt::Key_W){
        if(m[(y/50)-1][x/50]== 1){
            if(mode){
                m[(y/50)-1][x/50] = 0;
                map[(y/50)-1][x/50]->clear();
                map[(y/50)-1][x/50]->setStyleSheet("background-color:rgb(14, 168, 29)");
                time++;
                if(time==5) {
                    mode = false;
                    pix.load(":/img/Sonic2.png");
                    lab_char->setPixmap(pix);
                    lab_char->setScaledContents(true);
                }
            }
        }
        else if (m[(y/50)-1][x/50]== 9) {}
        else if (m[(y/50)-1][x/50]== 2) {
              if(m[(y/50)-2][x/50]== 2){}
              else if (m[(y/50)-2][x/50]== 1 || m[(y/50)-2][x/50]==9) {}
              else {
                  step++;
                  if(ui->stackedWidget->currentIndex()==0)
                      ui->count->setText("STEP "+QString::number(step));
                   emit up_signal();
              }
        }
        else {
            step++;
            if(ui->stackedWidget->currentIndex()==0)
                ui->count->setText("STEP "+QString::number(step));
            emit up_signal();

        }
    }
    if(k->key()== Qt::Key_S){
        if(m[(y/50)+1][x/50]== 1){
            if(mode){
                m[(y/50)+1][x/50] = 0;
                map[(y/50)+1][x/50]->clear();
                map[(y/50)+1][x/50]->setStyleSheet("background-color:rgb(14, 168, 29)");
                time++;
                if(time==5) {
                    mode = false;
                    pix.load(":/img/Sonic.png");
                    lab_char->setPixmap(pix);
                    lab_char->setScaledContents(true);
                }
            }
        }
        else if (m[(y/50)+1][x/50]== 9) {}
        else if (m[(y/50)+1][x/50]== 2) {
             if(m[(y/50)+2][x/50]== 2){}
             else if (m[(y/50)+2][x/50]== 1||m[(y/50)+2][x/50]==9) {}
             else {
                 step++;
                 if(ui->stackedWidget->currentIndex()==0)
                     ui->count->setText("STEP "+QString::number(step));
                 emit down_signal();
             }
       }
       else {
           step++;
           if(ui->stackedWidget->currentIndex()==0)
                ui->count->setText("STEP "+QString::number(step));
           emit down_signal();
      }
    }
    if(k->key()== Qt::Key_A){
        if(mode){
            QMovie *mov = new QMovie(":/img/supersonic flyL.gif");
            lab_char->setMovie(mov);
            lab_char->setScaledContents(true);
            mov->start();  
        }
        else{
           pix.load(":/img/Sonic2.png");
           lab_char->setPixmap(pix);
           lab_char->setScaledContents(true);
        }
        if(m[y/50][(x/50)-1]== 1){
            if(mode){
                m[y/50][(x/50)-1] = 0;
                map[y/50][(x/50)-1]->clear();
                map[y/50][(x/50)-1]->setStyleSheet("background-color:rgb(14, 168, 29)");
                time++;
                if(time==5) {
                    mode = false;
                    pix.load(":/img/Sonic2.png");
                    lab_char->setPixmap(pix);
                    lab_char->setScaledContents(true);
                }
            }
        }
        else if (m[y/50][(x/50)-1]== 9) {}
          else if (m[y/50][(x/50)-1]== 2) {
                if(m[y/50][(x/50)-2]== 2){}
                else if (m[y/50][(x/50)-2]== 1||m[y/50][(x/50)-2]== 9) {}
                else {
                    step++;
                    if(ui->stackedWidget->currentIndex()==0)
                        ui->count->setText("STEP "+QString::number(step));
                    emit left_signal();
                }
          }
          else {
            step++;
            if(ui->stackedWidget->currentIndex()==0)
                ui->count->setText("STEP "+QString::number(step));
            emit left_signal();
          }
    }
    if(k->key()==Qt::Key_D){
        if(mode){
            QMovie *mov = new QMovie(":/img/Supersonic flyR.gif");
            lab_char->setMovie(mov);
            lab_char->setScaledContents(true);
            mov->start();
        }
        else{
           pix.load(":/img/Sonic.png");
            lab_char->setPixmap(pix);
            lab_char->setScaledContents(true);
        }
        if(m[y/50][(x/50)+1]== 1){
            if(mode){
                m[y/50][(x/50)+1] = 0;
                map[y/50][(x/50)+1]->clear();
                map[y/50][(x/50)+1]->setStyleSheet("background-color:rgb(14, 168, 29)");
                time++;
                if(time==5) {
                    mode = false;
                    pix.load(":/img/Sonic.png");
                    lab_char->setPixmap(pix);
                    lab_char->setScaledContents(true);
                }
            }
        }
        else if (m[y/50][(x/50)+1]== 9) {}
        else if (m[y/50][(x/50)+1]== 2) {
             if(m[y/50][(x/50)+2]== 2){}
             else if (m[y/50][(x/50)+2]== 1 ||m[y/50][(x/50)+2]== 9) {}
             else {
                 step++;
                 if(ui->stackedWidget->currentIndex()==0)
                        ui->count->setText("STEP "+QString::number(step));
                 emit right_signal();

             }
        }
        else {
            step++;
            if(ui->stackedWidget->currentIndex()==0)
                   ui->count->setText("STEP "+QString::number(step));
             emit right_signal();  
        }
    }
}

void MainWindow::up()
{
    int t;
    unsigned long c;
    unsigned long x=static_cast<unsigned long>(lab_char->x());
    unsigned long y=static_cast<unsigned long>(lab_char->y());
    if(m[(y/50)-1][x/50]== 2){
       for (int i=0;i<3;i++) {
           c = static_cast<unsigned long> (i);
           if(box[c]->x()==lab_char->x() && box[c]->y()==lab_char->y()-50)
           {
                box[c]->setGeometry(box[c]->x(),box[c]->y()-50,50,50);
                box[c]->raise();
           }
       }
       if (m[(y/50)-2][x/50]== 6) {
           map[(y/50)-2][x/50]->clear();
           map[(y/50)-2][x/50]->setStyleSheet("background-color:rgb(14, 168, 29)");
           point+=10;
           ui->Pointlb->setText("Points "+QString::number(point));
           m[(y/50)-2][x/50]= 0;
       }
       t=m[(y/50)-1][x/50];
       m[(y/50)-1][x/50]=m[(y/50)-2][x/50];
       m[(y/50)-2][x/50]=t;

    }
    else if (m[(y/50)-1][x/50]== 4) {
        mode =true;
        emerald->clear();
        QMovie *mov = new QMovie(":/img/Supersonic2.gif");
        lab_char->setMovie(mov);
        lab_char->setScaledContents(true);
        mov->start();
        img.load(":/img/Amy.png");
        char_girl->setPixmap(img);
        char_girl->setScaledContents(true);
        m[(y/50)-1][x/50]= 0;
    }
    else if (m[(y/50)-1][x/50]== 6) {
        map[(y/50)-1][x/50]->clear();
        map[(y/50)-1][x/50]->setStyleSheet("background-color:rgb(14, 168, 29)");
        point+=1;
        ui->Pointlb->setText("Ring "+QString::number(point));
        m[(y/50)-1][x/50]= 0;
    }
    if((m[Gx[0]][Gy[0]]==2 && m[Gx[1]][Gy[1]]==2 && m[Gx[2]][Gy[2]]==2) || m[(y/50)-1][x/50]==5)
    {
        if(m[(y/50)-1][x/50]==5){
            char_girl->clear();
            pix.load(":/img/SA.png");
            lab_char->setPixmap(pix);
            lab_char->setScaledContents(true);
        }
        total_pt = point*10 +(100-step)*10;
        point = 0;
        ui->win->setText("Step: "+QString::number(step)+"\n"+"Point: "+QString::number(total_pt));
        ui->win->setVisible(true);
        ui->win->raise();

        if(!first)
        {

            ui->NtButton->setVisible(true);
            first=true;
        }
    }
    lab_char->setGeometry(lab_char->x(),lab_char->y()-50,50,50);
}

void MainWindow::down()
{
    int t;
    unsigned long c;
    unsigned long x=static_cast<unsigned long>(lab_char->x());
    unsigned long y=static_cast<unsigned long>(lab_char->y());
    if(m[(y/50)+1][x/50]== 2){
       for (int i=0;i<3;i++) {
           c = static_cast<unsigned long> (i);
           if(box[c]->x()==lab_char->x() && box[c]->y()==(lab_char->y()+50))
           {
                box[c]->setGeometry(box[c]->x(),box[c]->y()+50,50,50);
                box[c]->raise();
           }
       }
       if (m[(y/50)+2][x/50]== 6) {
          map[(y/50)+2][x/50]->clear();
          map[(y/50)+2][x/50]->setStyleSheet("background-color:rgb(14, 168, 29)");
          point+=1;
          ui->Pointlb->setText("Ring "+QString::number(point));
          m[(y/50)+2][x/50]= 0;
        }
        t=m[(y/50)+1][x/50];
        m[(y/50)+1][x/50]=m[(y/50)+2][x/50];
        m[(y/50)+2][x/50]=t;

    }
    else if (m[(y/50)+1][x/50]== 4) {
        mode =true;
        emerald->clear();
        QMovie *mov = new QMovie(":/img/Supersonic2.gif");
        lab_char->setMovie(mov);
        lab_char->setScaledContents(true);
        mov->start();
        img.load(":/img/Amy.png");
        char_girl->setPixmap(img);
        char_girl->setScaledContents(true);
        m[(y/50)+1][x/50]=0;
    }
    else if (m[(y/50)+1][x/50]== 6) {
        map[(y/50)+1][x/50]->clear();
        map[(y/50)+1][x/50]->setStyleSheet("background-color:rgb(14, 168, 29)");
        point+=1;
        ui->Pointlb->setText("Ring "+QString::number(point));
        m[(y/50)+1][x/50]= 0;
    }
    if((m[Gx[0]][Gy[0]]==2 && m[Gx[1]][Gy[1]]==2 && m[Gx[2]][Gy[2]]==2) || m[(y/50)+1][x/50]==5)
    {
        if(m[(y/50)+1][x/50]==5){
            char_girl->clear();
            pix.load(":/img/SA.png");
            lab_char->setPixmap(pix);
            lab_char->setScaledContents(true);
        }
        total_pt = point*10 +(100-step)*10;
        point = 0;
        ui->win->setText("Step: "+QString::number(step)+"\n"+"Point: "+QString::number(total_pt));
        ui->win->raise();
        ui->win->setVisible(true);
        if(!first)
        {
            ui->NtButton->setVisible(true);
            first=true;
        }
    }
    lab_char->setGeometry(lab_char->x(),lab_char->y()+50,50,50);
}

void MainWindow::left()
{
    int t;
    unsigned long c;
    unsigned long x=static_cast<unsigned long>(lab_char->x());
    unsigned long y=static_cast<unsigned long>(lab_char->y());
    if(m[y/50][(x/50)-1]== 2){
        for (int i=0;i<3;i++) {
            c = static_cast<unsigned long> (i);
            if(box[c]->x()==lab_char->x()-50 && box[c]->y()==lab_char->y())
            {
                 box[c]->setGeometry(box[c]->x()-50,box[c]->y(),50,50);
                 box[c]->raise();
            }
        }
        if (m[y/50][(x/50)-2]== 6) {
            map[y/50][(x/50)-2]->clear();
            map[y/50][(x/50)-2]->setStyleSheet("background-color:rgb(14, 168, 29)");
            point+=1;
            ui->Pointlb->setText("Ring "+QString::number(point));
            m[y/50][(x/50)-2]= 0;
        }
        t=m[y/50][(x/50)-1];
        m[y/50][(x/50)-1]=m[y/50][(x/50)-2];
        m[y/50][(x/50)-2]=t;
    }
    else if (m[y/50][(x/50)-1]== 4) {
        mode =true;
        emerald->clear();
        QMovie *mov = new QMovie(":/img/Supersonic2.gif");
        lab_char->setMovie(mov);
        lab_char->setScaledContents(true);
        mov->start();
        img.load(":/img/Amy.png");
        char_girl->setPixmap(img);
        char_girl->setScaledContents(true);
        m[y/50][(x/50)-1]= 0;
    }
    else if (m[y/50][(x/50)-1]== 6) {
        map[y/50][(x/50)-1]->clear();
        map[y/50][(x/50)-1]->setStyleSheet("background-color:rgb(14, 168, 29)");
        point+=1;
        ui->Pointlb->setText("Ring "+QString::number(point));
        m[y/50][(x/50)-1]= 0;
    }
    if((m[Gx[0]][Gy[0]]==2 && m[Gx[1]][Gy[1]]==2 && m[Gx[2]][Gy[2]]==2) || m[y/50][(x/50)-1]==5)
    {
        if(m[y/50][(x/50)-1]==5){
            char_girl->clear();
            pix.load(":/img/SA.png");
            lab_char->setPixmap(pix);
            lab_char->setScaledContents(true);
        }
        total_pt = point*10 +(100-step)*10;
        point = 0;
        ui->win->setText("Step: "+QString::number(step)+"\n"+"Point: "+QString::number(total_pt));
        ui->win->raise();
        ui->win->setVisible(true);
        if(!first)
        {
            ui->NtButton->setVisible(true);
            first=true;
        }

    }   
    lab_char->setGeometry(lab_char->x()-50,lab_char->y(),50,50);
}

void MainWindow::right()
{
    int t;
    unsigned long c;
    unsigned long x=static_cast<unsigned long>(lab_char->x());
    unsigned long y=static_cast<unsigned long>(lab_char->y());

    if(m[y/50][(x/50)+1]== 2){
        for (int i=0;i<3;i++) {
            c = static_cast<unsigned long> (i);
            if(box[c]->x()==lab_char->x()+50 && box[c]->y()==lab_char->y())
            {
                 box[c]->setGeometry(box[c]->x()+50,box[c]->y(),50,50);
                 box[c]->raise();
            }
        }
        if (m[y/50][(x/50)+2]== 6) {
            map[y/50][(x/50)+2]->clear();
            map[y/50][(x/50)+2]->setStyleSheet("background-color:rgb(14, 168, 29)");
            point+=1;
            ui->Pointlb->setText("Ring "+QString::number(point));
            m[y/50][(x/50)+2]= 0;
        }
        t=m[y/50][(x/50)+1];
        m[y/50][(x/50)+1]=m[y/50][(x/50)+2];
        m[y/50][(x/50)+2]=t;
    }
    else if (m[y/50][(x/50)+1]== 4) {
        mode =true;
        emerald->clear();
        QMovie *mov = new QMovie(":/img/Supersonic2.gif"); 
        lab_char->setMovie(mov);
        lab_char->setScaledContents(true);
        mov->start();
        img.load(":/img/Amy.png");
        char_girl->setPixmap(img);
        char_girl->setScaledContents(true);
        m[y/50][(x/50)+1]= 0;
    }
    else if (m[y/50][(x/50)+1]== 6) {
        map[y/50][(x/50)+1]->clear();
        map[y/50][(x/50)+1]->setStyleSheet("background-color:rgb(14, 168, 29)");
        point+=1;
        ui->Pointlb->setText("Ring "+QString::number(point));
        m[y/50][(x/50)+1]= 0;
    }
    if((m[Gx[0]][Gy[0]]==2 && m[Gx[1]][Gy[1]]==2 && m[Gx[2]][Gy[2]]==2) || m[y/50][(x/50)+1]==5)
    {   
        if(m[y/50][(x/50)+1]==5){
            char_girl->clear();
            pix.load(":/img/SA.png");
            lab_char->setPixmap(pix);
            lab_char->setScaledContents(true);
        }
        total_pt = point*10 +(100-step)*10;
        point = 0;
        ui->win->setText("Step: "+QString::number(step)+"\n"+"Point: "+QString::number(total_pt));
        ui->win->raise();
        ui->win->setVisible(true);
        if(!first)
        {

            ui->NtButton->setVisible(true);
            first=true;
        }
    }
    lab_char->setGeometry(lab_char->x()+50,lab_char->y(),50,50);
}

void MainWindow::ReButton()
{
    unsigned long c,r;
    step = 0;total_pt=0;point=0;
    ui->count->setText("STEP "+QString::number(step));
    ui->Pointlb->setText("Ring "+QString::number(total_pt));
    lab_char->clear();
    for (int i=0;i<3;++i) {
        c = static_cast<unsigned long> (i);
        box[c]->clear();
    }
    for (int i=0;i<9;++i) {
        c = static_cast<unsigned long> (i);
        for (int j=0;j<9;++j) {
            r = static_cast<unsigned long> (j);
            map[c][r]->clear();
        }
    }
    level_1();
}

void MainWindow::on_NtButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    unsigned long c,r;
    step = 0;total_pt = 0;
    ui->count->setText("STEP "+QString::number(step));
    ui->Pointlb->setText("Ring "+QString::number(total_pt));
    for (int i=0;i<9;++i) {
        c = static_cast<unsigned long> (i);
        for (int j=0;j<9;++j) {
            r = static_cast<unsigned long> (j);
            map[c][r]->clear();
        }
    }
    lab_char->clear();
    for (int i=0;i<3;++i) {
        c = static_cast<unsigned long> (i);
        box[c]->clear();
    }
    level_2();
    ui->ReButton->setVisible(false);
    ui->NtButton->setVisible(false);
    ui->RtButton2->setVisible(true);
    ui->win->setVisible(false);
    first=true;
}


void MainWindow::ReButton_2()
{
    unsigned long c,r;
    time = 0;point=0;
    step = 0;total_pt = 0;
    ui->count->setText("STEP "+QString::number(step));
    ui->Pointlb->setText("Ring "+QString::number(total_pt));
    lab_char->clear();
    emerald->clear();
    char_girl->clear();
    for (int i=0;i<9;++i) {
        c = static_cast<unsigned long> (i);
        for (int j=0;j<9;++j) {
            r = static_cast<unsigned long> (j);
            map[c][r]->clear();
        }
    }
    for (int i=0;i<3;++i) {
        c = static_cast<unsigned long> (i);
        box[c]->clear();
    }
    level_2();
}

void MainWindow::on_backButton_clicked()
{
    step=0;total_pt = 0;
    ui->count->setText("STEP "+QString::number(step));
    ui->win->setVisible(false);
    unsigned long c,r;
    time = 0;
    lab_char->clear();
    emerald->clear();
    char_girl->clear();
    for (int i=0;i<9;++i) {
        c = static_cast<unsigned long> (i);
        for (int j=0;j<9;++j) {
            r = static_cast<unsigned long> (j);
            map[c][r]->clear();
        }
    }
    for (int i=0;i<3;++i) {
        c = static_cast<unsigned long> (i);
        box[c]->clear();
    }
    this->setMaximumSize(1000,550);
    this->setMinimumSize(1000,550);
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Button1_clicked()
{
    level_1();
    ui->ReButton->setVisible(true);
    ui->RtButton2->setVisible(false);
    this->setMaximumSize(650,495);
    this->setMinimumSize(650,495);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Button2_clicked()
{
    ui->ReButton->setVisible(false);
    ui->NtButton->setVisible(false);
    ui->RtButton2->setVisible(true);
    ui->win->setVisible(false);
    first=true;
    level_2();
    this->setMaximumSize(650,495);
    this->setMinimumSize(650,495);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_StartButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_NtButton_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}
