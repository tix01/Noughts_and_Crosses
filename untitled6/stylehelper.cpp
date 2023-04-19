
#include "stylehelper.h"



QString StyleHelper::getMainWidgetStyle()
{
    return"QWidget{"
          "background-image: url(:/resourses/images/bg.png);"
          "}";
}

QString StyleHelper::getStartButtonStyle()
{
    return "QPushButton{"
           "color:#fff;"
           "background: none;"
           "border: none;"
           "border-radius:19px;"
           "background-color: qlineargradient(spread:pad, x1:0.741294, y1:0.824, x2:1, y2:1, stop:0 rgba(65, 118, 184, 255), stop:1 rgba(255, 255, 255, 255));"
           "font-family: 'Roboto Medium';"
           "font-size: 16px;"
           "}"
        "QPushButton::hover {"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.323383 rgba(255, 0, 0, 255), stop:0.766169 rgba(255, 255, 255, 255));"
        "}"
        "QPushButton::pressed {"
           "background-color: qlineargradient(spread:pad, x1:0.741294, y1:0.824, x2:1, y2:1, stop:0 rgba(65, 118, 184, 255), stop:1 rgba(255, 255, 255, 255));"
           "}";
}
QString StyleHelper::getStartButtonGameStyle()
{
    return "QPushButton{"
           "   color:#fff;"
           "   background: none;"
           "   border:none;"
           "   border-radius:19px;"
           "   background-color: qlineargradient(spread:pad, x1:0.006, y1:0, x2:0, y2:1, stop:0 rgba(212, 46, 96, 255), stop:1 rgba(255, 121, 119, 255));"
           "   font-family: 'Roboto Medium';"
           "   font-size:16px;"
           "}"
           "QPushButton::hover{"
           "background-color: qlineargradient(spread:pad, x1:0.006, y1:0, x2:0, y2:1, stop:0 rgba(212, 56, 106, 255), stop:1 rgba(255, 131, 129, 255));"
           "}"
           "QPushButton::pressed{"
           "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(89, 156, 208, 255), stop:1 rgba(65, 118, 184, 255));"
           "}";

}

QString StyleHelper::getAboutTextStyle()
{
    return "QLabel{"
           "font-family: 'Roboto Medium';"
           "font-size: 12px;"
           "color:#ffffff;"
           "font-style:italic;"
           "}";
}

QString StyleHelper::getTabStyle()
{
        return  "QWidget#tab{"
               "   background:none;"
               "   background: rgb(33, 40, 50);"
               "}";
}
QString StyleHelper::getLeftButtonStyle()
{
    return "QPushButton{"
           "background-color: qlineargradient(spread:pad, x1:0.119, y1:0.0625, x2:1, y2:1, stop:0 rgba(102, 102, 102, 255), stop:1 rgba(255, 255, 255, 255));"
           "background-image: url(:/resourses/images/cross_small.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:1px solid #333;"
           "border-top-left-radius:5px;"
           "border-bottom-left-radius:5px;"
           "}";
}

QString StyleHelper::getRightButtonStyle()
{
    return "QPushButton{"
           "background-color: qlineargradient(spread:pad, x1:0.119, y1:0.0625, x2:1, y2:1, stop:0 rgba(102, 102, 102, 255), stop:1 rgba(255, 255, 255, 255));"
           "background-image: url(:/resourses/images/zero_small.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:1px solid #333;"
           "border-left:none;"
           "border-top-right-radius:5px;"
           "border-bottom-right-radius:5px;"
           "}";


}

QString StyleHelper::getLeftButtonActiveStyle()
{
    return "QPushButton{"
           "background-color: #2b313b;"
           "background-image: url(:/resourses/images/cross_small.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:1px solid #333;"
           "border-left:none;"
           "border-top-right-radius:5px;"
           "border-bottom-right-radius:5px;"
           "}";
}

QString StyleHelper::getRightButtonActiveStyle()
{
    return "QPushButton{"
           "background-color: #2b313b;"
           "background-image: url(:/resourses/images/zero_small.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:1px solid #333;"
           "border-left:none;"
           "border-top-right-radius:5px;"
           "border-bottom-right-radius:5px;"
           "}";
}

QString StyleHelper::getTabWidgetStyle()
{
    return  "QTabWidget{"
           "border:none;"
           "}"
           "QTabWidget::pane{"
           "border:1px solid #222;"
           "border-radius:3px"
           "}"
           "QWidget#tab{"
           "background: rgb(33, 40, 50);"
           "}";
}

QString StyleHelper::getBlankButtonStyle()
{
    return"QPushButton{"
          "border:none;"
          "background:#272D39;"
          "}"
          "QPushButton::hover{"
          "background:#373D49;"
          "}";
}

QString StyleHelper::getCrossNormalStyle()
{
    return"QPushButton{"
           "border:none;"
           "background:#272D39 url(:/resourses/images/cross_large.png) no-repeat center center;"
           "}"
           "QPushButton::hover{"
           "background-color:#373D49;"
           "}";
}

QString StyleHelper::getCrossVictoryStyle()
{
    return"QPushButton{"
           "border:none;"
           "background-color:#20401B;"
           "background-image:url(:/resourses/images/cross_large.png);"
           "background-repeat:no-repeat;"
           "background-position: center center;"
           "}";
}

QString StyleHelper::getCrossLostStyle()
{
    return"QPushButton{"
           "border:none;"
           "background-color:#7F1F8C;"
           "background-image:url(:/resourses/images/cross_large.png);"
           "background-repeat:no-repeat;"
           "background-position: center center;"
           "}";
}
QString StyleHelper::getZeroNormalStyle()
{
    return"QPushButton{"
           "border:none;"
           "background:#272D39 url(:/resourses/images/zero_large.png) no-repeat center center;"
           "}"
           "QPushButton::hover{"
           "background-color:#373D49;"
           "}";
}

QString StyleHelper::getZeroVictoryStyle()
{
    return"QPushButton{"
           "border:none;"
           "background-color:#20401B;"
           "background-image:url(:/resourses/images/zero_large.png);"
           "background-repeat:no-repeat;"
           "background-position: center center;"
           "}";
}

QString StyleHelper::getZeroLostStyle()
{
    return"QPushButton{"
           "border:none;"
           "background-color:#7F1F8C;"
           "background-image:url(:/resourses/images/zero_large.png);"
           "background-repeat:no-repeat;"
           "background-position: center center;"
           "}";
}

QString StyleHelper::getNormalMassStyle()
{
    return "QLabel{"
           "font-family: 'Roboto Medium';"
           "font-size: 12px;"
           "background:none;"
           "color:#ffffff;"
           "}";
}

QString StyleHelper::getVictoryMassStyle()
{
    return "QLabel{"
           "font-family: 'Roboto Medium';"
           "font-size: 12px;"
           "background:#055902;"
           "border:1px solid #1C7C32;"
           "color:#ffffff;"
           "}";
}

QString StyleHelper::getLostMassStyle()
{
    return "QLabel{"
           "font-family: 'Roboto Medium';"
           "font-size: 12px;"
           "background:#961F99;"
           "border:1px solid #E237F5;"
           "color:#ffffff;"
           "}";
}


