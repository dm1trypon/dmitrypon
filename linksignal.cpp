#include "const.h"

void LinkSignal::destroy(int var)
{
    switch (var) {
    case DESTROY:
        emit signalDestroy();
        break;
    case ENDGAME:
        emit signalEndGameMessage();
        break;
    case DESTROY_ENEMY_SPACESHIP:
        emit signalDestroyEnemySpaceship();
        break;
    default:
        break;
    }
}

void LinkSignal::descriptionEndGame(QString textLine)
{
    emit signalDescriptionEndGame(textLine);
}

void LinkSignal::getScore(int score)
{
    emit signalGetScore(score);
}

void LinkSignal::getLineEditText(QString lineEditText)
{
    emit signalLineEditText(lineEditText);
}

void LinkSignal::endGameCheck(bool endGame)
{
    emit signalEndGameCheck(endGame);
}

void LinkSignal::sendToServerGet()
{
    emit signalSendToServerGet();
}

void LinkSignal::sendToServerSet()
{
    emit signalSendToServerSet();
}

LinkSignal &LinkSignal::Instance()
{
    static LinkSignal theSingleInstance;
    return theSingleInstance;
}
