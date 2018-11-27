/**
  widget.h
  Purpose: main gaming space

  @author inmistlosted
  @version 1.0
*/

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(600,600);
    this->setFixedSize(600,600);

    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->lcdNumber->setPalette(Qt::red);

    scene->setSceneRect(-250,-250,500,500);

    timer = new QTimer();

    timerCreatePear = new QTimer();

    gameState = GAME_STOPED;

    pauseKey = new QShortcut(this);
    pauseKey->setKey(Qt::Key_Space);
    connect(pauseKey, &QShortcut::activated, this, &Widget::slotPause);
}

//Ends game
void Widget::slotGameOver()
{
    /** stops all timers if game is over */
    timer->stop();
    timerCreatePear->stop();

  //  QMediaPlayer * m_player = new QMediaPlayer(this);
  //  QMediaPlaylist * m_playlist = new QMediaPlaylist(m_player);

     //   QSound::play("://Music/scream.wav");

  //  m_player->setPlaylist(m_playlist);
  //  m_playlist->addMedia(QUrl("qrc://Music/StarTrekWarning.wav"));
  //  m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
  //  m_player->play();

    /** warns that game is over */
    QMessageBox::warning(this,
                         "R.I.P",
                         "Unfortunately you were eaten!!!");

    /** disconnects signals from slots */
    disconnect(timerCreatePear, &QTimer::timeout, this, &Widget::slotCreatePear);
    disconnect(ant, &Ant::signalCheckItem, this, &Widget::slotDeletePear);
    disconnect(spider, &Spider::signalCheckGameOver, this, &Widget::slotGameOver);

    /* deletes all objects from scene */
    spider->deleteLater();
    ant->deleteLater();

    foreach (QGraphicsItem *pear, pears) {
        scene->removeItem(pear);
        pears.removeOne(pear);
        delete pear;
    }

    ui->pushButton->setEnabled(true);

    gameState = GAME_STOPED;
}

//Pauses game
void Widget::slotPause()
{
    if(gameState == GAME_STARTED)
    {
        if(timer->isActive())
        {
            timer->stop();
            timerCreatePear->stop();
            spider->pause();
        }
        else
        {
            timer->start(1000/100);
            timerCreatePear->start(1000);
            spider->pause();
        }
    }
}


Widget::~Widget()
{
    delete ui;
}

//Deletes pears if ant come across with it
void Widget::slotDeletePear(QGraphicsItem *item)
{
    /** with receiving signal from ant, find pear in list and deletes it */
    foreach (QGraphicsItem *pear, pears)
    {
        if(pear == item)
        {
            scene->removeItem(pear);
            pears.removeOne(item);
            delete pear;
            ui->lcdNumber->display(count++);
            ui->lcdNumber->setPalette(Qt::red);

         //   QMediaPlayer * m_player = new QMediaPlayer(this);
         //   QMediaPlaylist * m_playlist = new QMediaPlaylist(m_player);

            //QSound::play("://Music/munch.wav");

         //   m_player->setPlaylist(m_playlist);
         //   m_playlist->addMedia(QUrl("qrc://Music/munch.wav"));
        //    m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
         //   m_player->play();
        }
    }
}

//Creates pears
void Widget::slotCreatePear()
{
    Pear *pear = new Pear();
    scene->addItem(pear);
    pear->setPos((qrand() % (251)) * ((qrand()%2 == 1)?1:-1),
                  (qrand() % (251)) * ((qrand()%2 == 1)?1:-1));
    pear->setZValue(-1);
    pears.append(pear);
}

//Starts game
void Widget::on_pushButton_clicked()
{
    count = 0;
    ui->lcdNumber->display(count);
    ui->lcdNumber->setPalette(Qt::red);

    /** adds ant */
    ant = new Ant();
    scene->addItem(ant);
    ant->setPos(0,0);

    /** ads spider */
    spider = new Spider(ant);
    scene->addItem(spider);
    spider->setPos(180,180);

    connect(spider, &Spider::signalCheckGameOver, this, &Widget::slotGameOver);

    /** timer of a game */
    connect(timer, &QTimer::timeout, ant, &Ant::slotGameTimer);
    timer->start(1000/100);

    /** creates pear every second */
    connect(timerCreatePear, &QTimer::timeout, this, &Widget::slotCreatePear);
    timerCreatePear->start(1000);

    connect(ant, &Ant::signalCheckItem, this, &Widget::slotDeletePear);

    ui->pushButton->setEnabled(false);

    gameState = GAME_STARTED;
}
