#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_client(new QMqttClient(this))  // 멤버 변수로 MQTT 클라이언트 생성
{
    ui->setupUi(this);

    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    //    updateLogStateChange();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonConnect_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected)
    {
        // MQTT 브로커 설정
        QString hostname = ui -> lineEditHost -> text();
        int port = ui -> spinBoxPort -> value();

        qDebug()<<hostname<<","<<port;
        m_client->setHostname(hostname);
        m_client->setPort(port);  // 일반 MQTT 포트

        // 추가 설정
        m_client->setCleanSession(true);
        m_client->setProtocolVersion(QMqttClient::MQTT_3_1_1);

        // MQTT 브로커에 연결
        m_client->connectToHost(); // 브로커에 연결

        ui->lineEditHost->setEnabled(false);
        ui->spinBoxPort->setEnabled(false);
        ui->buttonConnect->setText(tr("Disconnect"));

        // 상태 변경 로그 출력
        updateLogStateChange();

        //        m_client->connectToHost();
    }

    else
    {
        ui->lineEditHost->setEnabled(true);
        ui->spinBoxPort->setEnabled(true);
        ui->buttonConnect->setText(tr("Connect"));
        m_client->disconnectFromHost();
    }
}

void MainWindow::on_buttonQuit_clicked()
{
    QApplication::quit();
}

void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
            + QLatin1String(": State Change")
            + QString::number(m_client->state())
            + QLatin1Char('\n');
    ui->editLog->insertPlainText(content);
}

void MainWindow::brokerDisconnected()
{
    ui->lineEditHost->setEnabled(true);
    ui->spinBoxPort->setEnabled(true);
    ui->buttonConnect->setText(tr("Connect"));
}

void MainWindow::setClientPort(int p)
{
    m_client->setPort(p);
}

void MainWindow::on_buttonPublish_clicked()
{
    QString msg = ui ->lineEditMessage->text();
    m_client->publish(QString("amr/topic"), QByteArray(msg.toUtf8()), 2); // QoS 1
}

void MainWindow::on_buttonSubscribe_clicked()
{
    // 구독 시도
    auto subscription = m_client->subscribe(ui->lineEditTopic->text());
    qDebug()<<subscription;
    if (!subscription)
    {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }

    // 구독 성공 후 상태 변경 로그 출력
    updateLogStateChange();

    // 메시지 수신 콜백 설정
    connect(m_client, &QMqttClient::messageReceived, this, &MainWindow::onMessageReceived);
}

void MainWindow::onMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    qDebug() << "Received message: " << message << ", Topic: " << topic;

    // 메시지 처리 로직을 추가
    // 예: 로그에 기록, UI 업데이트 등
    QMetaObject::invokeMethod(this, [this, message, topic]() {
        QString logMessage = QString("Received message on topic %1: %2\n").arg(topic.name(), QString(message));
        ui->editLog->insertPlainText(logMessage);
    });
}
