
#include "window.h"
#include "ui_window.h"
#include "QTabBar"
#include "stylehelper.h"
#include<QStyleOption>
#include<QFontDatabase>
#include<QGridLayout>
#include<QDebug>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    configurationTabWidget();
    addFonts();
    setInterStyle();
    configurationGameAreaButton();
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Window::onComputerSlot);


}

Window::~Window()
{
    delete ui;
}

/*void Window::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
    QWidget::paintEvent(event);
}
*/
void Window::setInterStyle()
{
    this->setStyleSheet(StyleHelper::getMainWidgetStyle());
    ui->aboutButton->setStyleSheet(StyleHelper::getStartButtonStyle());
    ui->startButton->setStyleSheet(StyleHelper::getStartButtonStyle());
    ui->LeftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
    ui->RightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
    ui->tabWidget->setStyleSheet(StyleHelper::getTabWidgetStyle());
    ui->tab->setStyleSheet(StyleHelper::getTabStyle());
    ui->MassegLabel->setStyleSheet(StyleHelper::getVictoryMassStyle());
    ui->MassegLabel->setText("Ходят крестики");

    setGameAreaButtonStyle();
    ui->MassegLabel->setText("");
    ui->MassegLabel->setStyleSheet(StyleHelper::getNormalMassStyle());
   ui->label_3->setStyleSheet(StyleHelper::getAboutTextStyle());
}

void Window::changeLeftRightButton(int num)
{
    if(num==1){
        ui->LeftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
        ui->RightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
    }else{
        ui->LeftButton->setStyleSheet(StyleHelper::getLeftButtonStyle());
        ui->RightButton->setStyleSheet(StyleHelper::getRightButtonActiveStyle());
    }
}

void Window::configurationTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setMaximumHeight(320);
    ui->tabWidget->setCurrentIndex(0);
}

void Window::configurationGameAreaButton()
{
    QGridLayout* grid=qobject_cast<QGridLayout*>(ui->tab->layout());
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            QPushButton* btn=qobject_cast<QPushButton*>(grid->itemAtPosition(i,j)->widget());
            btn->setProperty("row",i);
            btn->setProperty("colum",j);
            connect(btn,&QPushButton::clicked,this,&Window::onGameAreaButtonClicked);
        }
    }
}

void Window::addFonts()
{
    QFontDatabase::addApplicationFont(":/resourses/fonts/Roboto-Medium.ttf");
    QFontDatabase::addApplicationFont(":/resourses/fonts/Roboto-MediumItalic.ttf");

}

void Window::changeButtonStyle(int row, int colum, QString style)
{
    QGridLayout* grid=qobject_cast<QGridLayout*>(ui->tab->layout());
    QPushButton* btn=qobject_cast<QPushButton*>(grid->itemAtPosition(row,colum)->widget());
    btn->setStyleSheet(style);

}

void Window::setGameAreaButtonStyle()
{
    QString style=StyleHelper::getBlankButtonStyle();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            changeButtonStyle(i,j,style);
        }
    }
}

void Window::start()
{
    setGameAreaButtonStyle();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            gameArea[i][j]='-';
        }
    }
    progress=0;
    gameStart=true;
    stop=false;
    winner='-';
    if(player!='X'){
        computerInGame();
    }
}

void Window::lockPlayer()
{
    if(player=='X'){
        playerLocked=false;
    }else{
        playerLocked=true;
    }
}

void Window::computerInGame()
{
    if(stop){
        return;
    }
    ui->MassegLabel->setText("My ход");
    timer->start(2000);
}

void Window::chekGameStop()
{
    winner = '-';
    QString style;
    char symbols[2] = {'X','0'};
    for(int i=0;i<2;i++){
        for (int row=0;row<3;row++ ) {
            if((gameArea[row][0]==symbols[i])and(gameArea[row][1]==symbols[i])and(gameArea[row][2]==symbols[i])){
                stop = true;
                winner = symbols[i];
                if(winner==player){
                    if(player == 'X'){
                        style=StyleHelper::getCrossVictoryStyle();
                    }else{
                        style=StyleHelper::getZeroVictoryStyle();
                    }
                }else{
                    if(player == 'X'){
                        style=StyleHelper::getZeroLostStyle();
                    }else{
                        style=StyleHelper::getCrossLostStyle();
                    }
                }
                changeButtonStyle(row,0,style);
                changeButtonStyle(row,1,style);
                changeButtonStyle(row,2,style);
                return;
            }
        }
        for (int col=0;col<3;col++ ) {
            if((gameArea[0][col]==symbols[i])and(gameArea[1][col]==symbols[i])and(gameArea[2][col]==symbols[i])){
                stop = true;
                winner = symbols[i];
                if(winner==player){
                    if(player == 'X'){
                        style=StyleHelper::getCrossVictoryStyle();
                    }else{
                        style=StyleHelper::getZeroVictoryStyle();
                    }
                }else{
                    if(player == 'X'){
                        style=StyleHelper::getZeroLostStyle();
                    }else{
                        style=StyleHelper::getCrossLostStyle();
                    }
                }
                changeButtonStyle(0,col,style);
                changeButtonStyle(1,col,style);
                changeButtonStyle(2,col,style);
                return;
            }
        }
        if((gameArea[0][0]==symbols[i])and(gameArea[1][1]==symbols[i])and(gameArea[2][2]==symbols[i])){
            stop = true;
            winner = symbols[i];
            if(winner==player){
                if(player == 'X'){
                    style=StyleHelper::getCrossVictoryStyle();
                }else{
                    style=StyleHelper::getZeroVictoryStyle();
                }
            }else{
                if(player == 'X'){
                    style=StyleHelper::getZeroLostStyle();
                }else{
                    style=StyleHelper::getCrossLostStyle();
                }
            }
            changeButtonStyle(0,0,style);
            changeButtonStyle(1,1,style);
            changeButtonStyle(2,2,style);
            return;
        }
        if((gameArea[0][2]==symbols[i])and(gameArea[1][1]==symbols[i])and(gameArea[2][0]==symbols[i])){
            stop = true;
            winner = symbols[i];
            if(winner==player){
                if(player == 'X'){
                    style=StyleHelper::getCrossVictoryStyle();
                }else{
                    style=StyleHelper::getZeroVictoryStyle();
                }
            }else{
                if(player == 'X'){
                    style=StyleHelper::getZeroLostStyle();
                }else{
                    style=StyleHelper::getCrossLostStyle();
                }
            }
            changeButtonStyle(0,2,style);
            changeButtonStyle(1,1,style);
            changeButtonStyle(2,0,style);
            return;
        }

    }
    if(progress==9){
        stop = true;
    }

}

void Window::endGame()
{
    if(stop){
        if(winner == player){
            ui->MassegLabel->setText("Победа!");
            ui->MassegLabel->setStyleSheet(StyleHelper::getVictoryMassStyle());
        }else if(winner=='-'){
            ui->MassegLabel->setText("Ничья!");
        }else{
            ui->MassegLabel->setText("Проиграл");
            ui->MassegLabel->setStyleSheet(StyleHelper::getLostMassStyle());
        }
        playerLocked = true;
        ui->startButton->setText("Играть");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonStyle());

        ui->LeftButton->setDisabled(false);
        ui->RightButton->setDisabled(false);
        gameStart = false;
    }
}



void Window::on_LeftButton_clicked()
{
    changeLeftRightButton(1);
    player='X';
}


void Window::on_RightButton_clicked()
{
    changeLeftRightButton(0);
    player='0';
}


void Window::on_startButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    if(gameStart){
        playerLocked=true;
        ui->startButton->setText("Играть");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonStyle());
        ui->LeftButton->setDisabled(false);
        ui->RightButton->setDisabled(false);
        gameStart=false;
        ui->MassegLabel->setText("Проиграл");
        ui->MassegLabel->setStyleSheet(StyleHelper::getLostMassStyle());
    }else{
        ui->MassegLabel->setText("Игра началась");
        ui->MassegLabel->setStyleSheet(StyleHelper::getNormalMassStyle());
        start();
        lockPlayer();
        ui->startButton->setText("Сдаюсь");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonGameStyle());
        ui->LeftButton->setDisabled(true);
        ui->RightButton->setDisabled(true);

    }

}

void Window::onGameAreaButtonClicked()
{
    if(!playerLocked){
        QPushButton* btn=qobject_cast<QPushButton*>(sender());
        int row = btn->property("row").toInt();
        int colum = btn->property("colum").toInt();
        QString style;
        if(player=='X'){
            style=StyleHelper::getCrossNormalStyle();
            gameArea[row][colum]='X';
        }else{
            style=StyleHelper::getZeroNormalStyle();
            gameArea[row][colum]='0';
        }
        changeButtonStyle(row,colum,style);
        playerLocked=true;
        progress++;
        chekGameStop();
        endGame();
        computerInGame();

    }
}

void Window::onComputerSlot()
{

    char comp;
    QString style;
    if(player=='X'){
        comp='0';
        style=StyleHelper::getZeroNormalStyle();
    }else{
        comp='X';
        style=StyleHelper::getCrossNormalStyle();
    }
    timer->stop();
    while(true){
        int i=rand()%3;
        int j=rand()%3;
        if(gameArea[i][j]=='-'){
            gameArea[i][j]=comp;

            changeButtonStyle(i,j,style);
            ui->MassegLabel->setText("Твой ход");
            progress++;
            chekGameStop();
            endGame();
            playerLocked=false;
            break;
        }
    }


}


void Window::on_aboutButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

