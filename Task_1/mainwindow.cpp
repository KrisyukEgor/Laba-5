#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTextCursor cursor = ui -> Word_write_textedit -> textCursor();
    QTextBlockFormat blockFormat;

    blockFormat.setLineHeight(130, QTextBlockFormat::ProportionalHeight);
    cursor.setBlockFormat(blockFormat);

    ui -> Word_write_textedit ->setTextCursor(cursor);

    folder_path = QDir::currentPath() + "/files";

    Bel_symbols_array_input();
    Change_keyboard_language(bel_symbols);

    QDir folder_dir(folder_path);

    if(!folder_dir.exists()){
        folder_dir.mkdir(folder_path);
    }

    current_file_path = folder_path + "/belarussian";

    QFile bel_file(current_file_path);

    if(bel_file.open(QIODevice::ReadOnly | QIODevice:: Text)){

        QTextStream stream(&bel_file);
        QString line;
        QStringList words;

        while(!stream.atEnd()){
            line = stream.readLine();
            words = line.split(" ");

            for (const QString& word : words) {
                if (!word.isEmpty()) {
                    words_list.append(word.toLower());
                }
            }

        }
        Add_text_to_Widget();
    }
}


void MainWindow::keyPressEvent(QKeyEvent* event) {

    int key = event -> key();

    Define_button_to_light(key);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Add_text_to_Widget(){
    QString text;
    for(int i = 0; i < words_list.length(); ++i){
        text += words_list[i] + " ";
    }

    ui -> Word_write_textedit -> setText(text);
}

void MainWindow::Random_word_list(){

    QStringList words_list_copy = words_list;



    for(int i = 0; i < words_list.length(); ++i){

    }
}

void MainWindow::on_Word_write_textedit_textChanged()
{

}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    current_index = index;
}

void MainWindow::Bel_symbols_array_input(){

    bel_symbols.append("Й");
    bel_symbols.append("Ц");
    bel_symbols.append("У");
    bel_symbols.append("К");
    bel_symbols.append("Е");
    bel_symbols.append("Н");
    bel_symbols.append("Г");
    bel_symbols.append("Ш");
    bel_symbols.append("Ў");
    bel_symbols.append("З");
    bel_symbols.append("Х");
    bel_symbols.append("’");

    bel_symbols.append("Ф");
    bel_symbols.append("Ы");
    bel_symbols.append("В");
    bel_symbols.append("А");
    bel_symbols.append("П");
    bel_symbols.append("Р");
    bel_symbols.append("О");
    bel_symbols.append("Л");
    bel_symbols.append("Д");
    bel_symbols.append("Ж");
    bel_symbols.append("Э");
    bel_symbols.append("Я");

    bel_symbols.append("Ч");
    bel_symbols.append("С");
    bel_symbols.append("М");
    bel_symbols.append("І");
    bel_symbols.append("Т");
    bel_symbols.append("Ь");
    bel_symbols.append("Б");
    bel_symbols.append("Ю");
}

void MainWindow::Change_keyboard_language(QList<QString> list){
    ui -> English_q_button -> setText(list[0]);
    ui -> English_w_button -> setText(list[1]);
    ui -> English_e_button -> setText(list[2]);
    ui -> English_r_button -> setText(list[3]);
    ui -> English_t_button -> setText(list[4]);
    ui -> English_y_button -> setText(list[5]);
    ui -> English_u_button -> setText(list[6]);
    ui -> English_i_button -> setText(list[7]);
    ui -> English_o_button -> setText(list[8]);
    ui -> English_p_button -> setText(list[9]);
    ui -> English_array_left_button -> setText(list[10]);
    ui -> English_array_right_button -> setText(list[11]);

    ui -> English_a_button -> setText(list[12]);
    ui -> English_s_button -> setText(list[13]);
    ui -> English_d_button -> setText(list[14]);
    ui -> English_f_button -> setText(list[15]);
    ui -> English_g_button -> setText(list[16]);
    ui -> English_h_button -> setText(list[17]);
    ui -> English_j_button -> setText(list[18]);
    ui -> English_k_button -> setText(list[19]);
    ui -> English_l_button -> setText(list[20]);
    ui -> English_CAD_button -> setText(list[21]);
    ui -> English_quotes_button -> setText(list[22]);

    ui -> English_z_button -> setText(list[23]);
    ui -> English_x_button -> setText(list[24]);
    ui -> English_c_button -> setText(list[25]);
    ui -> English_v_button -> setText(list[26]);
    ui -> English_b_button -> setText(list[27]);
    ui -> English_n_button -> setText(list[28]);
    ui -> English_m_button -> setText(list[29]);
    ui -> English_comma_button -> setText(list[30]);
    ui -> English_dot_button -> setText(list[31]);

}

void MainWindow::Define_button_to_light(int key){
    QPushButton temp;
    int index = -1;
    if(key == Qt::Key_Q){
        Light_the_button(ui -> English_q_button);
        int index = 0;
    }

    else if(key == Qt::Key_W){
        Light_the_button(ui -> English_w_button);
        index = 1;
    }

    else if(key == Qt::Key_E){
        Light_the_button(ui -> English_e_button);
        index = 2;
    }
    else if(key == Qt::Key_R){
        Light_the_button(ui -> English_r_button);
        index = 3;
    }
    else if(key == Qt::Key_T){
        Light_the_button(ui -> English_t_button);
        index = 4;
    }
    else if(key == Qt::Key_Y){
        Light_the_button(ui -> English_y_button);
        index = 5;
    }
    else if(key == Qt::Key_U){
        Light_the_button(ui -> English_u_button);
        index = 6;
    }
    else if(key == Qt::Key_I){
        Light_the_button(ui -> English_i_button);
        index = 7;
    }
    else if(key == Qt::Key_O){
        Light_the_button(ui -> English_o_button);
        index = 8;
    }
    else if(key == Qt::Key_P){
        Light_the_button(ui -> English_p_button);
        index = 9;
    }
    else if(key == Qt::Key_BracketLeft){
        Light_the_button(ui -> English_array_left_button);
        index = 10;
    }
    else if(key == Qt::Key_BracketRight){
        Light_the_button(ui -> English_array_right_button);
        index = 11;
    }


    else if(key == Qt::Key_A){
        Light_the_button(ui -> English_a_button);
        index = 12;
    }
    else if(key == Qt::Key_S){
        Light_the_button(ui -> English_s_button);
        index = 13;
    }
    else if(key == Qt::Key_D){
        Light_the_button(ui -> English_d_button);
        index = 14;
    }
    else if(key == Qt::Key_F){
        Light_the_button(ui -> English_f_button);
        index = 15;
    }
    else if(key == Qt::Key_G){
        Light_the_button(ui -> English_g_button);
        index = 16;
    }
    else if(key == Qt::Key_H){
        Light_the_button(ui -> English_h_button);
        index = 17;
    }
    else if(key == Qt::Key_J){
        Light_the_button(ui -> English_j_button);
        index = 18;
    }
    else if(key == Qt::Key_K){
        Light_the_button(ui -> English_k_button);
        index = 19;
    }
    else if(key == Qt::Key_L){
        Light_the_button(ui -> English_l_button);
        index = 20;
    }
    else if(key == Qt::Key_Semicolon){
        Light_the_button(ui -> English_CAD_button);
        index = 21;
    }
    else if(key == Qt::Key_Apostrophe){
        Light_the_button(ui -> English_quotes_button);
        index = 22;
    }


    else if(key == Qt::Key_Z){
        Light_the_button(ui -> English_z_button);
        index = 23;
    }
    else if(key == Qt::Key_X){
        Light_the_button(ui -> English_x_button);
        index = 24;
    }
    else if(key == Qt::Key_C){
        Light_the_button(ui -> English_c_button);
        index = 25;
    }
    else if(key == Qt::Key_V){
        Light_the_button(ui -> English_v_button);
        index = 26;
    }
    else if(key == Qt::Key_B){
        Light_the_button(ui -> English_b_button);
        index = 27;
    }
    else if(key == Qt::Key_N){
        Light_the_button(ui -> English_n_button);
        index = 28;
    }
    else if(key == Qt::Key_M){
        Light_the_button(ui -> English_m_button);
        index = 29;
    }
    else if(key == Qt::Key_Comma){
        Light_the_button(ui -> English_comma_button);
        index = 30;
    }
    else if(key == Qt::Key_Period){
        Light_the_button(ui -> English_dot_button);
        index = 31;
    }
    else if(key == Qt::Key_Space){
        Light_the_button(ui -> English_space_button);
        index = 32;
    }
    Letter_in_text_change_color(index);

}

void MainWindow::Letter_in_text_change_color(int index){

}
void MainWindow::Light_the_button(QPushButton* button){

    QTimer* timer = new QTimer(this);

    timer -> setInterval(60);

    QString style = "background-color: yellow;";

    connect(timer, &QTimer::timeout, this, [=] () mutable{
        button->setStyleSheet("");
        timer -> stop();
    });

    button -> setStyleSheet(style);

    timer -> start();
}
