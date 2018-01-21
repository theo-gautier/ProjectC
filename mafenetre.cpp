#include "mafenetre.h"
#include "Donnees.hpp"

MaFenetre::MaFenetre() : QWidget()
{
    //Personnalisation de la fenêtre

    setWindowTitle("Cypher");

    // 0 : Creation du bouton Ferme et du bouton  Aide

    bouton_fermer = new QPushButton("Fermer");
    bouton_aide = new QPushButton("Aide");

    // 1 : Creer le QTabWidget
    onglets = new QTabWidget();

    //Création des pages
    page1 = new QWidget(); //Page_Cryptage(this) est-il nécessaire
    page2 = new QWidget();

    //Page 1
    textEditW1 = new QTextEdit("Bonjour je suis un systeme de Cryptage");
    textEditR1 = new QTextEdit(""); //Ancien "TU NE PEUX RIEN MARQUER ICI"
    textEditR1->setReadOnly(true);
    lineEditd1 = new QLineEdit("Message-clé");
    boutonc1 = new QPushButton("Cryptez-moi");
    gridboxc1 = new QGridLayout;
    comboboxc1 = new QComboBox;

    //Liste déroulante
    comboboxc1->addItem("César");
    comboboxc1->addItem("DecalageRandom");
    comboboxc1->addItem("Vigenere");

    //Assignation des widgets page 1
    gridboxc1->addWidget(textEditW1,0,0);
    gridboxc1->addWidget(textEditR1,0,1);
    gridboxc1->addWidget(boutonc1,1,0);
    gridboxc1->addWidget(lineEditd1,1,1);
    gridboxc1->addWidget(comboboxc1,2,0);

    page1 -> setLayout(gridboxc1);

    //Page 2
    textEditW2 = new QTextEdit("Bonjour je suis un systeme de decryptage");
    textEditR2 = new QTextEdit(""); //"TU NE PEUX RIEN MARQUER ICI"
    textEditR2->setReadOnly(true);
    boutond2 = new QPushButton("Decryptez-moi");
    gridboxd2 = new QGridLayout;
    comboboxd2 = new QComboBox;

    //Liste déroulante
    comboboxd2->addItem("César");
    comboboxd2->addItem("DecalageRandom");
    comboboxd2->addItem("Vigenere");

    //Assignation des widgets page 2
    gridboxd2->addWidget(textEditW2,0,0);
    gridboxd2->addWidget(textEditR2,0,1);
    gridboxd2->addWidget(boutond2,1,0);
    gridboxd2->addWidget(comboboxd2,2,0);


    page2 -> setLayout(gridboxd2);

    //Ajout des Onglets
    onglets->addTab(page1, "Cryptage");
    onglets->addTab(page2, "Decryptage");

    // Ajout du layout pour organiser la fenêtre

    gridbox = new QGridLayout;
    gridbox->addWidget(onglets,0,0);
    gridbox->addWidget(bouton_fermer,1,0);
    gridbox->addWidget(bouton_aide,2,0);

    this -> setLayout(gridbox);

    //Signaux

    QObject::connect(bouton_fermer, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(boutonc1, SIGNAL(clicked()), this, SLOT(Retourne_MessageCrypte()));
    QObject::connect(boutond2, SIGNAL(clicked()), this, SLOT(Retourne_MessageDecrypte()));
}

void MaFenetre::Retourne_MessageCrypte()
{
    QString Phrase_A_Crypter = textEditW1-> toPlainText();
    QString lineEditd1 -> text();
    int index = (lineEditd1-> text()).toInt();
    std::string Phrase_Decale0 = decodeCesar(Phrase_A_Crypter.toStdString(),index);
    textEditR1 -> setText(QString::fromStdString(Phrase_Decale0));
}

void MaFenetre::Retourne_MessageDecrypte()
{
    QString Phrase_A_Decrypter = textEditW2-> toPlainText();
    std::string Phrase_Decale1 = bestDecode(Phrase_A_Decrypter.toStdString());
    textEditR2 -> setText(QString::fromStdString(Phrase_Decale1));
}





