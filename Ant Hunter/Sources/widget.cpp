/**
  widget.h
  Purpose: main gaming space

  @author inmistlosted
  @version 1.1
*/

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(600,170);
    this->setFixedSize(600,170);

    scene = new QGraphicsScene();

    com = new Complexity();

    game_over = new GameOver();

    board = new Leader_board();

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
    connect(pauseKey, &QShortcut::activated, this, &Widget::Pause);

    ui->graphicsView->hide();
    ui->lcdNumber->hide();
    ui->label->hide();

    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::Choose_Complexity);
    connect(ui->leaderBtn, &QPushButton::clicked, this, &Widget::Open_ResultBoard);
    connect(game_over, &GameOver::accepted, this, &Widget::Add_Leader);
}

//Ends game
void Widget::GameIsOver()
{
    /** stops all timers if game is over */
    timer->stop();
    timerCreatePear->stop();

    this->resize(600,170);
    this->setFixedSize(600,170);
    ui->graphicsView->hide();
    ui->lcdNumber->hide();
    ui->label->hide();

    //QMediaPlayer * m_player = new QMediaPlayer(this);
    //QMediaPlaylist * m_playlist = new QMediaPlaylist(m_player);
    //QSound::play("://Music/scream.wav");
    //m_player->setPlaylist(m_playlist);
    //m_playlist->addMedia(QUrl("qrc://Music/StarTrekWarning.wav"));
    //m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    //m_player->play();

    /** warns that game is over */
    game_over->open();
    game_over->Show_score(ui->lcdNumber->value());
    contestant = new Leader();

    /** disconnects signals from slots */
    disconnect(timerCreatePear, &QTimer::timeout, this, &Widget::CreatePear);
    disconnect(ant, &Ant::CheckItem, this, &Widget::DeletePear);
    disconnect(spider, &Spider::CheckGameOver, this, &Widget::GameIsOver);

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
void Widget::Pause()
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

//opens dialog to choose complexity
void Widget::Choose_Complexity()
{
    com->open();
}

//opens ResultBoard
void Widget::Open_ResultBoard()
{
    board->open();
}

//adds player's result to ResultBoard
void Widget::Add_Leader()
{
    contestant->Set_Name(game_over->Enter_name());
    contestant->Set_Value(ui->lcdNumber->value());
    board->Add_Leader(contestant);
}

Widget::~Widget()
{
    delete ui;
}

//Deletes pears if ant come across with it
void Widget::DeletePear(QGraphicsItem *item)
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

            //QMediaPlayer * m_player = new QMediaPlayer(this);
            //QMediaPlaylist * m_playlist = new QMediaPlaylist(m_player);
            //QSound::play("://Music/munch.wav");
            //m_player->setPlaylist(m_playlist);
            //m_playlist->addMedia(QUrl("qrc://Music/munch.wav"));
            //m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
            //m_player->play();
        }
        ui->lcdNumber->display(count);
    }
}

//Creates pears
void Widget::CreatePear()
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
    this->resize(600,700);
    this->setFixedSize(600,700);

    count = 0;
    ui->lcdNumber->display(count);
    ui->lcdNumber->setPalette(Qt::red);

    ui->graphicsView->show();
    ui->lcdNumber->show();
    ui->label->show();

    /** adds ant */
    ant = new Ant();
    scene->addItem(ant);
    ant->setPos(0,0);

    /** ads spider */
    spider = new Spider(ant);
    spider->get_Complexity(com->getComplexity());
    scene->addItem(spider);
    spider->setPos(180,180);

    connect(spider, &Spider::CheckGameOver, this, &Widget::GameIsOver);

    /** timer of a game */
    connect(timer, &QTimer::timeout, ant, &Ant::GameTimer);
    timer->start(1000/100);

    /** creates pear every second */
    connect(timerCreatePear, &QTimer::timeout, this, &Widget::CreatePear);
    timerCreatePear->start(1000);

    connect(ant, &Ant::CheckItem, this, &Widget::DeletePear);

    ui->pushButton->setEnabled(false);

    gameState = GAME_STARTED;
}
