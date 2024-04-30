#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QString>
#include <QStringList>
#include <QLineEdit>
#include <QKeyEvent>
#include <QPushButton>
#include <QTimer>
#include <QList>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_Word_write_textedit_textChanged();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QString folder_path;
    QString current_file_path;

    QStringList words_list;

    void keyPressEvent(QKeyEvent* event) override;
    void Add_text_to_Widget();
    void Random_word_list();

    QList<QString> bel_symbols;
    QList<QString> german_symbols;
    QList<QString> franch_symbols;
    QList<QString> arabic_symbols;
    QList<QString> chinese_symbols;
    QList<QString> hebrew_symbols;

    void Bel_symbols_array_input();
    void German_symbols_array_input();
    void Franch_symbols_array_input();
    void Arabic_symbols_array_input();
    void Chinese_symbols_array_input();
    void Hebrew_symbols_array_input();

    void Change_keyboard_language(QList<QString>);

    void Define_button_to_light(int);
    void Light_the_button(QPushButton* );

    void Letter_in_text_change_color(int index);

    int current_index = 0;

};
#endif // MAINWINDOW_H
