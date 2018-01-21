#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QWidget>
#include <QPushButton>
#include <QtWidgets>
#include <QTabWidget>
#include <QTextEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QString>
#include <QComboBox>

class MaFenetre : public QWidget
{
    Q_OBJECT

    public:
    MaFenetre();


    public slots:
    void Retourne_MessageCrypte();
    void Retourne_MessageDecrypte();


    private:
    QPushButton *bouton_fermer;
    QPushButton *bouton_aide;
    QTabWidget *onglets;
    QWidget *page1;
    QWidget *page2;
    QTextEdit *textEditW1;
    QTextEdit *textEditR1;
    QTextEdit *textEditW2;
    QTextEdit *textEditR2;
    QLineEdit *lineEditd1;
    QPushButton *boutonc1;
    QPushButton *boutond2;
    QGridLayout *gridboxc1;
    QGridLayout *gridboxd2;
    QGridLayout *gridbox;
    QComboBox *comboboxc1;
    QComboBox *comboboxd2;
};

#endif
/*Homework:
 * Table de fréquences ppur random
 * analyse fréquentielle pour vigenere
 * Finir les signaux, les slots, petit menu déroulant*/
