
#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow

{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();
    //void paintEvent(QPaintEvent* event);
private slots:
    void on_LeftButton_clicked();

    void on_RightButton_clicked();

    void on_startButton_clicked();

    void onGameAreaButtonClicked();

    void onComputerSlot();

    void on_aboutButton_clicked();

private:
    Ui::Window *ui;
    void setInterStyle();
    void changeLeftRightButton(int num);
    void configurationTabWidget();
    void configurationGameAreaButton();
    void addFonts();
    void changeButtonStyle(int row,int colum,QString style);
    void setGameAreaButtonStyle();
    void start();
    void lockPlayer();
    void computerInGame();
    void chekGameStop();
    void endGame();
    char gameArea[3][3]={
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}

    };
    char player='X';
    int progress=0;
    bool gameStart=false;
    bool playerLocked=true;
    QTimer* timer;
    bool stop;
    char winner;

};

#endif // WINDOW_H
