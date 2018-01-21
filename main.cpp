#include <QApplication>
#include "mafenetre.h"
#include "DecodeRandom.hpp"


int main(int argc, char *argv[])
{
    std::string phrase0 = "easiratin est. une personne que j'apprecie fortement !";

    QString phraseClef = QString::fromStdString(phraseToRandomPhrase("abcdefghijklmnopqrstuvwxyz"));

    std::cout << phraseClef.toStdString() << std::endl;

    QString phraseCodee = decodeRandom(QString::fromStdString(phrase0), phraseClef, 0);

    QString phraseDecodee = decodeRandom(phraseCodee, phraseClef, 1);

    std::cout << phraseCodee.toStdString() << std::endl;

    std::cout << phraseDecodee.toStdString() << std::endl;

    QApplication app(argc, argv);

    MaFenetre fenetre;

    fenetre.show();

    return app.exec();

}
