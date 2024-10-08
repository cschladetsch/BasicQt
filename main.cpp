#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>
#include <format>

class BasicApp : public QWidget {
    Q_OBJECT

public:
    BasicApp(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Basic Qt App (C++23)");
        setGeometry(300, 300, 300, 150);

        auto layout = new QVBoxLayout(this);

        m_textField = new QLineEdit(this);
        layout->addWidget(m_textField);

        auto button = new QPushButton("Click Me", this);
        layout->addWidget(button);

        connect(button, &QPushButton::clicked, this, &BasicApp::onButtonClicked);
    }

private slots:
    void onButtonClicked() {
        auto text = m_textField->text();
        
        // Using C++23 std::format
        auto formatted = std::format("Button clicked! Text field contains: {}", text.toStdString());
        qDebug() << formatted.c_str();
    }

private:
    QLineEdit *m_textField;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    BasicApp basicApp;
    basicApp.show();
    return app.exec();
}

#include "main.moc"
